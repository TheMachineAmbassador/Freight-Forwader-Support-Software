#include "FreightCalculateWindow.h"

#include "wx/clipbrd.h"
#include <wx/statline.h>

#include "Common.h"

#include <map>

using namespace ForwarderSupportWare;

FreightCalculateWindow::FreightCalculateWindow(wxWindow* parent) : wxFrame(parent, wxID_ANY, "Freight Calculation Window", wxDefaultPosition, wxSize(675 , 500),wxMINIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN | wxDEFAULT_FRAME_STYLE) {
    wxSize fixedSize = wxSize(675, 500);
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

    
    OutputPanel();
    m_PanelText = new wxStaticText(this, wxID_ANY, m_FreightOutputText);

    wxString choices[] = { "M", "CM", "MM","in" };

    // Initialize stacableCheckbox
    m_StackableCheckbox = new wxCheckBox(this, wxID_ANY, "Non-Stackable", wxDefaultPosition, wxDefaultSize);

    // Initially hide stacableCheckbox
    //stacableCheckbox->Hide();

    m_WidthCmbBox = new wxComboBox(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 4, choices, wxCB_READONLY);
    m_WidthCmbBox->SetSelection(1);
    m_HeightCmbBox = new wxComboBox(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 4, choices, wxCB_READONLY);
    m_HeightCmbBox->SetSelection(1);
    m_LengthCmbBox = new wxComboBox(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 4, choices, wxCB_READONLY);
    m_LengthCmbBox->SetSelection(1);

    m_PieceCtrl = new wxTextCtrl(this, wxID_ANY);
    m_LengthCtrl = new wxTextCtrl(this, wxID_ANY);
    m_WidthCtrl = new wxTextCtrl(this, wxID_ANY);
    m_HeightCtrl = new wxTextCtrl(this, wxID_ANY);
    m_WeightCtrl = new wxTextCtrl(this, wxID_ANY);

    m_CalculateBtn = new wxButton(this, wxID_ANY, "Update");;
    m_ResetBtn = new wxButton(this, wxID_ANY, "Reset/Clear");;
    m_CopyOutputBtn = new wxButton(this, wxID_ANY, "Copy Data");;

    // Layout using sizers
    m_VBox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* MainHBox = new wxBoxSizer(wxHORIZONTAL);

    // Add the menu bar to the sizer
    m_VBox->Add(m_PanelText, 0, wxEXPAND | wxALL, 5);

    wxBoxSizer* hbox66 = new wxBoxSizer(wxHORIZONTAL);
    // Add items to the combo box
    m_FreightCmbBox->Append("Sealine");
    m_FreightCmbBox->Append("Airway");
    m_FreightCmbBox->Append("Land");

    // Set the default selection
    m_FreightCmbBox->SetSelection(0); // Select "Deniz" as the default item

    hbox66->Add(m_FreightCmbBox, 1, wxEXPAND | wxALL,5);

    // Bind the event handler to EVT_COMBOBOX
    m_FreightCmbBox->Bind(wxEVT_COMBOBOX, &FreightCalculateWindow::OnComboBoxChange, this);

    m_VBox->Add(hbox66, 0, wxEXPAND | wxALL, 5);

    wxBoxSizer* hbox1 = new wxBoxSizer(wxHORIZONTAL);
    hbox1->Add(new wxStaticText(this, wxID_ANY, "Piece:"), 0, wxEXPAND | wxALL, 5);
    hbox1->Add(m_PieceCtrl, 1, wxEXPAND);
    m_VBox->Add(hbox1, 0, wxEXPAND | wxALL, 5);
    
    // For "Uzunluk" and its control
    wxBoxSizer* hbox2 = new wxBoxSizer(wxHORIZONTAL);
    hbox2->Add(new wxStaticText(this, wxID_ANY, "Length:   "), 0, wxEXPAND | wxALL, 5);
    hbox2->Add(m_LengthCtrl, 1, wxEXPAND | wxALL, 5);
    hbox2->Add(m_LengthCmbBox, 1, wxEXPAND | wxALL, 5);
    m_VBox->Add(hbox2, 0, wxEXPAND | wxALL, 5);

    wxBoxSizer* hbox3 = new wxBoxSizer(wxHORIZONTAL);
    hbox3->Add(new wxStaticText(this, wxID_ANY, "Width:   "), 0, wxEXPAND | wxALL, 5);
    hbox3->Add(m_WidthCtrl, 1, wxEXPAND | wxALL, 5);
    hbox3->Add(m_WidthCmbBox, 1, wxEXPAND | wxALL, 5);
    m_VBox->Add(hbox3, 0, wxEXPAND | wxALL, 5);

    wxBoxSizer* hbox4 = new wxBoxSizer(wxHORIZONTAL);
    hbox4->Add(new wxStaticText(this, wxID_ANY, "Height:"), 0, wxEXPAND | wxALL, 5);
    hbox4->Add(m_HeightCtrl, 1, wxEXPAND | wxALL, 5);
    hbox4->Add(m_HeightCmbBox, 1, wxEXPAND | wxALL, 5);
    m_VBox->Add(hbox4, 0, wxEXPAND | wxALL, 5);

    wxBoxSizer* hbox5 = new wxBoxSizer(wxHORIZONTAL);
    hbox5->Add(new wxStaticText(this, wxID_ANY, "Weight:   "), 0, wxEXPAND | wxALL, 5);
    hbox5->Add(m_WeightCtrl, 1, wxEXPAND | wxALL, 5);
    m_VBox->Add(hbox5, 0, wxEXPAND | wxALL, 5);

    // Add stacableCheckbox under the Weight controls
    m_VBox->Add(m_StackableCheckbox, 0, wxEXPAND | wxALL, 5);

    // Create a horizontal box sizer
    wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
    hbox->Add(m_CalculateBtn, 0, wxRight, 10);
    hbox->Add(m_ResetBtn, 1);
    hbox->Add(m_CopyOutputBtn, 2);
    
    // Add the horizontal box sizer to the vertical box sizer, below the button
    m_VBox->Add(hbox, 0, wxEXPAND | wxALL, 10);

    // Add vertical line
    wxStaticLine* verticalLine = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL);

    ////////////////////////////////// SIDE PANEL ///////////////////////////////////////////////////////
    wxBoxSizer* SidePanelSizer = new wxBoxSizer(wxVERTICAL);
    m_ChildPanelText = new wxTextCtrl(this, wxID_ANY, "Waiting for details...", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY | wxBORDER_NONE);
    m_ChildPanelText->SetBackgroundColour(*wxLIGHT_GREY);
    SidePanelSizer->Add(m_ChildPanelText, 1, wxEXPAND | wxALL, 10);
    ////////////////////////////////// END OF SIDE PANEL ///////////////////////////////////////////////////////

    MainHBox->Add(m_VBox, 1, wxEXPAND | wxALL, 5);
    MainHBox->Add(verticalLine, 0, wxEXPAND | wxALL, 5);
    MainHBox->Add(m_ChildPanelText, 1, wxEXPAND | wxALL, 5);

    this->SetSizer(MainHBox);

    // Bind event
    m_CalculateBtn->Bind(   wxEVT_BUTTON,   &FreightCalculateWindow::OnCalculateButton,     this);
    m_ResetBtn->Bind(       wxEVT_BUTTON,   &FreightCalculateWindow::OnResetButton,         this);
    m_CopyOutputBtn->Bind(  wxEVT_BUTTON,   &FreightCalculateWindow::OnCopyButton,          this);

    m_WeightCtrl->Bind(     wxEVT_TEXT,     &FreightCalculateWindow::OnWeightTextChange,    this);

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
    m_CommonFreight->SetWeightKG(GetTextCtrlValueAsFloat(m_WeightCtrl));
    UpdateOutput();
}

