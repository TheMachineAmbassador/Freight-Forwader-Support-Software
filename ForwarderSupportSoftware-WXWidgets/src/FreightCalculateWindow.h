#ifndef FREIGHTCALCULATEWINDOW_H
#define FREIGHTCALCULATEWINDOW_H

#include <wx/wx.h>
#include <wx/notebook.h>

#include "CommonCargoDetails.h"
#include "SeaCargoBase.h"
#include "AirCargoBase.h"
#include "TruckFreightCore.h"

static const int ID_AlwaysOnTop = 10001; // Custom ID for the menu item

class FreightCalculateWindow : public wxFrame
{
private:
    ForwarderSupportWare::SeaCargoBase sea{};
    ForwarderSupportWare::AirCargoBase air{};
    TruckFreightCore high{};

    enum option
    {
        Deniz = 0, Hava, Kara, MAX
    };    

    ForwarderSupportWare::CargoDetails* Cargo = &sea;

    //std::string output;
    wxString output;

    wxTextCtrl* pieceCtrl;
    wxTextCtrl* lengthCtrl;
    wxTextCtrl* widthCtrl;
    wxTextCtrl* heightCtrl;
    wxTextCtrl* weightCtrl;

    wxButton* calculateBtn;
    wxButton* resetBtn;
    wxButton* copyDataBtn;

    wxStaticText* panelText;

    wxComboBox* widthCmbBox;
    wxComboBox* heightCmbBox;
    wxComboBox* lenthCmboBox;
    wxComboBox* freightCmboBox = new wxComboBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY);;
    
    wxCheckBox* stacableCheckbox;
    wxBoxSizer* vbox;

    bool showStackable = true;
    float weightBuff;

public:
    FreightCalculateWindow(wxWindow* parent);
    // Add other methods specific to TabOnePanel

private:
    wxString OutputPanel();
    
    void OnCalculateButton(wxCommandEvent& event);
    void OnResetButton(wxCommandEvent& event);
    void OnCopyButton(wxCommandEvent& event);
    void UpdateOutput(wxString& output);
    void OnComboBoxChange(wxCommandEvent& event);
    void OnWeightTextChange(wxCommandEvent& event);
    void OnToggleAlwaysOnTop(wxCommandEvent& event);

    // Add other member variables and methods
};

#endif