#include "cMain.h"

/*The event table associates the ID of items in the frame with functions
  i.e. 10001 is m_btn1, if m_btn1 is clicked it will initiate OnYESClicked*/
wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_BUTTON(10001, OnYESClicked)
EVT_BUTTON(10002, OnNOClicked)
wxEND_EVENT_TABLE()

/*creates a frame with 2 buttons, and a message box, and a pointer to an engine object*/
cMain::cMain(Engine *egn) : wxFrame(nullptr, wxID_ANY, "Career Advising", wxPoint(200, 10), wxSize(555, 465),
	wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
{
	m_btn1 = new wxButton(this, 10001, "YES", wxPoint(10, 315), wxSize(250, 100));
	m_btn2 = new wxButton(this, 10002, "NO", wxPoint(280, 315), wxSize(250, 100));
	m_msg1 = new wxTextCtrl(this, 10003, "Welcome, do you want to begin?\n", wxPoint(15, 10), wxSize(510, 300),
		wxTE_READONLY | wxTE_MULTILINE, wxDefaultValidator, "");
	this->egn = egn;

}

/*Deletes the egn and shuts down cMain*/
cMain::~cMain() {
	delete egn;
}

/*OnYESClicked takes the event of the YES button being clicked and uses this to initiate the 
  engine loop returning the next needed question. Returns YES for that variable property(question), and also outputs
  the next question needed to be answered. Once the backward chaining is completed, it will switch to a different 
  variable list for forward chaining*/
void cMain::OnYESClicked(wxCommandEvent& evt) {
		*m_msg1 << "YES\n";
		if (this->startq == false) {
			this->currentvar = this->egn->loop();
			*m_msg1 << this->currentvar;
			this->startq = true;
		}
		else {
			if (!egn->backwarddone) {
				egn->var_list.setVarProperty(this->currentvar, "YES");
			}
			else
				egn->fvar_list.setVarProperty(this->currentvar, "YES");
			this->currentvar = this->egn->loop();
			*m_msg1 << this->currentvar;
			this->startq = true;
			
		}
	evt.Skip();
}

/*OnNOClicked takes the event of the NO button being clicked and returns NO for that variable property(question), 
  while also outputting the next question needed. Once the backward chaining is completed, it will switch to a 
  different variable list for forward chaining**/
void cMain::OnNOClicked(wxCommandEvent& evt) {
	*m_msg1 << "NO\n";
		if (this->startq == false) {
			wxFrame::Close(true);
		}
		else {
			if (!egn->backwarddone) {
				egn->var_list.setVarProperty(this->currentvar, "NO");
			}
			else
				egn->fvar_list.setVarProperty(this->currentvar, "NO");
			this->currentvar = this->egn->loop();
			*m_msg1 << this->currentvar;
			this->startq = true;
		}
	evt.Skip();
}