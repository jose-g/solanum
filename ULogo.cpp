//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "ULogo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmLogo *frmLogo;
//---------------------------------------------------------------------------
__fastcall TfrmLogo::TfrmLogo(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmLogo::cmdContinueClick(TObject *Sender)
{
//this->Visible=false;
//frmMainPG->Visible=true;
//frmMenu->Visible=true;
//CrearFormulariofrmMainPG();
//CrearFormulariofrmMenu();
this->Visible=false;
}
//---------------------------------------------------------------------------
void TfrmLogo::CrearFormulariofrmMainPG()
{
  frmMainPG=new TfrmMainPG(this);
  frmLogo->Visible=false;
  frmMainPG->ShowModal();
}
//---------------------------------------------------------------------------
void TfrmLogo::CrearFormulariofrmMenu()
{
  frmMenu=new TfrmMenu(this);
  frmLogo->Visible=false;
  frmMenu->Visible=true;
}
//---------------------------------------------------------------------------
void TfrmLogo::TerminarAplicacion()
{
  if(frmMainPG!=NULL)
  {
    delete frmMainPG;
    frmMainPG=NULL;
  }
  if(frmMenu!=NULL)
  {
    delete frmMenu;
    frmMenu=NULL;
  }
  Close();
}
//---------------------------------------------------------------------------


