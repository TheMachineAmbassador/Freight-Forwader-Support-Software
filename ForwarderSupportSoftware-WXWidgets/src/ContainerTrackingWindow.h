#ifndef CONTAINERTRACKINGWINDOW_H
#define CONTAINERTRACKINGWINDOW_H

#include <wx/wx.h>
#include <wx/notebook.h>

#include "CommonContProp.h"
#include "CoscoTracking.h"
#include "MSCTracking.h"

class ContainerTrackingWindow : public wxDialog
{
private:
    wxTextCtrl* containerNumberCtrl;
    wxButton* trackButton;
    wxStaticText* containerNumText;
    wxStaticText* statusText;
    wxStaticText* locationText;
    wxStaticText* timeOfIssueText;
    wxStaticText* etaText;
    wxComboBox* comboBox;

    CommonContProp* common = nullptr;
    CoscoTracking cosco;
    MSCContainer msc;
public:
    ContainerTrackingWindow(wxWindow* parent);
private:
    void onButtonClick(wxCommandEvent& event);

};

#endif