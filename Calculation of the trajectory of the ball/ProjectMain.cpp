/***************************************************************
 * Name:      ProjectMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2024-01-13
 * Copyright:  ()
 * License:
 **************************************************************/

#include "ProjectMain.h"
#include <wx/msgdlg.h>
#include <wx/dcclient.h>
#include <cmath>
#include <algorithm>


#undef _
#define _(s) wxString::FromUTF8(s)

//(*InternalHeaders(ProjectDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(ProjectDialog)
const long ProjectDialog::ID_STATICTEXT1 = wxNewId();
const long ProjectDialog::ID_TEXTCTRL1 = wxNewId();
const long ProjectDialog::ID_STATICTEXT2 = wxNewId();
const long ProjectDialog::ID_TEXTCTRL2 = wxNewId();
const long ProjectDialog::ID_STATICTEXT3 = wxNewId();
const long ProjectDialog::ID_TEXTCTRL3 = wxNewId();
const long ProjectDialog::ID_STATICTEXT4 = wxNewId();
const long ProjectDialog::ID_SPINCTRLDOUBLE1 = wxNewId();
const long ProjectDialog::ID_BUTTON1 = wxNewId();
const long ProjectDialog::ID_PANEL1 = wxNewId();
const long ProjectDialog::ID_TEXTCTRL4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ProjectDialog,wxDialog)
    //(*EventTable(ProjectDialog)
    //*)
END_EVENT_TABLE()

