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
void test(string txt,string a,string b){
	string code = "<html><body><div><a><p></p></a></div></body></html>";
	code = "<a class=\"myclass\" href=\"http://localhost\"></a>";
	string found = "";
	//txt = code;
	//cout << txt << endl;
	int d1 = txt.find(a);
	//cout << "d1:"<< d1 << endl;
	txt.erase(0,d1+a.length());
	//cout << txt << endl;
	int d2 = d1+a.length()+txt.find(b);
	//cout << "d2:"<< d2 << endl;
	int d1e = d1+a.length();
	
	int d2e = d2 - d1e;
	//string temp = "<a>";
	
	found = code.substr(d1e,d2e);
	
	//string found = Util::find(code,"<html>","</html>");
	cout << found << endl;
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
	
	string t = Util::find(merged,"<div","</div>");
	
	cout << t << endl;
}
main(){
	//test("<a class=\"myclass\" href=\"http://localhost\"></a>","href=\"","\"");
	//removed2();
	test3();
}
