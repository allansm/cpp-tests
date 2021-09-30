#include <iostream>
#include <map>
#include <utility>

using namespace std;

class Test2{
	public:
//		template <typename T>
//		T val = "";
		int integer;
		float real;
		string text;

		string type;
		//Test data;

		
		/*template <typename T>
		T test(){
			if(type == "text"){
				return this->text;	
			}else if(type == "integer"){
				return this->integer;
			}else{
				return this->real;
			}
		}*/
};

struct n{
	template<typename T>
	T val;
};

/*T a(T x){
	return x;
}*/

main(){
	/*auto lamb = [](){
		return "aaa";
	};*/
	
	//n t;

	//t.val<int> = 2;

	cout << "hello";//t.val;

	//t2.val<string> = "helloworld";

	/*t2.text = "hello";
	t2.type = "text";	
	
	map<string,Test2> test;

	test["text"] = t2;

	cout << test["text"].test();*/

	/*t.text = "hello";

	map<string,Test> test;
	
	test["msg"] = t;
	
	t.text = "";
	t.integer = 2;

	test["n"] = t;
	
	//test["n"] = t;

	cout << test["msg"].text << endl;
	cout << test["n"].integer;	
*/
}

