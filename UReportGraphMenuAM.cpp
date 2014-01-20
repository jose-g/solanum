//---------------------------------------------------------------------------
#include <vcl.h>
#include <io.h>
#pragma hdrstop
#include "UReportGraphMenuAM.h"
#include "UGraph1AM.h"
#include "UGraph2AM.h"
#include "UGraph3AM.h"
#include "UGraph4AM.h"
#include "UGraph5AM.h"
#include "UGraph6AM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmReportGraphMenuAM* frmReportGraphMenuAM;
//---------------------------------------------------------------------------
__fastcall TfrmReportGraphMenuAM::TfrmReportGraphMenuAM(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportGraphMenuAM::SpeedButton4Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void TfrmReportGraphMenuAM::EnterInformation(Report* _cond)
{
cond=_cond;
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportGraphMenuAM::Button1Click(TObject *Sender)
{
  int existe=access(cond->Archivo1, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph1AM *frm = new TfrmGraph1AM(this);
    frm->EnterInformation(cond->Archivo1);
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportGraphMenuAM::Button2Click(TObject *Sender)
{
  int existe=access(cond->Archivo2, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph2AM *frm = new TfrmGraph2AM(this);
    frm->EnterInformation(cond->Archivo2);
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportGraphMenuAM::Button3Click(TObject *Sender)
{
  int existe=access(cond->Archivo3, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph3AM *frm = new TfrmGraph3AM(this);
    frm->EnterInformation(cond->Archivo3);
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmReportGraphMenuAM::Button4Click(TObject *Sender)
{
  int existe=access(cond->Archivo4, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph4AM *frm = new TfrmGraph4AM(this);
    frm->EnterInformation(cond->Archivo4);
    frm->ShowModal();
    delete frm;
  }

}
//---------------------------------------------------------------------------

void __fastcall TfrmReportGraphMenuAM::Button5Click(TObject *Sender)
{
  int existe=access(cond->Archivo5, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph5AM *frm = new TfrmGraph5AM(this);
    frm->EnterInformation(cond->Archivo5);
    frm->ShowModal();
    delete frm;
  }

}
//---------------------------------------------------------------------------

void __fastcall TfrmReportGraphMenuAM::Button6Click(TObject *Sender)
{
  int existe=access(cond->Archivo6, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph6AM *frm = new TfrmGraph6AM(this);
    frm->EnterInformation(cond->Archivo6);
    frm->ShowModal();
    delete frm;
  }

}
//---------------------------------------------------------------------------

