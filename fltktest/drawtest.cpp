#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>

class Rect : public Fl_Widget {
	public:

	Rect(int X,int Y,int W,int H,const char*L=0) : Fl_Widget(X,Y,W,H,L) {
	
	}
     
	void draw() {
		fl_color(FL_BLACK);
		fl_rectf(x(), y(), w(), h());
	}
};

main(int argc,char **argv){
	Fl_Window window(400, 300);
	
	Rect test(0,0,50,50);
	
	window.end();
	window.show(argc, argv);
	
	return Fl::run();
}
