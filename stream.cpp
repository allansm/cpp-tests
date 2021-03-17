/******************************************************************
*	.config file:
*	0:ip
*	1:port
*	2:protocol
*	3:bitrate
*	4:useStreamManager
*	5:useM3U8 note: this ignore all connection config need a path
*	6:m3u8Path
*	
*******************************************************************/


#include "class/files.h"
#include "class/io.h"

void stream(string file,string ip,string port,string protocol,string bitrate){
	string test = "ffmpeg -i \""+file+"\" -vcodec mpeg4 -f mpegts -b:v "+bitrate+" "+protocol+"://"+ip+":"+port;
	system(test.c_str());
}

void stream(string file,string bitrate,string loc){
	string test = "ffmpeg -i \""+file+"\" -b:v "+bitrate+" -g 60 -hls_time 2 -hls_list_size 0 -hls_segment_size 500000 "+loc+"output.m3u8";
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
				if(config[5] == "true"){
					stream(file,config[3],config[6]);
				}else{
					stream(file,config[0],config[1],config[2],config[3]);
				}
				bool isHere = !(file.find("\\") > 0);
				if(isHere){
					cmd = "echo "+file+" >> deleted.txt";
					//system(cmd.c_str());
					remove(file.c_str());
				}
			}
		}
	}
}

main(){
	Files::deleteBy("mp4");
	run();
}