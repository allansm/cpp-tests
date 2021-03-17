#include "class/files.h"
#include "class/io.h"

void stream(string file,string ip,string port,string protocol,string bitrate){
	string test = "ffmpeg -i \""+file+"\" -vcodec mpeg4 -f mpegts -b:v "+bitrate+" "+protocol+"://"+ip+":"+port;
	system(test.c_str());
}

void run(){
	string* config = Files::getLines(".config");
	if(config[4] == "true"){
		system("start /B filefeed");
		system("start /B autoytdl");
		system("start /B streammanager");
	}
	while(true){
		string file = Files::getFirstLine("file");
		if(file != ""){
			Files::removeLine("file",file);
			if(Files::exists(file.c_str())){
				string cmd = "echo "+file+" >> .log";
				system(cmd.c_str());
				stream(file,config[0],config[1],config[2],config[3]);
				bool isHere = !(file.find("\\") > 0);
				if(isHere){
					cmd = "echo "+file+" >> deleted.txt";
					system(cmd.c_str());
				}
			}
		}
	}
}

main(){
	Files::deleteBy("mp4");
	run();
}