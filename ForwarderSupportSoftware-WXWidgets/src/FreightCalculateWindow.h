#ifndef FREIGHTCALCULATEWINDOW_H
#define FREIGHTCALCULATEWINDOW_H

#include <wx/wx.h>
#include <wx/notebook.h>

#include "CommonCargoDetails.h"
#include "SeaCargoBase.h"
#include "AirCargoBase.h"
#include "TruckFreightCore.h"

class FreightCalculateWindow : public wxFrame
{
private:
    enum option
    {
        Deniz = 0, Hava, Kara, MAX
    };
    
    static const int ID_AlwaysOnTop = 10001; // Custom ID for the menu item

    ForwarderSupportWare::SeaCargoBase sea{};
    ForwarderSupportWare::AirCargoBase air{};
    TruckFreightCore high{};

    ForwarderSupportWare::CargoDetails* Cargo = &sea;

    std::string output;

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

    float weightBuff;

public:
    FreightCalculateWindow(wxWindow* parent);
    // Add other methods specific to TabOnePanel

private:
    std::string OutputPanel();
    
    void OnCalculateButton(wxCommandEvent& event);
    void OnResetButton(wxCommandEvent& event);
    void OnCopyButton(wxCommandEvent& event);
    void UpdateOutput(std::string& output);
    void OnComboBoxChange(wxCommandEvent& event);
    void OnWeightTextChange(wxCommandEvent& event);
    void OnToggleAlwaysOnTop(wxCommandEvent& event);

    // Add other member variables and methods
};

#endif