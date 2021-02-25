#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <string>
#include <sys/time.h>
#include <sstream>
#include <ctime>
#include <fstream>

using namespace std;

long int currentTimeToMs(){
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    return ms;
}

long int elapsedTime(long int start){
    return currentTimeToMs() - start;
}

int toSec(long int ms){
    return ms /1000;
}

int toMinute(int sec){
    return sec/60;
}

int toHour(int minute){
    return minute/60;
}

string elapsedTime(int sec){
    string temp;
    stringstream ss;
    int h = toHour(toMinute(sec));
    int m = toMinute(sec) - (h*60);
    int s = sec - (m*60);
    ss << h << ":" << m << ":" << s;
    ss >> temp;
    return temp;
}


int getDay(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return ltm->tm_mday;
}

int getMonth(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return ltm->tm_mon;
}

int getYear(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return 1900 + ltm->tm_year;
}

string getDate(){
    string temp;
    stringstream ss;
    ss << getDay() << "/" << getMonth() <<"/" << getYear();
    ss >> temp;
    return temp;
}
string getDate(string sep){
    string temp;
    stringstream ss;
    ss << getDay() << sep << getMonth() << sep << getYear();
    ss >> temp;
    return temp;
}

string wt(long int start){
    return elapsedTime(toSec(elapsedTime(start)));
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

int delimiterCount(string text,string delimiter){
    int lastSize = 0;
    int count = 0;
    while(lastSize != text.length()){
        string temp = text.substr(0, text.find(delimiter));
        lastSize = text.length();
        text.erase(0,text.find(delimiter)+delimiter.length());
        count++;
    }
    return count;
}
string split(string text, string delimiter,int index){
    int lastSize = 0;
    int size = delimiterCount(text,delimiter);
    string splited[size];
    int i = 0;
    while(lastSize != text.length()){
        string temp = text.substr(0, text.find(delimiter));
        lastSize = text.length();
        splited[i++] = temp;
        text.erase(0,text.find(delimiter)+delimiter.length());
    }
    return splited[index];
}

int parseInt(string number){
    stringstream ss;
    int n = 0;
    ss.str(number);
    ss >> n;
    return n;
}

string sumTime(string elapsed1,string elapsed2){
    stringstream ss;

    int h1 = parseInt(split(elapsed1,":",0));
    int m1 = parseInt(split(elapsed1,":",1));
    int s1 = parseInt(split(elapsed1,":",2));


    int h2 = parseInt(split(elapsed2,":",0));
    int m2 = parseInt(split(elapsed2,":",1));
    int s2 = parseInt(split(elapsed2,":",2));

    string temp;

    int s = s1+s2;
    int m = toMinute(s);
    int h = toHour(toMinute(s));

    h = h+h1+h2;
    m = m+m1+m2;

    m = m - (h*60);
    s = s - (m*60);

    ss << h << ":" << m << ":" << s;
    ss >> temp;

    return temp;
}



void overrideFile(string data,string fileName){
    string command = "echo "+data+" > "+fileName;
    system(command.c_str());
}


void run(){
    long int start = currentTimeToMs();
    string filename = getDate("");
    string data;
    string persistentData = getFirstLine(filename.c_str());
    if(persistentData == ""){
        persistentData = "0:0:0";
    }
    while(true){
        data = sumTime(wt(start),persistentData);
        cout << data << "\n";
        overrideFile(data,filename);
        system("cls");
    }
}

main(){
    run();
}
