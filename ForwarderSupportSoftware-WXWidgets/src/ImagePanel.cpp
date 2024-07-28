#include "ImagePanel.h"

wxBEGIN_EVENT_TABLE(ImagePanel, wxPanel)
EVT_PAINT(ImagePanel::OnPaint)
EVT_SIZE(ImagePanel::OnSize)
wxEND_EVENT_TABLE()

ImagePanel::ImagePanel(wxFrame* parent, const wxString& imagePath)
    : wxPanel(parent)
{
    // Initialize image handlers
    wxInitAllImageHandlers();

    // Attempt to load the image file
    if (!m_OriginalImage.LoadFile(imagePath, wxBITMAP_TYPE_JPEG)) {
        wxLogError("Could not load the image from the specified file: %s", imagePath);
    }
    RescaleImage(GetClientSize()); // Initial scaling
}

void ImagePanel::OnPaint(wxPaintEvent& event) {
    wxPaintDC dc(this);
    if (m_ResizedBitmap.IsOk()) {
        dc.DrawBitmap(m_ResizedBitmap, 0, 0, true);
    }
}

void ImagePanel::RescaleImage(const wxSize& newSize) {
    if (m_OriginalImage.IsOk()) {
        wxImage scaledImage = m_OriginalImage.Scale(newSize.GetWidth(), newSize.GetHeight(), wxIMAGE_QUALITY_HIGH);
        m_ResizedBitmap = wxBitmap(scaledImage);
    }
}

void ImagePanel::OnSize(wxSizeEvent& event) {
    RescaleImage(GetClientSize());
    Refresh();  // Redraw the panel
}