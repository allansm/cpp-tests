#include <string>
#include <fstream>
#include <vector>

#include <sys/time.h>

using namespace std;

class Files2{
	public:
		Files2();
		vector<string> getLines(const char* file);
		bool exists(const char* file);
};

Files2::Files2(){

}

vector<string> Files2::getLines(const char* file){
	ifstream temp(file);
	string text;

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

