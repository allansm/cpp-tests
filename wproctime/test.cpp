#include <allansm/win.hpp>
#include <allansm/io.hpp>
#include <allansm/elapse.hpp>
#include <allansm/util.hpp>

struct Process{
	string name;
	int ms;
};

main(){
	using namespace std;
	
	auto w = Win();
	
	vector<Process> procs;
	string current;
	
	int ms = 0;
	int i = 0;
	
	Elapse e = Elapse();

	while(true){
		Util().clear();
		
		auto name = w.getAppname(w.getFocused());
		
		i = 0;
		bool flag = true;
		for(auto n : procs){
			if(n.name == name){
				flag = false;
				break;
			}
			
			i++;
		}

		if(flag){
			procs.push_back({name,0});
		}

		if(!(current == name)){
			procs[i] = {name,procs[i].ms+e.elapsed()};
			e = Elapse();
		}

		for(auto n : procs){
			print(n.name);
			print(" ");
			print(n.ms);
			println("");
		}
	}
}
