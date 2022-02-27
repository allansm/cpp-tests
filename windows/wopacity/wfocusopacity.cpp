#include <allansm/win.hpp>
#include <allansm/parser.hpp>
#include <allansm/time.hpp>

main(int argc,char** argv){
	HWND previous = NULL;
	float opacity = 0.8;
	
	if(argc == 2){
		opacity = unknown(argv[1]);
	}

	while(true){
		if(previous != NULL){
			Win().changeOpacity(previous, 1);
		}
		
		auto focused = Win().getFocused();
		Win().changeOpacity(focused, unknown(opacity));

		previous = focused;

		Time().sleep(1000);
	}
}
