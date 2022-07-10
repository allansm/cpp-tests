#include <allansm/win.hpp>
#include <allansm/time.hpp>
#include <allansm/io.hpp>
#include <allansm/file.hpp>

bool ignored(std::string name, std::vector<std::string> ignore){
	Time t;

	for(auto n : ignore){
		if(n == name) return true;
		
		t.sleep(1);
	}

	return false;
}

main(int argc,char** argv){
	Win win;
	Time timeh;
	float opacity = 0.8;
	auto prev = win.getFocused();
	File config(".config");

	std::vector<std::string> ignore;

	if(config.exists()) ignore = config.lines();

	if(argc == 2){
		opacity = std::atof(argv[1]);
	}

	float screen = win.getSize(GetDesktopWindow())[0]*win.getSize(GetDesktopWindow())[1];
	
	while(true){
		auto focused = win.getFocused();
		auto fname = win.getAppname(focused);
		auto fsize = win.getSize(focused);
		float percent = (100/screen)*(fsize[0]*fsize[1]);
		float x = opacity/2;
		
		if(!ignored(fname, ignore)){
			if(percent >= 25) win.changeOpacity(focused, opacity);
			else win.changeOpacity(focused, 1);

			print(fname+" ");
			println(percent);
		}else{
			println(fname+" ignored");
		}

		if(focused != prev){
			if(percent >= 80) x = 0.0;
			
			for(auto n : win.hOnDisplay()){
				auto name = win.getAppname(n);

				if(focused != n && name != "explorer" && !ignored(name, ignore)){
					if(!win.isTopmost(n))
						win.changeOpacity(n, x);
				}

				timeh.sleep(10);
			}

			prev = focused;
		}

		timeh.sleep(1000);
	}
}
