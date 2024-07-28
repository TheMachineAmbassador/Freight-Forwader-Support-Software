#pragma once

#include <wx/wx.h>

inline float GetTextCtrlValueAsFloat(wxTextCtrl*& textCtrl) {
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

inline float GetTextCtrlValueAsInt(wxTextCtrl*& textCtrl) {
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
