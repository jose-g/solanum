//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "USoilDS.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSoilDS *frmSoilDS;
//---------------------------------------------------------------------------
__fastcall TfrmSoilDS::TfrmSoilDS(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfrmSoilDS::EnterInformation(Soil* _cond)
{
cond=_cond;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSoilDS::cmdCancelClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmSoilDS::cmdApplyClick(TObject *Sender)
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
bool TfrmSoilDS::Validate()
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
TEdit* TfrmSoilDS::FindDataError(int* _cod)
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
    datod=edSoilDepth->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edSoilDepth;
  }
  return edMoisture;
}
//---------------------------------------------------------------------------
void TfrmSoilDS::ShowMessageError(int _cod)
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
void TfrmSoilDS::SaveData()
{
   cond->SelectedSoil=cbSoilTexture->ItemIndex;
   cond->Moisture=edMoisture->Text.ToDouble();
   cond->SoilDepth=edSoilDepth->Text.ToDouble();
}
//---------------------------------------------------------------------------
void __fastcall TfrmSoilDS::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSoilDS::FormShow(TObject *Sender)
{
  int i;
  for(i=0;i<cond->SoilNumber;i++)
  {
     cbSoilTexture->Items->Add(cond->SoilList[i]);
  }
  PutValuesOnForm();
}
//---------------------------------------------------------------------------
void TfrmSoilDS::PutValuesOnForm()
{
   cbSoilTexture->ItemIndex=cond->SelectedSoil;
   edMoisture->Text=cond->Moisture;
   edSoilDepth->Text=cond->SoilDepth;
}
//---------------------------------------------------------------------------

