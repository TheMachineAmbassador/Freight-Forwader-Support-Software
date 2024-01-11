#include "CustomCalculatorWindow.h"

#include "CustomMath.h"

CustomCalculatorWindow::CustomCalculatorWindow(wxWindow* parent) : wxDialog(parent, wxID_ANY, "Custom Calculator", wxDefaultPosition, wxSize(600, 450)) {
    // Create controls
    commodityPriceCtrl = new wxTextCtrl(this, wxID_ANY);
    freightCtrl = new wxTextCtrl(this, wxID_ANY);
    calculateBtn = new wxButton(this, wxID_ANY, "Calculate");
    mpfText = new wxStaticText(this, wxID_ANY, "");
    hmfText = new wxStaticText(this, wxID_ANY, "");
    totalFreightText = new wxStaticText(this, wxID_ANY, "");

    // Layout using sizers
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(new wxStaticText(this, wxID_ANY, "Commodity Price (USD)"), 0, wxEXPAND | wxALL, 5);
    vbox->Add(commodityPriceCtrl, 0, wxEXPAND | wxALL, 5);
    vbox->Add(new wxStaticText(this, wxID_ANY, "Freight"), 0, wxEXPAND | wxALL, 5);
    vbox->Add(freightCtrl, 0, wxEXPAND | wxALL, 5);
    vbox->Add(calculateBtn, 0, wxEXPAND | wxALL, 5);
    vbox->Add(mpfText, 0, wxEXPAND | wxALL, 5);
    vbox->Add(hmfText, 0, wxEXPAND | wxALL, 5);
    vbox->Add(totalFreightText, 0, wxEXPAND | wxALL, 5);

    this->SetSizer(vbox);

    // Bind event
    calculateBtn->Bind(wxEVT_BUTTON, &CustomCalculatorWindow::OnCalculate, this);
}

void CustomCalculatorWindow::OnCalculate(wxCommandEvent& event)
{
    float commodityPrice = wxAtof(commodityPriceCtrl->GetValue());
    float freight = wxAtof(freightCtrl->GetValue());

    float total = commodityPrice + freight;

    float mpf = calcMPFValue(total); // Implement this function
    float hmf = calcHMFValue(total); // Implement this function

    float totalFreight = freight + mpf + hmf;

    mpfText->SetLabel(wxString::Format("Customs MPF: %.2f", mpf));
    hmfText->SetLabel(wxString::Format("Customs HMF: %.2f", hmf));
    totalFreightText->SetLabel(wxString::Format("Total Freight: %.2f", totalFreight));
}