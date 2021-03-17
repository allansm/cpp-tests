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
	
	int d1 = code.find(a);
	int d2 = code.find(b);
	
	int d1e = d1+a.length();
	
	int d2e = d2 - d1e;
	//string temp = "<a>";
	
	string found = code.substr(d1e,d2e);
	
	//string found = Util::find(code,"<html>","</html>");
	cout << found << endl;
}
main(){
	string p = "test/cbrowser/dump.txt";
	string* lines = Files::getLines(p.c_str());
	int size = lines->size();//Util::sizeOf(lines);
	string merged = Util::mergeString(lines,10);
	cout << merged << endl;
}
