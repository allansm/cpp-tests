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

main(){
	string test = "hello hello hello world hello world";
	string test2 = "world";
	cout << ocurrences(test,test2);
}
