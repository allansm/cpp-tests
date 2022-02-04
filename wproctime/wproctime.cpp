#include <allansm/win.hpp>
#include <allansm/io.hpp>
#include <allansm/elapse.hpp>
#include <allansm/util.hpp>
#include <allansm/time.hpp>
#include <allansm/path.hpp>
#include <allansm/file.hpp>
#include <allansm/parser.hpp>

struct Process{
	string name;
	int ms;
};

main(){
	using namespace std;
	
	const int MINUTE = 1000*60;

	auto data = File("wproctime"+Time().getDate("")+".data");
	auto w = Win();
	
	vector<Process> procs;
	
	int ms = 0;
	int i = 0;

	Elapse e = Elapse();
	Elapse save = Elapse();
	
	chdir(getTemp());

	if(data.exists()){
		for(auto n : data.lines()){
			auto tmp = Util().explode(n,";");
			procs.push_back({tmp[0],unknown(tmp[1])});
		}
	}

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

		procs[i] = {name,procs[i].ms+e.elapsed()};
		e = Elapse();
		
		if(save.elapsed() > MINUTE){
			data.write("");
			println("saving...");
		}
		
		for(auto n : procs){
			print(n.name);
			print(" ");
			print(Time().elapsedTime(n.ms/1000));
			println("");
			
			if(save.elapsed() > MINUTE){
				data.add(n.name+";"+to_string(n.ms)+"\n");
			}
		}

		if(save.elapsed() > MINUTE){
			save = Elapse();
		}

		Time().sleep(1100);
	}
}
