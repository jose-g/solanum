//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "USoilAM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSoilAM *frmSoilAM;
//---------------------------------------------------------------------------
__fastcall TfrmSoilAM::TfrmSoilAM(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfrmSoilAM::EnterInformation(Soil* _cond)
{
cond=_cond;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSoilAM::cmdCancelClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmSoilAM::cmdApplyClick(TObject *Sender)
{
  bool exitoso=false;
  exitoso=Validate();
  if(exitoso)
  {
    SaveData();
    Close();
  }
}
//---------------------------------------------------------------------------
bool TfrmSoilAM::Validate()
{
  TEdit *casilla=new TEdit(this);
  int cod=0; //0 : indica que no hay errores
  casilla = FindDataError(&cod);
  if(cod!=0)
  {
    ShowMessageError(cod);
    casilla->SetFocus();
    return false;
  }
  else
  {
    return true;
  }
}
//---------------------------------------------------------------------------
TEdit* TfrmSoilAM::FindDataError(int* _cod)
{
  double datod=0.0;
  int datoi=0;
  try
  {
    datod=edMoisture->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edMoisture;
  }
  try
  {
    datod=edOM->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edOM;
  }
  try
  {
    datod=edSoilDepth->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edSoilDepth;
  }
  try
  {
    datod=edPh->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edPh;
  }
  try
  {
    datod=edMaxDepth->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edMaxDepth;
  }
  return edMoisture;
}
//---------------------------------------------------------------------------
void TfrmSoilAM::ShowMessageError(int _cod)
{
  if(_cod==1)
  {
    Application->MessageBox("The value should be an integer!", "Warning!", MB_OK);
  }
  if(_cod==2)
  {
    Application->MessageBox("The value should be a real!", "Warning!", MB_OK);
  }
}
//---------------------------------------------------------------------------
void TfrmSoilAM::SaveData()
{
   cond->SelectedSoil=cbSoilTexture->ItemIndex+1;
   cond->Moisture=edMoisture->Text.ToDouble();
   cond->OM=edOM->Text.ToDouble();
   cond->SoilDepth=edSoilDepth->Text.ToDouble();
   cond->Ph=edPh->Text.ToDouble();
   cond->MaxDepth=edMaxDepth->Text.ToDouble();
}
//---------------------------------------------------------------------------
void __fastcall TfrmSoilAM::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSoilAM::FormShow(TObject *Sender)
{
  int i;
  for(i=0;i<cond->SoilNumber;i++)
  {
     cbSoilTexture->Items->Add(cond->SoilList[i]);
  }
  PutValuesOnForm();
}
//---------------------------------------------------------------------------
void TfrmSoilAM::PutValuesOnForm()
{
   cbSoilTexture->ItemIndex=cond->SelectedSoil-1;
   edMoisture->Text=cond->Moisture;
   edOM->Text=cond->OM;
   edSoilDepth->Text=cond->SoilDepth;
   edPh->Text=cond->Ph;
   edMaxDepth->Text=cond->MaxDepth;
}
//---------------------------------------------------------------------------

