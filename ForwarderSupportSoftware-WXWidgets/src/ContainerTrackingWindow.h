#ifndef CONTAINERTRACKINGWINDOW_H
#define CONTAINERTRACKINGWINDOW_H

#include <wx/wx.h>
#include <wx/notebook.h>

#include "CommonContProp.h"
#include "CoscoTracking.h"
#include "MSCTracking.h"

class ContainerTrackingWindow : public wxDialog
{
    public:
        ContainerTrackingWindow(wxWindow* parent);
    private:
        void onButtonClick(wxCommandEvent& event);
    private:
        wxTextCtrl* m_ContainerNumberCtrl;

        wxStaticText* m_ContainerNumText;
        wxStaticText* m_StatusText;
        wxStaticText* m_CurrentLocationText; // Where is containers current location
        wxStaticText* m_TimeOfIssueText;
        wxStaticText* m_ETAText; // ETA = Estimaded Time Arrival

        wxComboBox* m_CarrierComboBox;

        wxButton* m_TrackButton;

        CommonContProp* m_Carrier = nullptr;
        CoscoTracking m_Cosco;
        MSCContainer m_MSC;
};

#endif // CONTAINERTRACKINGWINDOW_H