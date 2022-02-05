#include <iostream>
#include <winsock2.h>

int main(int argc , char *argv[]){
	WSADATA wsa;
	SOCKET s , new_socket;
	struct sockaddr_in server , client;
	int c;
	std::string message;

	WSAStartup(MAKEWORD(2,2),&wsa);	
	s = socket(AF_INET,SOCK_STREAM,0);	
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(54321);
	
	bind(s,(struct sockaddr *)&server,sizeof(server));	
	
	listen(s,3);	
	
	c = sizeof(struct sockaddr_in);
	
	std::cout << "waiting...\n";
	new_socket = accept(s,(struct sockaddr *)&client,&c);
	
	std::cout << "sending..\n";
	
	message = "helloworld\n";
	send(new_socket,message.c_str(),strlen(message.c_str()),0);
	
	getchar();
	closesocket(s);
	WSACleanup();
	
	return 0;
}
