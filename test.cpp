#include "class/io.h"
#include "optimizedclass/util.h"
#include "optimizedclass/files.h"

main(){
	Util util;
	Files files;
	
	string fn = "test.txt";
	string text = "helloworld";
	files.writeFile(fn.c_str(),text.c_str());
	files.addLine(fn.c_str(),text.c_str());
}
