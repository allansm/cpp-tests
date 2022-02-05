#include <zlib.h>
#include <iostream>
#include <allansm/io.hpp>

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

	println(compressed);

	char decompressed[255];

	stream.zalloc = Z_NULL;
	stream.zfree = Z_NULL;
	stream.opaque = Z_NULL;

    	stream.avail_in = (uInt) strlen(compressed)+1;
	stream.next_in = (Bytef *) compressed;

    	stream.avail_out = (uInt) sizeof(decompressed);
    	stream.next_out = (Bytef *) decompressed;
     
    	inflateInit(&stream);
    	inflate(&stream, Z_NO_FLUSH);
    	inflateEnd(&stream);
     	
	println(decompressed);
}

