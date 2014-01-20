//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UMenuBorrar.h"
#include "ULogoBorrar.h"
//#include "UMainAM.h"
#include "UMainPGBorrar.h"
//#include "UMainDS.h"
//#include "UMainNS.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMenu *frmMenu;
TfrmMainPG* MainPG;
//DS::TfrmMainDS* MainDS;
//NS::TfrmMainNS* MainNS;
//TfrmMainAM* MainAM;
//---------------------------------------------------------------------------
__fastcall TfrmMenu::TfrmMenu(TComponent* Owner)
        : TForm(Owner)
{
TfrmLogo* frm=new TfrmLogo(this);
frm->ShowModal();
accion=frm->ModalResult;
if(frm!=NULL)
{
  delete frm;
  frm=NULL;
}
cargo=false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMenu::cmdExitClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMenu::FormShow(TObject *Sender)
{
if(accion==2)
{
  Close();
}
if(accion==1)
{
  if(MainPG==NULL && !cargo)
  {
    MainPG=new TfrmMainPG(this);
    MainPG->Enabled=false;
    cargo=true;
  }
}
}
//---------------------------------------------------------------------------
void __fastcall TfrmMenu::FormClose(TObject *Sender, TCloseAction &Action)
{
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMenu::cmdApplyClick(TObject *Sender)
{
   if(rbPG->Checked)
   {
     sbPGClick(Sender);
   }
/*
   if(rbDS->Checked)
   {
     sbDSClick(Sender);
   }
   if(rbNS->Checked)
   {
     sbNSClick(Sender);
   }
*/
   if(rbAM->Checked)
   {
     sbOtherClick(Sender);
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMenu::sbPGClick(TObject *Sender)
{
/*
  if(MainDS!=NULL)
  {
    delete MainDS;
    MainDS=NULL;
  }
  if(MainNS!=NULL)
  {
    delete MainNS;
    MainNS=NULL;
  }
  if(MainAM!=NULL)
  {
    delete MainAM;
    MainAM=NULL;
  }
*/  
  if(MainPG!=NULL)
  {
     this->Visible=false;
     MainPG->Enabled=true;
  }
  else
  {
    MainPG=new TfrmMainPG(this);
    this->Visible=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMenu::sbDSClick(TObject *Sender)
{
  if(MainPG!=NULL)
  {
    delete MainPG;
    MainPG=NULL;
  }
/*
  if(MainNS!=NULL)
  {
    delete MainNS;
    MainNS=NULL;
  }
  if(MainAM!=NULL)
  {
    delete MainAM;
    MainAM=NULL;
  }
  if(MainDS!=NULL)
  {
     this->Visible=false;
     MainDS->Enabled=true;
  }
  else
  {
    MainDS=new DS::TfrmMainDS(this);
    this->Visible=false;
  }
*/
}
//---------------------------------------------------------------------------
void TfrmMenu::CerrarTodo()
{
  if(MainPG!=NULL)
  {
     delete MainPG;
     MainPG=NULL;
  }
/*
  if(MainDS!=NULL)
  {
     delete MainDS;
     MainDS=NULL;
  }
  if(MainNS!=NULL)
  {
     delete MainNS;
     MainNS=NULL;
  }
  if(MainAM!=NULL)
  {
     delete MainAM;
     MainAM=NULL;
  }
*/
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMenu::sbNSClick(TObject *Sender)
{
/*
  if(MainDS!=NULL)
  {
    delete MainDS;
    MainDS=NULL;
  }
*/
  if(MainPG!=NULL)
  {
    delete MainPG;
    MainPG=NULL;
  }
/*
  if(MainAM!=NULL)
  {
    delete MainAM;
    MainAM=NULL;
  }
  if(MainNS!=NULL)
  {
     this->Visible=false;
     MainNS->Enabled=true;
  }
  else
  {
    MainNS=new NS::TfrmMainNS(this);
    this->Visible=false;
  }
*/
}
//---------------------------------------------------------------------------
void __fastcall TfrmMenu::sbOtherClick(TObject *Sender)
{
/*
  if(MainDS!=NULL)
  {
    delete MainDS;
    MainDS=NULL;
  }
  if(MainNS!=NULL)
  {
    delete MainNS;
    MainNS=NULL;
  }
*/
  if(MainPG!=NULL)
  {
    delete MainPG;
    MainPG=NULL;
  }
/*
  if(MainAM!=NULL)
  {
     this->Visible=false;
     MainAM->Enabled=true;
  }
  else
  {
    MainAM=new TfrmMainAM(this);
    this->Visible=false;
  }
*/
}
//---------------------------------------------------------------------------

