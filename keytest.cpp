#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0500


#include <windows.h>

#include "class/keybot.h"

main(){
	KeyBot k;
	char c = 'c';
	while(true){
	k.KeyClick((int)c);	
	}	
}
