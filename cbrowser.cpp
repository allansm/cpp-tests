#include "class/files.h"
#include "class/util.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

string dump = "dump.txt";
string url = "";


void download(string url){
    string command = "wget "+url;
    system(command.c_str());
}

/*void getPage(string url){
    string command = "wget -O "+dump+" "+url;
    system(command.c_str());
}*/

void getPage(string url){
	if(Files::exists("phantom.txt")){
		remove("phantom.txt");
	}
	string* phantom = Files::getLines("phantom");
	phantom[1] = Util::replace(phantom[1],"$url","'"+url+"'");
	//cout << phantom[1] << "\n";
	try{
		int i =0;
		while(true){
			string echo = "echo "+phantom[i++]+" >> "+"phantom.txt";
			system(echo.c_str());
		}
	}catch(const exception &e){}
    
	string command = "phantomjs phantom.txt";
    system(command.c_str());
}

bool store(string file,string op,bool redirect,string help){
	
    int startline,endline;
	int size = Files::countLines(file.c_str());

	string lines[size];

	startline = 0;
	endline = size;

	ifstream temp(file.c_str());
	string line;

	int count = 0;
	while (getline (temp, line)) {
		lines[count++] = line;
	}
	temp.close();
	while(true){
		 cout << url << ">";
		 cin >> op;
		 if(op == "exitPage"){
			
			return redirect;
		 }
		 if(op == "showLines"){
			for(int i=startline;i<endline;i++){
				cout << i << " : " <<lines[i] << "\n\n";
			}
		 }
		 if(op == "showLine"){
			int i;
			cout << "line>";
			cin >> i;
			cout << i << " : " <<lines[i] << "\n\n";
		 }
		 if(op == "resetRange"){
			startline = 0;
			endline = size;
		 }
		 if(op == "setRange"){
			cout << "start>";
			cin >> startline;
			cout << "end>";
			cin >> endline;
		 }
		 if(op == "storeLines"){
			string fname;
			cout << "filename>";
			cin >> fname;
			string cmd = "echo founded lines > "+fname;
			system(cmd.c_str());
			for(int i=0;i<size;i++){
			   cmd = "echo "+lines[i]+" >> "+fname;
			   system(cmd.c_str());
			}
		 }
		 if(op == "storeRange"){
			string fname;
			cout << "filename>";
			cin >> fname;
			string cmd = "echo founded lines > "+fname;
			system(cmd.c_str());
			for(int i=startline;i<endline;i++){
			   cmd = "echo "+lines[i]+" >> "+fname;
			   system(cmd.c_str());
			}
		 }
		 if(op == "storeAll"){
			string fname;
			cout << "filename>";
			cin >> fname;

			cout << "start>";
			string d1,d2;
			cin >> d1;
			cout << "end>";
			cin >> d2;
			string all = "";
			for(int i=0;i<size;i++){
				all += Util::findAllInOne(lines[i],d1,d2);
			}
			cout << all << "\n";
			ofstream temp2(fname.c_str());
			temp2.write(all.c_str(),all.length());
			temp2.close();
		 }
		 if(op == "storeAllToDump"){
			cout << "start>";
			string d1,d2;
			cin >> d1;
			cout << "end>";
			cin >> d2;
			string all = "";
			for(int i=0;i<size;i++){
				all += Util::findAllInOne(lines[i],d1,d2);
			}
			
			cout << all << "\n";
			
			ofstream temp2(dump.c_str());
			temp2.write(all.c_str(),all.length());
			temp2.close();
		 }
		 if(op == "download"){
			int index;
			cout << "line>";
			cin >> index;

			download(lines[index]);
		 }
		 if(op == "addToLines"){
			string add;
			cout << "start or end(s/e)?";
			string o;
			cin >> o;
			cout << "text>";
			cin >> add;
			if(o == "s"){
				for(int i=0;i<size;i++){
				  lines[i] = add+lines[i];
				}
			}else{
				for(int i=0;i<size;i++){
				  lines[i] = lines[i]+add;
				}
			}


		 }
		 if(op == "urlToLines"){
			for(int i=0;i<size;i++){
			  lines[i] = url+lines[i];
			}
		 }
		 if(op == "find"){
			cout << "start>";
			string d1,d2;
			cin >> d1;
			cout << "end>";
			cin >> d2;
			string found[size];
			for(int i=0;i<size;i++){
				try{
					lines[i] = Util::find(lines[i],d1,d2);
				}catch (const exception &exc){

				}
			}
		 }
		 if(op == "findAll"){
			cout << "start>";
			string d1,d2;
			cin >> d1;
			cout << "end>";
			cin >> d2;
			string found[size];
			for(int i=0;i<size;i++){
				try{
					Util::showAll(lines[i],d1,d2);
				}catch (const exception &exc){

				}
			}
		 }
		 if(op == "redirectTo"){
			int index;
			cout << "line>";
			cin >> index;

			url = lines[index];
			redirect = true;
			
			return redirect;
		 }
		 if(op == "help"){
			cout << help << "\n";
		 }
	}
}

main(){
    string help = "commands:\nsetUrl\ngetPage\nstoreDump\n   exitPage\n   showLines\n   resetRange\n   setRange\n   storeLines\n    storeRange\n   addToLines\n   find";

    string op;
    bool redirect;
   
    while(true){
        if(!redirect){
            cout << "@>";
            cin >> op;
        }else{
            getPage(url);
            op = "storeDump";
            redirect = false;
        }
        if(op == "help"){
            cout << help << "\n";
        }
        if(op == "setUrl"){

            cin >> url;
        }

        if(op == "getPage"){
           getPage(url);
        }
        if(op == "storeDump"){
			if(url == ""){
				url = dump;
			}
			
            redirect = store(dump,op,redirect,help);
        }
		if(op == "store"){
			string fname;
			cout << "filename>";
			cin >> fname;
			url = fname;
			
            redirect = store(fname,op,redirect,help);
        }
    }
}
