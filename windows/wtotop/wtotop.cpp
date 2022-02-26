#include <allansm/mswindow.hpp>

int main(int argc,char** argv){
	if(argc == 2){
		auto window = new MsWindow(argv[1]);

		window->topmost();
	}else{
		auto window = new MsWindow();
		
		window->topmost();
	}

	return 0;
}
