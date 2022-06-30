#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Box.H>

main(int argc,char **argv){
	Fl_Window window(400, 300);
	
	Fl_PNG_Image img(argv[1]);
	Fl_Box box(0,0,0,0);
	
	box.image(img);
	box.show();
	//box.redraw();

	window.end();
	window.show(argc, argv);
	
	return Fl::run();
}
