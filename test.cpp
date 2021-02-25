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

void deleteDownloadedFile(){
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


void run(){
    const int WAIT_TIME = 1000*10;
    while(true){
        if(generate("next.txt") || canDownload()){
            Sleep(WAIT_TIME);
            deleteDownloadedFile();

            string link = getRandomLine("links.txt");
            string command = "youtube-dl.exe "+link+" -4";

            system(command.c_str());

            system("echo 1 > next.txt");
        }
    }
}

main(){
    run();
    //ls();
}
