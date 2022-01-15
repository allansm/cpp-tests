#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>

using namespace std;

string exec(string command) {
   char buffer[256];
   string result = "";

   // Open pipe to file
   FILE* pipe = popen(command.c_str(), "r");
   if (!pipe) {
      return "popen failed!";
   }

   // read till end of process:
   //while (!feof(pipe)) {
        while(fgets(buffer,256,pipe)){
            result += buffer;
        }
        /*char key = getKey();
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
        Sleep(1);*/
   //}

   pclose(pipe);
   return result;
}

main(){
    string ip;
    int limit;
    stringstream ss;
    stringstream ss2;
    cout << "set ip:";
    cin >> ip;
    cout << "set limit in celsius:";
    cin >> limit;
    cout << "ignore cpu? (y/n):";
    string r;
    cin >> r;
    bool ignorecpu = (r=="y")?true:false;
    ss << "adb -s " << ip << " shell cat sys/class/thermal/thermal_zone0/temp";
    ss2 << "adb -s " << ip << " shell cat sys/class/thermal/thermal_zone4/temp";
    bool usb = true;
    while(true){
        int battery;
        int cpu;
        stringstream h;
        h << exec(ss.str().c_str());
        h >> battery;

        stringstream h2;
        h2 << exec(ss2.str().c_str());
        h2 >> cpu;
        //int c;
        battery = battery / 1000;
        cpu = cpu / 1000;
        cout << " battery:" << battery << "c cpu:" << cpu << "c\n";
        if(ignorecpu){
            cpu = 0;
        }
        if(battery == limit || cpu == limit && usb){
            stringstream co;
            co << "adb -s " << ip << " shell dumpsys battery set usb 0";
            system(co.str().c_str());
            cout << "usb power disabled\n";
            usb = false;
        }else if(!usb){
            if(battery != limit && cpu != limit){
               stringstream co;
               co << "adb -s " << ip << " shell dumpsys battery set usb 1";
               system(co.str().c_str());
               cout << "usb power enabled\n";
               usb = true;
            }
        }
        if(battery > limit || cpu > limit){
            stringstream co;
            co << "adb -s " << ip << " shell ";
            co << "sendevent dev/input/event1 1 116 1 ; sendevent dev/input/event1 0 0 0 ;sendevent dev/input/event1 1 116 0 ;sendevent dev/input/event1 0 0 0 ";
            system(co.str().c_str());
            Sleep(60000*2);
        }
        //cout << "end;";
        Sleep(10000);
    }
}
