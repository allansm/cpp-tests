#include <allansm/mswindow.hpp>

main(int argc, char** argv){
	std::string program = argv[1];
	
	for(auto n : MsWindow(program).instances()){
		SetWindowPos(n, 0, 0, 0, 400, 300, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);
	}

	for(auto n : MsWindow(program).instances()){
		SetWindowPos(n, 0, 100, 100, 0, 0, SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER);
	}
}
