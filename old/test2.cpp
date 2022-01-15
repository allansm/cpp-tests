#include <allansm/io.hpp>

main(){
	void *addr = (void*)(0x12345678);
	println(addr);
	println(*(int*)addr);
}
