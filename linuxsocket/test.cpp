#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 

#include <iostream>

int main(int argc, char **argv){
	char recv[1024];   
	int sockfd = 0;
	int n = 0;

	struct sockaddr_in serv_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0); 

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(80); 

	inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
	connect(sockfd,(struct sockaddr *)&serv_addr, sizeof(serv_addr));

	while((n = read(sockfd, recv, sizeof(recv)-1)) > 0){
		recv[n] = 0;

		std::cout << recv;
	} 

	if(n < 0){
		std::cout << "error!!";
	} 

	return 0;
}