ProjectDialog::ProjectDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(ProjectDialog)
    wxFlexGridSizer* FlexGridSizer10;
    wxFlexGridSizer* FlexGridSizer11;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer5;
    wxFlexGridSizer* FlexGridSizer6;
    wxFlexGridSizer* FlexGridSizer7;
    wxFlexGridSizer* FlexGridSizer8;
    wxFlexGridSizer* FlexGridSizer9;

    Create(parent, wxID_ANY, _("Trajektoria ukośnego rzutu  kuli z oporem powietrza"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(1, 3, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableRow(0);
    FlexGridSizer7 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer7->AddGrowableCol(1);
    FlexGridSizer7->AddGrowableRow(0);
    FlexGridSizer10 = new wxFlexGridSizer(2, 1, 0, 0);
    FlexGridSizer10->AddGrowableRow(0);
    FlexGridSizer2 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer2->AddGrowableCol(0);
    FlexGridSizer2->AddGrowableRow(0);
    FlexGridSizer4 = new wxFlexGridSizer(0, 2, 0, 0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("prędkość początkowa:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer4->Add(StaticText1, 1, wxALL|wxEXPAND, 5);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer4->Add(TextCtrl1, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer2->Add(FlexGridSizer4, 1, wxALL|wxALIGN_RIGHT, 5);
    FlexGridSizer5 = new wxFlexGridSizer(0, 2, 0, 0);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("kąt rzutu:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT2"));
    FlexGridSizer5->Add(StaticText2, 1, wxALL, 5);
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer5->Add(TextCtrl2, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer2->Add(FlexGridSizer5, 1, wxALL|wxALIGN_RIGHT, 5);
    FlexGridSizer6 = new wxFlexGridSizer(0, 3, 0, 0);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("przyspieszenie grawitacyjne:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer6->Add(StaticText3, 1, wxALL, 5);
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, _("9.81"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    FlexGridSizer6->Add(TextCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer6, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer11 = new wxFlexGridSizer(0, 3, 0, 0);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Współczynnik oporu"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer11->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlDouble1 = new wxSpinCtrlDouble(this, ID_SPINCTRLDOUBLE1, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 100, 0, 0.1, _T("ID_SPINCTRLDOUBLE1"));
    SpinCtrlDouble1->SetValue(_T("0"));
    FlexGridSizer11->Add(SpinCtrlDouble1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer10->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer8 = new wxFlexGridSizer(1, 1, 0, 0);
    FlexGridSizer8->AddGrowableCol(0);
    FlexGridSizer8->AddGrowableRow(0);
    Button1 = new wxButton(this, ID_BUTTON1, _("Rysuj"), wxDefaultPosition, wxSize(-1,100), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetMaxSize(wxSize(-1,-1));
    FlexGridSizer8->Add(Button1, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer10->Add(FlexGridSizer8, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer7->Add(FlexGridSizer10, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer3 = new wxFlexGridSizer(1, 1, 0, 0);
    FlexGridSizer3->AddGrowableCol(0);
    FlexGridSizer3->AddGrowableRow(0);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(576,418), wxBORDER_NONE|wxALWAYS_SHOW_SB|wxFULL_REPAINT_ON_RESIZE, _T("ID_PANEL1"));
    Panel1->SetFocus();
    FlexGridSizer3->Add(Panel1, 1, wxALL|wxEXPAND, wxDLG_UNIT(this,wxSize(5,0)).GetWidth());
    FlexGridSizer7->Add(FlexGridSizer3, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer9 = new wxFlexGridSizer(1, 1, 0, 0);
    FlexGridSizer9->AddGrowableRow(0);
    TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDLG_UNIT(this,wxSize(158,167)), wxTE_NO_VSCROLL|wxTE_MULTILINE|wxTE_READONLY|wxVSCROLL, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    FlexGridSizer9->Add(TextCtrl4, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer7->Add(FlexGridSizer9, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(FlexGridSizer7, 1, wxALL|wxEXPAND, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_SPINCTRLDOUBLE1,wxEVT_SPINCTRLDOUBLE,(wxObjectEventFunction)&ProjectDialog::OnSpinCtrlDouble1Change);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProjectDialog::OnButton1Click);
    Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ProjectDialog::OnPaint,0,this);
    Panel1->Connect(wxEVT_SIZE,(wxObjectEventFunction)&ProjectDialog::OnPanel1Resize,0,this);
    //*)

    SetIcon(wxICON(aaaa));
}

ProjectDialog::~ProjectDialog()
{
    //(*Destroy(ProjectDialog)
    //*)
}

void ProjectDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void ProjectDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}



void ProjectDialog::OnButton1Click(wxCommandEvent& event)
{
    // Pobierz dane z TextCtrl
    wxString speedStr = TextCtrl1->GetValue();
    wxString angleStr = TextCtrl2->GetValue();
    wxString gravityStr = TextCtrl3->GetValue();


    if (speedStr.ToDouble(&speed) && angleStr.ToDouble(&angle) && gravityStr.ToDouble(&gravity))
    {
        // Zapisz dane do zmiennych klasy
        this->speed = speed;
        this->angle = angle;
        this->gravity = gravity;
        labelsVisible = true;}
    else
    {
        // Sytuację, gdy konwersja nie powiedzie się
        wxMessageBox("Nieprawidlowe dane wejsciowe. Wprowadz liczby.", "Blad", wxICON_ERROR | wxOK);
    }

     Panel1->Refresh();
}



void ProjectDialog::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(Panel1);

    // Pobierz rozmiary Panel1
    wxCoord panelWidth, panelHeight;
    Panel1->GetSize(&panelWidth, &panelHeight);

    // Ustaw marginesy
    int margin = 30;

    // Rysowanie osi (opcjonalne, jeśli nie zostały już narysowane wcześniej)
    dc.DrawLine(margin, panelHeight - margin, panelWidth - margin, panelHeight - margin); // Oś X
    dc.DrawText( "x" , panelWidth - margin+4, panelHeight-margin);
    dc.DrawLine(margin, margin, margin, panelHeight - margin); // Oś Y
    dc.DrawText( "y" , margin/1.5 , margin/3);

    double angleRad = angle * M_PI / 180.0;


    // Początkowe punkty trajektorii
    double x_prev = margin;
    double y_prev = panelHeight - margin;
    double max_x;
    double max_y;

    double m = 3.145;
    double r,r1;

    r = value/m;
    r1 = m*speed/value;


    double co = cos(angleRad);
    double si = sin(angleRad);

    double t = 0;
    double dt = 0.02;

    double x,y;
    // Pętla while do obliczeń i wyświetlania trajektorii
        while (t <= 1000) {
        x = margin +(r1*co*(1-exp(-r*t)));
        y = panelHeight - ((r1*si+gravity/(r*r))*(1-exp(-r*t))-gravity*t/r)-margin ;

        if( y<y_prev)
            max_y = panelHeight- y_prev;

        t += dt;  // zaktualizuj czas

        if (y >= panelHeight - margin + 1) {
            break;
        }
        x_prev = x;
        y_prev = y;
        max_x = x;
    }

    double XScale = (panelWidth-100)/max_x;
    double YScale = (panelHeight-40)/max_y;

    t = 0;
     x = margin;
     y = panelHeight - margin;
     x_prev = margin;
     y_prev = panelHeight - margin;
    while (t<= 1000){
         x = margin + XScale * ((r1*co*(1-exp(-r*t))));
         y = panelHeight - YScale*((r1*si+gravity/(r*r))*(1-exp(-r*t))-gravity*t/r)-margin ;

        if( y<y_prev)
            max_y = panelHeight- y_prev;

        t += dt;  // zaktualizuj czas

        wxCoord x1 = static_cast<wxCoord>(x_prev);
        wxCoord y1 = static_cast<wxCoord>(y_prev);
        wxCoord x2 = static_cast<wxCoord>(x);
        wxCoord y2 = static_cast<wxCoord>(y);

        if (y >= panelHeight - margin + 1) {
            break;
        }

        dc.DrawLine(x1, y1, x2, y2);

        x_prev = x;
        y_prev = y;
        max_x = x;
    }


  if (labelsVisible){
    TextCtrl4->WriteText(wxT("\nPrędkość: "));
    TextCtrl4->WriteText( std::to_string(speed));
    TextCtrl4->WriteText(wxT("\nKąt: "));
    TextCtrl4->WriteText(std::to_string(angle));
    TextCtrl4->WriteText(wxT("\nGravitacja: "));
    TextCtrl4->WriteText(std::to_string(gravity));
    TextCtrl4->WriteText(wxT("\nWspółczynnik oporu powietrza: "));
    TextCtrl4->WriteText( std::to_string(value));
    TextCtrl4->WriteText(wxT("\nCzas: "));
    TextCtrl4->WriteText(std::to_string(t));
    TextCtrl4->WriteText(wxT("\nZasięg rzutu: "));
    TextCtrl4->WriteText(std::to_string(max_x/XScale));
    TextCtrl4->WriteText(wxT("\nMaksymalna wysokość: "));
    TextCtrl4->WriteText(std::to_string(max_y/YScale));
    TextCtrl4->WriteText("\n\n");


    dc.DrawText(wxString::Format(wxT("%.1f"), max_y/YScale), 2 , panelHeight - max_y-6 );
    dc.DrawText(wxString::Format(wxT("%.1f"), max_x/XScale), max_x-6, panelHeight - margin+3);
  }
}




void ProjectDialog::OnPanel1Resize(wxSizeEvent& event)
{

}

void ProjectDialog::OnSpinCtrlDouble1Change(wxSpinDoubleEvent& event)
{
    value = 0;
    value = SpinCtrlDouble1->GetValue();

    SpinCtrlDouble1 -> SetLabel(std::to_string(value));
    SpinCtrlDouble1 -> Refresh();
    Panel1 -> Refresh();
}
