#include <iostream>
#include <vector>
using namespace std;

void x(){
	cout << "helloworld";
}

int val(int n){
	return n;
}
int val2(){
	return 2;
}

template<typename T>
T val3(T n){
	return n;
}

void (*po)();


vector<void (*)()> vec;

template<typename T>
void test(T* val){
	*val = 10;
}

template<typename T,typename U>
using function = T (*)(U);

template<typename T>
using function2 = T (*)();

template<typename T>
using function3 = T (*)(T);

main(){
	po = &x;
	vec.push_back(po);
	
	vec[0]();

	int a = 2;
	test(&a);

	cout << a;

	function2<int> po2 = &val2;
	function<int,int> po3 = &val;
	function3<float> po4 = &val3;

	cout << po2() << po3 << po4(2.5);
}
