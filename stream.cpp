/******************************************************************
*	.config file:
*	0:ip
*	1:port
*	2:protocol
*	3:bitrate
*	4:useStreamManager
*	
*******************************************************************/


#include "class/files.h"
#include "class/util.h"
#include "class/io.h"

void stream(string file,string ip,string port,string protocol,string bitrate){
	//removed attributes 
	//start:-thread_queue_size 327
	//middle:-c:v h264 -preset ultrafast
	//end:
	string test = "ffmpeg -re -i \""+file+"\" -filter:v fps=30 -vcodec mpeg4 -f mpegts -b:v "+bitrate+" "+protocol+"://"+ip+":"+port;
	system(test.c_str());
}

void vlcStream(string file,string ip,string port){
	//temp remove 
	string vlc = "start /wait \"\" \"c:/program files (x86)/videolan/vlc/vlc.exe\" -I dummy --dummy-quiet -vvv \""+file+"\" :sout=#http{dst="+ip+",port="+port+",mux=ts,ttl=1} :sout-all :sout-keep vlc://quit";
	cout << vlc << endl;
	system(vlc.c_str());
}

/*void stream(string file,string bitrate,string loc){
	string test = "ffmpeg -i \""+file+"\" -b:v "+bitrate+" -g 60 -hls_time 2 -hls_list_size 0 -hls_segment_size 500000 "+loc+"output.m3u8";
	system(test.c_str());
}*/

void run(){
	string* config = Files::getLines(".config");
	if(config[4] == "true"){
		system("start /B filefeed");
		system("start /B autoytdl");
		system("start /B streammanager");
	}
	while(true){
		string file = Files::getFirstLine("file");
		string line = file;
		file = Util::split(file,"\"",1);
		cout << "file:"<< file << endl;
		if(file != ""){
			Files::removeLine("file",line);
			if(Files::exists(file.c_str())){
				string cmd = "echo "+file+" >> .log";
				system(cmd.c_str());
				/*if(config[5] == "true"){
					stream(file,config[3],config[6]);
				}else{*/
					//stream(file,config[0],config[1],config[2],config[3]);
					vlcStream(file,config[0],config[1]);
				//}
				int i = file.find("\\");
				bool isHere = !(i>0);
				if(isHere){
					cout << "file is here" << endl;
					cmd = "echo \""+file+"\" >> deleted.txt";
					system(cmd.c_str());
					remove(file.c_str());
				}
			}
		}
		Sleep(1000);
	}
}

main(){
	//Files::deleteBy("mp4");
	run();
}