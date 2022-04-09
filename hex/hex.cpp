#include <allansm/io.hpp>
#include <allansm/file.hpp>
#include <allansm/base.hpp>

main(int argc, char ** argv){
	File file = File(argv[1]);
	
	int i = 0;

	if(file.exists()){
		std::vector<std::string> hex = Base(file.read(), 16);

		for(std::string n : hex){
			if(n.length() < 2) n="0"+n;

			print(n+" ");

			if(i++ == 15){
				print("\n");
				i=0;
			}
		}
	}else{
		std::vector<std::string> hex = Base(argv[1], 16);

		for(std::string n : hex){
			if(n.length() < 2) n="0"+n;

			print(n+" ");

			if(i++ == 15){
				print("\n");
				i=0;
			}
		}	
	}

	print("\n");
}
