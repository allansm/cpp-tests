#ifndef EVENTTEST_H
#define EVENTTEST_H

#include <wx/wx.h>
#include <wx/image.h>

class MyFrame: public wxFrame {
	public:
    		MyFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxDEFAULT_FRAME_STYLE);
		
		//
		void test(wxCommandEvent & event);
		
		//
		DECLARE_EVENT_TABLE()
	
	private:
		
	protected:
    		wxButton* execute;
};

//
enum{
	BT = wxID_HIGHEST+1
};

#endif
