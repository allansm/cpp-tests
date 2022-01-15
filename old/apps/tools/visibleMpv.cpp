#include <cpp-lib/win.hpp>
#include <cpp-lib/io.hpp>
#include <cpp-lib/time.hpp>

Win w = Win();

main(){
	while(true){	
		auto visible = w.getVisible();
		bool skip = true;
		for(auto win : visible){
			if(skip){
				skip = false;
			}else{
				w.changeOpacity(win,1);
			}
		}

		if(w.getAppname(visible[0]) != "mpv") w.changeOpacity(visible[0],0.8);

		if(w.getAppname(visible[1]) != "mpv" && w.getAppname(visible[0]) != "explorer" && (w.isMaximized(visible[0]) || w.isFullScreen(visible[0]))){
			w.minimize(visible[1]);
		}
		if(w.getAppname(visible[1]) != "mpv"){
			w.changeOpacity(visible[1],0.8);	
		}

		if(w.getAppname(visible[1]) == "mpv"){
			w.maximize(visible[1]);
		}

		Time().sleep(1000);
	}

}

