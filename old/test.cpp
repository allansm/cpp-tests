#include <iostream>
#include <allansm/io.hpp>
#include <vector>

main(){
	std::string k = "0123456789ABCDEF";
	std::string hex = "68";
	std::vector<int> n;

	for(int i=0;i<hex.size();i++){
		for(int i2=0;i2<k.size();i2++){
			if(hex[i] == k[i2]){
				n.push_back(i2);
			}
		}
	}

	int res = (n[0]*k.size()) + (n[1]*1);

	print(res);
}
