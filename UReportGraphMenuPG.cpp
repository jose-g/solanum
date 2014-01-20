//---------------------------------------------------------------------------
#include <vcl.h>
#include <io.h>
#pragma hdrstop
#include "UReportGraphMenuPG.h"
#include "UGraph1PG.h"
#include "UGraph2PG.h"
#include "UGraph3PG.h"
#include "UGraph4PG.h"
#include "UGraph6PG.h"
#include "UGraphBoxPlot.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmReportGraphMenuPG *frmReportGraphMenuPG;
//---------------------------------------------------------------------------
__fastcall TfrmReportGraphMenuPG::TfrmReportGraphMenuPG(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportGraphMenuPG::SpeedButton4Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void TfrmReportGraphMenuPG::EnterInformation(Report* _cond)
{
cond=_cond;
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportGraphMenuPG::Button1Click(TObject *Sender)
{
  int existe=access(cond->Archivo1, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph1PG *frm = new TfrmGraph1PG(this);
    frm->EnterInformation(cond->Archivo1);
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportGraphMenuPG::Button2Click(TObject *Sender)
{
  int existe=access(cond->Archivo2, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph2PG *frm = new TfrmGraph2PG(this);
    frm->EnterInformation(cond->Archivo2);
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportGraphMenuPG::Button3Click(TObject *Sender)
{
  int existe=access(cond->Archivo3, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph3PG *frm = new TfrmGraph3PG(this);
    frm->EnterInformation(cond->Archivo3);
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmReportGraphMenuPG::Button4Click(TObject *Sender)
{
  int existe=access(cond->Archivo4, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph4PG *frm = new TfrmGraph4PG(this);
    frm->EnterInformation(cond->Archivo4);
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmReportGraphMenuPG::Button6Click(TObject *Sender)
{
  int existe=access(cond->Archivo6, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph6PG *frm = new TfrmGraph6PG(this);
    frm->EnterInformation(cond->Archivo6);
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportGraphMenuPG::Button5Click(TObject *Sender)
{
  int existe=access(cond->rBoxPlotfty, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraphBoxPlot *frm = new TfrmGraphBoxPlot(this);
    frm->EnterInformation(cond->rBoxPlotfty);
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------

