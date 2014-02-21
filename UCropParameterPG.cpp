//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UCropParameterPG.h"
#include "UImportCropParameter.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmCropParameterPG *frmCropParameterPG;
//---------------------------------------------------------------------------
__fastcall TfrmCropParameterPG::TfrmCropParameterPG(TComponent* Owner)
        : TForm(Owner)
{
   sgCrop->RowCount=3;
   sgCrop->Cells[0][1]="#";
   sgCrop->Cells[1][0]="Variety name";
   sgCrop->Cells[2][0]="Wmax";
   sgCrop->Cells[3][0]="tm";
   sgCrop->Cells[4][0]="te";
   sgCrop->Cells[5][0]="A";
   sgCrop->Cells[6][0]="Tu";
   sgCrop->Cells[7][0]="b";
   sgCrop->Cells[8][0]="DMC";
   sgCrop->Cells[9][0]="RUE";
   sgCrop->Cells[10][0]="w";
   sgCrop->Cells[11][0]="Pc";
   sgCrop->Cells[1][1]="";
   sgCrop->Cells[2][1]="";
   sgCrop->Cells[3][1]="";
   sgCrop->Cells[4][1]="";
   sgCrop->Cells[5][1]="";
   sgCrop->Cells[6][1]="";
   sgCrop->Cells[7][1]="";
   sgCrop->Cells[8][1]="";
   sgCrop->Cells[9][1]="";
   sgCrop->Cells[10][1]="";
   sgCrop->Cells[11][1]="";
   sgCrop->RowHeights[0]=18;
   sgCrop->RowHeights[1]=18;
   sgCrop->ColWidths[0]=30;
   sgCrop->ColWidths[1]=100;
   sgCrop->ColWidths[2]=50;
   sgCrop->ColWidths[3]=50;
   sgCrop->ColWidths[4]=50;
   sgCrop->ColWidths[5]=50;
   sgCrop->ColWidths[6]=50;
   sgCrop->ColWidths[7]=50;
   sgCrop->ColWidths[8]=50;
   sgCrop->ColWidths[9]=50;
   sgCrop->ColWidths[10]=50;
   sgCrop->ColWidths[11]=50;
}
//---------------------------------------------------------------------------
void TfrmCropParameterPG::EnterInformation(Crop* _cond,DBCultivo* _dbcultivo)
{
cond=_cond;
dbcultivo=_dbcultivo;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameterPG::FormShow(TObject *Sender)
{
/*
  int i;
  for(i=0;i<cond->CropNumber;i++)
  {
     cbCrop->Items->Add(cond->CropList[i]);
  }
*/
// poblar grilla
  PoblarGrilla();
//  uestro los parametros y otros inputs en el formulario
  PutValuesOnForm();
}
//---------------------------------------------------------------------------
void TfrmCropParameterPG::PoblarGrilla()
{
  sgCrop->RowCount=2+dbcultivo->numreg;
  for(int i=0;i<dbcultivo->numreg;i++)
  {
    sgCrop->Cells[0][i+2]=i+1;
    sgCrop->Cells[1][i+2]=AnsiString(dbcultivo->Item[i].cropname);
    sgCrop->Cells[2][i+2]=dbcultivo->Item[i].plant->fcl;
    sgCrop->Cells[3][i+2]=dbcultivo->Item[i].plant->F0;
    sgCrop->Cells[4][i+2]=dbcultivo->Item[i].plant->R0;
    sgCrop->Cells[5][i+2]=dbcultivo->Item[i].tuber->M;
    sgCrop->Cells[6][i+2]=dbcultivo->Item[i].tuber->A;
    sgCrop->Cells[7][i+2]=dbcultivo->Item[i].tuber->b;
    sgCrop->Cells[8][i+2]=dbcultivo->Item[i].tuber->DMCont;
    sgCrop->Cells[9][i+2]=dbcultivo->Item[i].plant->LUE;
    sgCrop->Cells[10][i+2]=dbcultivo->Item[i].tuber->w;
    sgCrop->Cells[11][i+2]=dbcultivo->Item[i].tuber->Pc;
  }
}
//---------------------------------------------------------------------------
void TfrmCropParameterPG::PutValuesOnForm()
{
  if(cond->SelectedCrop==-1)
  {
    sgCrop->Row=2;
  }
  else
  {
    sgCrop->Row=cond->SelectedCrop+2;
  }
//   cbCrop->ItemIndex=cond->SelectedCrop;
   edNameCrop->Text=cond->cropname;
   edMaxgc->Text=cond->plant->fcl;
   edIniLig->Text=cond->plant->F0;
   edIniGro->Text=cond->plant->R0;
   edMaxHI->Text=cond->tuber->M;
   edAsyHI->Text=cond->tuber->A;
   edSlopeHI->Text=cond->tuber->b;
   edDMContent->Text=cond->tuber->DMCont;
   edAveLight->Text=cond->plant->LUE;
   edTcr->Text=cond->tuber->Tcr;
   edTld->Text=cond->tuber->Tld;
   edTrg->Text=cond->tuber->Trg;
   edEmDay->Text=cond->plant->EDay;


   edDurLeaf->Text=cond->plant->d;
   edThermal->Text=cond->plant->t50;

   edPhotoSen->Text=cond->tuber->w;
   edPhotoCrit->Text=cond->tuber->Pc;

}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameterPG::sgCropSelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
  if(ARow>=2)
  {
   edNameCrop->Text=dbcultivo->Item[ARow-2].cropname;
   edMaxgc->Text=dbcultivo->Item[ARow-2].plant->fcl;
   edIniLig->Text=dbcultivo->Item[ARow-2].plant->F0;
   edIniGro->Text=dbcultivo->Item[ARow-2].plant->R0;
   edMaxHI->Text=dbcultivo->Item[ARow-2].tuber->M;
   edAsyHI->Text=dbcultivo->Item[ARow-2].tuber->A;
   edSlopeHI->Text=dbcultivo->Item[ARow-2].tuber->b;
   edDMContent->Text=dbcultivo->Item[ARow-2].tuber->DMCont;
   edAveLight->Text=dbcultivo->Item[ARow-2].plant->LUE;
   edTcr->Text=dbcultivo->Item[ARow-2].tuber->Tcr;
   edTld->Text=dbcultivo->Item[ARow-2].tuber->Tld;
   edTrg->Text=dbcultivo->Item[ARow-2].tuber->Trg;
   edEmDay->Text=dbcultivo->Item[ARow-2].plant->EDay;
   edPhotoSen->Text=dbcultivo->Item[ARow-2].tuber->w;
   edPhotoCrit->Text=dbcultivo->Item[ARow-2].tuber->Pc;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameterPG::butAddClick(TObject *Sender)
{
  bool exitoso=false;
  exitoso=Validate();
  if(exitoso)
  {
    // x defecto guardo un nuevo cultivo con valores constantes para Tcr,Tld y Trg
    edTcr->Text=-3;
    edTld->Text=-5;
    edTrg->Text=-8;
    //
    SaveInDB(dbcultivo->numreg);
    dbcultivo->numreg++;
    PoblarGrilla();
    sgCrop->Row=dbcultivo->numreg+2-1;
    dbcultivo->saveAllParameters(dbcultivo->DBName);
    Application->MessageBox("the parameters were added to the database !!!", "Successful!", MB_OK);
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameterPG::butUpdateClick(TObject *Sender)
{
  int reg=sgCrop->Row-2;
  if(reg>=18)
  {
    bool exitoso=false;
    exitoso=Validate();
    if(exitoso)
    {
      int numreg=sgCrop->Row-2;
      SaveInDB(numreg);
      PoblarGrilla();
      dbcultivo->saveAllParameters(dbcultivo->DBName);
      Application->MessageBox("the parameters were updated in the database !!!", "Successful!", MB_OK);
    }
  }
  else
  {
   Application->MessageBox("This parameter can not be updated!", "Warning!", MB_OK);
  }
}
//---------------------------------------------------------------------------
void TfrmCropParameterPG::SaveInDB(int reg)
{
   int numreg=reg;
   strcpy(dbcultivo->Item[numreg].cropname,edNameCrop->Text.c_str());

   dbcultivo->Item[numreg].plant->fcl=edMaxgc->Text.ToDouble();
   dbcultivo->Item[numreg].plant->F0=edIniLig->Text.ToDouble();
   dbcultivo->Item[numreg].plant->R0=edIniGro->Text.ToDouble();
   dbcultivo->Item[numreg].tuber->M=edMaxHI->Text.ToDouble();
   dbcultivo->Item[numreg].tuber->A=edAsyHI->Text.ToDouble();
   dbcultivo->Item[numreg].tuber->b=edSlopeHI->Text.ToDouble();
   dbcultivo->Item[numreg].tuber->DMCont=edDMContent->Text.ToDouble();
   dbcultivo->Item[numreg].plant->LUE=edAveLight->Text.ToDouble();
   dbcultivo->Item[numreg].tuber->Tcr=edTcr->Text.ToDouble();
   dbcultivo->Item[numreg].tuber->Tld=edTld->Text.ToDouble();
   dbcultivo->Item[numreg].tuber->Trg=edTrg->Text.ToDouble();
   dbcultivo->Item[numreg].plant->EDay=edEmDay->Text.ToInt();
   dbcultivo->Item[numreg].tuber->w=edPhotoSen->Text.ToDouble();
   dbcultivo->Item[numreg].tuber->Pc=edPhotoCrit->Text.ToDouble();
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameterPG::butDeleteClick(TObject *Sender)
{
  int reg=sgCrop->Row-2;
  if(reg>=18)
  {
    if(Application->MessageBox("Are you sure that you want to delete the parameter?", "Warning!", MB_YESNO)==IDYES)
    {
      dbcultivo->deleteReg(reg);
      PoblarGrilla();
      dbcultivo->saveAllParameters(dbcultivo->DBName);
      Application->MessageBox("The parameter was deleted!", "Successful!", MB_OK);
    }
  }
  else
  {
    Application->MessageBox("This parameter can not be deleted!", "Warning!", MB_OK);
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameterPG::butExportClick(TObject *Sender)
{
  TfrmImportCropParameter* frm=new TfrmImportCropParameter(2);
  frm->EnterInformation(dbcultivo);
  frm->ShowModal();
  bool exporto=frm->hizo;
  if(exporto)
  {
    Application->MessageBox("The selected crop parameters were exported!", "Successful!", MB_OK);
  }
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameterPG::cmdApplyClick(TObject *Sender)
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
bool TfrmCropParameterPG::Validate()
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
TEdit* TfrmCropParameterPG::FindDataError(int* _cod)
{
  double datod=0.0;
  int datoi=0;
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
  try
  {
    datod=edPhotoSen->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edPhotoSen;
  }
  try
  {
    datod=edPhotoCrit->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edPhotoCrit;
  }
  return edMaxgc;
}
//---------------------------------------------------------------------------
void TfrmCropParameterPG::ShowMessageError(int _cod)
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
void TfrmCropParameterPG::SaveData()
{
   cond->SelectedCrop = sgCrop->Row-2;
   strcpy(cond->cropname,edNameCrop->Text.c_str());
   cond->plant->fcl=edMaxgc->Text.ToDouble();
   cond->plant->F0=edIniLig->Text.ToDouble();
   cond->plant->R0=edIniGro->Text.ToDouble();
   cond->tuber->M=edMaxHI->Text.ToDouble();
   cond->tuber->A=edAsyHI->Text.ToDouble();
   cond->tuber->b=edSlopeHI->Text.ToDouble();
   cond->tuber->DMCont=edDMContent->Text.ToDouble();
   cond->plant->LUE=edAveLight->Text.ToDouble();
   cond->tuber->Tcr=edTcr->Text.ToDouble();
   cond->tuber->Tld=edTld->Text.ToDouble();
   cond->tuber->Trg=edTrg->Text.ToDouble();
   cond->plant->EDay=edEmDay->Text.ToInt();
   cond->plant->d=edDurLeaf->Text.ToDouble();
   cond->plant->t50=edThermal->Text.ToDouble();
   cond->tuber->w=edPhotoSen->Text.ToDouble();
   cond->tuber->Pc=edPhotoCrit->Text.ToDouble();
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameterPG::cmdCancelClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameterPG::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCropParameterPG::butImportClick(TObject *Sender)
{
  TfrmImportCropParameter* frm=new TfrmImportCropParameter(1);
  frm->EnterInformation(dbcultivo);
  frm->ShowModal();
  bool importo=frm->hizo;
  if(importo)
  {
    PoblarGrilla();
    dbcultivo->saveAllParameters(dbcultivo->DBName);
    Application->MessageBox("the parameters were imported to the database !!!", "Successful!", MB_OK);
  }
  delete frm;
}
//---------------------------------------------------------------------------

