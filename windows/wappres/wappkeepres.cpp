#include <allansm/mswindow.hpp>
#include <allansm/io.hpp>
#include <allansm/parser.hpp>
#include <allansm/util.hpp>
#include <allansm/time.hpp>

main(int argc, char ** argv){
	std::string app = argv[1];
	std::string res = argv[2];
	
	auto scale = Util().explode(res,"x");

	auto window = MsWindow(app);
	
	int x = unknown(scale[0]);
	int y = unknown(scale[1]);

	while(true){
		bool flag = false;
		
		for(auto n : window.size()){
			if(n["x"] != x || n["y"] != y){
				std::cout << n["x"] << "x" << n["y"] << " >> " << x << "x" << y << "\n";
				
				flag = true;
				break;
			}
		}

		if(flag) window.resize(x, y);

		Time().sleep(5000);
	}
}
