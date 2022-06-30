#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

main(int argc,char **argv){
	Fl_Window window(200,30);
	Fl_Box box(0,0,100,25,"helloworld");
	
	window.end();
	window.show(argc, argv);
	
	return Fl::run();
}
