#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <string>
#include <sys/time.h>
#include <sstream>
#include <ctime>
#include <fstream>
using namespace std;


class Time{
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
        int s = sec - ((m*60)+(h*60*60));
        ss << h << ":" << m << ":" << s;
        ss >> temp;
        return temp;
    }

    int getSec(){
        time_t now = time(0);
        tm *ltm = localtime(&now);
        return ltm->tm_sec;
    }

    public : static int getMin(){
        time_t now = time(0);
        tm *ltm = localtime(&now);
        return ltm->tm_min;
    }

    public : static int getHour(){
        time_t now = time(0);
        tm *ltm = localtime(&now);
        return ltm->tm_hour;
    }


    public : static int getDay(){
        time_t now = time(0);
        tm *ltm = localtime(&now);
        return ltm->tm_mday;
    }

    public : static int getMonth(){
        time_t now = time(0);
        tm *ltm = localtime(&now);

        int mon = ltm->tm_mon;

        // +1 fix unkno error!!
        mon+=1;
        return mon;
    }

    public : static int getYear(){
        time_t now = time(0);
        tm *ltm = localtime(&now);
        return 1900 + ltm->tm_year;
    }

    public : static string getDate(){
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

    /*string getFirstLine(const char* file){
        string line;
        ifstream temp(file);
        while (getline (temp,line)) {
            return line;
        }
        temp.close();
        return "";
    }*/

    /*int delimiterCount(string text,string delimiter){
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

    string toString(int number){
        stringstream ss;
        string st;
        ss << number;
        ss >> st;
        return st;
    }*/
};
