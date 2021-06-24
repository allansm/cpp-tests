#include <string>
//#include <sstream>
#include <fstream>
#include <vector>

#include <sys/time.h>
//#include <windows.h>

using namespace std;

class Files2{
	public:
		Files2();
		vector<string> getLines(const char* file);
		bool exists(const char* file);
};

Files2::Files2(){

}

/*
int countLines(const char* file){
	string text;
	ifstream temp(file);
	int i = 0;
	while (getline (temp, text)) {
	  i++;
	}
	temp.close();
	return i;
}

string getRandomLine(const char* file){
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

string getFirstLine(const char* file){
	string line;
	ifstream temp(file);
	while (getline (temp,line)) {
	    return line;
	}
	temp.close();
	return "";
}
*/
/*
string getLine(const char* file,int n){
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
*/
vector<string> Files2::getLines(const char* file){
	ifstream temp(file);
	string text;
	//int size = countLines(file);
	vector<string> lines;
	int count = 0;

	while (getline (temp, text)) {
		lines.push_back(text);
	}

	temp.close();

	return lines;
}

bool Files2::exists(const char *fileName){
	ifstream infile(fileName);
	return infile.good();
}

/*
void removeLine(const char* file,string line){
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
*/
