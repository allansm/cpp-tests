#include <allansm/io.hpp>
#include <allansm/file.hpp>
#include <allansm/base.hpp>

main(int argc, char ** argv){
	File file = File(argv[1]);
	
	int i = 1;
	int size = 15;

	if(argc == 3) size = atoi(argv[2]);
	
	if(file.exists()){
		std::vector<std::string> hex = Base(file.read(), 16);

		for(std::string n : hex){
			if(n.length() < 2) n="0"+n;

			print(n+" ");

			if(i++ == size){
				print("\n");
				i=1;
			}
		}
	}else{
		std::vector<std::string> hex = Base(argv[1], 16);

		for(std::string n : hex){
			if(n.length() < 2) n="0"+n;

			print(n+" ");

			if(i++ == size){
				print("\n");
				i=1;
			}
		}	
	}

	print("\n");
}
