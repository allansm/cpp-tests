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
	public:
		long int currentTimeToMs();
		long int elapsedTime(long int start);
		int toSec(long int ms);
		int toMinute(int sec);
		int toHour(int minute);
		string elapsedTime(int sec);

};

long int Time::currentTimeToMs(){
	struct timeval tp;
	gettimeofday(&tp, NULL);
	long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return ms;
}

long int Time::elapsedTime(long int start){
	return currentTimeToMs() - start;
}

int Time::toSec(long int ms){
	return ms /1000;
}

int Time::toMinute(int sec){
	return sec/60;
}

int Time::toHour(int minute){
	return minute/60;
}

string Time::elapsedTime(int sec){
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

int getMin(){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	return ltm->tm_min;
}

int getHour(){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	return ltm->tm_hour;
}


int getDay(){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	return ltm->tm_mday;
}

int getMonth(){
	time_t now = time(0);
	tm *ltm = localtime(&now);

	int mon = ltm->tm_mon;

	// +1 fix unkno error!!
	mon+=1;
	return mon;
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

string getCurrent(){
	string temp;
	stringstream ss;
	ss <<  getDate() << "," << getHour() << ":" << getMin();
	ss >> temp;
	return temp;
}

