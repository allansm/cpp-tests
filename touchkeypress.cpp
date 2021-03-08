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
        //Sleep(10);
      // use buffer to read and add to result
      stringstream key;
      int k = getKey();
      key << k << "\n";
      //cout << key.str().c_str();
      fputs(key.str().c_str(),pipe);
      fflush(pipe);
      //Sleep(10);
      /*while(true){
        if(GetAsyncKeyState(k) != -32768){
            stringstream s;
            s << "r" << "\n";
            fputs(s.str().c_str(),pipe);
            fflush(pipe);
            Sleep(1);
            //cout << "send R\n";
            break;
        }
      }*/
   }

   pclose(pipe);
   return result;
}
int main(){
    stringstream command;
    command << "java -jar touchkeypress.jar";
    exec(command.str().c_str());
}
