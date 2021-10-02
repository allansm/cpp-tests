#include <iostream>
#include <vector>
using namespace std;

void x(){
	cout << "helloworld";
}

void (*po)();


vector<void (*)()> vec;

template<typename T>
void test(T* val){
	*val = 10;
}

main(){
	po = &x;
	vec.push_back(po);
	
	vec[0]();

	int a = 2;
	test(&a);

	cout << a;
}
