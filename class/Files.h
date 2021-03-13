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

};

#endif // FILES_H
