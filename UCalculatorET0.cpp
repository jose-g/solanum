//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UCalculatorET0.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmCalculatorET0 *frmCalculatorET0;
//---------------------------------------------------------------------------
__fastcall TfrmCalculatorET0::TfrmCalculatorET0(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfrmCalculatorET0::EnterInformation(ManageDataPotato *_cond)
{
cond=_cond;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalculatorET0::cmdCancelClick(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalculatorET0::cmdApplyClick(TObject *Sender)
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
bool TfrmCalculatorET0::Validate()
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
TEdit* TfrmCalculatorET0::FindDataError(int* _cod)
{
/*
  double datod;
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
    datod=edMaxDepth->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edMaxDepth;
  }
  return edPathFile;
*/
}
//---------------------------------------------------------------------------
void TfrmCalculatorET0::ShowMessageError(int _cod)
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
void TfrmCalculatorET0::SaveData()
{
/*
   char* cp1 = new char[ edPathFile->Text.Length() + 1 ];
   strcpy( cp1, edPathFile->Text.c_str() );
   cond->climate->FileName=cp1;
   char* cp2 = new char[ edMinTemp->Text.Length() + 1 ];
   strcpy( cp2, edMinTemp->Text.c_str() );
   cond->climate->TitTMin=cp2;
   char* cp3 = new char[ edMaxTemp->Text.Length() + 1 ];
   strcpy( cp3, edMaxTemp->Text.c_str() );
   cond->climate->TitTMax=cp3;

   cond->soil->SelectedSoil=cbSoilTexture->ItemIndex+1;
   cond->soil->SoilDepth=edSoilDepth->Text.ToDouble();
   cond->soil->MaxDepth=edMaxDepth->Text.ToDouble();

    for(int i=0;i<cond->climate->RecNum;i++)
    {
       cond->climate->SoilTemp[i]=sgClimate->Cells[3][i+2].ToDouble();
    }
*/
}
//---------------------------------------------------------------------------