#include <iostream>
#include <winsock2.h>

main(){
	WSADATA wsa;
	char *hostname = "www.google.com";
	char ip[15];
	struct hostent *he;
	struct in_addr **addr_list;
	int i;

	WSAStartup(MAKEWORD(2,2),&wsa);	
	
	he = gethostbyname( hostname );
	addr_list = (struct in_addr **) he->h_addr_list;
	
	for(i = 0;addr_list[i] != NULL;i++){
		strcpy(ip, inet_ntoa(*addr_list[i]));
	}
	
	std::cout << hostname << " " << ip << "\n";	
}
