//---------------------------------------------------------------------------
#include <vcl.h>
#include <io.h>
#pragma hdrstop
#include "UReportGraphMenuMYA.h"
#include "UGraphBoxPlotMYA.h"
#include "UGraphCIinP_MYA.h"
#include "UGraphBoxPlotMYA_Yearly.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmReportGraphMenuMYA *frmReportGraphMenuMYA;
//---------------------------------------------------------------------------
__fastcall TfrmReportGraphMenuMYA::TfrmReportGraphMenuMYA(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportGraphMenuMYA::SpeedButton4Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void TfrmReportGraphMenuMYA::EnterInformation(ManageDataPotato* _cond)
{
cond=_cond;
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportGraphMenuMYA::Button5Click(TObject *Sender)
{
  TfrmGraphBoxPlotMYA *frm = new TfrmGraphBoxPlotMYA(this);
  frm->EnterInformation(cond->simulation);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportGraphMenuMYA::Button6Click(TObject *Sender)
{
  TfrmGraphCIinP_MYA *frm = new TfrmGraphCIinP_MYA(this);
  frm->EnterInformation(cond->simulation,"Confidence interval of the projection for past scenarios",1);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------

void __fastcall TfrmReportGraphMenuMYA::Button1Click(TObject *Sender)
{
  TfrmGraphCIinP_MYA *frm = new TfrmGraphCIinP_MYA(this);
  frm->EnterInformation(cond->simulation,"Confidence interval of the projection for future scenarios",2);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportGraphMenuMYA::Button2Click(TObject *Sender)
{
  TfrmGraphBoxPlotMYA_Yearly *frm = new TfrmGraphBoxPlotMYA_Yearly(this);
  frm->EnterInformation(cond->simulation);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------

