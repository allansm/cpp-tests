#include <allansm/mswindow.hpp>
#include <allansm/io.hpp>
#include <allansm/parser.hpp>
#include <allansm/util.hpp>

main(int argc, char ** argv){
	std::string app = argv[1];
	std::string res = argv[2];
	auto scale = Util().explode(res,"x");

	auto window = MsWindow(app);

	window.resize(unknown(scale[0]), unknown(scale[1]));
}
