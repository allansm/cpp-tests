#include <zlib.h>
#include <iostream>

main(){
	char text[255] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; 

	char compressed[255];

	z_stream stream;
	stream.zalloc = Z_NULL;
	stream.zfree = Z_NULL;
	stream.opaque = Z_NULL;

	stream.avail_in = (uInt) strlen(text)+1;
	stream.next_in = (Bytef *) text;

	stream.avail_out = (uInt) sizeof(compressed);
	stream.next_out = (Bytef *) compressed;

	deflateInit(&stream, Z_BEST_COMPRESSION);
	deflate(&stream, Z_FINISH);
	deflateEnd(&stream);

	std::cout << compressed;
}

