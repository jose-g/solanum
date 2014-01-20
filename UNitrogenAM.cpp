//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UNitrogenAM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmNitrogenAM *frmNitrogenAM;
//---------------------------------------------------------------------------
__fastcall TfrmNitrogenAM::TfrmNitrogenAM(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfrmNitrogenAM::EnterInformation(Nitrogen* _cond)
{
cond=_cond;
}
//---------------------------------------------------------------------------
void __fastcall TfrmNitrogenAM::cmdCancelClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmNitrogenAM::cmdApplyClick(TObject *Sender)
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
bool TfrmNitrogenAM::Validate()
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
TEdit* TfrmNitrogenAM::FindDataError(int* _cod)
{
  double datod=0.0;
  int datoi=0;
  try
  {
    datod=edFOMi->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edFOMi;
  }
  try
  {
    datod=edAmountFert->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edAmountFert;
  }
  return edAmountFert;
}
//---------------------------------------------------------------------------
void TfrmNitrogenAM::ShowMessageError(int _cod)
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
void TfrmNitrogenAM::SaveData()
{
   cond->SelectedOM=cbOM->ItemIndex;
   cond->SelectedFert=cbFert->ItemIndex;
   cond->AmountFert=edAmountFert->Text.ToDouble();
   cond->FOMi=edFOMi->Text.ToDouble();
}
//---------------------------------------------------------------------------
void __fastcall TfrmNitrogenAM::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TfrmNitrogenAM::FormShow(TObject *Sender)
{
  int i;
  for(i=0;i<cond->OMNumber;i++)
  {
     cbOM->Items->Add(cond->OMList[i]);
  }
  for(i=0;i<cond->FertNumber;i++)
  {
     cbFert->Items->Add(cond->FertList[i]);
  }
  PutValuesOnForm();
}
//---------------------------------------------------------------------------
void TfrmNitrogenAM::PutValuesOnForm()
{
   cbOM->ItemIndex=cond->SelectedOM;
   cbFert->ItemIndex=cond->SelectedFert;
   edAmountFert->Text=cond->AmountFert;
   edFOMi->Text=cond->FOMi;
}
//---------------------------------------------------------------------------

