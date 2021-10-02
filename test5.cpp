#include <iostream>
using namespace std;

class n{
	public:
	int val(){
		return 7;
	}
};

using n::val;

main(){
	val();
}
