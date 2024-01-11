#include "ContainerTrackingWindow.h"

ContainerTrackingWindow::ContainerTrackingWindow(wxWindow* parent) : wxDialog(parent, wxID_ANY, "Container Tracking Window", wxDefaultPosition, wxSize(600, 450)) {
    // ComboBox setup
    wxString choices[] = { "Cosco", "MSC", "Maersk" };
    comboBox = new wxComboBox(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 3, choices, wxCB_READONLY);
    
    // Input text setup
    containerNumberCtrl = new wxTextCtrl(this, wxID_ANY);
    trackButton = new wxButton(this, wxID_ANY, "Takip Et");

    // Static text for output
    containerNumText = new wxStaticText(this, wxID_ANY, "");
    statusText = new wxStaticText(this, wxID_ANY, "");
    locationText = new wxStaticText(this, wxID_ANY, "");
    timeOfIssueText = new wxStaticText(this, wxID_ANY, "");
    etaText = new wxStaticText(this, wxID_ANY, "");

    // Layout using sizers
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(comboBox, 0, wxEXPAND | wxALL, 5);
    vbox->Add(containerNumberCtrl, 0, wxEXPAND | wxALL, 5);
    vbox->Add(trackButton, 0, wxEXPAND | wxALL, 5);
    vbox->Add(containerNumText, 0, wxEXPAND | wxALL, 5);
    vbox->Add(statusText, 0, wxEXPAND | wxALL, 5);
    vbox->Add(locationText, 0, wxEXPAND | wxALL, 5);
    vbox->Add(timeOfIssueText, 0, wxEXPAND | wxALL, 5);
    vbox->Add(etaText, 0, wxEXPAND | wxALL, 5);

    this->SetSizer(vbox);

    // Event Bindings
    trackButton->Bind(wxEVT_BUTTON, &ContainerTrackingWindow::onButtonClick, this);
}


// TODO: Add enum to retrieve shipping line information
// wtf is the current item switcher ? 
void ContainerTrackingWindow::onButtonClick(wxCommandEvent& event)
{
    wxString current_item = comboBox->GetValue();
    wxString containerNumber = containerNumberCtrl->GetValue();

    // Assuming 'common' is an instance of a class that handles tracking information
    // Replace with your actual logic to get container data
    current_item = "Cosco";
    if (current_item == "Cosco")
    {
        common = &cosco;
    }
    else if (current_item == "MSC")
    {
        common = &msc;
    }

    // ... Update other fields with actual data retrieved
    std::string contData = containerNumber.ToStdString();

    // Update text fields with information
    common->requestContainerData(contData);
    containerNumText->SetLabel("Konteyner Numaras�: " + contData);
    statusText->SetLabel("Durumu: " + static_cast<wxString>(common->getStatusDescription().c_str()));
    locationText->SetLabel("Konumu: " + static_cast<wxString>(common->getLocation().c_str()));
    timeOfIssueText->SetLabel("Time of Issue (Ne old�unu bilmiyorum...): " + static_cast<wxString>(common->getTimeOfIssue().c_str()));
    etaText->SetLabel("ETA: " + static_cast<wxString>(common->getPodEta().c_str()));
}
