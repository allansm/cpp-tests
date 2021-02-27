#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <string>
#include <sstream>
#include <fstream>

#include <sys/time.h>
#include <windows.h>

using namespace std;


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

string getRandomLine(const char* file){
    ifstream temp(file);
    string text;
    int size = countLines(file);
    string lines[size];
    int count = 0;

    while (getline (temp, text)) {
      lines[count++] = text;
    }

    temp.close();

    srand (time(NULL));

    int iSecret;

    iSecret = rand() % size + 0;

    return lines[iSecret];
}

string getFirstLine(const char* file){
    string line;
    ifstream temp(file);
    while (getline (temp,line)) {
        return line;
    }
    temp.close();
    return "";
}

void overrideFile(string data,string fileName){
    string command = "echo "+data+" > "+fileName;
    system(command.c_str());
}

bool generate(const char* file){
    if(getFirstLine(file) == "0"){
        return true;
    }else{
        return false;
    }
}

void deleteDownloadedFile(int waittime){
   Sleep(waittime);
   system("dir /B *.mp4 > mp4file.txt");
   string file = getFirstLine("mp4file.txt");
   if(file != "" && file != "Arquivo não encontrado"){
       remove(file.c_str());
   }
}

bool canDownload(){
    system("dir /B *.mp4 > mp4file.txt");
   string file = getFirstLine("mp4file.txt");
   if(file != "" && file != "Arquivo não encontrado"){
       return true;
   }
   return false;
}


int parseInt(string number){
    stringstream ss;
    int n = 0;
    ss.str(number);
    ss >> n;
    return n;
}

void hide(){
    HWND wnd;
    AllocConsole();
    wnd = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(wnd,0);
}

void run(){
    hide();
    Sleep(100);
    const int WAIT_TIME = parseInt(getFirstLine("waitTime.txt"))*1000;
    while(true){
        if(generate("next.txt")){
            //Sleep(WAIT_TIME);
            cout << "waiting..\n";
            deleteDownloadedFile(WAIT_TIME);
            cout << "removing files\n";

            string link = getRandomLine("links.txt");
            string command = "youtube-dl.exe "+link+" -4";

            system(command.c_str());

            system("echo 1 > next.txt");
        }
         Sleep(1);
    }
}

main(){
    run();
    //ls();
}
