#include "class/io.h"
#include "optimizedclass/util.h"
#include "optimizedclass/time.h"
#include <windows.h>

main(){
	Time time;
	Util util;
	long int start = time.currentTimeToMs();
	while(true){
		system("cls");
		util.println(time.elapsedTime(time.toSec(time.elapsedTime(start))));
	}
}
