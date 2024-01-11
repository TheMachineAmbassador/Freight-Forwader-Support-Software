#include "FreightCalculateWindow.h"

#include <format>

float GetTextCtrlValueAsFloat(wxTextCtrl* &textCtrl) {
    wxString textValue = textCtrl->GetValue();
    
    // Convert wxString to std::string
    std::string stdStr = std::string(textValue.mb_str());

    try {
        // Convert std::string to float
        return std::stof(stdStr);
    }
    catch (const std::exception&) {
        // Handle error
        return 0.0f;
    }
}

float GetTextCtrlValueAsInt(wxTextCtrl*& textCtrl) {
    wxString textValue = textCtrl->GetValue();

    // Convert wxString to std::string
    std::string stdStr = std::string(textValue.mb_str());

    try {
        // Convert std::string to float
        return std::stoi(stdStr);
    }
    catch (const std::exception&) {
        // Handle error
        return 0.0f;
    }
}

ForwarderSupportWare::SeaCargoBase sea{};
ForwarderSupportWare::AirCargoBase air{};
TruckFreightCore high{};

FreightCalculateWindow::FreightCalculateWindow(wxWindow* parent) : wxFrame(parent, wxID_ANY, "Freight Calculation Window", wxDefaultPosition, wxSize(350 ,450),wxMINIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN | wxDEFAULT_FRAME_STYLE) {
    wxSize fixedSize = wxSize(350, 450);
    this->SetSize(fixedSize);
    this->SetMinSize(fixedSize);
    this->SetMaxSize(fixedSize);
    this->SetBackgroundColour(*wxWHITE);

    wxMenuBar* menuBar = new wxMenuBar;

    wxMenu* optionsMenu = new wxMenu;

    // Add a checkable item for always-on-top feature
    optionsMenu->AppendCheckItem(ID_AlwaysOnTop, "Make window always on top");

    menuBar->Append(optionsMenu, "Options");
    SetMenuBar(menuBar);

    // Bind the menu event
    Bind(wxEVT_MENU, &FreightCalculateWindow::OnToggleAlwaysOnTop, this, ID_AlwaysOnTop);

    // About menu
    wxMenu* helpMenu = new wxMenu;
    helpMenu->Append(wxID_ABOUT, "About\tF1", "About");
    menuBar->Append(helpMenu, "&Help");
    SetMenuBar(menuBar);

    
    panelText = new wxStaticText(this, wxID_ANY, wxString(OutputPanel().c_str(), wxConvUTF8));

    wxString choices[] = { "M", "CM", "MM","in" };

    widthCmbBox = new wxComboBox(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 4, choices, wxCB_READONLY);
    widthCmbBox->SetSelection(1);
    heightCmbBox = new wxComboBox(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 4, choices, wxCB_READONLY);
    heightCmbBox->SetSelection(1);
    lenthCmboBox = new wxComboBox(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 4, choices, wxCB_READONLY);
    lenthCmboBox->SetSelection(1);

    pieceCtrl = new wxTextCtrl(this, wxID_ANY);;
    lengthCtrl = new wxTextCtrl(this, wxID_ANY);;
    widthCtrl = new wxTextCtrl(this, wxID_ANY);;
    heightCtrl = new wxTextCtrl(this, wxID_ANY);;
    weightCtrl = new wxTextCtrl(this, wxID_ANY);;

    calculateBtn = new wxButton(this, wxID_ANY, "Update");;
    resetBtn = new wxButton(this, wxID_ANY, "Reset/Clear");;
    copyDataBtn = new wxButton(this, wxID_ANY, "Copy Data");;

    // Layout using sizers
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    // Add the menu bar to the sizer
    vbox->Add(panelText, 0, wxEXPAND | wxALL, 5);

    wxBoxSizer* hbox66 = new wxBoxSizer(wxHORIZONTAL);
    // Add items to the combo box
    freightCmboBox->Append("Deniz");
    freightCmboBox->Append("Hava");
    //freightCmboBox->Append("Kara");
    // Set the default selection (optional)
    freightCmboBox->SetSelection(0); // Select "Deniz" as the default item
    hbox66->Add(freightCmboBox, 1, wxEXPAND | wxALL,5);
    // Bind the event handler to EVT_COMBOBOX
    freightCmboBox->Bind(wxEVT_COMBOBOX, &FreightCalculateWindow::OnComboBoxChange, this);

    vbox->Add(hbox66, 0, wxEXPAND | wxALL, 5);

    wxBoxSizer* hbox1 = new wxBoxSizer(wxHORIZONTAL);
    hbox1->Add(new wxStaticText(this, wxID_ANY, "Piece:"), 0, wxEXPAND | wxALL, 5);
    hbox1->Add(pieceCtrl, 1, wxEXPAND);
    vbox->Add(hbox1, 0, wxEXPAND | wxALL, 5);
    
    // For "Uzunluk" and its control
    wxBoxSizer* hbox2 = new wxBoxSizer(wxHORIZONTAL);
    hbox2->Add(new wxStaticText(this, wxID_ANY, "Length:   "), 0, wxEXPAND | wxALL, 5);
    hbox2->Add(lengthCtrl, 1, wxEXPAND | wxALL, 5);
    hbox2->Add(heightCmbBox, 1, wxEXPAND | wxALL, 5);
    vbox->Add(hbox2, 0, wxEXPAND | wxALL, 5);

    wxBoxSizer* hbox3 = new wxBoxSizer(wxHORIZONTAL);
    hbox3->Add(new wxStaticText(this, wxID_ANY, "Width:   "), 0, wxEXPAND | wxALL, 5);
    hbox3->Add(widthCtrl, 1, wxEXPAND | wxALL, 5);
    hbox3->Add(widthCmbBox, 1, wxEXPAND | wxALL, 5);
    vbox->Add(hbox3, 0, wxEXPAND | wxALL, 5);

    wxBoxSizer* hbox4 = new wxBoxSizer(wxHORIZONTAL);
    hbox4->Add(new wxStaticText(this, wxID_ANY, "Height:"), 0, wxEXPAND | wxALL, 5);
    hbox4->Add(heightCtrl, 1, wxEXPAND | wxALL, 5);
    hbox4->Add(lenthCmboBox, 1, wxEXPAND | wxALL, 5);
    vbox->Add(hbox4, 0, wxEXPAND | wxALL, 5);

    wxBoxSizer* hbox5 = new wxBoxSizer(wxHORIZONTAL);
    hbox5->Add(new wxStaticText(this, wxID_ANY, "Weight:   "), 0, wxEXPAND | wxALL, 5);
    hbox5->Add(weightCtrl, 1, wxEXPAND | wxALL, 5);
    vbox->Add(hbox5, 0, wxEXPAND | wxALL, 5);

    // Create a horizontal box sizer
    wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
    hbox->Add(calculateBtn, 0, wxRight, 10);
    hbox->Add(resetBtn, 1);
    hbox->Add(copyDataBtn, 2);

    // Add the horizontal box sizer to the vertical box sizer, below the button
    vbox->Add(hbox, 0, wxEXPAND | wxALL, 10);

    this->SetSizer(vbox);

    // Bind event
    calculateBtn->Bind(wxEVT_BUTTON, &FreightCalculateWindow::OnCalculateButton, this);
    resetBtn->Bind(wxEVT_BUTTON, &FreightCalculateWindow::OnResetButton, this);
    copyDataBtn->Bind(wxEVT_BUTTON, &FreightCalculateWindow::OnCopyButton, this);

    weightCtrl->Bind(wxEVT_TEXT, &FreightCalculateWindow::OnWeightTextChange, this);
}

