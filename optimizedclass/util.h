#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <sys/time.h>

using namespace std;

class Util{
	public:
		Util();
		
		string replace(string txt,string oldtxt,string newtxt);
		vector<string> explode(string line,string deli);
		bool has(string line,string text);
		
		void print_r(vector<string> array);
		void print_r(string* array);
		
		void print(string txt);
		void print(int txt);
		void print(float txt);
		void print(double txt);

		void println(string txt);
		void println(int txt);
		void println(float txt);
		void println(double txt);

		string input(string message);
		string getRandomValue(vector<string> list);

		string exec(string command);
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

void Util::print_r(string* array){
	int i = 0;
	while(true){
		try{
			string tmp = array[i++]; 
			cout << "[" << i-1 << "] => " << tmp << "\n";
		}catch(const exception e){
			break;
		}
	}
}

void Util::print_r(vector<string> array){
	int i = 0;
	for(string tmp : array){
		cout << "[" << i << "] => " << tmp << "\n";
		i++;
	}
}

void Util::print(string txt){
	cout << txt;
}

void Util::print(int val){
	cout << val;
}

void Util::print(float val){
	cout << val;
}

void Util::print(double val){
	cout << val;
}

void Util::println(string txt){
	cout << txt << endl;
}

void Util::println(int val){
	cout << val << endl;
}

void Util::println(float val){
	cout << val << endl;
}

void Util::println(double val){
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

string Util::input(string message){
	string user_input;
	cout << message;
	getline(cin,user_input);

	return user_input;
}

int arraySize(vector<string> arr){
	int i = 0;
	
	for(string value : arr){
		i++;
	}

	return i;
}

string Util::getRandomValue(vector<string> arr){
	srand (time(NULL));

	int iSecret;

        iSecret = rand() % arraySize(arr) + 0;

        return arr[iSecret];
}

string Util::exec(string command){
	FILE* pipe = popen(command.c_str(),"r");
	char buffer[256];
	string result = "";
	while(fgets(buffer,256,pipe)){
		result+=buffer;		
	}
	pclose(pipe);

	return result;
}
