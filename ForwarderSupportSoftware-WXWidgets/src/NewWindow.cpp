#include "NewWindow.h"

NewWindow::NewWindow(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size)
    : wxDialog(parent, id, title, pos, size) {
    // Add controls and set up the layout for the dialog
    new wxStaticText(this, wxID_ANY, "This is a new window", wxPoint(10, 10), wxDefaultSize);
}