void FreightCalculateWindow::ChangeSidePanelText()
{
    wxString SidePanelText = "";
    for (const auto& entry : m_CommonFreight->GetDimensions()) {
        SidePanelText += wxString::Format("%d adet, %.2fx%.2fx%.2fcm\n", entry.Count, entry.Dimension.x, entry.Dimension.y, entry.Dimension.z);
    }

    m_ChildPanelText->SetValue(SidePanelText);
}

void FreightCalculateWindow::OnCalculateButton(wxCommandEvent& event)
{
    int index = Sea;

    Vec3 stuff{ GetTextCtrlValueAsFloat(m_LengthCtrl) ,GetTextCtrlValueAsFloat(m_WidthCtrl),GetTextCtrlValueAsFloat(m_HeightCtrl)};
    m_CommonFreight->SetWeightKG(GetTextCtrlValueAsFloat(m_WeightCtrl));
    
    if (m_FreightCmbBox->GetSelection() == -1)
        index = Sea;
    else
        index = m_FreightCmbBox->GetSelection();

    int selectedIndex = m_WidthCmbBox->GetSelection();

    switch (index)
    {
        case Sea:
            selectedIndex = m_LengthCmbBox->GetSelection();
            convertToMeters(stuff.x, m_LengthCmbBox->GetSelection());

            selectedIndex = m_WidthCmbBox->GetSelection();
            convertToMeters(stuff.y, selectedIndex);

            if (m_StackableCheckbox->IsChecked())
                stuff.z = 2.65f;
            else 
            {
                selectedIndex = m_HeightCmbBox->GetSelection();
                convertToMeters(stuff.z, selectedIndex);
            }
            
            m_SeaFreight.setWeightLBS(m_CommonFreight->GetWeightKG());
            break;
        case Air:
            selectedIndex = m_LengthCmbBox->GetSelection();
            convertToCentimeters(stuff.x, selectedIndex);

            selectedIndex = m_WidthCmbBox->GetSelection();
            convertToCentimeters(stuff.y, selectedIndex);

            selectedIndex = m_HeightCmbBox->GetSelection();
            convertToCentimeters(stuff.z, selectedIndex);

            break;
        case Land:
            if (m_StackableCheckbox->IsChecked())
                m_LandFreight.isStackable = true;
            else
                m_LandFreight.isStackable = false;

            selectedIndex = m_LengthCmbBox->GetSelection();
            convertToCentimeters(stuff.x, selectedIndex);

            selectedIndex = m_WidthCmbBox->GetSelection();
            convertToCentimeters(stuff.y, selectedIndex);

            selectedIndex = m_HeightCmbBox->GetSelection();
            convertToCentimeters(stuff.z, selectedIndex);

            break;
    default:
        assert("I hope no one arrive it here");
        break;
    }
    
    m_CommonFreight->PushValueToDimensions(stuff, GetTextCtrlValueAsInt(m_PieceCtrl));

    ChangeSidePanelText();

    // Layout adjustment after showing or hiding controls
    Layout();
    Refresh();

    // Update output or other relevant logic based on the combo box selection
    UpdateOutput();
}

