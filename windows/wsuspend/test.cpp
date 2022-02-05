#include <allansm/file.hpp>
#include <allansm/mswindow.hpp>
#include <allansm/io.hpp>

main(){
	auto config = File(".config");

	if(config.exists()){
		for(auto n : config.lines()){
			println("suspending:"+n);

			auto tmp = MsWindow(n);
			tmp.suspend();
		}
	}
}
