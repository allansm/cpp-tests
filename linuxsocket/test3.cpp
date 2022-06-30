#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <iostream>

main(){
	char ip[15];
	std::string host = "www.google.com";
	
	struct hostent *he;
	struct in_addr **addr_list;

	he = gethostbyname(host.c_str());
	addr_list = (struct in_addr **) he->h_addr_list;
	
	for(int i = 0;addr_list[i] != NULL;i++){
		strcpy(ip , inet_ntoa(*addr_list[i]));
	}

	std::cout << ip << "\n";
}
