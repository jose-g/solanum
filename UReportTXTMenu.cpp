//---------------------------------------------------------------------------
#include <io.h>
#include <vcl.h>
#pragma hdrstop
#include "UReportTXTMenu.h"
#include "UReportTXT.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmReportTXTMenu *frmReportTXTMenu;
//---------------------------------------------------------------------------
__fastcall TfrmReportTXTMenu::TfrmReportTXTMenu(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportTXTMenu::SpeedButton4Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void TfrmReportTXTMenu::EnterInformation(Report* _cond)
{
cond=_cond;
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportTXTMenu::Button1Click(TObject *Sender)
{
  int existe=access(cond->DMProd, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmReportTXT *frm = new TfrmReportTXT(this);
    frm->EnterInformation(cond->DMProd,"Text report : Dry matter production");
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportTXTMenu::Button2Click(TObject *Sender)
{
  int existe=access(cond->DMProdResume, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmReportTXT *frm = new TfrmReportTXT(this);
    frm->EnterInformation(cond->DMProdResume,"Text report : Dry matter production resume");
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------

