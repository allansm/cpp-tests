#include "class/io.h"
#include "class/files.h"

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

void deleteBy(string extension){
    string command = "dir /B "+extension+" > filesToDelete.txt";
    system(command.c_str());

    ifstream temp("filesToDelete.txt");
    string text;
    int size = countLines("filesToDelete.txt");
    string lines[size];
    int count = 0;

    while (getline (temp, text)) {
      lines[count++] = text;
    }
    temp.close();

    for(int i=0;i<size;i++){
        cout << "deleting : "+lines[i]+"\n";
        remove(lines[i].c_str());
    }

}


void autodel(const char* file){
	string ext = Files::getFirstLine(file);
	deleteBy(ext);
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

bool generate(const char* file){
    if(getFirstLine(file).at(0) == '0'){
        return true;
    }else{
        return false;
    }
}

void hide(){
    HWND wnd;
    AllocConsole();
    wnd = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(wnd,0);
}

void run(){
    while(true){
        if(generate("canDelete.txt")){
            autodel("autodel.txt");
            system("echo 1 > canDelete.txt");
        }
        Sleep(1);
    }
}

main(){
    run();
}
