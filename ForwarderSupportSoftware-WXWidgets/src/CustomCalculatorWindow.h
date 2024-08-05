#ifndef CUSTOMCALCULATORWINDOW_H
#define CUSTOMCALCULATORWINDOW_H

#include <wx/wx.h>
#include <wx/notebook.h>

class CustomCalculatorWindow : public wxDialog
{
    public:
        CustomCalculatorWindow(wxWindow* parent);
    private:
        void OnCalculate(wxCommandEvent& event);
    private:
        wxStaticText* m_MPFText;
        wxStaticText* m_HMFText;
        wxStaticText* m_TotalFreightText;

        wxTextCtrl* m_CommodityPriceCtrl;
        wxTextCtrl* m_FreightCtrl;

        wxButton* m_CalculateBtn;
};

#endif // CUSTOMCALCULATORWINDOW_H