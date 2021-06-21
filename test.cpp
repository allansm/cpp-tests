#include "class/io.h"

bool has(string line,string text){
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

string* explode(string line,string deli){
	string* exp = new string[n(line,deli)+1];
	int i = 0;
	while(has(line,deli)){
		string temp = line.substr(0,line.find(deli));
		line.erase(0,line.find(deli)+deli.length());

		exp[i++] = temp;
	}
	exp[i++] = line;
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

string replace(string txt,string oldtxt,string newtxt){
	while(has(txt,oldtxt)){
		txt = replaceFirst(txt,oldtxt,newtxt);
	}
	return txt;
}


main(){
	int test = 0;

	string* arr = new string[2];
	arr[0] = "a";
	arr[1] = "b";
	arr[2] = "c";
	
	do{
		try{
			string tmp = arr[50];
			print(tmp);
		}catch(const exception &e){
			break;
		}
	}while(true);

	println("catched error!!");

}
