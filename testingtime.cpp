#include <cpp-lib/time.hpp>
#include <cpp-lib/io.hpp>
#include <cpp-lib/util.hpp>

main(){
	auto start = Time().currentTimeToMs();
	while(true){	
		Util().clear();
		auto tmp = Time().elapsedTime(start);
		auto sec = Time().toSec(tmp);
		auto clock = Time().elapsedTime(sec);
		
		println(Time().getCurrent()+" "+clock);
		Time().sleep(1000);
	}
}
