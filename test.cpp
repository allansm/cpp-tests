#include "class/files.h"
#include "class/util.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

string dump = "dump.txt";


void storeDumpLines(){

}

void getPage(string url){
    string command = "wget -O "+dump+" "+url;
    system(command.c_str());
}

main(){
    string op;
    string url = "";
    while(true){
        cout << "@>";
        cin >> op;

        if(op == "setUrl"){

            cin >> url;
        }

        else if(op == "getPage"){
           getPage(url);
        }
        else if(op == "storeDump"){
            int size = Files::countLines(dump.c_str());

            string lines[size];

            ifstream temp(dump.c_str());
            string line;

            int count = 0;
            while (getline (temp, line)) {
                lines[count++] = line;
            }
            while(true){
                 cout << url << ">";
                 cin >> op;
                 if(op == "exitPage"){
                    break;
                 }
                 if(op == "showLines"){
                    for(int i=0;i<size;i++){
                        cout << lines[i] << "\n\n";
                    }
                 }
                 if(op == "storeLines"){
                    string fname;
                    string cmd = "echo founded lines > "+fname;
                    system(cmd.c_str());
                    for(int i=0;i<size;i++){
                       cmd = "echo "+lines[i]+" >> "+fname;
                       system(cmd.c_str());
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
                            lines[i] = Util::test(lines[i],d1,d2);
                        }catch (const exception &exc){

                        }
                    }
                 }
            }
        }
    }
}
