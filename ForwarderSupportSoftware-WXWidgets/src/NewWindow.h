#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include <wx/wx.h>

class NewWindow : public wxDialog {
public:
    NewWindow(wxWindow* parent, wxWindowID id, const wxString& title,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize);
};

#endif // NEWWINDOW_H
