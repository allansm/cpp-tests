#include <iostream>

int main(){
	std::string s = "a b c d";
	
	std::cout << s << "\n\n";

	int i = 0;
	int pos = 0;

	while((pos = s.find(" ", i)) != -1){
		std::cout << i << " " << pos-i << "\n";
		std::cout << s.substr(i, pos-i) << "\n\n";
		
		i = pos+1;
	}
	
	std::cout << i << " " << s.length()-i << "\n";
	std::cout << s.substr(i, s.length()-i);

	return 0;
}
