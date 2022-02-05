#include "eventtest.h"

//
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
	    EVT_BUTTON(BT,  MyFrame::test)
END_EVENT_TABLE()

//
void MyFrame::test(wxCommandEvent & event){
	system("notepad");
}

MyFrame::MyFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
    wxFrame(parent, id, title, pos, size, wxDEFAULT_FRAME_STYLE){

    SetSize(wxSize(400, 300));
    SetTitle(wxT("frame"));
    wxBoxSizer* sizer_2 = new wxBoxSizer(wxVERTICAL);
    sizer_2->Add(0, 0, 0, 0, 0);
    execute = new wxButton(this, BT, wxT("execute"));
    sizer_2->Add(execute, 0, wxALIGN_CENTER_HORIZONTAL, 0);
    sizer_2->Add(0, 0, 0, 0, 0);
    
    SetSizer(sizer_2);
    Layout();
}


class MyApp: public wxApp {
	public:
    		bool OnInit();
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit(){
    wxInitAllImageHandlers();
    MyFrame* frame = new MyFrame(NULL, wxID_ANY, wxEmptyString);
    SetTopWindow(frame);
    frame->Show();
    
    return true;
}

