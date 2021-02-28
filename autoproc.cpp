#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <string>
#include <sstream>
#include <fstream>

#include <sys/time.h>
#include <windows.h>

using namespace std;

string getFirstLine(const char* file){
    string line;
    ifstream temp(file);
    while (getline (temp,line)) {
        return line;
    }
    temp.close();
    return "";
}

bool generate(const char* file){
    if(getFirstLine(file) == "0"){
        return true;
    }else{
        return false;
    }
}

int countLines(const char* file){
    string text;
    ifstream temp(file);
    int i = 0;
    while (getline (temp, text)) {
      i++;
    }
    temp.close();
    return i;
}

void tProc(const char* file,string command,int t){
    ifstream temp(file);
    string text;
    int size = countLines(file);
    string lines[size];
    int count = 0;

    while (getline (temp, text)) {
      lines[count++] = text;
    }
    temp.close();

    for(int i=0;i<size;i++){
        string cmd = command+lines[i];
        system(cmd.c_str());
        Sleep(t);
    }
}

void run(){
     while(true){
        if(generate("error.txt")){
            tProc("cProc.txt","taskkill /f /im ",1);
            Sleep(100);
            tProc("sProc.txt","start /B ",1000);
            system("echo 1 > error.txt");
        }
        Sleep(1000);
    }
}

main(){
    run();
}
