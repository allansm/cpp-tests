#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "class/files.h"
#include "class/util.h"



void run(){

    string file = "config.txt";
    string dump = "dump.txt";
    string deli = "deli.txt";
    string d1 = Files::getLine(deli.c_str(),0);
    string d2 = Files::getLine(deli.c_str(),1);
    string d3 = Files::getLine(deli.c_str(),2);
    string site = Files::getFirstLine(file.c_str());
    string param =  Files::getLine(file.c_str(),1);

    cout << param << "\n";

    string command = "wget -O "+dump+" \""+site+param+"\"";

    system(command.c_str());

    int size = Files::countLines(dump.c_str());
    string lines[size];
    system("echo found: > get.txt");
    for(int i = 0;i<=size;i++){
        lines[i] = Files::getLine(dump.c_str(),i);


        try{
           string splited = Util::find(lines[i],d1,d2);

            string url = site+d3+splited;
            string command =  "echo "+url+" >> get.txt";
            system(command.c_str());
            cout << url << "\n";
        }
        catch (const exception &exc){

        }
    }

}

main(){
    run();
}
