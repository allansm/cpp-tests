#include <iostream>
#include <winsock2.h>

#pragma comment(lib,"ws2_32.lib")

int main(int argc , char *argv[]){
	WSADATA wsa;
	SOCKET s;
	struct sockaddr_in server;
	char *message , server_reply[2000];
	int recv_size;

	std::cout << "starting...\n";
	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0){
		return 1;
	}
	
	std::cout << "started\n";

	if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET){
		return 1;	
	}

	std::cout << "socket created\n";

	server.sin_addr.s_addr = inet_addr("142.250.218.36");
	server.sin_family = AF_INET;
	server.sin_port = htons(80);

	if (connect(s , (struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR){
		std::cout << "connection error\n";
		WSACleanup();
		return 1;
	}
	
	std::cout << "connected\n";

	message = "GET / HTTP/1.1\r\n\r\n";
	if( send(s , message , strlen(message) , 0) < 0){
		std::cout << "send error";
		return 1;
	}

	std::cout << "data send\n";
	
	if((recv_size = recv(s , server_reply , 2000 , 0)) == SOCKET_ERROR){
		std::cout << "recv error";
	}
	
	std::cout << "received\n";

	server_reply[recv_size] = '\0';
	std::cout << server_reply;
	
	closesocket(s);
	WSACleanup();
	
	return 0;
}
