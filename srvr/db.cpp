#include "db.h"

void saveMessage(const std::string& sender, const std::string& receiver, const std::string& message) {
    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        std::unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3306", "root", "123"));

        con->setSchema("chatdb");

        std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(
            "INSERT INTO Messages (SenderID, ReceiverID, MessageText) "
            "VALUES ((SELECT UserID FROM Users WHERE Username = ?), "
            "(SELECT UserID FROM Users WHERE Username = ?), ?)"
        ));

        pstmt->setString(1, sender);
        pstmt->setString(2, receiver);
        pstmt->setString(3, message);

        pstmt->executeUpdate();
        std::cout << "Message saved successfully!" << std::endl;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL error: " << e.what() << std::endl;
    }
}

void fetchMessages(const std::string& receiver) {
    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        std::unique_ptr<sql::Connection> con(driver->connect("tcp://127.0.0.1:3306", "root", "123"));

        con->setSchema("chatdb");

        std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(
            "SELECT SenderID, MessageText, Timestamp FROM Messages "
            "WHERE ReceiverID = (SELECT UserID FROM Users WHERE Username = ?)"
        ));
        pstmt->setString(1, receiver);

        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        while (res->next()) {
            std::cout << "From: " << res->getInt("SenderID")
                << " | Message: " << res->getString("MessageText")
                << " | At: " << res->getString("Timestamp") << std::endl;
        }
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL error: " << e.what() << std::endl;
    }
}


