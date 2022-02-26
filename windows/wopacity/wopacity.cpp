#include <allansm/mswindow.hpp>
#include <allansm/parser.hpp>

main(int argc,char** argv){
	MsWindow* window = new MsWindow(argv[1]);
	float opacity = unknown(argv[2]);
	
	window->opacity(opacity);
}
