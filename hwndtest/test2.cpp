#include <win.cpp>
#include <allansm/io.hpp>

main(){
	for(auto n : Win().getAll()){
		RECT rect;
		if(GetWindowRect(n, &rect)){
			int width = rect.right - rect.left;
			int height = rect.bottom - rect.top;
			auto name = Win().getAppname(n);
			print(name);
			for(int i = name.length(); i < 25;i++){
				print(" ");
			}
			print(width);
			print("x");
			println(height);
		}
	}
}
