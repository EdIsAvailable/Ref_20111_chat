#ifndef CHAT_DB_OPERATIONS_H
#define CHAT_DB_OPERATIONS_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <iostream>
#include <string>

void saveMessage(const std::string& sender, const std::string& receiver, const std::string& message);
void fetchMessages(const std::string& receiver);

#endif

