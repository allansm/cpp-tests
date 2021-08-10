#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif
class App : public wxApp{
	public:
		virtual bool OnInit();
};
class Frm : public wxFrame{
	public:
		Frm(const wxString& title, const wxPoint& pos, const wxSize& size);
};

wxIMPLEMENT_APP(App);

bool App::OnInit(){
	Frm *frame = new Frm(wxString(""),wxPoint(50,50),wxSize(800,600));
	frame->Show(true);
	return true;
}
Frm::Frm(const wxString& title, const wxPoint& pos, const wxSize& size)
	:wxFrame(NULL,wxID_ANY,title,pos,size){
	
}


