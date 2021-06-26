#include "class/io.h"
#include "optimizedclass/util.h"
#include <windows.h>

main(){
	Util u;
	int i = 0;
	vector<string> arr = u.explode("a;b;c;d;e;f;g;h;i;j;k;l;m;n;o;p;q;r;s;t;u",";");
	while(i++ < 10){
		string value = u.getRandomValue(arr);
		Sleep(1);
		u.print(value);
	}
}
