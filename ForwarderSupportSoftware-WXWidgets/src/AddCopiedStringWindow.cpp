#include "AddCopiedStringWindow.h"

AddCopiedStringWindow::AddCopiedStringWindow(wxWindow* parent)
    : wxDialog(parent, wxID_ANY, "Add Copied String", wxDefaultPosition, wxSize(600, 450)) {
    // Create fields
    textCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(0, 100), wxTE_MULTILINE);
    resultText = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY  | wxBORDER_NONE);

    // Set Vertical Box Sizer for positioning elements
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(textCtrl, 0, wxEXPAND | wxALL, 5);
    vbox->Add(resultText, 1, wxEXPAND | wxALL, 5);

    // Set sizer    
    this->SetSizer(vbox);

    // Bind event handlers
    textCtrl->Bind(wxEVT_TEXT, &AddCopiedStringWindow::OnTextChanged, this);
}

void AddCopiedStringWindow::OnTextChanged(wxCommandEvent& event) {
    wxString inputText = textCtrl->GetValue();

    // Use strncpy to copy the text to inputBuffer
    wxString textFromControl = textCtrl->GetValue();

    strncpy(add.inputBuffer, textFromControl.mb_str(wxConvUTF8), sizeof(add.inputBuffer) - 1);

    add.addCopiedTexts();
    wxString DATA(add.resultStr.c_str(), wxConvUTF8);

    resultText->SetValue(DATA);
}
