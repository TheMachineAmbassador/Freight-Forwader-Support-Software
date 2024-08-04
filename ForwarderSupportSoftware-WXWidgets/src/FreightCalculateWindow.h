#ifndef FREIGHTCALCULATEWINDOW_H
#define FREIGHTCALCULATEWINDOW_H

#include <wx/wx.h>
#include <wx/notebook.h>

#include "CommonCargoDetails.h"
#include "SeaCargoBase.h"
#include "AirCargoBase.h"
#include "TruckFreightCore.h"

static constexpr int ID_AlwaysOnTop = 10001; // Custom ID for the menu item

class FreightCalculateWindow : public wxFrame
{
    public:
        FreightCalculateWindow(wxWindow* parent);
    private:
        void OutputPanel();
        void ChangeSidePanelText();

        void OnCalculateButton(wxCommandEvent& event);
        void OnResetButton(wxCommandEvent& event);
        void OnCopyButton(wxCommandEvent& event);
        void OnComboBoxChange(wxCommandEvent& event);
        void OnWeightTextChange(wxCommandEvent& event);
        void OnToggleAlwaysOnTop(wxCommandEvent& event);

        void UpdateOutput();
    private:

        ForwarderSupportWare::SeaCargoBase m_SeaFreight{};
        ForwarderSupportWare::AirCargoBase m_AirFreight{};
        ForwarderSupportWare::TruckFreightCore m_LandFreight{};

        ForwarderSupportWare::CargoDetails* m_CommonFreight = &m_SeaFreight;

        wxString m_FreightOutputText = {};

        wxTextCtrl* m_PieceCtrl;
        wxTextCtrl* m_LengthCtrl;
        wxTextCtrl* m_WidthCtrl;
        wxTextCtrl* m_HeightCtrl;
        wxTextCtrl* m_WeightCtrl;

        wxButton* m_CalculateBtn;
        wxButton* m_ResetBtn;
        wxButton* m_CopyOutputBtn;

        wxStaticText* m_PanelText;

        wxComboBox* m_WidthCmbBox;
        wxComboBox* m_HeightCmbBox;
        wxComboBox* m_LengthCmbBox;
        wxComboBox* m_FreightCmbBox = new wxComboBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY);;
    
        wxCheckBox* m_StackableCheckbox;
        wxBoxSizer* m_VBox;

        wxTextCtrl* m_ChildPanelText;

        float m_Weight;
};

#endif // FREIGHTCALCULATEWINDOW_H