#include <cpp-lib/output.hpp>
#include <cpp-lib/util.hpp>
#include <cpp-lib/json.h>

Util util = Util();
Json jsn = Json();

json getApiTime(){
	return jsn.toJson(util.exec("curl -s http://worldtimeapi.org/api/timezone/America/Sao_Paulo"));
}

string getDate(json time){
	return util.explode(time["datetime"].get<string>(),"T")[0];
}

string getTime(json time){
	string tmp = util.explode(time["datetime"].get<string>(),"T")[1];
	
	return util.explode(tmp,".")[0];
}

long getUnixTime(json time){
	return time["unixtime"].get<long>();
}

string getWeekDay(json time){
	vector<string> wday{"dom","seg","ter","qua","qui","sex","sab"};
	
	return wday[time["day_of_week"].get<int>()];	
}

main(){
	json time = getApiTime();

	println("date:"+getDate(time));
	println("time:"+getTime(time));
	println("week day:"+getWeekDay(time));
}
