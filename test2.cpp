#include "class/files.h"
#include "class/util.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>


/*string replace(string txt,string toReplace,string newTxt){
    int start = txt.find(toReplace);
    int end = toReplace.length();
    return txt.replace(start,end,newTxt);
}

void findAll(string txt,string deli1, string deli2){
    while(txt != ""){
        string found = Util::test(txt,deli1,deli2);
        cout << found << "\n";
        string complete = deli1+found+deli2;
        int start = txt.find(complete);
        int end = start+complete.length();
        txt.replace(start,end,"");
    }
}

int countDeliO(string txt,string deli1, string deli2){
    int i=0;
    while(txt != ""){
        string found = Util::test(txt,deli1,deli2);
        //cout << found << "\n";
        i++;
        string complete = deli1+found+deli2;
        int start = txt.find(complete);
        int end = start+complete.length();
        txt.replace(start,end,"");
    }
    return i;
}

string findAt(string txt,string deli1, string deli2,int i){
    int size = countDeliO(txt,deli1,deli2);
    string temp[size];
    int ind =0;
    while(txt != ""){
        string found = Util::test(txt,deli1,deli2);
        //cout << found << "\n";
        temp[ind++] = found;
        string complete = deli1+found+deli2;
        int start = txt.find(complete);
        int end = start+complete.length();
        txt.replace(start,end,"");
    }
    return temp[i];
}*/

main(){
    string ts = "123abc1234123abcd1234123abcde1234";
    //cout << findAt(ts,"123","1234",2);
	
	//string* test = Files::getLines("test.txt");
	
	string test2 = "a;b;c;d;e;f;g;h;i;j;k";
	
	//string* test = Util::split(test2,";");
	
	string* test = Util::findAll(ts,"123","1234");
	
	try{
		int i = 0;
		while(true){
			cout << test[i++] << "\n";
		}
	}catch(const exception &e){}
}
