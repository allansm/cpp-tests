#include <cpp-lib/basic.h>
#include <cpp-lib/util.h>
#include <cpp-lib/json.h>

Util util = Util();
Json jsn = Json();

main(){
	string res = util.exec("curl -s \"http://worldtimeapi.org/api/timezone/America/Sao_Paulo\"");
	json time = jsn.toJson(res);

	int weekday = time["day_of_week"].get<int>();
	int epoch = time["unixtime"].get<long>();
	util.println(epoch);
	util.println(weekday);
}
