#include <cpp-lib/io.hpp>
#include <cpp-lib/json.hpp>

using namespace std;

main(){
	auto tmp = Json("{'a':[1,2,3]}").array<int>("a");

	print_r(tmp);

	print(tmp[0]);
}
