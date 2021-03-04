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
                        cout << i << " : " <<lines[i] << "\n\n";
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
