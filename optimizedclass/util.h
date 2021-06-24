#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Util{
	public:
		Util();
		string replace(string txt,string oldtxt,string newtxt);
		vector<string> explode(string line,string deli);
		bool has(string line,string text);
};


Util::Util(){

}


bool has(string line,string text){
	if(line.find(text) == -1){
		return false;
	}else{
		return true;
	}
}
bool Util::has(string line,string text){
	if(line.find(text) == -1){
		return false;
	}else{
		return true;
	}
}

int n(string line,string text){
	int count = 0;
	while(has(line,text)){
		line.erase(0,line.find(text)+text.length());
		count++;
	}

	return count;
}

vector<string> Util::explode(string line,string deli){
	vector<string> exp;
	while(has(line,deli)){
		string temp = line.substr(0,line.find(deli));
		line.erase(0,line.find(deli)+deli.length());

		exp.push_back(temp);
	}
	
	exp.push_back(line);

	return exp;
}

void print_r(string* array){
	int i = 0;
	while(true){
		try{
			string tmp = array[i++]; 
			cout << i-1 << " => " << tmp << "\n";
		}catch(const exception e){
			break;
		}
	}
}

void print_r(vector<string> array){
	int i = 0;
	for(string tmp : array){
		cout << i << " => " << tmp << "\n";
		i++;
	}
}

void print(string txt){
	cout << txt;
}

void print(int val){
	cout << val;
}

void print(float val){
	cout << val;
}

void print(double val){
	cout << val;
}

void println(string txt){
	cout << txt << endl;
}

void println(int val){
	cout << val << endl;
}

void println(float val){
	cout << val << endl;
}

void println(double val){
	cout << val << endl;
}

string replaceFirst(string txt,string oldtxt,string newtxt){
        int start = txt.find(oldtxt);
        int end = oldtxt.length();
        return txt.replace(start,end,newtxt);
}

string Util::replace(string txt,string oldtxt,string newtxt){
	while(has(txt,oldtxt)){
		txt = replaceFirst(txt,oldtxt,newtxt);
	}
	return txt;
}
