#ifndef FILES_H
#define FILES_H

/*#include <stdio.h>
#include <stdlib.h>
#include <iostream>*/

#include <string>
#include <sstream>
#include <fstream>

#include <sys/time.h>
#include <windows.h>

using namespace std;

class Files{
    public : static int countLines(const char* file){
        string text;
        ifstream temp(file);
        int i = 0;
        while (getline (temp, text)) {
          i++;
        }
        temp.close();
        return i;
    }

    public : static string getRandomLine(const char* file){
        ifstream temp(file);
        string text;
        int size = countLines(file);
        string lines[size];
        int count = 0;

        while (getline (temp, text)) {
          lines[count++] = text;
        }

        temp.close();

        srand (time(NULL));

        int iSecret;

        iSecret = rand() % size + 0;

        return lines[iSecret];
    }

    public : static string getFirstLine(const char* file){
        string line;
        ifstream temp(file);
        while (getline (temp,line)) {
            return line;
        }
        temp.close();
        return "";
    }

    public : static string getLine(const char* file,int n){
        ifstream temp(file);
        string text;
        int size = countLines(file);
        string lines[size];
        int count = 0;

        while (getline (temp, text)) {
          lines[count++] = text;
        }

        temp.close();

        return lines[n];
    }

    public : static string* getLines(const char* file){
        ifstream temp(file);
        string text;
        int size = countLines(file);
        string* lines = new string[size];
        int count = 0;

        while (getline (temp, text)) {
          lines[count++] = text;
        }

        temp.close();

        return lines;
    }
	
	public : static bool exists(const char *fileName){
		ifstream infile(fileName);
		return infile.good();
	}
	
	public : static void removeLine(const char* file,string line){
		ifstream temp(file);
		string text;
		int size = countLines(file);
		string lines[size];
		int count = 0;
		string txt = "";
		while (getline (temp, text)) {
		  if(text != line){
			txt += text+"\n";
		  }
		}
		remove(file);
		ofstream output(file);
		output.write(txt.c_str(),txt.length());
		output.close();
		temp.close();
	}
	
	public : static void deleteBy(string extension){
		string command = "dir /B *."+extension+" > filesToDelete.txt";
		system(command.c_str());

		ifstream temp("filesToDelete.txt");
		string text;
		int size = countLines("filesToDelete.txt");
		string lines[size];
		int count = 0;

		while (getline (temp, text)) {
		  lines[count++] = text;
		}
		temp.close();

		for(int i=0;i<size;i++){
			//cout << "deleting : "+lines[i]+"\n";
			remove(lines[i].c_str());
		}

	}

};

#endif // FILES_H
