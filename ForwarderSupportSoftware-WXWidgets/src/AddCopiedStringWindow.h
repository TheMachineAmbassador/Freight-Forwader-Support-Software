#ifndef ADDCOPIEDSTRINGWINDOW_H
#define ADDCOPIEDSTRINGWINDOW

#include <wx/wx.h>
#include <wx/notebook.h>

#include "AddCopiedString.h"


class AddCopiedStringWindow : public wxDialog {
public:
    AddCopiedStringWindow(wxWindow* parent);
    
private:
    wxTextCtrl* textCtrl;
    wxStaticText* resultText;

    void OnTextChanged(wxCommandEvent& event);
};

#endif // ADDCOPIEDSTRINGWINDOW
