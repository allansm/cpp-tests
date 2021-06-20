#include "class/io.h"

bool has(string line,string text){
	if(line.find(text) == -1){
		return false;
	}else{
		return true;
	}
}

int ocurrences(string line,string text){
	int count = 0;
	while(has(line,text)){
		line.erase(0,line.find(text)+text.length());
		count++;
	}

	return count;
}

string* explode(string line,string deli){
	string* exp = new string[ocurrences(line,deli)+1];
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

//why don't work?
int size(string* array){
	int i = 0;

	try{
		while(true){
			string tmp = array[i];
			i++;	
		}
	}catch(const exception e){return i;}

	return i;
}


main(){
	string test = "n1;n2;n3;n4;n5;n6";
	string test2 = ",";
	
	test = replace(test,";",",");

	string* array = explode(test,test2);

	print_r(array);
	print(size(array));
	print("\n");
}

