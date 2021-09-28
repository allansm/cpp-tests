#include <optimizedclass/util.h>

void hello(void (*lambda)()){
	lambda();
}

main(){
	auto lambda = [](){
		Util().print("helloworld");
	};

	hello(lambda);
}
