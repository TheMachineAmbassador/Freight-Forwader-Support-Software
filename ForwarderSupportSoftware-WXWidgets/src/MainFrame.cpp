#include "MainFrame.h"
#include "ImagePanel.h"

#include "AddCopiedStringWindow.h" 
#include "CustomCalculatorWindow.h" 
#include "ContainerTrackingWindow.h"
#include "FreightCalculateWindow.h" 


MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(550, 500), wxMINIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN) {
    wxSize fixedSize = wxSize(550, 500);
    this->SetSize(fixedSize);
    this->SetMinSize(fixedSize);
    this->SetMaxSize(fixedSize);
    
    ////////////////////// TOP BAR SECTION ////////////////////////////////////////////////

    // Topbar buttons
    wxMenuBar* menuBar = new wxMenuBar;

    // Setting up "Menu" button's items
    wxMenu* fileMenu = new wxMenu;
    fileMenu->Append(wxID_ANY, "&Calculate Freight");
    fileMenu->Append(wxID_ANY, "&Calculate Customs");
    fileMenu->Append(wxID_ANY, "&Container Tracking");
    fileMenu->Append(wxID_ANY, "&Calculate Copied Texts");
    // Multiple Mail sender : Just planned to do 
    // fileMenu->Append(wxID_ANY, "&Multiple mail"); 

    // Setting up "About" button's items
    wxMenu* helpMenu = new wxMenu;
    helpMenu->Append(wxID_ABOUT, "About\tF1", "About");

    menuBar->Append(fileMenu, "&Start");
    menuBar->Append(helpMenu, "&Help");

    SetMenuBar(menuBar);

    ////////////////////// TOP BAR SECTION END /////////////////////////////////////////////

    // TOP BAR "START" BUTTON ITEM EVENTS
    Bind(wxEVT_MENU, &MainFrame::OnOpenFreightCalculation,  this,       fileMenu->FindItem("&Calculate Freight"));
    Bind(wxEVT_MENU, &MainFrame::OnOpenContainerTracking,   this,       fileMenu->FindItem("&Container Tracking"));
    Bind(wxEVT_MENU, &MainFrame::OnOpenAddCopiedString,     this,       fileMenu->FindItem("&Calculate Copied Texts"));
    Bind(wxEVT_MENU, &MainFrame::OnOpenCustomCalculator,    this,       fileMenu->FindItem("&Calculate Customs"));

    // TOB BAR "HELP" BUTTON ITEM EVENTS 
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, helpMenu->FindItem("&About"));
    

    /////////////////////////////////////////////////////////////////////////////////////
    // Create an ImagePanel and add it to the frame
    #ifndef DEBUG
        ImagePanel* imagePanel = new ImagePanel(this);
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(imagePanel, 1, wxEXPAND | wxALL);
        SetSizer(sizer);
    #endif // DEBUG
    ////////////////////////////////////////////////////////////////////////////////////

    AdjustFontForDPI(this);
}

void MainFrame::OnOpenFreightCalculation(wxCommandEvent& event)
{
    FreightCalculateWindow* seaWindow = new FreightCalculateWindow(this);
    seaWindow->Show();
}

void MainFrame::OnOpenAddCopiedString(wxCommandEvent& event)
{
    AddCopiedStringWindow* copiedString = new AddCopiedStringWindow(this);
    copiedString->Show();
}

void MainFrame::OnOpenCustomCalculator(wxCommandEvent& event)
{
    CustomCalculatorWindow* customCalcWindow = new CustomCalculatorWindow(this);
    customCalcWindow->Show();
}

void MainFrame::OnOpenContainerTracking(wxCommandEvent& event)
{
    ContainerTrackingWindow* contTracking = new ContainerTrackingWindow(this);
    contTracking->Show();
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("Copyright (c) 2024 Can Albayrak",
        "About Forwarder Support Software", wxOK | wxICON_INFORMATION);
}


void MainFrame::AdjustFontForDPI(wxWindow* window) {
    float scaleFactor = GetContentScaleFactor();
    wxFont font = window->GetFont();
    font.SetPointSize(static_cast<int>(font.GetPointSize() * scaleFactor));
    window->SetFont(font);

    // Recursively adjust font for child windows
    wxWindowList& children = window->GetChildren();
    for (wxWindowList::iterator it = children.begin(); it != children.end(); ++it) {
        AdjustFontForDPI(*it);
    }

}
