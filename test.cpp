#include "optimizedclass/util.h"

main(){
	Util u;
	vector<string> arr = u.explode("a;b;c;d",";");
	u.print_r(arr);
}
