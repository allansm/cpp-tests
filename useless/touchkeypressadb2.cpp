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
int event;
/*int getKey(){

    while(true){
        if(GetAsyncKeyState(i) == -32768){
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
}*/
int getKey(){
	int buttonpressed = 0;
	while (!buttonpressed){
	    //Sleep(10);
		for (int i = 0; i < 255; i++){
            //Sleep(10);
			if (GetKeyState(i) < 0){buttonpressed = i;}
		}
	}
	//while (GetKeyState(buttonpressed) < 0){;}
	return buttonpressed;
}
string inputPos(int x,int y){
    stringstream ss;
    ss << "sendevent /dev/input/event"<< event <<" 1 330 1;";
    ss << "sendevent /dev/input/event"<< event <<" 3 48 1;";
    ss << "sendevent /dev/input/event"<< event <<" 3 53 "<< x <<";";
    ss << "sendevent /dev/input/event"<< event <<" 3 54 "<<y <<"\n";
    return ss.str();
}
string inputTap(){
    stringstream ss;
    ss << "sendevent /dev/input/event"<< event <<" 0 2 0;";
    ss << "sendevent /dev/input/event"<< event <<" 0 0 0\n";
    return ss.str();
}
void adbSendEvent(int sx,int sy,int ex,int ey,bool hold,char key,FILE* pipe){
    stringstream ss;
    ss << inputPos(sx,sy) << inputTap() << inputPos(ex,ey) << inputTap();
    //cout << key;
    fputs(ss.str().c_str(),pipe);
    fflush(pipe);
    if(hold){
        while (GetKeyState((int)key) < 0){;}
    }
    fputs(inputTap().c_str(),pipe);
    fflush(pipe);
}
void adbSendEvent(int x,int y,bool hold,char key,FILE* pipe){
    stringstream ss;
    ss << inputPos(x,y) << inputTap();
    //cout << key;
    fputs(ss.str().c_str(),pipe);
    fflush(pipe);
    if(hold){
        while (GetKeyState((int)key) < 0){;}
    }
    fputs(inputTap().c_str(),pipe);
    fflush(pipe);
}
string exec(string command) {
   char buffer[256];
   string result = "";

   // Open pipe to file
   FILE* pipe = popen(command.c_str(), "w");
   if (!pipe) {
      return "popen failed!";
   }

   // read till end of process:
   while (!feof(pipe)) {
        char key = getKey();
        stringstream ss;
        if(key == 'A'){
            adbSendEvent(10,480,true,key,pipe);
        }else if(key == 'D'){
            adbSendEvent(480,480,true,key,pipe);
        }else if(key == 'W'){
            adbSendEvent(240,480,true,key,pipe);
        }else if(key == 'E'){
            adbSendEvent(300,480,300,600,true,key,pipe);
        }
        else if(key == 'S'){
            adbSendEvent(240,800,true,key,pipe);
        }
        else if(key == 'X'){
           while(true){
                cout << "paused.\n";
                cout << "type yes to return:";
                string asw;
                cin >> asw;
                if(asw == "yes"){
                    cout << "returning";
                    break;
                }
           }
        }
        Sleep(1);
   }

   pclose(pipe);
   return result;
}
int main(){
    stringstream command;
    string ip;
    cout << "set ip:";
    cin >> ip;
    cout << "set event n:";
    cin >> event;
    command << "adb -s " << ip <<" shell";
    exec(command.str().c_str());
}
