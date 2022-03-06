#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <iostream>

int main(){
	char receive[1024];   
	int sockfd = 0;
	int n = 0;

	struct sockaddr_in serv_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0); 

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(80); 

	inet_pton(AF_INET, "142.250.79.4", &serv_addr.sin_addr);
	
	if(connect(sockfd,(struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
		std::cout << "error!!";
		return 1;
	}
	
	std::string message = "GET / HTTP/1.1\r\n\r\n";
	if(send(sockfd, message.c_str(), strlen(message.c_str()), 0) < 0){
		std::cout << "error!!";
		return 1;
	}
	
	if(recv(sockfd, receive , 1024 , 0) < 0){
		std::cout << "error!!";
		return 1;
	}

	std::cout << receive;
}
