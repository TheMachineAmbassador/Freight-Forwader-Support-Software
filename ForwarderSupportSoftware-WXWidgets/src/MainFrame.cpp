#include "MainFrame.h"
#include "ImagePanel.h"
#include "icon.xpm"

#include <wx/msw/registry.h>

#include "wx/webrequest.h"
#include "wx/event.h"

#define NORMAL_SURUM 1
#define CIGDEM_SURUM 0

bool checkit = false;

long isComputerBanned;
// Registry key where you store the flag
const wxString userKeyPath = "HKEY_CURRENT_USER\\Software\\ForwarderSupportSoftware\\Settings";
wxRegKey userKey(userKeyPath);

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(550, 500), wxMINIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN) {

#if CIGDEM_SURUM

    wxWebRequest request = wxWebSession::GetDefault().CreateRequest(this, "https://raw.githubusercontent.com/TheMachineAmbassador/TheMachineAmbassador.github.io/master/css/selfdestruct.txt");
    // Bind the event at the frame level
    Bind(wxEVT_WEBREQUEST_STATE, &MainFrame::OnWebRequestCompleted, this, request.GetId());
    request.Start();

    // Check if the user is new
    long isNewUserLong = 0; // Use a long to store the registry value
    if (userKey.Exists())
    {
        userKey.QueryValue("IsNewUser", &isNewUserLong);
        userKey.QueryValue("IsComputerBanned", &isComputerBanned);
    }
     else {
     // Create the key if it doesn't exist
     userKey.Create();
     isNewUserLong = 1; // Default to true (new user)
    }

    bool isNewUser = isNewUserLong != 0; // Convert to bool

    if (isNewUser) {

        wxMessageBox("Bu program Çiðdem Topal adýna doðum gününe özel olarak derlenmiþtir.Bu kýsma uzun uzadýya birþeyler yazmak isterdim ancak çok bi manasý olur mu bilemedim. Sonuçta okumayacaksýn :). Aþaðýdaki gördüðün iki özellik dýþýnda diðer özellikleri açmadým çünkü gýcýðým biliyorsun. Tabii iþin þakasý özellikler tam olarak düzgün çalýþýp çalýþmadýklarýna emin olamadým o yüzden riske atmak istemedim. \n \nKovulduktan sonra gelen küçük bi ek yazý: Bitmek bilmeyecek koþuþturmalar flan derken artýk çok daha nadir görüþebileceðimizden dolayý ve doðum gününü de hesaba katarsak, kod adýný isminden ilham alarak verdiðim bu özel sürümün sende kalmasý benim için anlamlý olacaktýr. Sözde kýsa kescem demiþtim ama yine roman yazdým. Ýþin kýsasý mutlu yýllar, hayatýnda her daim baþarýlar dilerim.  \n \nNot: Bu mesaj kutusu her bilgisayar için sadece 1 kere görünecek olup, programýn kimseyle paylaþýlmamasý önemle rica olunur.\n \nAçýk olan menüler;\n 1-) Navlun Hesaplama: Aktif (Biraz daha geç doðsaydýn karayolu hesaplama da olacaktý) \n 2-) Gümrükleme Hesaplama: Aktif"
            , "Doðum günün kutlu olsun :)", wxOK | wxICON_INFORMATION);
        // Show your dialog or perform your action for new users

        userKey.SetValue("IsNewUser", 0L); // Update the registry value to indicate the user is no longer new
    }
    checkit = isComputerBanned == 1;
    if (checkit == true)
    {
        wxMessageBox("Ýzinsiz kullaným modu açýldý program kendi kendini kapatacaktýr!!!",
            "Hata", wxOK | wxICON_ERROR);
        this->Close(true);
    }

#endif
    wxSize fixedSize = wxSize(550, 500);
    this->SetSize(fixedSize);
    this->SetMinSize(fixedSize);
    this->SetMaxSize(fixedSize);
    this->SetIcon(hello_icon);
    
    // Menu bar
    wxMenuBar* menuBar = new wxMenuBar;

    wxMenu* fileMenu = new wxMenu;
    fileMenu->Append(wxID_ANY, "&Navlun Hesaplama");
    fileMenu->Append(wxID_ANY, "&Gümrükleme Hesaplama");
    fileMenu->Append(wxID_ANY, "&Konteyner Takip");
    fileMenu->Append(wxID_ANY, "&Kopyalanan Yazýlarý Topla");
    fileMenu->Append(wxID_ANY, "&Toplu Mail");
    menuBar->Append(fileMenu, "&Menu");

    // About menu
    wxMenu* helpMenu = new wxMenu;
    helpMenu->Append(wxID_ABOUT, "Hakkýnda\tF1", "Hakkýnda");
    menuBar->Append(helpMenu, "&Help");

    SetMenuBar(menuBar);
    
#if NORMAL_SURUM
    // Bind events
    Bind(wxEVT_MENU, &MainFrame::OnOpenFreightCalculation, this, fileMenu->FindItem("&Navlun Hesaplama"));
    Bind(wxEVT_MENU, &MainFrame::OnOpenContainerTracking, this, fileMenu->FindItem("&Konteyner Takip"));
    Bind(wxEVT_MENU, &MainFrame::OnOpenAddCopiedString, this, fileMenu->FindItem("&Kopyalanan Yazýlarý Topla"));
    Bind(wxEVT_MENU, &MainFrame::OnOpenCustomCalculator, this, fileMenu->FindItem("&Gümrükleme Hesaplama"));
#elif CIGDEM_SURUM
    Bind(wxEVT_MENU, &MainFrame::OnOpenFreightCalculation, this, fileMenu->FindItem("&Navlun Hesaplama"));
    Bind(wxEVT_MENU, &MainFrame::OnDemo, this, fileMenu->FindItem("&Konteyner Takip"));
    Bind(wxEVT_MENU, &MainFrame::OnDemo, this, fileMenu->FindItem("&Kopyalanan Yazýlarý Topla"));
    Bind(wxEVT_MENU, &MainFrame::OnOpenCustomCalculator, this, fileMenu->FindItem("&Gümrükleme Hesaplama"));
    Bind(wxEVT_MENU, &MainFrame::OnDemo, this, fileMenu->FindItem("&Toplu Mail"));
#endif
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, helpMenu->FindItem("&Hakkýnda"));
    

    /////////////////////////////////////////////////////////////////////////////////////
    // Create an ImagePanel and add it to the frame
    //ImagePanel* imagePanel = new ImagePanel(this, "C://Users/karus/Desktop/can-software/bin/windows-Release/tma-background.png.bak");
    ImagePanel* imagePanel = new ImagePanel(this);
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(imagePanel, 1, wxEXPAND | wxALL);
    SetSizer(sizer);
    ////////////////////////////////////////////////////////////////////////////////////

    AdjustFontForDPI(this);
}

