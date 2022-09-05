#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/copy.hpp>

#include <iostream>
#include <sstream>

std::string compress(std::string data){
	using namespace boost::iostreams;

	std::istringstream decompressed(data);

	filtering_istreambuf in;
	
	in.push(gzip_compressor(gzip_params(gzip::best_compression)));
	in.push(decompressed);

	std::ostringstream compressed;
	copy(in, compressed);
	
	return compressed.str();
}

std::string decompress(std::string data){
	using namespace boost::iostreams;
    	
	std::istringstream compressed(data);

	filtering_istreambuf in;
    	
	in.push(gzip_decompressor());
    	in.push(compressed);

    	std::ostringstream decompressed;
    	copy(in, decompressed);
    	
	return decompressed.str();
}

int main(){
	std::string data = "000000000000000000000000000000000000000000000400";
	
	auto compressed = compress(data);
	
	std::cout << "data         : " << data                    << "\n";
	std::cout << "compressed   : " << compressed              << "\n";
	std::cout << "decompressed : " << decompress(compressed)  << "\n";
}