void FreightCalculateWindow::OnToggleAlwaysOnTop(wxCommandEvent& event) {
    long style = this->GetWindowStyleFlag();
    if (event.IsChecked()) {
        this->SetWindowStyleFlag(style | wxSTAY_ON_TOP);
    }
    else {
        this->SetWindowStyleFlag(style & ~wxSTAY_ON_TOP);
    }
    // You might need to call SetWindowStyleFlag() followed by Show() to apply the style change immediately
    this->Show();
}


void FreightCalculateWindow::OnWeightTextChange(wxCommandEvent& event)
{
    Cargo->setWeightKG(GetTextCtrlValueAsFloat(weightCtrl));
    UpdateOutput(output);
}

void FreightCalculateWindow::OnCalculateButton(wxCommandEvent& event)
{
    Vec3 stuff{ GetTextCtrlValueAsFloat(lengthCtrl) ,GetTextCtrlValueAsFloat(widthCtrl),GetTextCtrlValueAsFloat(heightCtrl)};
    Cargo->setWeightKG(GetTextCtrlValueAsFloat(weightCtrl));
    
    int index = Deniz;
    if (freightCmboBox->GetSelection() == -1)
        index = 0;
    else
        index = freightCmboBox->GetSelection();

    int selectedIndex = widthCmbBox->GetSelection();

    switch (index)
    {
    case Deniz:
        selectedIndex = widthCmbBox->GetSelection();
        convertToMeters(stuff.x, selectedIndex);

        selectedIndex = heightCmbBox->GetSelection();
        convertToMeters(stuff.y, selectedIndex);

        selectedIndex = lenthCmboBox->GetSelection();
        convertToMeters(stuff.z, lenthCmboBox->GetSelection());

        sea.setWeightLBS(Cargo->getWeightKG());
        break;
    case Hava:
    case Kara:
        selectedIndex = widthCmbBox->GetSelection();
        convertToCentimeters(stuff.x, selectedIndex);

        selectedIndex = heightCmbBox->GetSelection();
        convertToCentimeters(stuff.y, selectedIndex);

        selectedIndex = lenthCmboBox->GetSelection();
        convertToCentimeters(stuff.z, selectedIndex);
    default:
        assert("I hope no one arrive it here");
        break;
    }
    
    Cargo->pushValueToOzelliker(stuff, GetTextCtrlValueAsInt(pieceCtrl));
    
    UpdateOutput(output);
}

