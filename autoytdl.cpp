#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <string>
#include <sstream>
#include <fstream>

#include <sys/time.h>
#include <windows.h>
#include <algorithm>
#include <cctype>

#include <pthread.h>

using namespace std;


void overrideFile(string data,string fileName){
    string command = "echo "+data+" > "+fileName;
    system(command.c_str());
}

void addLineToFile(string data,string fileName){
    string command = "echo "+data+" >> "+fileName;
    system(command.c_str());
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

string removeBlank(string txt){
    string text = txt;
    string delimiter = " ";
    text.replace(text.find(delimiter),text.find(delimiter)+delimiter.length(),"");

    return text;
}

void removeLine(const char* file,string line){
    ifstream temp(file);
    string text;
    int size = countLines(file);
    string lines[size];
    int count = 0;
    string txt = "";
    while (getline (temp, text)) {
      if(text != line){
        txt += text+"\n";
      }
    }
    remove(file);
    ofstream output(file);
    output.write(txt.c_str(),txt.length());
    output.close();
    temp.close();
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

bool fileExist(const char *fileName){
    ifstream infile(fileName);
    return infile.good();
}

string getParameters(){
	if(fileExist("parameters.txt")){
		return getFirstLine("parameters.txt")+" ";
	}
	return "";
}

void *thread(void *command){
    string c =  *(static_cast<std::string*>(command));
	
	cout << c << "\n";
	cout << "thread started";
	system(c.c_str());
}

void startThread(string command){
	pthread_create(NULL, NULL, thread,  static_cast<void*>(&command));
	cout << "starting thread\n";
}

void run(){
    const int WAIT_TIME = parseInt(getFirstLine("waitTime.txt"))*1000;
    while(true){
		try{
			if(generate("next.txt")){
				cout << "waiting..\n";
				//deleteDownloadedFile(WAIT_TIME);
				cout << "removing files\n";

				string link = getRandomLine("links.txt");
				removeLine("links.txt",link);
				cout << "remove link :" << link << "\n";

				string command = "youtube-dl.exe "+getParameters()+link;
				//cout << command << "\n";
				//system(command.c_str());
				system("taskkill /f /im you*");
				startThread(command);

				system("echo 1 > next.txt");
			}
			Sleep(1);
		}catch (const exception &exc){
			
		}
    }
}

main(){
    run();
}

