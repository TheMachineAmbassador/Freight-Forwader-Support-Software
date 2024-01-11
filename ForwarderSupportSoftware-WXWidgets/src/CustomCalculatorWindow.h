#ifndef CUSTOMCALCULATORWINDOW_H
#define CUSTOMCALCULATORWINDOW_H

#include <wx/wx.h>
#include <wx/notebook.h>

class CustomCalculatorWindow : public wxDialog {
private:
    wxTextCtrl* commodityPriceCtrl;
    wxTextCtrl* freightCtrl;
    wxButton* calculateBtn;
    wxStaticText* mpfText;
    wxStaticText* hmfText;
    wxStaticText* totalFreightText;

public:
    CustomCalculatorWindow(wxWindow* parent);

private:
    void OnCalculate(wxCommandEvent& event);
};

#endif