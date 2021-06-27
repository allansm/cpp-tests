#include "class/io.h"
#include "optimizedclass/util.h"
#include "optimizedclass/time.h"
#include <windows.h>

main(){
	string mysql = "C:\\xampp\\mysql\\bin\\mysql.exe -u root";
	char buffer[256];

	FILE* pipe = popen(mysql.c_str(),"w");

	if(!feof(pipe)){
		fputs("use allan;",pipe);
		fflush(pipe);

		fputs("insert into test (nome) values ('c++');",pipe);
		fflush(pipe);

	}
	pclose(pipe);
}
