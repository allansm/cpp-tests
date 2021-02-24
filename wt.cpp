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

string sumTime(string elapsed1,string elapsed2){
    stringstream ss;

    int h1;
    int m1;
    int s1;

    ss << split(elapsed1,":",0);
    ss >> h1;
    ss.str("");

    ss << split(elapsed1,":",1);
    ss >> m1;
    ss.str("");

    ss << split(elapsed1,":",2);
    ss >> s1;
    ss.str("");

    int h2;
    int m2;
    int s2;

    ss << split(elapsed2,":",0);
    ss >> h2;
    ss.str("");

    ss << split(elapsed2,":",1);
    ss >> m2;
    ss.str("");

    ss << split(elapsed2,";",2);
    ss >> s2;
    ss.str("");

    cout << h1;
    cout << h2;

    string temp = "";

    /*int h = (h1+h2);
    int m = ((m1+m2) - (h1+h2)*60);
    int s = ((s1+s2) - (m1+m2)*60);
    ss << h << ":" << m << ":" << s;
    ss >> temp;
*/
    cout << temp;

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
    cout << persistentData << "\n";
    while(true){
        data = sumTime(wt(start),persistentData);
        //cout << filename << " " << data << "\n";
        //overrideFile(data,filename);
        //system("cls");
    }
}

main(){
    run();
    //string arr = split("5:7:20",":",1);
    //cout << arr;
    //test2();
    //test("test.txt");
}
