Проект по итогам модуля 20.11.1 (PJ-03) Ref_20111_chat
Идея: Ранее созданный месседжер на делён возможностью работать на платформе Linux с использованием клиент-серверной архитектуры.

Условие задачи
Сделайте ваш чат сетевым, то есть доработайте его так, чтобы два экземпляра программы могли отправлять и принимать сообщения между собой.
Используйте протокол UDP или TCP на свое усмотрение.
Можно использовать архитектуру клиент-сервер, в этом случае будут две программы — клиент и сервер.
Можно использовать децентрализованную (англ. peer-to-peer, P2P — равный к равному) сеть, в которой каждый узел является как клиентом, так и выполняет функции сервера.
Проект чата следует загрузить в свой репозиторий на GitHub. 

Программы cозданы и собраны с помощью Makefile,  chats -сервер и chatc-клиент со следующим функционалом:

консольные программы
Реализован сокет для обмена по протоколу TCP/IP в классе Socket (Socket.h, Socket.cpp).
запрос на регистрацию пользователей - логин, пароль, имя
проект загружен на github из linux
