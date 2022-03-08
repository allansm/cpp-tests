#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

main(){
	int socket_desc;
	int sock;
	int size;

	struct sockaddr_in server , client;
	
	char receive[1024];
	char tosend[11] = "helloworld";
	
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(54321);
	
	bind(socket_desc,(struct sockaddr *)&server , sizeof(server));
	listen(socket_desc , 3);
	
	std::cout << "waiting...\n";
	size = sizeof(struct sockaddr_in);
	while((sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&size))){
		recv(sock, receive , 1024 , 0);
		std::cout << receive << "\n";
		send(sock, tosend, 11, 0);
	}
}
