#include "class/files.h"
#include "class/util.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

/*string find(string txt,string a,string b){
	
	string found = "";
	
	int d1 = txt.find(a);
	
	//if(d1 > 0){
	
		txt.erase(0,d1+a.length());
	
		found = txt.substr(0,txt.find(b));
	
	//}
	return found;
}
int delimiterCount(string txt,string a,string b){
	int i = 0;
	string prev = txt;
	string original = txt;
	while(txt != ""){
		//cout << txt << endl;
		string temp = find(txt,a,b);
		//cout << temp << endl << endl << endl;
		string erase = a+temp+b;
		//cout << erase << endl;
		txt.erase(0,txt.find(erase)+erase.length());
		if(original.find(erase) != -1){
			i++;
		}
		/*if(prev == txt){
			break;
		}else{
			prev = txt;
		}*/
	/*}
	return i;
}

string* findAll(string txt,string a,string b){
	int size = delimiterCount(txt,a,b);
	string* arr = new string[size];
	string prev = txt;
	string original = txt;
	int i=0;
	while(txt != ""){
		//cout << txt << endl;
		if(find(txt,a,b)!=-1){
			string temp = find(txt,a,b);
			//cout << temp << endl << endl << endl;
			string erase = a+temp+b;
			//cout << erase << endl;
			txt.erase(0,txt.find(erase)+erase.length());
			/*if(prev == txt){
				break;
			}else{
				prev = txt;
			}*//*
			if(original.find(erase) != -1){
				arr[i++] = erase;
			}
		}else{
			txt.erase(0,1);
		}
	}
	return arr;
}*/

string finalboss(string txt,string a){
	string found = "";
	string temp = "";
	for(int i=0;i<txt.length();i++){
		if(txt.at(i) == a.at(0)){
			try{
				temp = "";
				for(int ii=0;ii<a.length();ii++){
					if(txt.at(i+ii) == a.at(ii)){
						temp+= txt.at(i+ii);
						if(temp == a){
							cout << i << endl;
							found+=i+",";
						}
					}
				}
			}catch(const exception &e){
				break;
			}
		}
	}
	cout << found;
	return found;
}

/*test3(){
	string p = "test/cbrowser/dump.txt";
	string* lines = Files::getLines(p.c_str());
	int size = Files::countLines(p.c_str());//Util::sizeOf(lines);
	cout << size << endl;
	string merged = Util::mergeString(lines,size);
	
	//string t = Util::find(merged,"<div","</div>");
	
	//cout << t << endl;
	//cout << "found:" << test(merged,"href=\"","\"") << endl;
	string* arr = findAll(merged,"\"","\"");
	//size = delimiterCount(merged,"<a","</a>");
	int sz = Util::sizeOf(arr);
	cout << "size:" << size << "sz:" << sz << endl << endl;
	for(int i=0;i<sz;i++){
		//cout << find(arr[i],">","</a>") << endl << endl;
		cout << arr[i] << endl << endl;
	}
}*/
main(){
	//test("<a class=\"myclass\" href=\"http://localhost\"></a>","href=\"","\"");
	//removed2();
	//test3();
	
	cout << finalboss("<html><body><div><a>link</a></div><div></div></body></html>","<div>");
}
