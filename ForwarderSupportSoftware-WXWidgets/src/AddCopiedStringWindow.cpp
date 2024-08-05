#include "AddCopiedStringWindow.h"

AddCopiedStringWindow::AddCopiedStringWindow(wxWindow* parent)
    : wxDialog(parent, wxID_ANY, "Add Copied String", wxDefaultPosition, wxSize(600, 450)) {

    // Create fields
    m_TextCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(0, 100), wxTE_MULTILINE);
    m_TextCtrl->SetMaxLength(sizeof(m_Add.m_InputBuffer));

    m_ResultText = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY | wxBORDER_NONE);

    // Set Vertical Box Sizer for positioning elements
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(m_TextCtrl, 0, wxEXPAND | wxALL, 5);
    vbox->Add(m_ResultText, 1, wxEXPAND | wxALL, 5);

    // Set sizer    
    this->SetSizer(vbox);

    // Bind event handlers
    m_TextCtrl->Bind(wxEVT_TEXT, &AddCopiedStringWindow::OnTextChanged, this);
}

void AddCopiedStringWindow::OnTextChanged(wxCommandEvent& event) {
    wxString inputText = m_TextCtrl->GetValue();

    // Use strncpy to copy the text to inputBuffer
    wxString textFromControl = m_TextCtrl->GetValue();

    strncpy(m_Add.m_InputBuffer, textFromControl.mb_str(wxConvUTF8), sizeof(m_Add.m_InputBuffer) - 1);

    m_Add.addCopiedTexts();
    wxString DATA(m_Add.m_ResultStr.c_str(), wxConvUTF8);

    m_ResultText->SetValue(DATA);
}
