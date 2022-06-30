#include <allansm/file.hpp>
#include <allansm/io.hpp>
#include <cstdio>

main(){
	File hello("hello.txt");
	hello.write("helloworld");
	
	std::rename("hello.txt", "helloworld.txt");

	File helloworld("helloworld.txt");
	
	println(helloworld.read());
	
	std::remove("helloworld.txt");
}
