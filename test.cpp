#include <cpp-lib/io.hpp>
#include <cpp-lib/json.hpp>

using namespace std;

string removeSpaces(string txt){
	int chain = 0;
	int chain2 = 0;
	int chain3 = 0;
	
	char buffer[99999];
	int  n = 0;
	for(int i=0;i<txt.length();i++){
		char cha = txt.at(i);
		
		if(cha == '{' || cha == '['){
			//chain++;
		}
		if(cha == '"' && chain2 ==0){
			chain2++;
		}else if(cha == '"' && chain2 > 0){
			chain2--;
		}

		if(cha == '\'' && chain3==0){
			chain3++;
		}else if(cha == '\'' && chain3 > 0){
			chain3--;
		}
		
		if(cha == '}' || cha == ']'){
			//chain--;
		}

		if(cha == ' ' && chain == 0 && chain2 == 0 && chain3 == 0){
			
		}else{
			buffer[n++]=cha;
		}
	}

	string str = buffer;

	return str;
}

main(){
	/*auto tmp = Json("{'a':[1,2,3]}").array<int>("a");

	print_r(tmp);

	print(tmp[0]+tmp[2]);*/

	auto test = Json("{'a' : 'b' , 'b' : 'hello world'}");
	
	println(removeSpaces(test.data));

	print_r(test.fields);
	println(test.obj["b"].data);
	
	println(unknown("hello world").get<string>());
}
