#include "HTTPRequest.hpp"
#include <iostream>

using namespace std;

string get(string url){
	try{
    		http::Request request{url};
    		const auto response = request.send("GET");

		return string{response.body.begin(), response.body.end()};
	}
	catch (const std::exception& e){}

	return "erro!!!";
}


main(){
	string resp = get("http://worldtimeapi.org/api/timezone/America/Sao_Paulo");

	cout << resp;
}
