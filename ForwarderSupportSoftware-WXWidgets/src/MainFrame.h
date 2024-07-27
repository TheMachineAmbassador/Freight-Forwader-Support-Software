#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/webrequest.h>

class MainFrame: public wxFrame {
private:
    void OnOpenFreightCalculation(wxCommandEvent& event);
    void OnOpenAddCopiedString(wxCommandEvent& event);
    void OnOpenCustomCalculator(wxCommandEvent& event);
    void OnOpenContainerTracking(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void AdjustFontForDPI(wxWindow* window);
public:
    MainFrame(const wxString& title);
};

#endif // MAINFRAME_H
