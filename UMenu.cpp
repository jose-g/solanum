//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UMenu.h"
#include "ULogo.h"
#include "UMainAM.h"
#include "UMainPG.h"
#include "UMainDS.h"
#include "UMainNS.h"
#include "UMainFS.h"
#include "UMainPG_AMY.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMenu *frmMenu;
TfrmMainPG* MainPG;
TfrmMainPG_AMY* MainPG_AMY;
TfrmMainDS* MainDS;
TfrmMainNS* MainNS;
TfrmMainAM* MainAM;
TfrmMainFS* MainFS;
//---------------------------------------------------------------------------
__fastcall TfrmMenu::TfrmMenu(TComponent* Owner)
        : TForm(Owner)
{
TfrmLogo* frm=new TfrmLogo(this);
frm->ShowModal();
accion=frm->ModalResult;
if(frm!=0)
{
  delete frm;
  frm=0;
}
cargo=false;
prjSolanum=new Solanum();
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
  if(MainPG==0 && !cargo)
  {
    MainPG=new TfrmMainPG(this,prjSolanum);
    MainPG->Enabled=false;
    cargo=true;
  }
}
}
//---------------------------------------------------------------------------
void __fastcall TfrmMenu::FormClose(TObject *Sender, TCloseAction &Action)
{
//delete prjSolanum;
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMenu::cmdApplyClick(TObject *Sender)
{
   if(rbPG->Checked)
   {
     sbPGClick(Sender);
   }
   if(rbDS->Checked)
   {
     sbDSClick(Sender);
   }
   if(rbNS->Checked)
   {
     sbNSClick(Sender);
   }
   if(rbFS->Checked)
   {
     sbFSClick(Sender);
   }
   if(rbAM->Checked)
   {
     sbOtherClick(Sender);
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMenu::sbPGClick(TObject *Sender)
{
  rbPG->Checked=true;
  if(MainDS!=0)
  {
    delete MainDS;
    MainDS=0;
  }
  if(MainNS!=0)
  {
    delete MainNS;
    MainNS=0;
  }
  if(MainFS!=0)
  {
    delete MainFS;
    MainFS=0;
  }
  if(MainAM!=0)
  {
    delete MainAM;
    MainAM=0;
  }
  if(chbMYA->Checked)
  {
    if(MainPG!=0)
    {
      delete MainPG;
      MainPG=0;
    }
  }
  else
  {
    if(MainPG_AMY!=0)
    {
      delete MainPG_AMY;
      MainPG_AMY=0;
    }
  }
// aqui me quede
  if(chbMYA->Checked)
  {
    if(MainPG_AMY!=0)
    {
       this->Visible=false;
       MainPG_AMY->Enabled=true;
    }
    else
    {
      MainPG_AMY=new TfrmMainPG_AMY(this,prjSolanum);
      this->Visible=false;
    }
  }
  else
  {
    if(MainPG!=0)
    {
       this->Visible=false;
       MainPG->Enabled=true;
    }
    else
    {
      MainPG=new TfrmMainPG(this,prjSolanum);
      this->Visible=false;
    }
  }

}
//---------------------------------------------------------------------------
void __fastcall TfrmMenu::sbDSClick(TObject *Sender)
{
  rbDS->Checked=true;

  if(MainPG!=0)
  {
    delete MainPG;
    MainPG=0;
  }
  if(MainPG_AMY!=0)
  {
    delete MainPG_AMY;
    MainPG_AMY=0;
  }
  if(MainNS!=0)
  {
    delete MainNS;
    MainNS=0;
  }
  if(MainAM!=0)
  {
    delete MainAM;
    MainAM=0;
  }
  if(MainFS!=0)
  {
    delete MainFS;
    MainFS=0;
  }
  if(MainDS!=0)
  {
     this->Visible=false;
     MainDS->Enabled=true;
  }
  else
  {
    MainDS=new TfrmMainDS(this,prjSolanum);
    this->Visible=false;
  }
}
//---------------------------------------------------------------------------
void TfrmMenu::CerrarTodo()
{
  if(MainPG!=0)
  {
     delete MainPG;
     MainPG=0;
  }
  if(MainPG_AMY!=0)
  {
    delete MainPG_AMY;
    MainPG_AMY=0;
  }
  if(MainDS!=0)
  {
     delete MainDS;
     MainDS=0;
  }
  if(MainNS!=0)
  {
     delete MainNS;
     MainNS=0;
  }
  if(MainFS!=0)
  {
     delete MainFS;
     MainFS=0;
  }
  if(MainAM!=0)
  {
     delete MainAM;
     MainAM=0;
  }
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMenu::sbNSClick(TObject *Sender)
{
  rbNS->Checked=true;
  if(MainDS!=0)
  {
    delete MainDS;
    MainDS=0;
  }
  if(MainPG!=0)
  {
    delete MainPG;
    MainPG=0;
  }
  if(MainPG_AMY!=0)
  {
    delete MainPG_AMY;
    MainPG_AMY=0;
  }
  if(MainAM!=0)
  {
    delete MainAM;
    MainAM=0;
  }
  if(MainFS!=0)
  {
    delete MainFS;
    MainFS=0;
  }
  if(MainNS!=0)
  {
     this->Visible=false;
     MainNS->Enabled=true;
  }
  else
  {
    MainNS=new TfrmMainNS(this,prjSolanum);
    this->Visible=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMenu::sbOtherClick(TObject *Sender)
{
  rbAM->Checked=true;
  if(MainDS!=0)
  {
    delete MainDS;
    MainDS=0;
  }
  if(MainNS!=0)
  {
    delete MainNS;
    MainNS=0;
  }
  if(MainPG!=0)
  {
    delete MainPG;
    MainPG=0;
  }
  if(MainPG_AMY!=0)
  {
    delete MainPG_AMY;
    MainPG_AMY=0;
  }
  if(MainFS!=0)
  {
    delete MainFS;
    MainFS=0;
  }
  if(MainAM!=0)
  {
     this->Visible=false;
     MainAM->Enabled=true;
  }
  else
  {
    MainAM=new TfrmMainAM(this,prjSolanum);
    this->Visible=false;
  }
}
//---------------------------------------------------------------------------


void __fastcall TfrmMenu::sbFSClick(TObject *Sender)
{
  rbFS->Checked=true;
  if(MainDS!=0)
  {
    delete MainDS;
    MainDS=0;
  }
  if(MainNS!=0)
  {
    delete MainNS;
    MainNS=0;
  }
  if(MainPG!=0)
  {
    delete MainPG;
    MainPG=0;
  }
  if(MainPG_AMY!=0)
  {
    delete MainPG_AMY;
    MainPG_AMY=0;
  }
  if(MainAM!=0)
  {
    delete MainAM;
    MainAM=0;
  }
  if(MainFS!=0)
  {
     this->Visible=false;
     MainFS->Enabled=true;
  }
  else
  {
    MainFS=new TfrmMainFS(this,prjSolanum);
    this->Visible=false;
  }
}
//---------------------------------------------------------------------------


