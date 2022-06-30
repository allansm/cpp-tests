#include <stdio.h>
#include <string.h>
#include <zlib.h>
#include <iostream>

struct compressed{
	char * data;
	uInt size;
};

compressed compress(char * data){
	char result[strlen(data)+1];

	z_stream defstream;
	defstream.zalloc = Z_NULL;
	defstream.zfree = Z_NULL;
	defstream.opaque = Z_NULL;

	defstream.avail_in = (uInt)strlen(data)+1; 
	defstream.next_in = (Bytef *)data; 
	defstream.avail_out = (uInt)sizeof(result); 
	defstream.next_out = (Bytef *)result; 

	deflateInit(&defstream, Z_BEST_COMPRESSION);
	deflate(&defstream, Z_FINISH);
	deflateEnd(&defstream);

	return {result,(uInt)((char*)defstream.next_out - result)};
}

std::string decompress(char * data,uInt size){ 
	char result[999999];	

	z_stream infstream;
	infstream.zalloc = Z_NULL;
	infstream.zfree = Z_NULL;
	infstream.opaque = Z_NULL;

	infstream.avail_in = size;
	infstream.next_in = (Bytef *)data; 
	infstream.avail_out = (uInt)sizeof(result); 
	infstream.next_out = (Bytef *)result; 


	inflateInit(&infstream);
	inflate(&infstream, Z_NO_FLUSH);
	inflateEnd(&infstream);

	return result;
}


int main(int argc, char* argv[]){
	auto data = compress((char*)"aaaaabbbbbaaaaa");
	std::cout << decompress(data.data,data.size);

	return 0;
}
