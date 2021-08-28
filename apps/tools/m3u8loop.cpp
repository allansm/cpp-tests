#include <optimizedclass/files.h>
#include <optimizedclass/util.h>

main(int argc,char *argv[]){
	Files f = Files();
	Util u = Util();
	string player = f.getLines(".config")[0];
	string site = f.getLines(".config")[1];
	site = site+argv[1];	
	f.createFile("play.m3u8");
	f.addLine("play.m3u8",site.c_str());
	string tmp = "play.m3u8";
	f.addLine("play.m3u8",tmp.c_str());
	
	string command = player+" play.m3u8";
	system(command.c_str());
}
