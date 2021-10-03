#include <cpp-lib/output.hpp>
#include <cpp-lib/parser.hpp>
#include <cpp-lib/array.hpp>
#include <cpp-lib/util.hpp>

using namespace std;

struct test{
	undefined data;
	Array<undefined> obj;
		
	test(std::string x){
		this->data = unknown(x);
		string txt = this->data.get<string>();
		if(txt[0] == '{' && txt[txt.size()-1] == '}'){
			txt = txt.substr(0, txt.size()-1); 
			txt = txt.substr(1, txt.size());

			for(string s : Util().explode(txt,",")){
				auto tmp = Util().explode(s,":");
				string field = tmp[0];
				string val = tmp[1];
				
				txt = field;

				txt = txt.substr(0, txt.size()-1); 
				txt = txt.substr(1, txt.size());
				
				field = txt;

				txt = val;

				txt = txt.substr(0, txt.size()-1); 
				txt = txt.substr(1, txt.size());
				
				val = txt;

				obj[field] = unknown(val);
			}	
		}
	}

	template<typename T>
	T get(){
		return this->data.get<T>();
	}

	template<typename T>
	T get(string field){
		return this->obj[field].get<T>();
	}
};

main(){
	test x = test("{\"msg\":\"helloworld\"}");

	println(x.get<string>("msg"));
}
