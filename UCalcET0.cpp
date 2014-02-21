//---------------------------------------------------------------------------
#include <vcl.h>
#include <io.h>
#pragma hdrstop
#include "UCalcET0.h"
#include "UCampo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmCalcET0 *frmCalcET0;
//---------------------------------------------------------------------------
__fastcall TfrmCalcET0::TfrmCalcET0(TComponent* Owner)
        : TForm(Owner)
{
 condTemp=new ClimateFile(15000);
   sgClimate->RowCount=3;
   sgClimate->Cells[0][1]="Day";
   sgClimate->Cells[1][0]="Minimun Temp";
   sgClimate->Cells[2][0]="Maximun Temp";
   sgClimate->Cells[3][0]="Radiation";
   sgClimate->Cells[4][0]="Sunshine";
   sgClimate->Cells[5][0]="ET";
   sgClimate->Cells[1][1]="oC";
   sgClimate->Cells[2][1]="oC";
   sgClimate->Cells[3][1]="MJ/m2";
   sgClimate->Cells[4][1]="";
   sgClimate->Cells[5][1]="mm";
   sgClimate->RowHeights[0]=18;
   sgClimate->RowHeights[1]=18;
   sgClimate->ColWidths[0]=30;
   sgClimate->ColWidths[1]=80;
   sgClimate->ColWidths[2]=80;
   sgClimate->ColWidths[3]=80;
   sgClimate->ColWidths[4]=80;
   sgClimate->ColWidths[5]=80;
}
//---------------------------------------------------------------------------
void TfrmCalcET0::EnterInformation(ClimateFile *_cond)
{
cond=_cond;
CopyValuesToCondTemp();
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcET0::FormShow(TObject *Sender)
{
  int cant=AnsiString(cond->FileName).Length();
  if (cant==0)
  {
  }
  else
  {
    int existe=access(cond->FileName, 0);
    if(existe==-1) // el archivo no existe
    {
      Application->MessageBox("The specified file does not exist!!!","¡Warning!",MB_OK);
      return;
    }
    else
    {
      FileData *util=new FileData();
      AnsiString nombre = AnsiString(condTemp->FileName);
      int posicion=nombre.Pos(".");
      int longitud=nombre.Length();
      int caract=longitud-posicion;
      AnsiString ext=nombre.SubString(posicion+1,caract);
      if(ext=="prn") num=util->GetFieldsName(List,condTemp->FileName);
      if(ext=="csv") num=util->GetFieldsNameFromCSVFile(List,condTemp->FileName);
      delete util;
    }
  }
  PutValuesOnForm();
}
//---------------------------------------------------------------------------
void TfrmCalcET0::CopyValuesToCondTemp()
{
   strcpy(condTemp->FileName,cond->FileName);
   strcpy(condTemp->TitTMin,cond->TitTMin);
   strcpy(condTemp->TitTMax,cond->TitTMax);
   strcpy(condTemp->TitRad,cond->TitRad);
   strcpy(condTemp->TitSunshine,cond->TitSunshine);
   strcpy(condTemp->TitET,cond->TitET);
   condTemp->haveSunshine=cond->haveSunshine;
   condTemp->RecNum=cond->RecNum;
   for(int i=1;i<=condTemp->RecNum;i++)
   {
     condTemp->MinTemp[i-1]   = cond->MinTemp[i-1];
     condTemp->MaxTemp[i-1]   = cond->MaxTemp[i-1];
     condTemp->Radiation[i-1]   = cond->Radiation[i-1];
     condTemp->Sunshine[i-1]   = cond->Sunshine[i-1];
     condTemp->ET[i-1]   = cond->ET[i-1];
   }
   condTemp->Lat_Degrees=cond->Lat_Degrees;
   condTemp->Lat_Minutes=cond->Lat_Minutes;
   condTemp->Lat_Seconds=cond->Lat_Seconds;
   condTemp->Hemisphere=cond->Hemisphere;
   condTemp->z=cond->z;
   condTemp->G=cond->G;
   condTemp->Albedo=cond->Albedo;
   condTemp->Select_Wind_cat=cond->Select_Wind_cat;
   condTemp->ThermalCond=cond->ThermalCond;
   condTemp->Select_AP=cond->Select_AP;
}
//---------------------------------------------------------------------------
void TfrmCalcET0::PutValuesOnForm()
{
   edPathFile->Text=condTemp->FileName;
   edMinTemp->Text=condTemp->TitTMin;
   edMaxTemp->Text=condTemp->TitTMax;
   edRad->Text=condTemp->TitRad;
   edSunshine->Text=condTemp->TitSunshine;

   if(condTemp->RecNum==0)
   {
     sgClimate->RowCount=3;
   }
   else
   {
     sgClimate->RowCount=condTemp->RecNum+2;
   }

   for(int i=1;i<=condTemp->RecNum;i++)
   {
     sgClimate->RowHeights[i+1] = 18;
     sgClimate->Cells[0][i+1]   = i;
     sgClimate->Cells[1][i+1]   = condTemp->MinTemp[i-1];
     sgClimate->Cells[2][i+1]   = condTemp->MaxTemp[i-1];
     sgClimate->Cells[3][i+1]   = condTemp->Radiation[i-1];
     sgClimate->Cells[4][i+1]   = condTemp->Sunshine[i-1];
     sgClimate->Cells[5][i+1]   = condTemp->ET[i-1];
   }
   edLatDegree->Text=condTemp->Lat_Degrees;
   edLatMinutes->Text=condTemp->Lat_Minutes;
   edLatSeconds->Text=condTemp->Lat_Seconds;
   switch(condTemp->Hemisphere)
   {
    case 1:
      cbHemisphere->ItemIndex=0;
    break;
    case -1:
      cbHemisphere->ItemIndex=1;
    break;
    default:
    break;
   };
   edz->Text=condTemp->z;
   edG->Text=condTemp->G;
   edAlbedo->Text=condTemp->Albedo;
   cbSelect_Wind_cat->ItemIndex=condTemp->Select_Wind_cat-1;
   cbThermalCond->ItemIndex=condTemp->ThermalCond-1;
   cbSelect_AP->ItemIndex=condTemp->Select_AP-1;
   if(condTemp->haveSunshine==1)
   {
     chbSunshine->Checked=true;
     edSunshine->Enabled=true;
     cmdSunshine->Enabled=true;
   }
   else
   {
     chbSunshine->Checked=false;
     edSunshine->Enabled=false;
     cmdSunshine->Enabled=false;
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcET0::cmdCancelClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcET0::cmdApplyClick(TObject *Sender)
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
bool TfrmCalcET0::Validate()
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
TEdit* TfrmCalcET0::FindDataError(int* _cod)
{
//  int datoi;
//  try
//  {
//    datoi=edInput1->Text.ToInt();
//  }
//  catch(...)
//  {
//    *_cod=1; // 1: No es un valor entero
//    return edInput1;
//  }
  double datod=0.0;
  try
  {
    datod=edLatDegree->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edLatDegree;
  }
  try
  {
    datod=edLatMinutes->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edLatMinutes;
  }
  try
  {
    datod=edLatSeconds->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edLatSeconds;
  }
  try
  {
    datod=edz->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edz;
  }
  try
  {
    datod=edG->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edG;
  }
  try
  {
    datod=edAlbedo->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edAlbedo;
  }
  return edLatDegree;
}
//---------------------------------------------------------------------------
void TfrmCalcET0::ShowMessageError(int _cod)
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
void TfrmCalcET0::SaveData()
{
   strcpy( cond->TitTMin,condTemp->TitTMin);
   strcpy( cond->TitTMax,condTemp->TitTMax);
   strcpy( cond->TitRad,condTemp->TitRad);
   strcpy( cond->TitSunshine,condTemp->TitSunshine);
   strcpy( cond->TitET,condTemp->TitET);

   cond->RecNum=condTemp->RecNum;
   for(int i=1;i<=condTemp->RecNum;i++)
   {
     cond->MinTemp[i-1]=condTemp->MinTemp[i-1];
     cond->MaxTemp[i-1]=condTemp->MaxTemp[i-1];
     cond->Radiation[i-1]=condTemp->Radiation[i-1];
     cond->Sunshine[i-1]=condTemp->Sunshine[i-1];
     cond->ET[i-1]=condTemp->ET[i-1];
   }

   cond->Lat_Degrees=edLatDegree->Text.ToDouble();
   cond->Lat_Minutes=edLatMinutes->Text.ToDouble();
   cond->Lat_Seconds=edLatSeconds->Text.ToDouble();

   switch(cbHemisphere->ItemIndex)
   {
    case 0:
      cond->Hemisphere=1;
    break;
    case 1:
      cond->Hemisphere=-1;
    break;
    default:
    break;
   };

   cond->z=edz->Text.ToDouble();
   cond->G=edG->Text.ToDouble();
   cond->Albedo=edAlbedo->Text.ToDouble();

   cond->Select_Wind_cat=cbSelect_Wind_cat->ItemIndex+1;
   cond->ThermalCond=cbThermalCond->ItemIndex+1;
   cond->Select_AP=cbSelect_AP->ItemIndex+1;

   if(chbSunshine->Checked)
   {
     cond->haveSunshine=1;
   }
   else
   {
     cond->haveSunshine=0;
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcET0::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  delete condTemp;
  Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcET0::cmdMinTempClick(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Minimun temperature");
  if(frm->ShowModal()==mrOk)
  {
    edMinTemp->Text=frm->ReturnInformation();
    strcpy(condTemp->TitTMin, edMinTemp->Text.c_str());
    int numelem=condTemp->GetColumnData(condTemp->FileName,condTemp->TitTMin,condTemp->MinTemp);
    if(numelem==0) numelem=condTemp->GetColumnDataFromCSVFile(condTemp->FileName,condTemp->TitTMin,condTemp->MinTemp);
    sgClimate->RowCount=condTemp->RecNum+2;
    for(int i=1;i<=condTemp->RecNum;i++)
    {
     sgClimate->Cells[1][i+1]=condTemp->MinTemp[i-1];
    }
  }
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcET0::cmdMaxTempClick(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Maximun temperature");
  if(frm->ShowModal()==mrOk)
  {
    edMaxTemp->Text=frm->ReturnInformation();
    strcpy(condTemp->TitTMax, edMaxTemp->Text.c_str());
    int numelem=condTemp->GetColumnData(condTemp->FileName,condTemp->TitTMax,condTemp->MaxTemp);
    if(numelem==0)numelem=condTemp->GetColumnDataFromCSVFile(condTemp->FileName,condTemp->TitTMax,condTemp->MaxTemp);
    sgClimate->RowCount=condTemp->RecNum+2;
    for(int i=1;i<=condTemp->RecNum;i++)
    {
     sgClimate->Cells[2][i+1]=condTemp->MaxTemp[i-1];
    }
  }
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcET0::cmdRadClick(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Radiation");
  if(frm->ShowModal()==mrOk)
  {
    edRad->Text=frm->ReturnInformation();
    strcpy(condTemp->TitRad, edRad->Text.c_str());
    int numelem=condTemp->GetColumnData(condTemp->FileName,condTemp->TitRad,condTemp->Radiation);
    if(numelem==0)numelem=condTemp->GetColumnDataFromCSVFile(condTemp->FileName,condTemp->TitRad,condTemp->Radiation);
    sgClimate->RowCount=condTemp->RecNum+2;
    for(int i=1;i<=condTemp->RecNum;i++)
    {
     sgClimate->Cells[3][i+1]=condTemp->Radiation[i-1];
    }
  }
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcET0::cmdSunshineClick(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Sunshine");
  if(frm->ShowModal()==mrOk)
  {
    edSunshine->Text=frm->ReturnInformation();
    strcpy(condTemp->TitSunshine, edSunshine->Text.c_str());
    int numelem=condTemp->GetColumnData(condTemp->FileName,condTemp->TitSunshine,condTemp->Sunshine);
    if(numelem==0)numelem=condTemp->GetColumnDataFromCSVFile(condTemp->FileName,condTemp->TitSunshine,condTemp->Sunshine);
    sgClimate->RowCount=condTemp->RecNum+2;
    for(int i=1;i<=condTemp->RecNum;i++)
    {
     sgClimate->Cells[4][i+1]=condTemp->Sunshine[i-1];
    }
  }
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcET0::butGenerateET0Click(TObject *Sender)
{
   condTemp->Lat_Degrees=edLatDegree->Text.ToDouble();
   condTemp->Lat_Minutes=edLatMinutes->Text.ToDouble();
   condTemp->Lat_Seconds=edLatSeconds->Text.ToDouble();

   switch(cbHemisphere->ItemIndex)
   {
    case 0:
      condTemp->Hemisphere=1;
    break;
    case 1:
      condTemp->Hemisphere=-1;
    break;
    default:
    break;
   };
   condTemp->z=edz->Text.ToDouble();
   condTemp->G=edG->Text.ToDouble();
   condTemp->Albedo=edAlbedo->Text.ToDouble();

   condTemp->Select_Wind_cat=cbSelect_Wind_cat->ItemIndex+1;
   condTemp->ThermalCond=cbThermalCond->ItemIndex+1;
   condTemp->Select_AP=cbSelect_AP->ItemIndex+1;
   if(chbSunshine->Checked)
   {
     condTemp->haveSunshine=1;
   }
   else
   {
     condTemp->haveSunshine=0;
   }
   condTemp->CalcularET0();
   sgClimate->RowCount=condTemp->RecNum+2;
   for(int i=1;i<=condTemp->RecNum;i++)
   {
     sgClimate->Cells[5][i+1]=FormatFloat("00.00",condTemp->ET[i-1]);
     sgClimate->Cells[4][i+1]=FormatFloat("00.00",condTemp->Sunshine[i-1]);
   }
   strcpy(condTemp->TitET,"Calculated using the tool 'Calculator ET0'");
}
//---------------------------------------------------------------------------

void __fastcall TfrmCalcET0::chbSunshineClick(TObject *Sender)
{
  if(chbSunshine->Checked)
  {
     edSunshine->Enabled=true;
     cmdSunshine->Enabled=true;
  }
  else
  {
     edSunshine->Enabled=false;
     cmdSunshine->Enabled=false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmCalcET0::butSaveET0Click(TObject *Sender)
{
  AnsiString NomArchivo;
  bool exito=false;
  if(sdResult->Execute())
  {
    NomArchivo=sdResult->FileName;
    exito=condTemp->saveET0(NomArchivo.c_str());
    if(exito)
    {
    Application->MessageBox("Information about Evapotranspiration was saved!", "Successful!", MB_OK);
    }
  }
}
//---------------------------------------------------------------------------

