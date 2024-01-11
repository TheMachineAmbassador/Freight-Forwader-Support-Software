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

        wxMessageBox("Bu program �i�dem Topal ad�na do�um g�n�ne �zel olarak derlenmi�tir.Bu k�sma uzun uzad�ya bir�eyler yazmak isterdim ancak �ok bi manas� olur mu bilemedim. Sonu�ta okumayacaks�n :). A�a��daki g�rd���n iki �zellik d���nda di�er �zellikleri a�mad�m ��nk� g�c���m biliyorsun. Tabii i�in �akas� �zellikler tam olarak d�zg�n �al���p �al��mad�klar�na emin olamad�m o y�zden riske atmak istemedim. \n \nKovulduktan sonra gelen k���k bi ek yaz�: Bitmek bilmeyecek ko�u�turmalar flan derken art�k �ok daha nadir g�r��ebilece�imizden dolay� ve do�um g�n�n� de hesaba katarsak, kod ad�n� isminden ilham alarak verdi�im bu �zel s�r�m�n sende kalmas� benim i�in anlaml� olacakt�r. S�zde k�sa kescem demi�tim ama yine roman yazd�m. ��in k�sas� mutlu y�llar, hayat�nda her daim ba�ar�lar dilerim.  \n \nNot: Bu mesaj kutusu her bilgisayar i�in sadece 1 kere g�r�necek olup, program�n kimseyle payla��lmamas� �nemle rica olunur.\n \nA��k olan men�ler;\n 1-) Navlun Hesaplama: Aktif (Biraz daha ge� do�sayd�n karayolu hesaplama da olacakt�) \n 2-) G�mr�kleme Hesaplama: Aktif"
            , "Do�um g�n�n kutlu olsun :)", wxOK | wxICON_INFORMATION);
        // Show your dialog or perform your action for new users

        userKey.SetValue("IsNewUser", 0L); // Update the registry value to indicate the user is no longer new
    }
    checkit = isComputerBanned == 1;
    if (checkit == true)
    {
        wxMessageBox("�zinsiz kullan�m modu a��ld� program kendi kendini kapatacakt�r!!!",
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
    fileMenu->Append(wxID_ANY, "&G�mr�kleme Hesaplama");
    fileMenu->Append(wxID_ANY, "&Konteyner Takip");
    fileMenu->Append(wxID_ANY, "&Kopyalanan Yaz�lar� Topla");
    fileMenu->Append(wxID_ANY, "&Toplu Mail");
    menuBar->Append(fileMenu, "&Menu");

    // About menu
    wxMenu* helpMenu = new wxMenu;
    helpMenu->Append(wxID_ABOUT, "Hakk�nda\tF1", "Hakk�nda");
    menuBar->Append(helpMenu, "&Help");

    SetMenuBar(menuBar);
    
#if NORMAL_SURUM
    // Bind events
    Bind(wxEVT_MENU, &MainFrame::OnOpenFreightCalculation, this, fileMenu->FindItem("&Navlun Hesaplama"));
    Bind(wxEVT_MENU, &MainFrame::OnOpenContainerTracking, this, fileMenu->FindItem("&Konteyner Takip"));
    Bind(wxEVT_MENU, &MainFrame::OnOpenAddCopiedString, this, fileMenu->FindItem("&Kopyalanan Yaz�lar� Topla"));
    Bind(wxEVT_MENU, &MainFrame::OnOpenCustomCalculator, this, fileMenu->FindItem("&G�mr�kleme Hesaplama"));
#elif CIGDEM_SURUM
    Bind(wxEVT_MENU, &MainFrame::OnOpenFreightCalculation, this, fileMenu->FindItem("&Navlun Hesaplama"));
    Bind(wxEVT_MENU, &MainFrame::OnDemo, this, fileMenu->FindItem("&Konteyner Takip"));
    Bind(wxEVT_MENU, &MainFrame::OnDemo, this, fileMenu->FindItem("&Kopyalanan Yaz�lar� Topla"));
    Bind(wxEVT_MENU, &MainFrame::OnOpenCustomCalculator, this, fileMenu->FindItem("&G�mr�kleme Hesaplama"));
    Bind(wxEVT_MENU, &MainFrame::OnDemo, this, fileMenu->FindItem("&Toplu Mail"));
#endif
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, helpMenu->FindItem("&Hakk�nda"));
    

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
    wxMessageBox("Onu kullanm�yoruz :) \n A��k olan men�ler;\n 1-) Navlun Hesaplama: Aktif \n 2-) G�mr�kleme Hesaplama: Aktif"
        
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
    wxMessageBox("Copyright (C) TMA Software - All Rights Reserved 2021-2024 \n Sosyal medya ula��m ara�lar�m�z; \nWebsite: https://themachineambassador.github.io/ (#Paraya k�y�p sunucu al!!!)\nInstagram: @tmayazilim \nEmail: tmayazilimdestek@outlook.com (#Sunucu alabilirsen maili de kuruver bizahmet)",
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
