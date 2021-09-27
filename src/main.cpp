#include <iostream>

#include "main.h"

//-------------------------------------------------------------------------------------------------
// MainFrame
//-------------------------------------------------------------------------------------------------

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) {

  wxMenu* pFileMenu = new wxMenu;
  pFileMenu->Append(wxID_EXIT);

  wxMenu* pHelpMenu = new wxMenu;
  pHelpMenu->Append(wxID_ABOUT);

  wxMenuBar* pMenuBar = new wxMenuBar;
  pMenuBar->Append(pFileMenu, "&File");
  pMenuBar->Append(pHelpMenu, "&Help");

  SetMenuBar(pMenuBar);
  CreateStatusBar();
  SetStatusText("Ready.");

  wxSizer* pTopSizer = new wxBoxSizer(wxVERTICAL);

  SetSizer(pTopSizer);
  Show(true);
}

void MainFrame::OnExit(wxCommandEvent& event) {
  Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event) {
  wxMessageBox("Made by coon\n\n"
               "E-Mail: coon@mailbox.org\n"
               "IRC: coon@hackint.org\n\n"
               "https://www.reddit.com/user/coon42\nhttps://github.com/coon42\n",
               "<WxApp>", wxOK | wxICON_INFORMATION);
}

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_MENU(wxID_EXIT, MainFrame::OnExit)
EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
wxEND_EVENT_TABLE()

//-------------------------------------------------------------------------------------------------
// WxApp
//-------------------------------------------------------------------------------------------------

bool WxApp::OnInit() {
  new MainFrame("<WxApp>", wxDefaultPosition, wxSize(640, 480));

  printf("<WxApp> started.\n");

  return true;
}

wxIMPLEMENT_APP_CONSOLE(WxApp);
