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

string getFirstLine(const char* file){
    string line;
    ifstream temp(file);
    //int i = 0;
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
        //cout << temp;
        lastSize = text.length();
        text.erase(0,text.find(delimiter)+delimiter.length());
        count++;
    }
    return count;
}
string * split(string text, string delimiter){
    //std::string s = "scott>=tiger";
    //std::string delimiter = ">=";
    //std::string token = s.substr(0, s.find(delimiter)); // token is "scott"
    //s.erase(0, pos + delimiter.length());
    //string[] words;
    //int size;
    int lastSize = 0;
    int size = delimiterCount(text,delimiter);
    string splited[size];
    int i = 0;
    while(lastSize != text.length()){
        string temp = text.substr(0, text.find(delimiter));
        //cout << temp;
        lastSize = text.length();
        splited[i++] = temp;
        text.erase(0,text.find(delimiter)+delimiter.length());
    }
    cout << splited[0] << splited[1] << splited[2];
    return splited;
}

void overrideFile(string data,string fileName){
    string command = "echo "+data+" > "+fileName;
    system(command.c_str());
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

void run(){
    long int start = currentTimeToMs();
    string filename = getDate("");
    string data;
    while(true){
        data = wt(start);
        //cout << filename << " " << data << "\n";
        overrideFile(data,filename);
        //system("cls");
    }
}

main(){
    //run();
    string arr = split("0:1:2",":")[0];
    cout << arr;
    //test2();
    //test("test.txt");
}
