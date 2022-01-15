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
//#include <thread>

using namespace std;
class KeyBot
{
private:
    INPUT _buffer[1];

public:
    KeyBot();
    void KeyUp( char key );
    void KeyDown( char key );
    void KeyClick( char key );
};

KeyBot::KeyBot()
{
    _buffer->type = INPUT_KEYBOARD;
    _buffer->ki.wScan = 0;
    _buffer->ki.time = 0;
    _buffer->ki.dwExtraInfo = 0;
}

void KeyBot::KeyUp( char key )
{
    _buffer->ki.wVk = key;
    _buffer->ki.dwFlags = /*KEYEVENTF_UNICODE |*/ KEYEVENTF_KEYUP;
    SendInput( 1, _buffer, sizeof( INPUT ) );
}

void KeyBot::KeyDown( char key )
{
    _buffer->ki.wVk = key;
    _buffer->ki.dwFlags = 0;
    SendInput( 1, _buffer, sizeof( INPUT ) );
}

void KeyBot::KeyClick( char key )
{
    KeyDown( key );
    Sleep( 10 );
    KeyUp( key );
}
bool keyInUse[90];
int st = 50;
void *releaseAll(void *arg){
    int i = 1;
    KeyBot bot;
    while(true){

        if(keyInUse[i]){
            bot.KeyUp(i);
            keyInUse[i] = false;
            st = 50;
        }
        i++;
        //Sleep(1);
        if(i > 90){
            i=1;
            if(st < 150){
                st++;
            }
            Sleep(st);
        }
    }
}
long int timeToMil(){
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    return ms;
}
int prev = 0;
int start = 0;
int k;
int ms =1;
int num = 0;
void *pipeHandle(void *arg){
    char buffer[256];
    string result = "";
     FILE* pipe = *((FILE* *) &arg);
     //int k;
     int mms = ms;
     ms+=10;
     int n = num++;
     KeyBot bot;
    while (!feof(pipe)) {
       //Sleep(mms);
      // use buffer to read and add to result
      cout << "running fgets\n";
      if (fgets(buffer, 3, pipe) != NULL){
            result = buffer;
            //cout << "result:" << result;
            stringstream key;
            key << result;
            key >> k;

            //cout << "thread:" << n << " ms:" <<(timeToMil()-start) << "\n";
            /*if(k != prev){
                bot.KeyUp(prev);
                prev = k;
                cout << k << "\n";
            }*/
            cout << "thread:" << n << " key:" << k << "\n";
            if(!keyInUse[k]){
                bot.KeyDown(k);
                keyInUse[k] = true;
            }
            prev = k;
            //start = timeToMil();
            //Sleep(1);
         //pthread_create(NULL, NULL, thread, (void *) k);
      }
    }
}
void HideConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}
void *thread(void *k){
    //Sleep(1);
    cout << "thread start\n";
    int c = *((int *) &k);
    cout << "storage int\n";
    cout << c << "\n";
    KeyBot bot;
    cout << "created bot\n";
    bot.KeyDown(c);
    cout << "keydown\n";
    Sleep(10);
    //cout << "sleep\n";
    bot.KeyUp(c);
    //cout << "keyup\n";
    //for(int i=0;i<10;i++){
        //Sleep(1000*60*60*24);
        //cout << "hahaha";
    //}
    //pthread_exit(NULL);
    //return NULL;
}


string exec(string command) {
   char buffer[256];
   string result = "";

   // Open pipe to file
   FILE* pipe = popen(command.c_str(), "r");
   if (!pipe) {
      return "popen failed!";
   }
   pthread_create(NULL, NULL, pipeHandle, (void *) pipe);
   pthread_create(NULL, NULL, pipeHandle, (void *) pipe);
   pthread_create(NULL, NULL, pipeHandle, (void *) pipe);
   pthread_create(NULL, NULL, pipeHandle, (void *) pipe);
   pthread_create(NULL, NULL, pipeHandle, (void *) pipe);
   pthread_create(NULL, NULL, pipeHandle, (void *) pipe);
   while(true){
    Sleep(60000*60*24);
   }
   pclose(pipe);
   return result;
}



void *openPort(void *p){

    int port = *((int *) &p);
    stringstream command;
    command << "ncat -l " << port;
    //cout << command.str() << "\n";
    while(true){
        cout << "waiting " << port << "\n";
        stringstream key;
        key << exec(command.str());

        int k;
        key >> k;
        KeyBot bot;
        cout << "ms:" <<(timeToMil()-start) << "\n";
        if(k != prev || (timeToMil()-start) > 10){
                bot.KeyUp(prev);
                prev = k;
        }
        start = timeToMil();
        pthread_create(NULL, NULL, thread, (void *) k);
        //start = timeToMil();
    }
    cout << "exiting\n";
    return 0;
}

int main(){
    pthread_create(NULL, NULL, releaseAll,NULL);
    exec("ncat -l 7171");
    system("pause");
}
