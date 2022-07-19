#include <allansm/win.hpp>

main(){
	Win win;

	for(auto n : win.hOnDisplay()){
		win.changeOpacity(n, 1);
	}
}
