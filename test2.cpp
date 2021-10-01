#include <iostream>
#include <sstream>
using namespace std;



int x = 123;
string y = "hello";
float z = 2.5;


template<typename T>
int toInt(T n){
	stringstream ss;

	ss << n;

	int tmp;

	ss >> tmp;

	return tmp;
}

template<typename T>
string toString(T n){
	stringstream ss;

	ss << n;

	string tmp;

	ss >> tmp;

	return tmp;
}

template<typename T>
float toFloat(T n){
	stringstream ss;

	ss << n;

	float tmp;

	ss >> tmp;

	return tmp;
}

main(){
	string val = "2";

	int x = toInt(val);
	
	x = x+2;

	cout << x << endl;

	val = toString(x);

	val = "val:"+val;

	cout << val << endl;

	float y = toFloat(x);

	y+=2.5;

	cout << y << endl;

	val = toString(y);

	val = "val:"+val;

	cout << val;
}
