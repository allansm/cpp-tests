#include <string>
#include <fstream>
#include <vector>

#include <sys/time.h>

using namespace std;

class Files{
	public:
		Files();
		vector<string> getLines(const char* file);
		bool exists(const char* file);
};

Files::Files(){

}

vector<string> Files::getLines(const char* file){
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

bool Files::exists(const char *fileName){
	ifstream infile(fileName);
	return infile.good();
}

