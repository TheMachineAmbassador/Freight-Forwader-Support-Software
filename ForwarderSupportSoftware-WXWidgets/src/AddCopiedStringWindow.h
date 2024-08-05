#ifndef ADDCOPIEDSTRINGWINDOW_H
#define ADDCOPIEDSTRINGWINDOW

#include <wx/wx.h>
#include <wx/notebook.h>

#include "AddCopiedString.h"

class AddCopiedStringWindow : public wxDialog
{
    public:
        AddCopiedStringWindow(wxWindow* parent);
    private:
        void OnTextChanged(wxCommandEvent& event);
    private:
        wxTextCtrl* m_TextCtrl;
        wxTextCtrl* m_ResultText;
        AddCopiedString m_Add;
};

#endif // ADDCOPIEDSTRINGWINDOW
