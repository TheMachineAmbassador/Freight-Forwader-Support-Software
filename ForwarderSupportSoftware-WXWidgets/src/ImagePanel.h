#ifndef IMAGEPANEL_H
#define IMAGEPANEL_H

#include <wx/wx.h>
#include "background.xpm"  // Include the XPM file

class ImagePanel : public wxPanel {
public:
    ImagePanel(wxFrame* parent);

private:
    wxBitmap resizedBitmap;
    wxImage originalImage; // Store the original image
    void OnPaint(wxPaintEvent& event);
    void RescaleImage(const wxSize& newSize);
    void OnSize(wxSizeEvent& event);

    wxDECLARE_EVENT_TABLE();
};

#endif // IMAGEPANEL_H
