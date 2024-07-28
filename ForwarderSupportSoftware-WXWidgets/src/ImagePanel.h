#ifndef IMAGEPANEL_H
#define IMAGEPANEL_H

#include <wx/wx.h>

class ImagePanel : public wxPanel
{
    public:
        ImagePanel(wxFrame* parent, const wxString& imagePath);
    private:
        void OnPaint(wxPaintEvent& event);
        void OnSize(wxSizeEvent& event);
        void RescaleImage(const wxSize& newSize);

        wxDECLARE_EVENT_TABLE();
    private:
        wxBitmap m_ResizedBitmap;
        wxImage m_OriginalImage; // Store the original image
};

#endif // IMAGEPANEL_H
