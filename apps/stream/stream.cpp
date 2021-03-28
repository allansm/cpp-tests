/******************************************************************
*	.config file:
*	0:ip
*	1:port
*	2:protocol
*	3:bitrate
*	4:useStreamManager
*******************************************************************/


#include "class/files.h"
#include "class/util.h"
#include "class/io.h"
#include "class/time.h"

void stream(string file,string ip,string port,string protocol,string bitrate){
	
	string test = "ffmpeg -re -i \""+file+"\" -filter:v fps=30 -vcodec mpeg4 -f mpegts -b:v "+bitrate+" "+protocol+"://"+ip+":"+port;
	system(test.c_str());
}

void vlcStream(string file,string ip,string port){
	system("taskkill /f /im vlc*");
 
	string vlc = "start /wait \"\" \"c:/program files (x86)/videolan/vlc/vlc.exe\" -I dummy --dummy-quiet -vvv \""+file+"\" :sout=#http{dst="+ip+",port="+port+",mux=ts,ttl=1} :sout-all :sout-keep vlc://quit";
	cout << vlc << endl;
	system(vlc.c_str());
}


void run(){
	string* config = Files::getLines(".config");
	if(config[4] == "true"){
		system("start /B filefeed");
		system("start /B autoytdl");
		system("start /B streammanager");
		system("start /B autodel");
	}
	while(true){
		string file = Files::getFirstLine("file");
		string line = file;
		file = Util::split(file,"\"",1);
		cout << "file:"<< file << endl;
		Files::removeLine("file",line);
		if(file != ""){
			if(Files::exists(file.c_str())){
				string log = "echo \""+file+" "+Time::getCurrent()+"\" >> .log";
				system(log.c_str());
				system("echo 0 > canDelete.txt");
				vlcStream(file,config[0],config[1]);
				
				int i = file.find("\\");
				bool isHere = !(i>0);
				if(isHere){
					cout << "file is here" << endl;
					string cmd = "echo \""+file+" "+Time::getCurrent()+"\" >> deleted.txt";
					system(cmd.c_str());
					remove(file.c_str());
				}
			}
		}
		Sleep(1000);
	}
}

main(){
	run();
}