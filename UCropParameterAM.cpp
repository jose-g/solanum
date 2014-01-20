//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UCropParameterAM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
AnsiString namevariety="Name of variety ...";
TfrmCropParameterAM *frmCropParameterAM;
//---------------------------------------------------------------------------
__fastcall TfrmCropParameterAM::TfrmCropParameterAM(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfrmCropParameterAM::EnterInformation(Crop* _cond)
{
cond=_cond;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameterAM::cmdCancelClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameterAM::cmdApplyClick(TObject *Sender)
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
bool TfrmCropParameterAM::Validate()
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
TEdit* TfrmCropParameterAM::FindDataError(int* _cod)
{
  double datod=0.0;
  int datoi=0;
  try
  {
    datod=edPlantDensity->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edPlantDensity;
  }
  try
  {
    datod=edMaxgc->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edMaxgc;
  }
  try
  {
    datod=edIniLig->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edIniLig;
  }
  try
  {
    datod=edIniGro->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edIniGro;
  }
  try
  {
    datod=edDurLeaf->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edDurLeaf;
  }
  try
  {
    datod=edThermal->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edThermal;
  }
  try
  {
    datod=edMaxHI->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edMaxHI;
  }
  try
  {
    datod=edAsyHI->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edAsyHI;
  }
  try
  {
    datod=edSlopeHI->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edSlopeHI;
  }
  try
  {
    datod=edDMContent->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edDMContent;
  }
  try
  {
    datod=edAveLight->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edAveLight;
  }
  try
  {
    datoi=edEmDay->Text.ToInt();
  }
  catch(...)
  {
    *_cod=1; // 1: No es un valor entero
    return edEmDay;
  }
  try
  {
    datod=edDMIVar->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edDMIVar;
  }
  try
  {
    datod=edBaseTemp->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edBaseTemp;
  }
  try
  {
    datod=edTcr->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edTcr;
  }
  try
  {
    datod=edTld->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edTld;
  }
  try
  {
    datod=edTrg->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edTrg;
  }
  return edBaseTemp;
}
//---------------------------------------------------------------------------
void TfrmCropParameterAM::ShowMessageError(int _cod)
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
void TfrmCropParameterAM::SaveData()
{
   cond->SelectedCrop = cbCrop->ItemIndex;
   cond->plant->N=edPlantDensity->Text.ToDouble();
   cond->plant->fcl=edMaxgc->Text.ToDouble();
   cond->plant->F0=edIniLig->Text.ToDouble();
   cond->plant->R0=edIniGro->Text.ToDouble();
   cond->plant->d=edDurLeaf->Text.ToDouble();
   cond->plant->t50=edThermal->Text.ToDouble();
   cond->plant->LUE=edAveLight->Text.ToDouble();
   cond->plant->EDay=edEmDay->Text.ToInt();
   cond->plant->v=edDMIVar->Text.ToDouble();
   cond->plant->t0=edBaseTemp->Text.ToDouble();
   cond->tuber->M=edMaxHI->Text.ToDouble();
   cond->tuber->A=edAsyHI->Text.ToDouble();
   cond->tuber->b=edSlopeHI->Text.ToDouble();
   cond->tuber->DMCont=edDMContent->Text.ToDouble();
   cond->tuber->Tcr=edTcr->Text.ToDouble();
   cond->tuber->Tld=edTld->Text.ToDouble();
   cond->tuber->Trg=edTrg->Text.ToDouble();
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameterAM::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameterAM::FormShow(TObject *Sender)
{
  int i;
  for(i=0;i<cond->CropNumber;i++)
  {
     cbCrop->Items->Add(cond->CropList[i]);
  }
  PutValuesOnForm();
}
//---------------------------------------------------------------------------
void TfrmCropParameterAM::PutValuesOnForm()
{
   cbCrop->ItemIndex=cond->SelectedCrop;
   edPlantDensity->Text=cond->plant->N;
   edMaxgc->Text=cond->plant->fcl;
   edIniLig->Text=cond->plant->F0;
   edIniGro->Text=cond->plant->R0;
   edDurLeaf->Text=cond->plant->d;
   edThermal->Text=cond->plant->t50;
   edAveLight->Text=cond->plant->LUE;
   edEmDay->Text=cond->plant->EDay;
   edDMIVar->Text=cond->plant->v;
   edBaseTemp->Text=cond->plant->t0;
   edMaxHI->Text=cond->tuber->M;
   edAsyHI->Text=cond->tuber->A;
   edSlopeHI->Text=cond->tuber->b;
   edDMContent->Text=cond->tuber->DMCont;
   edTcr->Text=cond->tuber->Tcr;
   edTld->Text=cond->tuber->Tld;
   edTrg->Text=cond->tuber->Trg;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameterAM::cbCropClick(TObject *Sender)
{
  int sel;
  sel=cbCrop->ItemIndex;
  if(ItemSelected!=sel)
  {
    Crop *temp=new Crop();
    temp->DefaultValuesForKindOfCrop(sel);
    edMaxgc->Text=temp->plant->fcl;
    edIniLig->Text=temp->plant->F0;
    edIniGro->Text=temp->plant->R0;
    edDurLeaf->Text=temp->plant->d;
    edThermal->Text=temp->plant->t50;
    edAveLight->Text=temp->plant->LUE;
    edMaxHI->Text=temp->tuber->M;
    edAsyHI->Text=temp->tuber->A;
    edSlopeHI->Text=temp->tuber->b;
    edDMContent->Text=temp->tuber->DMCont;
    edTcr->Text=temp->tuber->Tcr;
    edTld->Text=temp->tuber->Tld;
    edTrg->Text=temp->tuber->Trg;
    delete temp;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameterAM::cbCropEnter(TObject *Sender)
{
  ItemSelected=cbCrop->ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TfrmCropParameterAM::edNameChange(TObject *Sender)
{
edName->Font->Color=clBlack;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameterAM::edNameClick(TObject *Sender)
{
if(edName->Text==namevariety)
{
  edName->Text="";
}
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameterAM::edNameExit(TObject *Sender)
{
AnsiString valor=edName->Text.Trim();
int tam=valor.Length();
if(tam==0)
{
  edName->Text=namevariety;
  edName->Font->Color=8421504;
}
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameterAM::butAddCropClick(TObject *Sender)
{
  edName->Text=namevariety;
  edName->Font->Color=8421504;
  Application->MessageBox("The crop parameters were saved to favorite varieties list!", "Successful!", MB_OK);
}
//---------------------------------------------------------------------------
void TfrmCropParameterAM::LoadListFavoriteCrop()
{
  AnsiString favorite=ExtractFileDir(Application->ExeName)+"\\favoritecrop.csv";
  FileData *util=new FileData();
  int numlin=util->GetNumberLinesFromCSVFile(favorite.c_str());
  delete util;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameterAM::Button1Click(TObject *Sender)
{
LoadListFavoriteCrop();
}
//---------------------------------------------------------------------------

