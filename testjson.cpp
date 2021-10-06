//#include <cpp-lib/parser.hpp>
//#include <cpp-lib/util.hpp>
#include <cpp-lib/output.hpp>
#include <cpp-lib/json.hpp>
#include <cpp-lib/files.hpp>

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

string getInside(string txt,char cha,char cha2){
	return txt.substr(getFirst(txt,cha),getLast(txt,cha2));	
}

string getParam(string txt){
	char buff[255];
	int n = 0;
	for(int i = 0;i<txt.length();i++){
		if(txt.at(i) == ':'){
			break;
		}

		buff[n++] = txt.at(i);
	}

	string s = buff;

	memset(buff,'\0',255);

	return s;
}

string getVal(string txt){
	char buff[255];
	int n = 0;
	bool flag = false;
	for(int i = 0;i<txt.length();i++){
		if(txt.at(i) == ','){
			break;
		}

		if(flag){
			buff[n++] = txt.at(i);
		}
		
		if(txt.at(i) == ':'){
			flag = true;
		}	
	}

	string s = buff;

	memset(buff,'\0',255);

	return s;	
}

Array<undefined> test(string txt){
	vector<string> fields;
	vector<string> values;
	char buff[255];
	
	int n = 0;

	char target = ':';
	int chain = 0;

	for(int i = 0;i<txt.length();i++){
		if(txt.at(i) == '[' || txt.at(i) == '{'){
			chain++;
		}
		
		if(txt.at(i) == ']' || txt.at(i) == '}'){
			chain--;
		}

		if(txt.at(i) == target && chain == 0){
			if(target == ':'){
				target = ',';
				string s = buff;
				fields.push_back(s);
			}else{
				target = ':';
				string s = buff;
				values.push_back(s);
			}

			//println(buff);
			memset(buff,'\0',255);
			n=0;
		}else{
			buff[n++] = txt.at(i);
		}
	}

	string s = buff;
	values.push_back(s);

	memset(buff,'\0',255);	
	
	int i = 0;
	Array<undefined> arr;
	for(string f : fields){
		arr[f] = unknown(values[i++]);
	}
	
	/*for(string f : fields){
		println(arr[f].data);
	}*/	

	return arr;
	
}

main(){
	//string tmp = util.exec("curl -s https://api.mangadex.org/manga?title="+util.input("title:"));
	
	string son = "{'a':'b','c':'d','e':[{'msg':'hello',['1','2']},{'a':['3','4']}],'f':[],'g':{'h':'i'}}";
	string inside = getInside(son,'{','}');

	//son = util.replace(inside,":",":\n\n");
	Json t = Json(Files().readFile("../test.json"));

	println(t.get<string>("user","username"));	
	//println(Json(inside).get<string>("'a'"));

	//println(test(inside)["'f'"].data);

	//string inside = getInside(test,'{','}');

	//println(getParam(inside));

	//println(getVal(inside));

	/*tmp = util.replace(tmp,"\t","");
	tmp = util.replace(tmp,"\n","");

	tmp = util.replace(tmp,"],","]\n\n");
	tmp = util.replace(tmp,"},","}\n\n");
	println(tmp);*/

	//string test = "{'a':{'b':'c'}}";
	//string inside = getInside(test,'{','}');
	//println(getInside(inside,'{','}'));

	/*println(test);

	string test2 = "";

	bool flag = false;
	bool flag2 = false;
	
	string inside = getInside(test,'{','}');

	println(inside);

	inside = getInside(inside,'{','}');

	println(inside);

	inside = getInside(inside,'{','}');

	println(inside);*/
 
}
