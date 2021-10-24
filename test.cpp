#include <iostream>

std::string getTemp(){
	const char* temp = getenv("XDG_RUNTIME_DIR");
	temp = temp ? temp : getenv("TMPDIR");
        temp = temp ? temp : getenv("TMP");
	temp = temp ? temp : getenv("TEMP");
	temp = temp ? temp : "/tmp";
	
	return temp;
}

main(){
	std::cout << getTemp();
}
