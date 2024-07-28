#include "ContainerTrackingWindow.h"

ContainerTrackingWindow::ContainerTrackingWindow(wxWindow* parent) : wxDialog(parent, wxID_ANY, "Container Tracking Window", wxDefaultPosition, wxSize(600, 450)) {
    // ComboBox setup
    wxString choices[] = { "Cosco", "MSC", "Maersk" };
    m_CarrierComboBox = new wxComboBox(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 3, choices, wxCB_READONLY);
    
    // Input text setup
    m_ContainerNumberCtrl = new wxTextCtrl(this, wxID_ANY);
    m_TrackButton = new wxButton(this, wxID_ANY, "Track");

    // Static text for output
    m_ContainerNumText = new wxStaticText(this, wxID_ANY, "");
    m_StatusText = new wxStaticText(this, wxID_ANY, "");
    m_CurrentLocationText = new wxStaticText(this, wxID_ANY, "");
    m_TimeOfIssueText = new wxStaticText(this, wxID_ANY, "");
    m_ETAText = new wxStaticText(this, wxID_ANY, "");

    // Layout using sizers
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(m_CarrierComboBox, 0, wxEXPAND | wxALL, 5);
    vbox->Add(m_ContainerNumberCtrl, 0, wxEXPAND | wxALL, 5);
    vbox->Add(m_TrackButton, 0, wxEXPAND | wxALL, 5);
    vbox->Add(m_ContainerNumText, 0, wxEXPAND | wxALL, 5);
    vbox->Add(m_StatusText, 0, wxEXPAND | wxALL, 5);
    vbox->Add(m_CurrentLocationText, 0, wxEXPAND | wxALL, 5);
    vbox->Add(m_TimeOfIssueText, 0, wxEXPAND | wxALL, 5);
    vbox->Add(m_ETAText, 0, wxEXPAND | wxALL, 5);

    this->SetSizer(vbox);

    // Event Bindings
    m_TrackButton->Bind(wxEVT_BUTTON, &ContainerTrackingWindow::onButtonClick, this);
}


// TODO: Add enum to retrieve shipping line information
// wtf is the current item switcher ? 
void ContainerTrackingWindow::onButtonClick(wxCommandEvent& event)
{
    wxString current_item = m_CarrierComboBox->GetValue();
    wxString containerNumber = m_ContainerNumberCtrl->GetValue();

    // Assuming 'common' is an instance of a class that handles tracking information
    // Replace with your actual logic to get container data
    current_item = "Cosco";
    if (current_item == "Cosco")
    {
        m_Carrier = &m_Cosco;
    }
    else if (current_item == "MSC")
    {
        m_Carrier = &m_MSC;
    }

    // ... Update other fields with actual data retrieved
    std::string contData = containerNumber.ToStdString();

    // Update text fields with information
    m_Carrier->requestContainerData(contData);
    m_ContainerNumText->SetLabel("Container Number: " + contData);
    m_StatusText->SetLabel("Status: " + static_cast<wxString>(m_Carrier->getStatusDescription().c_str()));
    m_CurrentLocationText->SetLabel("Location: " + static_cast<wxString>(m_Carrier->getLocation().c_str()));
    m_TimeOfIssueText->SetLabel("Time of Issue: " + static_cast<wxString>(m_Carrier->getTimeOfIssue().c_str()));
    m_ETAText->SetLabel("ETA: " + static_cast<wxString>(m_Carrier->getPodEta().c_str()));
}