void FreightCalculateWindow::OutputPanel()
{
    int index = Sea;

    m_Weight = m_CommonFreight->GetWeightKG();

    const float tonnage = m_Weight / 1000.0f;

    m_FreightOutputText =  wxString::Format("Pieces: %d\n", m_CommonFreight->GetPieces());
    m_FreightOutputText += wxString::Format("Weight: %.3f KG / %.3f Ton\n", m_CommonFreight->GetWeightKG(), tonnage);

    if (m_FreightCmbBox->GetSelection() == -1)
    {
        index = Sea;
    }
    else
        index = m_FreightCmbBox->GetSelection();

    switch (index)
    {
    case Sea:
        m_CommonFreight = &m_SeaFreight;
        m_FreightOutputText += wxString::Format("Volume (CBM): %.3f\n", m_SeaFreight.getVolume());
        m_FreightOutputText += wxString::Format("Weight (LBS/Pound): %.3f LBS\n", m_SeaFreight.getWeightLbs());
        m_FreightOutputText += wxString::Format("Volume (CBF): %.3f\n", m_SeaFreight.getVolumeCBF());
        m_FreightOutputText += wxString::Format("W/M: %.3f", m_SeaFreight.getWMValue());
        break;
    case Air:
        m_CommonFreight = &m_AirFreight;
        m_FreightOutputText += wxString::Format("Volumetric weight: %.3f\n", m_AirFreight.getVolumeWeight());
        m_FreightOutputText += wxString::Format("Chargable weight: %.3f\n\n", m_AirFreight.getChargableWeight());
        break;
    case Land:
        m_CommonFreight = &m_LandFreight;
        m_FreightOutputText += wxString::Format("LDM: %.3f \n\n\n", m_LandFreight.getLDM());
        break;
    default:
        break;
    }
}

void FreightCalculateWindow::UpdateOutput()
{
    OutputPanel();
    m_PanelText->SetLabel(m_FreightOutputText);
}

void FreightCalculateWindow::OnCopyButton(wxCommandEvent& event)
{
    // Get current output text
    wxString outputText = m_FreightOutputText;

    // Open the clipboard
    if (wxTheClipboard->Open())
    {
        // Clear the clipboard
        wxTheClipboard->Clear();

        // Create a text data object
        wxTextDataObject textData(outputText);

        // Set the data
        wxTheClipboard->SetData(new wxTextDataObject(outputText));

        // Close the clipboard
        wxTheClipboard->Close();
    }
}

void FreightCalculateWindow::OnResetButton(wxCommandEvent& event)
{
    m_CommonFreight->Clear();
    m_Weight = 0;
    
    m_ChildPanelText->SetLabel("");

    UpdateOutput();
}

void FreightCalculateWindow::OnComboBoxChange(wxCommandEvent& event)
{
    int index = m_FreightCmbBox->GetSelection();

    // Show stacableCheckbox when Deniz or Hava is selected
    if (index == Sea || index == Land) {
        m_StackableCheckbox->Show();
    }
    else {
        m_StackableCheckbox->Hide();
    }

    m_CommonFreight->Clear();
    m_Weight = 0;

    m_ChildPanelText->SetLabel("");


    // Layout adjustment after showing or hiding stacableCheckbox
    Layout();
    Refresh();

    // Update output or other relevant logic based on the combo box selection
    UpdateOutput();
}