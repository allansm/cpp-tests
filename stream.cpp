#include "class/files.h"
#include "class/io.h"

void stream(string file,string ip,string port,string protocol){
	string test = "ffmpeg -i \""+file+"\" -vcodec mpeg4 -f mpegts -b:v 9999999 "+protocol+"://"+ip+":"+port;
	system(test.c_str());
}

void run(){
	system("start /B streammanager");
	while(true){
		string file = Files::getFirstLine("file");
		string* config = Files::getLines(".config");
		
		if(file != ""){
			Files::removeLine("file",file);
			stream(file,config[0],config[1],config[2]);
		}
	}
}

main(){
	run();
}