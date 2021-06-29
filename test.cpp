#include "class/io.h"
#include "optimizedclass/util.h"
#include "optimizedclass/time.h"
#include <windows.h>

class Mysql{
	private:
		string mysql;
		string user;
		string password;
		string database;
		string command;

	public:
		Mysql(string mysql,string user,string password,string database);
		string query(string q);
};

Mysql::Mysql(string mysql,string user,string password,string database){
	this->mysql = mysql;
	this->user = user;
	this->password = password;
	this->database = database;
	this->command = mysql+" -u "+user;

	if(password != ""){

		this->command += " -p "+password;
	}

	this->command += " --database "+database;
}

string Mysql::query(string q){
	string query = this->command+" -e \""+q+"\" -X";
	FILE* pipe = popen(query.c_str(),"r");
	char buffer[256];
	string result = "";
	while(fgets(buffer,256,pipe)){
		result+=buffer;		
	}
	pclose(pipe);

	return result;
}

main(){

	Util util;
	
	Mysql mysql = Mysql("C:\\xampp\\mysql\\bin\\mysql.exe","root","","allan");
	string result = mysql.query("select * from test;");
	
	util.print(result);

}
