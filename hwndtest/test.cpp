#include <allansm/win.hpp>
#include <allansm/io.hpp>
#include <allansm/parser.hpp>
#include <allansm/util.hpp>

main(int argc,char ** argv){

	for(auto n:Win().getAll()){
		DWORD pid = 0;
		GetWindowThreadProcessId(n, &pid);

		if(pid == 688){
			print(Win().getAppname(n));
			break;
		}
	}
}
