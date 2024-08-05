#include "CustomCalculatorWindow.h"

#include "CustomMath.h"

CustomCalculatorWindow::CustomCalculatorWindow(wxWindow* parent) : wxDialog(parent, wxID_ANY, "Custom Calculator", wxDefaultPosition, wxSize(600, 450)) {
    // Create controls
    m_CommodityPriceCtrl = new wxTextCtrl(this, wxID_ANY);
    m_FreightCtrl = new wxTextCtrl(this, wxID_ANY);
    m_CalculateBtn = new wxButton(this, wxID_ANY, "Calculate");
    m_MPFText = new wxStaticText(this, wxID_ANY, "");
    m_HMFText = new wxStaticText(this, wxID_ANY, "");
    m_TotalFreightText = new wxStaticText(this, wxID_ANY, "");

    // Layout using sizers
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(new wxStaticText(this, wxID_ANY, "Commodity Price (USD)"), 0, wxEXPAND | wxALL, 5);
    vbox->Add(m_CommodityPriceCtrl, 0, wxEXPAND | wxALL, 5);
    vbox->Add(new wxStaticText(this, wxID_ANY, "Freight"), 0, wxEXPAND | wxALL, 5);
    vbox->Add(m_FreightCtrl, 0, wxEXPAND | wxALL, 5);
    vbox->Add(m_CalculateBtn, 0, wxEXPAND | wxALL, 5);
    vbox->Add(m_MPFText, 0, wxEXPAND | wxALL, 5);
    vbox->Add(m_HMFText, 0, wxEXPAND | wxALL, 5);
    vbox->Add(m_TotalFreightText, 0, wxEXPAND | wxALL, 5);

    this->SetSizer(vbox);

    // Bind event
    m_CalculateBtn->Bind(wxEVT_BUTTON, &CustomCalculatorWindow::OnCalculate, this);
}

void CustomCalculatorWindow::OnCalculate(wxCommandEvent& event)
{
    float commodityPrice = wxAtof(m_CommodityPriceCtrl->GetValue());
    float freight = wxAtof(m_FreightCtrl->GetValue());

    float total = commodityPrice + freight;

    float mpf = calcMPFValue(total); // Implement this function
    float hmf = calcHMFValue(total); // Implement this function

    float totalFreight = freight + mpf + hmf;

    m_MPFText->SetLabel(wxString::Format("Customs MPF: %.2f", mpf));
    m_HMFText->SetLabel(wxString::Format("Customs HMF: %.2f", hmf));
    m_TotalFreightText->SetLabel(wxString::Format("Total Freight: %.2f", totalFreight));
}
