#include <wx/wx.h>

class App : public wxApp{
	public:
		virtual bool OnInit();
};

class Frame : public wxFrame{
	public:
		Frame(const wxString& title, const wxPoint& pos, const wxSize& size);
};

wxIMPLEMENT_APP(App);

bool App::OnInit(){
	Frame *frame = new Frame(wxString(""),wxPoint(50,50),wxSize(800,600));
	frame->Show(true);
	return true;
}

Frame::Frame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(NULL,wxID_ANY,title,pos,size){
	
}


