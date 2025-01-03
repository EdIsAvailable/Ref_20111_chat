SRC = Acc.cpp Main.cpp NewUser.cpp Message.cpp Chat.cpp Server.cpp UserRepository.cpp Socket.cpp db.cpp
TARGET = chats
PREFIX = /home/server/ref2571/srvr
HEADERS = /usr/include/mysql/
LIBS = /usr/lib/x86_64-linux-gnu

chats: $(SRC)
	g++ -o $(TARGET) $(SRC) -I $(HEADERS) -L $(LIBS) -o $@ -lmysqlcppconn -ldl -lresolv -lm -lrt


clean:
	rm -rf *.o *.a

install:
	install $(TARGET) $(PREFIX)

uninstall:
	rm -rf $(PREFIX)/$(TARGET)


