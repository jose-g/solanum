//---------------------------------------------------------------------------
#include <vcl.h>
#include <io.h>
#pragma hdrstop
#include "UCalcSoilTemp.h"
#include "UCampo.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmCalcSoilTemp *frmCalcSoilTemp;
//---------------------------------------------------------------------------
__fastcall TfrmCalcSoilTemp::TfrmCalcSoilTemp(TComponent* Owner)
        : TForm(Owner)
{
 condTemp=new ManageDataPotato(0);
   sgClimate->RowCount=3;
   sgClimate->Cells[0][1]="Day";
   sgClimate->Cells[1][0]="Minimun Temp";
   sgClimate->Cells[2][0]="Maximun Temp";
   sgClimate->Cells[3][0]="Soil Temp";
   sgClimate->Cells[1][1]="oC";
   sgClimate->Cells[2][1]="oC";
   sgClimate->Cells[3][1]="oC";
   sgClimate->RowHeights[0]=18;
   sgClimate->RowHeights[1]=18;
   sgClimate->ColWidths[0]=30;
   sgClimate->ColWidths[1]=80;
   sgClimate->ColWidths[2]=80;
   sgClimate->ColWidths[3]=50;
}
//---------------------------------------------------------------------------
void TfrmCalcSoilTemp::EnterInformation(ManageDataPotato *_cond)
{
cond=_cond;
CopyValuesToCondTemp();
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcSoilTemp::FormShow(TObject *Sender)
{
  int cant=AnsiString(cond->climate->FileName).Length();
  if (cant==0)
  {
  }
  else
  {
    int existe=access(cond->climate->FileName, 0);
    if(existe==-1) // el archivo no existe
    {
      Application->MessageBox("The specified file does not exist!!!","¡Warning!",MB_OK);
      return;
    }
    else
    {
      FileData *util=new FileData();
      AnsiString nombre = AnsiString(cond->climate->FileName);
      int posicion=nombre.Pos(".");
      int longitud=nombre.Length();
      int caract=longitud-posicion;
      AnsiString ext=nombre.SubString(posicion+1,caract);
      if(ext=="prn") num=util->GetFieldsName(List,cond->climate->FileName);
      if(ext=="csv") num=util->GetFieldsNameFromCSVFile(List,cond->climate->FileName);
      delete util;
    }
  }
  for(int i=0;i<condTemp->soil->SoilNumber;i++)
  {
     cbSoilTexture->Items->Add(condTemp->soil->SoilList[i]);
  }
  PutValuesOnForm();
}
//---------------------------------------------------------------------------
void TfrmCalcSoilTemp::CopyValuesToCondTemp()
{
   strcpy(condTemp->climate->FileName,cond->climate->FileName);
   strcpy(condTemp->climate->TitTMin,cond->climate->TitTMin);
   strcpy(condTemp->climate->TitTMax,cond->climate->TitTMax);
   strcpy(condTemp->climate->TitSoilTemp,cond->climate->TitSoilTemp);

   condTemp->climate->RecNum=cond->climate->RecNum;
   for(int i=1;i<=condTemp->climate->RecNum;i++)
   {
     condTemp->climate->MinTemp[i-1]   = cond->climate->MinTemp[i-1];
     condTemp->climate->MaxTemp[i-1]   = cond->climate->MaxTemp[i-1];
     condTemp->climate->SoilTemp[i-1]   = cond->climate->SoilTemp[i-1];
   }
   condTemp->soil->SelectedSoil=cond->soil->SelectedSoil;
   condTemp->soil->SoilDepth=cond->soil->SoilDepth;
   condTemp->soil->MaxDepth=cond->soil->MaxDepth;
}
//---------------------------------------------------------------------------
void TfrmCalcSoilTemp::PutValuesOnForm()
{
   edPathFile->Text=condTemp->climate->FileName;
   edMinTemp->Text=condTemp->climate->TitTMin;
   edMaxTemp->Text=condTemp->climate->TitTMax;

   cbSoilTexture->ItemIndex=condTemp->soil->SelectedSoil-1;
   edSoilDepth->Text=condTemp->soil->SoilDepth;
   edMaxDepth->Text=condTemp->soil->MaxDepth;

   if(condTemp->climate->RecNum==0)
   {
     sgClimate->RowCount=3;
   }
   else
   {
     sgClimate->RowCount=condTemp->climate->RecNum+2;
   }

   for(int i=1;i<=condTemp->climate->RecNum;i++)
   {
     sgClimate->RowHeights[i+1] = 18;
     sgClimate->Cells[0][i+1]   = i;
     sgClimate->Cells[1][i+1]   = condTemp->climate->MinTemp[i-1];
     sgClimate->Cells[2][i+1]   = condTemp->climate->MaxTemp[i-1];
     sgClimate->Cells[3][i+1]   = condTemp->climate->SoilTemp[i-1];
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcSoilTemp::cmdCancelClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcSoilTemp::cmdApplyClick(TObject *Sender)
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
bool TfrmCalcSoilTemp::Validate()
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
TEdit* TfrmCalcSoilTemp::FindDataError(int* _cod)
{
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
}
//---------------------------------------------------------------------------
void TfrmCalcSoilTemp::ShowMessageError(int _cod)
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
void TfrmCalcSoilTemp::SaveData()
{
   strcpy(cond->climate->TitTMin,condTemp->climate->TitTMin);
   strcpy(cond->climate->TitTMax,condTemp->climate->TitTMax);
   strcpy(cond->climate->TitSoilTemp,condTemp->climate->TitSoilTemp);
   cond->climate->RecNum=condTemp->climate->RecNum;
   for(int i=1;i<=condTemp->climate->RecNum;i++)
   {
     cond->climate->MinTemp[i-1]=condTemp->climate->MinTemp[i-1];
     cond->climate->MaxTemp[i-1]=condTemp->climate->MaxTemp[i-1];
     cond->climate->SoilTemp[i-1]=condTemp->climate->SoilTemp[i-1];
   }
   cond->soil->SelectedSoil=cbSoilTexture->ItemIndex+1;
   cond->soil->SoilDepth=edSoilDepth->Text.ToDouble();
   cond->soil->MaxDepth=edMaxDepth->Text.ToDouble();
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcSoilTemp::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  delete condTemp;
  Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcSoilTemp::cmdMinTempClick(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Minimun temperature");
  if(frm->ShowModal()==mrOk)
  {
    edMinTemp->Text=frm->ReturnInformation();
    strcpy(condTemp->climate->TitTMin, edMinTemp->Text.c_str());
    int numelem=condTemp->climate->GetColumnData(condTemp->climate->FileName,condTemp->climate->TitTMin,condTemp->climate->MinTemp);
    if(numelem==0) numelem=condTemp->climate->GetColumnDataFromCSVFile(condTemp->climate->FileName,condTemp->climate->TitTMin,condTemp->climate->MinTemp);
    sgClimate->RowCount=condTemp->climate->RecNum+2;
    for(int i=1;i<=condTemp->climate->RecNum;i++)
    {
     sgClimate->Cells[1][i+1]=condTemp->climate->MinTemp[i-1];
    }
  }
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcSoilTemp::cmdMaxTempClick(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Maximun temperature");
  if(frm->ShowModal()==mrOk)
  {
    edMaxTemp->Text=frm->ReturnInformation();
    strcpy(condTemp->climate->TitTMax, edMaxTemp->Text.c_str());
    int numelem=condTemp->climate->GetColumnData(condTemp->climate->FileName,condTemp->climate->TitTMax,condTemp->climate->MaxTemp);
    if(numelem==0)numelem=condTemp->climate->GetColumnDataFromCSVFile(condTemp->climate->FileName,condTemp->climate->TitTMax,condTemp->climate->MaxTemp);
    sgClimate->RowCount=condTemp->climate->RecNum+2;
    for(int i=1;i<=condTemp->climate->RecNum;i++)
    {
     sgClimate->Cells[2][i+1]=condTemp->climate->MaxTemp[i-1];
    }
  }
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcSoilTemp::butGenSoilTempClick(TObject *Sender)
{
  double SoilDepth=edSoilDepth->Text.ToDouble();
  double Dl=edMaxDepth->Text.ToDouble();
  double Soil_texture=cbSoilTexture->ItemIndex;
  condTemp->soil->SelectedSoil=Soil_texture+1;
  condTemp->soil->SetVariables();
  double c=condTemp->soil->c;
  double k=condTemp->soil->k;
  double BD=condTemp->soil->BD*1000;
  for(int i=1;i<=condTemp->climate->RecNum;i++)
  {
     double tmin=condTemp->climate->MinTemp[i-1];
     double tmax=condTemp->climate->MaxTemp[i-1];
     double Tav=(tmin+tmax)/2.0;
     double Tl=1.25*Tav;
     double D=SoilDepth*100;
     double Stemp=2/3.1416*(Tav-Tl)*exp(-(k/(BD*c))*pow(3.1416,2)*1.0E+10/pow(Dl,2))*sin(3.1416*D/Dl)+Tav+(Tl-Tav)/Dl*D;
     double Stemp_Redond=floor(Stemp * 100.0 + 0.5) / 100.0; // se redondea el valor de Stemp a dos decimales
     condTemp->climate->SoilTemp[i-1]=Stemp_Redond;
     sgClimate->Cells[3][i+1]=condTemp->climate->SoilTemp[i-1];
  }
  strcpy(condTemp->climate->TitSoilTemp,"Calculated using the tool 'Calculator Soil Temperature'");
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcSoilTemp::butSaveET0Click(TObject *Sender)
{
  AnsiString NomArchivo;
  bool exito=false;
  if(sdResult->Execute())
  {
    NomArchivo=sdResult->FileName;
    exito=condTemp->climate->saveSoil(NomArchivo.c_str());
    if(exito)
    {
    Application->MessageBox("Information about Soil temperature was saved!", "Successful!", MB_OK);
    }
  }
}
//---------------------------------------------------------------------------

