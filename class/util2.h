#include "class/io.h"
#include <vector>

class Util2{
	public:
		Util2();
		string replace(string txt,string oldtxt,string newtxt);
		vector<string> explode(string line,string deli);
		bool has(string line,string text);
};


Util2::Util2(){

}


bool Util2::has(string line,string text){
	if(line.find(text) == -1){
		return false;
	}else{
		return true;
	}
}

int Util2::n(string line,string text){
	int count = 0;
	while(has(line,text)){
		line.erase(0,line.find(text)+text.length());
		count++;
	}

	return count;
}

vector<string> Util2::explode(string line,string deli){
	vector<string> exp;
	while(has(line,deli)){
		string temp = line.substr(0,line.find(deli));
		line.erase(0,line.find(deli)+deli.length());

		exp.push_back(temp);
	}
	
	exp.push_back(line);

	return exp;
}

void Util2::print_r(string* array){
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

void Util2::print_r(vector<string> array){
	int i = 0;
	for(string tmp : array){
		cout << i << " => " << tmp << "\n";
		i++;
	}
}

void Util2::print(string txt){
	cout << txt;
}

void Util2::print(int val){
	cout << val;
}

void Util2::print(float val){
	cout << val;
}

void Util2::print(double val){
	cout << val;
}

void Util2::println(string txt){
	cout << txt << endl;
}

void Util2::println(int val){
	cout << val << endl;
}

void Util2::println(float val){
	cout << val << endl;
}

void Util2::println(double val){
	cout << val << endl;
}

string replaceFirst(string txt,string oldtxt,string newtxt){
        int start = txt.find(oldtxt);
        int end = oldtxt.length();
        return txt.replace(start,end,newtxt);
}

string Util2::replace(string txt,string oldtxt,string newtxt){
	while(has(txt,oldtxt)){
		txt = replaceFirst(txt,oldtxt,newtxt);
	}
	return txt;
}
