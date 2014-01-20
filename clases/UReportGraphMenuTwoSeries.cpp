//---------------------------------------------------------------------------
#include <vcl.h>
#include <io.h>
#pragma hdrstop
#include "UReportGraphMenuTwoSeries.h"
//#include "UGraph2TwoSeries.h"
//#include "UGraph3TwoSeries.h"
//#include "UGraph4TwoSeries.h"
#include "UGraph6TwoSeries.h"
#include "UGraphBoxPlot.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmReportGraphMenuTwoSeries *frmReportGraphMenuTwoSeries;
//---------------------------------------------------------------------------
__fastcall TfrmReportGraphMenuTwoSeries::TfrmReportGraphMenuTwoSeries(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportGraphMenuTwoSeries::SpeedButton4Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void TfrmReportGraphMenuTwoSeries::EnterInformation(Report* _cond,int idModel)
{
cond=_cond;
IDmodel=idModel;
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportGraphMenuTwoSeries::Button2Click(TObject *Sender)
{
  int existe=access(cond->Archivo5, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph6TwoSeries *frm = new TfrmGraph6TwoSeries(this);
    frm->EnterInformation(cond->Archivo5,IDmodel,3);  // 1: Total Dry Matter Production, 2: Dry tuber yield , 3: Fresh tuber yield , 4: Canopy Cover
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportGraphMenuTwoSeries::Button3Click(TObject *Sender)
{
  int existe=access(cond->Archivo3, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph6TwoSeries *frm = new TfrmGraph6TwoSeries(this);
    frm->EnterInformation(cond->Archivo3,IDmodel,4);  // 1: Total Dry Matter Production, 2: Dry tuber yield , 3: Fresh tuber yield , 4: Canopy Cover
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmReportGraphMenuTwoSeries::Button4Click(TObject *Sender)
{
  int existe=access(cond->Archivo4, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph6TwoSeries *frm = new TfrmGraph6TwoSeries(this);
    frm->EnterInformation(cond->Archivo4,IDmodel,2);  // 1: Total Dry Matter Production, 2: Dry tuber yield , 3: Fresh tuber yield , 4: Canopy Cover
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportGraphMenuTwoSeries::Button6Click(TObject *Sender)
{
  int existe=access(cond->Archivo6, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph6TwoSeries *frm = new TfrmGraph6TwoSeries(this);
    frm->EnterInformation(cond->Archivo6,IDmodel,1);  // 1: Total Dry Matter Production, 2: Dry tuber yield , 3: Fresh tuber yield , 4: Canopy Cover
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmReportGraphMenuTwoSeries::Button5Click(TObject *Sender)
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

