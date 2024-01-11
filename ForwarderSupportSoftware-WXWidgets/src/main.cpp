#include "MainFrame.h"
#include <wx/app.h>

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    wxImage::AddHandler(new wxPNGHandler);

    MainFrame* frame = new MainFrame("Forwarder Support Software | Beta Build 0.2.4 | Kod-adý: Crocus |");
    frame->Show(true);
    return true;
}
