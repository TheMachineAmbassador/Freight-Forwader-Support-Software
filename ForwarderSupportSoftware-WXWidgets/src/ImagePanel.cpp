#include "ImagePanel.h"

wxBEGIN_EVENT_TABLE(ImagePanel, wxPanel)
EVT_PAINT(ImagePanel::OnPaint)
EVT_SIZE(ImagePanel::OnSize)
wxEND_EVENT_TABLE()

ImagePanel::ImagePanel(wxFrame* parent) : wxPanel(parent), originalImage(d2e5e1d938844846c1a0711d0b58e01bpL0jCD07kggAOWzH) {
    //RescaleImage(GetClientSize()); // Initial scaling
}


void ImagePanel::OnPaint(wxPaintEvent& event) {
    wxPaintDC dc(this);
    if (resizedBitmap.IsOk()) {
        dc.DrawBitmap(resizedBitmap, 0, 0, true);
    }
}

void ImagePanel::RescaleImage(const wxSize& newSize) {
    if (originalImage.IsOk()) {
        wxImage scaledImage = originalImage.Scale(newSize.GetWidth(), newSize.GetHeight(), wxIMAGE_QUALITY_HIGH);
        resizedBitmap = wxBitmap(scaledImage);
    }
}

void ImagePanel::OnSize(wxSizeEvent& event) {
    RescaleImage(GetClientSize());
    Refresh();  // Redraw the panel
}
