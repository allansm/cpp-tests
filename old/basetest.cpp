#include <basen.hpp>
#include <allansm/io.hpp>

main(){
	std::string txt = "helloworld";
	std::string res = "";
	
	bn::encode_b64(txt.begin(), txt.end(), std::back_inserter(res));
	println(res);
	std::string res2 = "";
	bn::decode_b64(res.begin(), res.end(), std::back_inserter(res2));
	println(res2);	
	
	res = "";
	bn::encode_b32(txt.begin(), txt.end(), std::back_inserter(res));
	println(res);
	
	res = "";
	bn::encode_b16(txt.begin(), txt.end(), std::back_inserter(res));
	println(res);
}
