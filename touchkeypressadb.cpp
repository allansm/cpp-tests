#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include <sys/time.h>

using namespace std;

int i = 1;
int getKey(){
    while(true){
        if(GetAsyncKeyState(i) == -32768){
            //stringstream txt ;
            //cout << i << "\n";
            //txt << "echo " << i << " | " << "ncat " << ip << " " << port << " --send-only";
            int cp = i;
            i++;
            return cp;
        }
        i++;
        if(i > 90){
            i=1;
            Sleep(1);
        }
    }
}
void *thread(void *k){
    int c = *((int *) &k);
    char key = c;
    if(key == 'A'){
        cout << "a";
        system("adb.exe shell input swipe 240 480 100 480 50");
    }else if(key == 'D'){
        cout << "d";
        system("adb.exe shell input swipe 240 480 400 480 50");
    }else if(key == 'W'){
        cout << "w";
        system("adb.exe shell input tap 240 480");
    }
}
int main(){
    int totalthread = 0;
    system("adb connect 192.168.0.101");
    while(true){
        char key = getKey();
         //pthread_create(NULL, NULL, thread, (void *) key);
         //Sleep(250);
         //totalthread++;
         //cout << "\n" << totalthread <<"\n";

        if(key == 'A'){
            cout << "a";
            system("adb.exe -s 192.168.0.101 shell input swipe 240 480 100 480 100");
        }else if(key == 'D'){
            cout << "d";
            system("adb.exe -s 192.168.0.101 shell input swipe 240 480 400 480 100");
        }else if(key == 'W'){
            cout << "w";
            system("adb.exe -s 192.168.0.101 shell input tap 240 480");
        }
    }
}
