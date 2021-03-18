#include "class/files.h"
#include "class/util.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void removed(){
	string code = "<html><body><div><a><p></p></a></div></body></html>";
    string ts = "123abc1234123abcd1234123abcde1234";
    //cout << findAt(ts,"123","1234",2);
	string a = "<a href=\"http://www.google.com\">link</a>";
	string* all = Files::getLines("test/dump.txt");
	
	/*all[0] = a;
	all[1] = a;
	all[2] = a;
	all[3] = "<a href=\"http://www.github.com\">link</a>";
	all[4] = a;
	*/
	int size = Util::sizeOf(all);
	string test = Util::mergeString(all,size);
	//int c = Util::countDeliO(test,"href=\"","\"");
	//cout << c << "\n";
	//return 0;
	
	//cout << "reach this\n";
	
	string* test2 = Util::findAll(code,"<a","</a>");
	
	//cout << "reach this\n";
	
	size = Util::sizeOf(test2);//Util::sizeOf(test2);
	
	//cout << "reach this\n";
	cout << size << endl;
	
	cout << test2[0] << endl;
	
	for(int i = 0;i<size;i++){
		cout << test2[i] << "\n";
	}
	
	//string s = Util::find(test,"href=\"","\"");
	
	//cout << s << "\n";
	
	//system("pause");
	
	//return 0;
	/*try{
		int i = 0;
		while(true){
			cout << test2[i++] << "\n";
		}
	}catch(const exception &e){}
	
	cout << test ;
	
	system("pause");*/
	
}
string find(string txt,string a,string b){
	
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
	}
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
		string temp = find(txt,a,b);
		//cout << temp << endl << endl << endl;
		string erase = a+temp+b;
		//cout << erase << endl;
		txt.erase(0,txt.find(erase)+erase.length());
		/*if(prev == txt){
			break;
		}else{
			prev = txt;
		}*/
		if(original.find(erase) != -1){
			arr[i++] = erase;
		}
	}
	return arr;
}
void removed2(){
	string p = "test/cbrowser/dump.txt";
	string* lines = Files::getLines(p.c_str());
	int size = Files::countLines(p.c_str());//Util::sizeOf(lines);
	cout << size << endl;
	string merged = Util::mergeString(lines,size);
	/*string temp = merged;
	int t1 = "href=\"";
	int start = temp.find(t1);
	temp.erase(0,start+t1.length());
	int end = merged.find("")*/
	//cout << merged << endl;
	string* all = Util::findAll(merged,"<div>","</div>");
	
	int i =0;
	
	while(true){
		cout << all[i] << endl;
	}
	
	/*size = Util::countDeliO(merged,"<div>","</div>");
	cout << size << endl;
	for(int i=0;i<size;i++){
		cout << all[i] << endl;
	}*/
}

test3(){
	string p = "test/cbrowser/dump.txt";
	string* lines = Files::getLines(p.c_str());
	int size = Files::countLines(p.c_str());//Util::sizeOf(lines);
	cout << size << endl;
	string merged = Util::mergeString(lines,size);
	
	//string t = Util::find(merged,"<div","</div>");
	
	//cout << t << endl;
	//cout << "found:" << test(merged,"href=\"","\"") << endl;
	string* arr = findAll(merged,"<a","</a>");
	size = delimiterCount(merged,"<a","</a>");
	int sz = Util::sizeOf(arr);
	cout << "size:" << size << "sz:" << sz << endl << endl;
	for(int i=0;i<size;i++){
		cout << find(arr[i],">","</a>") << endl << endl;
	}
}
main(){
	//test("<a class=\"myclass\" href=\"http://localhost\"></a>","href=\"","\"");
	//removed2();
	test3();
}
