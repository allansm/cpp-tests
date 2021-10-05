//#include <cpp-lib/parser.hpp>
//#include <cpp-lib/util.hpp>
#include <cpp-lib/output.hpp>
#include <cpp-lib/json.hpp>

Util util = Util();

int getFirst(string txt,char cha){
	for(int i = 0;i<txt.length();i++){
		if(txt.at(i) == cha){
			return i+1;
		}
	}

	return 0;
}

int getLast(string txt,char cha){
	int last = 0;

	for(int i = 0;i<txt.length();i++){
		if(txt.at(i) == cha){
			last = i-1;
		}
	}

	return last;
}

main(){
	//string tmp = util.exec("curl -s https://api.mangadex.org/manga?title="+util.input("title:"));

	string test = "{{{aaa}}}";
	string test2 = "";

	bool flag = false;
	bool flag2 = false;
	
	string inside = test.substr(getFirst(test,'{'),getLast(test,'}'));

	//bool flag3 = false;
	//bool flag4 = false;
	
	/*char buffer[255];
	int n = 0;
	/for(int i = 0;i<test.length();i++){
		if(test.at(i) == '}' && flag && !flag2){
			flag = false;
		}

		else if(test.at(i) == '}' && flag2){
			flag2 = false;
		}
		
		if(flag){
			buffer[n++] = test.at(i);
		}
		
		if(test.at(i) == '{' && !flag && !flag2){
			flag = true;
		}

		else if(test.at(i) == '{' && flag){
			flag2 = true;
		}

			
	}*/

	print(inside);
}
