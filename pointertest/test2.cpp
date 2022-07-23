#include <iostream>


class Test{
	private:
		void* ptr;
	
	public:
		Test(void* ptr){
			this->ptr = ptr;
		}

		void test(){
			int* val = (int*) this->ptr;
			
			*val+=2;
		}
};

class Test2{
	private:
		void* ptr;
	public:
		Test2(void* ptr){
			this->ptr = ptr;
		}

		void test2(){
			Test* test = (Test*) this->ptr;

			test->test();
		}
};


main(){
	int x = 10;

	auto test = Test(&x);
	auto test2 = Test2(&test);
	
	test2.test2();

	std::cout << x;
}
