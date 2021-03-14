#include "class/files.h"
#include "class/util.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

main(){
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
	
	string test = Util::mergeString(all);
	//int c = Util::countDeliO(test,"href=\"","\"");
	//cout << c << "\n";
	//return 0;
	
	cout << "reach this\n";
	
	string* test2 = Util::findAll(test,"href=\"","\"");
	
	cout << "reach this\n";
	
	int size = test2->size();//Util::sizeOf(test2);
	
	cout << "reach this\n";
	
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
