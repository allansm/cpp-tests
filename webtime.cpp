#include <cpp-lib/basic.h>
#include <cpp-lib/util.h>
#include <cpp-lib/json.h>
#include <cpp-lib/request.h>

Util util = Util();
Json jsn = Json();

Request request = Request();


json getApiTime(){
	return jsn.toJson(request.get("http://worldtimeapi.org/api/timezone/America/Sao_Paulo"));
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

	util.println("date:"+getDate(time));
	util.println("time:"+getTime(time));
	util.println("week day:"+getWeekDay(time));
}
