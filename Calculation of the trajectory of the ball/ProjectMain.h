/***************************************************************
 * Name:      ProjectMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2024-01-13
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef PROJECTMAIN_H
#define PROJECTMAIN_H

#include <wx/wx.h>


//(*Headers(ProjectDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class ProjectDialog: public wxDialog
{
    bool labelsVisible = false;
    public:

        ProjectDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~ProjectDialog();

    protected:
        double speed;
        double angle;
        double gravity;
        double value = 0.1;

    private:

        //(*Handlers(ProjectDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnPaint(wxPaintEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnSpinButton1Change(wxSpinEvent& event);
        void OnPanel1Resize(wxSizeEvent& event);
        void OnSpinCtrlDouble1Change(wxSpinDoubleEvent& event);
        //*)

        //(*Identifiers(ProjectDialog)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT4;
        static const long ID_SPINCTRLDOUBLE1;
        static const long ID_BUTTON1;
        static const long ID_PANEL1;
        static const long ID_TEXTCTRL4;
        //*)

        //(*Declarations(ProjectDialog)
        wxButton* Button1;
        wxPanel* Panel1;
        wxSpinCtrlDouble* SpinCtrlDouble1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl3;
        wxTextCtrl* TextCtrl4;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // PROJECTMAIN_H
