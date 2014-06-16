//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "USimulationTime.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSimulationTime *frmSimulationTime;
//---------------------------------------------------------------------------
__fastcall TfrmSimulationTime::TfrmSimulationTime(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfrmSimulationTime::EnterInformation(ManageDataPotato *_cond)
{
cond=_cond;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSimulationTime::cmdSimulateClick(TObject *Sender)
{
  bool exitoso=false;
  exitoso=Validate();
  if(exitoso)
  {
    SaveData();
  }
}
//---------------------------------------------------------------------------
void TfrmSimulationTime::PutValuesOnForm()
{
  int anio=0;
  if(cond->idModel==6)
  {
    cbYear->Enabled=false;cbYear->ItemIndex=-1;
  }
  else
  {
    for(int i=0;i<cond->climate->RecNum;i++)
    {
      if(anio!=cond->climate->Year[i])
      {
        cbYear->Items->Add(cond->climate->Year[i]);
        anio=cond->climate->Year[i];
      }
    }
  }
  cbYear->ItemIndex=cond->time->idYear;
  cbMonth->ItemIndex=cond->time->MonthStart-1;
  edDay->Text=cond->time->DayStart;
  edTime->Text=cond->time->duration;
  edNumSim->Text=cond->time->repetitions;
  edLocation->Text=cond->time->location;
  cbThermal->ItemIndex=cond->climate->ThermalCond-1;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSimulationTime::FormShow(TObject *Sender)
{
  PutValuesOnForm();
}
//---------------------------------------------------------------------------
bool TfrmSimulationTime::Validate()
{
  TEdit *box=new TEdit(this);
  int cod=0; //0 : indica que no hay errores
  box = FindDataError(&cod);
  if(cod!=0)
  {
    ShowMessageError(cod);
    box->SetFocus();
    return false;
  }
  else
  {
    return true;
  }
}
//---------------------------------------------------------------------------
TEdit* TfrmSimulationTime::FindDataError(int* _cod)
{
  int datoi;
  try
  {
    datoi=edTime->Text.ToInt();
  }
  catch(...)
  {
    *_cod=1; // 1: No es un valor entero
    return edTime;
  }
  try
  {
    datoi=edDay->Text.ToInt();
  }
  catch(...)
  {
    *_cod=1; // 1: No es un valor entero
    return edDay;
  }
  return edTime;
}
//---------------------------------------------------------------------------
void TfrmSimulationTime::ShowMessageError(int _cod)
{
  if(_cod==1)
  {
    Application->MessageBox("The value should be an integer!", "Warning!", MB_OK);
  }
}
//---------------------------------------------------------------------------
void TfrmSimulationTime::SaveData()
{
  if(cond->idModel==6)
  {
    cond->time->YearStart = 0;
  }
  else
  {
    cond->time->YearStart = cbYear->Text.ToInt();
  }
  cond->time->idYear = cbYear->ItemIndex;
  cond->time->MonthStart = cbMonth->ItemIndex+1;
  cond->time->DayStart   = edDay->Text.ToInt();
  cond->time->duration   = edTime->Text.ToInt();
  cond->time->repetitions   = edNumSim->Text.ToInt();
  cond->climate->ThermalCond=cbThermal->ItemIndex+1;
  char* cp1 = new char[ edLocation->Text.Length() + 1 ];
  strcpy( cp1, edLocation->Text.c_str() );
  cond->time->location=cp1;
  char* cp2 = new char[ cbMonth->Text.Length() + 1 ];
  strcpy( cp2, cbMonth->Text.c_str() );
  cond->time->Month=cp2;
}
//---------------------------------------------------------------------------





