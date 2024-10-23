/***************************************************************
 * Name:      ProjectApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2024-01-13
 * Copyright:  ()
 * License:
 **************************************************************/

#include "ProjectApp.h"

//(*AppHeaders
#include "ProjectMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ProjectApp);

bool ProjectApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	ProjectDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
