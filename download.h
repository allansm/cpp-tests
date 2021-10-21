#include <iostream>

extern "C" {
	const char* download(const char* url);
}

std::string download(std::string url){
	return download(url.c_str());
}
