#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Files{
	public:
		Files();
		vector<string> getLines(const char* file);
		bool exists(const char* file);
		void createFile(const char *filename);
		void writeFile(const char *filename,const char *text);
		void writeFile(string filename,string text);
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

void Files::createFile(const char *filename){
	ofstream file(filename);
	file.close();
}

void Files::writeFile(const char *filename,const char *text){
	ofstream file(filename);
	file << text;
	file.close();
}

void Files::writeFile(string filename,string text){
	ofstream file(filename.c_str());
	file << text.c_str();
	file.close();
}

bool Files::exists(const char *fileName){
	ifstream infile(fileName);
	return infile.good();
}

