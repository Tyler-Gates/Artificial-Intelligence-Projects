#pragma once
#include "wx/wx.h"
#include "Engine.h"


class cMain : public wxFrame
{
public:
	cMain(Engine *egn);
	~cMain();

public:
	wxButton* m_btn1 = nullptr;
	wxButton* m_btn2 = nullptr;
	wxTextCtrl* m_msg1 = nullptr;
	Engine* egn;
	//fEngine* feng;
	bool startq = false;
	std::string currentvar;
	bool finBackward = false;
	void OnYESClicked(wxCommandEvent& evt);
	void OnNOClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

#pragma once
