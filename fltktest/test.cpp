#include <FL/Fl.H>
#include <FL/Fl_Window.H>

#include <FL/Fl_Button.H>
#include <allansm/io.hpp>
#include <FL/Fl_Multiline_Input.H>

std::string text = "";
Fl_Multiline_Input *inp;

void test(Fl_Widget *butt, void *data){
	println(inp->value());
		
}

int main(int argc, char **argv) {
	Fl_Window window(202,27);

	inp = new Fl_Multiline_Input(1,1,100,25,"");
	Fl_Button butt(101,1,100,25,"show");
	butt.callback(test, &window);

	window.end();
	window.show(argc, argv);
	return Fl::run();
}