std::string FreightCalculateWindow::OutputPanel()
{
    weightBuff = Cargo->getWeightKG();

    const float tonnage = weightBuff / 1000.0f;

    output =  std::format("Pieces: {}\n", std::to_string(Cargo->getPieces()));
    output += std::format("Weight: {0:.3f} KG / {1:.3f} Ton\n", weightBuff, tonnage);

    int index = 0;
    if (freightCmboBox->GetSelection() == -1)
    {
        index = 0;
    }
    else
        index = freightCmboBox->GetSelection();

    switch (index)
    {
    case Deniz:
        Cargo = &sea;
        output += std::format("Volume: (CBM): {0:.3f}\n", sea.getVolume());
        output += std::format("Weight: (LBS/Pound): {0:.3f} LBS\n", sea.getWeightLbs());
        output += std::format("Volume: (CBF): {0:.3f}\n", sea.getVolumeCBF());
        output += std::format("W/M: {0:.3f}", sea.getWMValue());
        break;
    case Hava:
        Cargo = &air;
        output += std::format("Volumetric weight: {0:.3f}\n", air.getVolumeWeight());
        output += std::format("Chargable weight: {0:.3f}\n", air.getChargableWeight());
        break;
    case Kara:
        Cargo = &high;
        output += std::format("LDM: {0:.3f}", high.getLDM());
        break;
    default:
        break;
    }

    return output;
}

void FreightCalculateWindow::UpdateOutput(std::string & output)
{
    wxString piecesStr(OutputPanel().c_str(), wxConvUTF8);
    panelText->SetLabel(piecesStr);
}

void FreightCalculateWindow::OnCopyButton(wxCommandEvent& event)
{
    CopyClipboard(output);
}

void FreightCalculateWindow::OnResetButton(wxCommandEvent& event)
{
    Cargo->Clear();
    weightBuff = 0;
    OutputPanel();     
    UpdateOutput(output);
}

void FreightCalculateWindow::OnComboBoxChange(wxCommandEvent& event)
{
    OutputPanel();
    UpdateOutput(output);
}