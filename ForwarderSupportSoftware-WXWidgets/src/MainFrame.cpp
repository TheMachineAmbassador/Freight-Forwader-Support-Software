#include "MainFrame.h"
#include "ImagePanel.h"

#include <wx/msw/registry.h>

#include "wx/webrequest.h"
#include "wx/event.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(550, 500), wxMINIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN) {
    wxSize fixedSize = wxSize(550, 500);
    this->SetSize(fixedSize);
    this->SetMinSize(fixedSize);
    this->SetMaxSize(fixedSize);
    
    // Menu bar
    wxMenuBar* menuBar = new wxMenuBar;

    wxMenu* fileMenu = new wxMenu;
    fileMenu->Append(wxID_ANY, "&Calculate Freight");
    fileMenu->Append(wxID_ANY, "&Calculate Customs");
    fileMenu->Append(wxID_ANY, "&Container Tracking");
    fileMenu->Append(wxID_ANY, "&Calculate Copied Texts");
    /*
    * // Just planned to do
    fileMenu->Append(wxID_ANY, "&Multiple mail");
    */
    menuBar->Append(fileMenu, "&Menu");

    // About menu
    wxMenu* helpMenu = new wxMenu;
    helpMenu->Append(wxID_ABOUT, "About\tF1", "About");
    menuBar->Append(helpMenu, "&Help");

    SetMenuBar(menuBar);
    
    // Bind events
    Bind(wxEVT_MENU, &MainFrame::OnOpenFreightCalculation, this, fileMenu->FindItem("&Calculate Freight"));
    Bind(wxEVT_MENU, &MainFrame::OnOpenContainerTracking, this, fileMenu->FindItem("&Container Tracking"));
    Bind(wxEVT_MENU, &MainFrame::OnOpenAddCopiedString, this, fileMenu->FindItem("&Calculate Copied Texts"));
    Bind(wxEVT_MENU, &MainFrame::OnOpenCustomCalculator, this, fileMenu->FindItem("&Calculate Customs"));

    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, helpMenu->FindItem("&About"));
    

    /////////////////////////////////////////////////////////////////////////////////////
    // Create an ImagePanel and add it to the frame
    ImagePanel* imagePanel = new ImagePanel(this);
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(imagePanel, 1, wxEXPAND | wxALL);
    SetSizer(sizer);
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
