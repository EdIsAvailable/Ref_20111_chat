#include<iostream>
#include <vector>
#include <string>
#include "Acc.h"
#include "Chat.h"
#include "Server.h"
#include "db.h"
#include <cstdio>
#include "Acc.h"
#include "Socket.h"
#include <memory>
using namespace std;

Server* _server;

int main()
{
	//setlocale(LC_ALL, "ru_RU.UTF-8");

	_server = new Server();
	_server->MainProcess();
        printf("Вас приветствует %s!\n", "Chat_db");
 
	return 0;
};



