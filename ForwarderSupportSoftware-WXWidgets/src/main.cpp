#include "MainFrame.h"
#include <wx/app.h>

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    wxImage::AddHandler(new wxPNGHandler);

    MainFrame* frame = new MainFrame("Forwarder Support Software");
    frame->Show(true);
    return true;
}
