#include <download.h>
#include <iostream>
main(){
	GoString str = {"http://www.google.com/"};
	auto html = download(str);

	std::cout << html.p;
}