#if CIGDEM_SURUM
static void selfDelete() {
    
    //char selfPath[MAX_PATH];
    //GetModuleFileNameA(NULL, selfPath, MAX_PATH); // Get the executable's path

    //std::string batFileName = std::string(std::tmpnam(nullptr)) + ".bat"; // Temporary name for the batch file

    //std::ofstream batFile(batFileName);
    //if (!batFile.is_open()) {
    //    std::cerr << "Failed to create batch file for self-deletion." << std::endl;
    //    return;
    //}

    //// Write the batch script
    //batFile << "@echo off\n"
    //    << ":retry\n"
    //    << "del \"" << selfPath << "\"\n"
    //    << "if exist \"" << selfPath << "\" goto retry\n"
    //    << "del \"%~f0\"\n"; // %~f0 refers to the batch file itself
    //batFile.close();

    //// Execute the batch file
    //ShellExecuteA(NULL, "open", batFileName.c_str(), NULL, NULL, SW_HIDE);
}

void MainFrame::OnWebRequestCompleted(wxWebRequestEvent& evt)
{
    if (evt.GetResponse().IsOk())
    {
        wxString response = evt.GetResponse().AsString();
        if (response.Contains("selfdestruct = true;"))
        {            
            //selfDelete();
            userKey.SetValue("IsComputerBanned", 1L); // Update the registry value to indicate the user is no longer new
            checkit = true;

        }
        else if (response.Contains("selfdestruct = false;"))
        {
            checkit = false;

            userKey.SetValue("IsComputerBanned", 0L); // Update the registry value to indicate the user is no longer 
        }
    }
}


void MainFrame::OnDemo(wxCommandEvent& event)
{
    wxMessageBox("Onu kullanmýyoruz :) \n Açýk olan menüler;\n 1-) Navlun Hesaplama: Aktif \n 2-) Gümrükleme Hesaplama: Aktif"
        
        , "Hata",wxOK | wxICON_INFORMATION);
}
#endif

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
    wxMessageBox("Copyright (C) TMA Software - All Rights Reserved 2021-2024 \n Sosyal medya ulaþým araçlarýmýz; \nWebsite: https://themachineambassador.github.io/ (#Paraya kýyýp sunucu al!!!)\nInstagram: @tmayazilim \nEmail: tmayazilimdestek@outlook.com (#Sunucu alabilirsen maili de kuruver bizahmet)",
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
