//---------------------------------------------------------------------------
#include <vcl.h>
#include <io.h>
#include <string.h>
#include <math.h>

#pragma hdrstop
#include "UDatabaseClimate.h"
#include "UCampo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmClimateAM *frmClimateAM;
//---------------------------------------------------------------------------
__fastcall TfrmClimateAM::TfrmClimateAM(TComponent* Owner,ClimateFile *_cond)
        : TForm(Owner)
{
Initialize();
cond=_cond;
CopyValuesToCondTemp();
}
//---------------------------------------------------------------------------
__fastcall TfrmClimateAM::TfrmClimateAM(TComponent* Owner)
        : TForm(Owner)
{
Initialize();
cond=new ClimateFile(15000);
//GetDemo();
}
//---------------------------------------------------------------------------
void TfrmClimateAM::Initialize()
{
 condTemp=new ClimateFile(15000);
   sgClimate->RowCount=3;
   sgClimate->Cells[0][1]="#";
   sgClimate->Cells[1][0]="Day";
   sgClimate->Cells[2][0]="Month";
   sgClimate->Cells[3][0]="Year";
   sgClimate->Cells[4][0]="Date";
   sgClimate->Cells[5][0]="Minimun Temp";
   sgClimate->Cells[6][0]="Maximun Temp";
   sgClimate->Cells[7][0]="Precipitation";
   sgClimate->Cells[8][0]="Radiation";
   sgClimate->Cells[9][0]="ET";
   sgClimate->Cells[10][0]="Irrigation";
   sgClimate->Cells[11][0]="Soil Temp";
   sgClimate->Cells[5][1]="oC";
   sgClimate->Cells[6][1]="oC";
   sgClimate->Cells[7][1]="mm";
   sgClimate->Cells[8][1]="MJ/m2";
   sgClimate->Cells[9][1]="mm";
   sgClimate->Cells[10][1]="mm";
   sgClimate->Cells[11][1]="oC";
   sgClimate->RowHeights[0]=18;
   sgClimate->ColWidths[0]=30;
   sgClimate->ColWidths[1]=50;
   sgClimate->ColWidths[2]=50;
   sgClimate->ColWidths[3]=50;
   sgClimate->ColWidths[4]=50;
   sgClimate->ColWidths[5]=80;
   sgClimate->ColWidths[6]=80;
   sgClimate->ColWidths[7]=80;
   sgClimate->ColWidths[8]=50;
   sgClimate->ColWidths[9]=50;
   sgClimate->ColWidths[10]=50;
   sgClimate->ColWidths[11]=60;
}
//---------------------------------------------------------------------------
void TfrmClimateAM::EnterInformation(ClimateFile *_cond)
{
 cond=_cond;
 CopyValuesToCondTemp();
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimateAM::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  delete condTemp;
  delete cond; // tener cuidado al eliminar este objeto, si este formulario se inicializo con el primer constructor no se deberia borrar el objeto cond
  Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimateAM::FormShow(TObject *Sender)
{
  int cant=AnsiString(condTemp->FileName).Length();
  if (cant==0)
  {
  }
  else
  {
    int existe=access(condTemp->FileName, 0);
    if(existe==-1) // el archivo no existe
    {
      Application->MessageBox("The specified file does not exist!!!","¡Advertencia!",MB_OK);
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
void TfrmClimateAM::CopyValuesToCondTemp()
{
   strcpy(condTemp->FileName,cond->FileName);
   strcpy(condTemp->TitTMin,cond->TitTMin);
   strcpy(condTemp->TitTMax,cond->TitTMax);
   strcpy(condTemp->TitPrec,cond->TitPrec);
   strcpy(condTemp->TitRad,cond->TitRad);
   strcpy(condTemp->TitET,cond->TitET);
   strcpy(condTemp->TitIrri,cond->TitIrri);
   strcpy(condTemp->TitSoilTemp,cond->TitSoilTemp);
   strcpy(condTemp->TitDay,cond->TitDay);
   strcpy(condTemp->TitMonth,cond->TitMonth);
   strcpy(condTemp->TitYear,cond->TitYear);
   strcpy(condTemp->TitSunshine,cond->TitSunshine);
   condTemp->RecNum=cond->RecNum;
   for(int i=1;i<=condTemp->RecNum;i++)
   {
     condTemp->MinTemp[i-1]   = cond->MinTemp[i-1];
     condTemp->MaxTemp[i-1]   = cond->MaxTemp[i-1];
     condTemp->Precipit[i-1]   = cond->Precipit[i-1];
     condTemp->Radiation[i-1]   = cond->Radiation[i-1];
     condTemp->ET[i-1]   = cond->ET[i-1];
     condTemp->Irri[i-1]   = cond->Irri[i-1];
     condTemp->SoilTemp[i-1]   = cond->SoilTemp[i-1];
     condTemp->Sunshine[i-1]   = cond->Sunshine[i-1];
     condTemp->Day[i-1]   = cond->Day[i-1];
     condTemp->Month[i-1]   = cond->Month[i-1];
     condTemp->Year[i-1]   = cond->Year[i-1];
   }
}
//---------------------------------------------------------------------------
void TfrmClimateAM::PutValuesOnForm()
{
   edPathFile->Text=condTemp->FileName;
   edMinTemp->Text=condTemp->TitTMin;
   edMaxTemp->Text=condTemp->TitTMax;
   edPrecip->Text=condTemp->TitPrec;
   edRad->Text=condTemp->TitRad;
   edET->Text=condTemp->TitET;
   edIrri->Text=condTemp->TitIrri;
   edSoilTemp->Text=condTemp->TitSoilTemp;

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
     sgClimate->Cells[5][i+1]   = condTemp->MinTemp[i-1];
     sgClimate->Cells[6][i+1]   = condTemp->MaxTemp[i-1];
     sgClimate->Cells[7][i+1]   = condTemp->Precipit[i-1];
     sgClimate->Cells[8][i+1]   = condTemp->Radiation[i-1];
     sgClimate->Cells[9][i+1]   = condTemp->ET[i-1];
     sgClimate->Cells[10][i+1]   = condTemp->Irri[i-1];
     sgClimate->Cells[11][i+1]   = condTemp->SoilTemp[i-1];
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimateAM::cmdCancelClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimateAM::cmdApplyClick(TObject *Sender)
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
bool TfrmClimateAM::Validate()
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
TEdit* TfrmClimateAM::FindDataError(int* _cod)
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
//  double datod=0.0;
//  try
//  {
//    datod=edInput2->Text.ToDouble();
//  }
//  catch(...)
//  {
//    *_cod=2; // 2: No es un valor real
//    return edInput2;
//  }
//  try
//  {
//    datod=edInput3->Text.ToDouble();
//  }
//  catch(...)
//  {
//    *_cod=2; // 2: No es un valor real
//    return edInput3;
//  }
  return edPathFile;
}
//---------------------------------------------------------------------------
void TfrmClimateAM::ShowMessageError(int _cod)
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
void TfrmClimateAM::SaveData()
{
   strcpy( cond->FileName,condTemp->FileName);
   strcpy( cond->TitTMin,condTemp->TitTMin);
   strcpy( cond->TitTMax,condTemp->TitTMax);
   strcpy( cond->TitPrec,condTemp->TitPrec);
   strcpy( cond->TitRad,condTemp->TitRad);
   strcpy( cond->TitET,condTemp->TitET);
   strcpy( cond->TitIrri,condTemp->TitIrri);
   strcpy( cond->TitSoilTemp,condTemp->TitSoilTemp);
   strcpy( cond->TitDay,condTemp->TitDay);
   strcpy( cond->TitMonth,condTemp->TitMonth);
   strcpy( cond->TitYear,condTemp->TitYear);
   strcpy( cond->TitSunshine,condTemp->TitSunshine);

   cond->RecNum=condTemp->RecNum;
   for(int i=1;i<=condTemp->RecNum;i++)
   {
     cond->MinTemp[i-1]=condTemp->MinTemp[i-1];
     cond->MaxTemp[i-1]=condTemp->MaxTemp[i-1];
     cond->Precipit[i-1]=condTemp->Precipit[i-1];
     cond->Radiation[i-1]=condTemp->Radiation[i-1];
     cond->ET[i-1]=condTemp->ET[i-1];
     cond->Irri[i-1]=condTemp->Irri[i-1];
     cond->SoilTemp[i-1]=condTemp->SoilTemp[i-1];
     cond->Sunshine[i-1]=condTemp->Sunshine[i-1];
     cond->Day[i-1]=condTemp->Day[i-1];
     cond->Month[i-1]=condTemp->Month[i-1];
     cond->Year[i-1]=condTemp->Year[i-1];
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimateAM::cmdOpenClimateClick(TObject *Sender)
{
  if(odClimate->Execute())
  {
     FileData *util=new FileData();
     int numTemp=0;
     if(odClimate->FilterIndex==1)
     {
       numTemp = util->GetFieldsNameFromCSVFile(ListTemp,odClimate->FileName.c_str());
     }
     if(odClimate->FilterIndex==2)
     {
       numTemp = util->GetFieldsName(ListTemp,odClimate->FileName.c_str());
     }
     delete util;
     // si se captura los titulos
if(numTemp>0)
{
   edPathFile -> Text = odClimate->FileName;
   strcpy(condTemp->FileName,odClimate->FileName.c_str());

   condTemp->CleanTitles();
   edMinTemp  -> Text = "";
   edMaxTemp  -> Text = "";
   edPrecip   -> Text = "";
   edRad      -> Text = "";
   edET      -> Text = "";
   edIrri      -> Text = "";
   edSoilTemp      -> Text = "";
   condTemp->CleanVectorClimate();

   if(odClimate->FilterIndex==1)
   {
     condTemp->RecNum=condTemp->CountRegistersFromCSVFile(condTemp->FileName);
   }
   if(odClimate->FilterIndex==2)
   {
     condTemp->RecNum=condTemp->CountRegisters(condTemp->FileName);
   }
   sgClimate->RowCount=condTemp->RecNum+2;
   for(int i=2;i<=sgClimate->RowCount;i++)
   {
     for(int j=1;j<=11;j++)
     {
       sgClimate->Cells[j][i]="";
     }
     sgClimate->Cells[0][i]=i-1;
   }
}
/*
     else
     {
      Application->MessageBox("No information on the climate file!", "Warning!", MB_OK);
     }
*/
}
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimateAM::cmdMinTempClick(TObject *Sender)
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
     sgClimate->Cells[5][i+1]=condTemp->MinTemp[i-1];
    }
  }
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimateAM::cmdMaxTempClick(TObject *Sender)
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
     sgClimate->Cells[6][i+1]=condTemp->MaxTemp[i-1];
    }
  }
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimateAM::cmdPrecipClick(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Precipitation");
  if(frm->ShowModal()==mrOk)
  {
    edPrecip->Text=frm->ReturnInformation();
    strcpy(condTemp->TitPrec, edPrecip->Text.c_str());
    int numelem=condTemp->GetColumnData(condTemp->FileName,condTemp->TitPrec,condTemp->Precipit);
    if(numelem==0)numelem=condTemp->GetColumnDataFromCSVFile(condTemp->FileName,condTemp->TitPrec,condTemp->Precipit);
    sgClimate->RowCount=condTemp->RecNum+2;
    for(int i=1;i<=condTemp->RecNum;i++)
    {
     sgClimate->Cells[7][i+1]=condTemp->Precipit[i-1];
    }
  }
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimateAM::cmdRadiationClick(TObject *Sender)
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
     sgClimate->Cells[8][i+1]=condTemp->Radiation[i-1];
    }
  }
  delete frm;
}
//---------------------------------------------------------------------------

void __fastcall TfrmClimateAM::cmdET0Click(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Evapotranspiration");
  if(frm->ShowModal()==mrOk)
  {
    edET->Text=frm->ReturnInformation();
    strcpy(condTemp->TitET, edET->Text.c_str());
    int numelem=condTemp->GetColumnData(condTemp->FileName,condTemp->TitET,condTemp->ET);
    if(numelem==0)numelem=condTemp->GetColumnDataFromCSVFile(condTemp->FileName,condTemp->TitET,condTemp->ET);
    sgClimate->RowCount=condTemp->RecNum+2;
    for(int i=1;i<=condTemp->RecNum;i++)
    {
     sgClimate->Cells[9][i+1]=condTemp->ET[i-1];
    }
  }
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimateAM::cmdIrrigationClick(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Irrigation");
  if(frm->ShowModal()==mrOk)
  {
    edIrri->Text=frm->ReturnInformation();
    strcpy(condTemp->TitIrri, edIrri->Text.c_str());
    int numelem=condTemp->GetColumnData(condTemp->FileName,condTemp->TitIrri,condTemp->Irri);
    if(numelem==0)numelem=condTemp->GetColumnDataFromCSVFile(condTemp->FileName,condTemp->TitIrri,condTemp->Irri);
    sgClimate->RowCount=condTemp->RecNum+2;
    for(int i=1;i<=condTemp->RecNum;i++)
    {
     sgClimate->Cells[10][i+1]=condTemp->Irri[i-1];
    }
  }
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimateAM::cmdSoilClick(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Soil Temperature");
  if(frm->ShowModal()==mrOk)
  {
    edSoilTemp->Text=frm->ReturnInformation();
    strcpy(condTemp->TitSoilTemp, edSoilTemp->Text.c_str());
    int numelem=condTemp->GetColumnData(condTemp->FileName,condTemp->TitSoilTemp,condTemp->SoilTemp);
    if(numelem==0)numelem=condTemp->GetColumnDataFromCSVFile(condTemp->FileName,condTemp->TitSoilTemp,condTemp->SoilTemp);
    sgClimate->RowCount=condTemp->RecNum+2;
    for(int i=1;i<=condTemp->RecNum;i++)
    {
     sgClimate->Cells[11][i+1]=condTemp->SoilTemp[i-1];
    }
  }
  delete frm;
}
//---------------------------------------------------------------------------

void __fastcall TfrmClimateAM::cmdDayClick(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Day");
  if(frm->ShowModal()==mrOk)
  {
    edDay->Text=frm->ReturnInformation();
    strcpy(condTemp->TitDay, edDay->Text.c_str());

    int numelem=condTemp->GetColumnData(condTemp->FileName,condTemp->TitDay,condTemp->Day);
    if(numelem==0) numelem=condTemp->GetColumnDataFromCSVFile(condTemp->FileName,condTemp->TitDay,condTemp->Day);

    sgClimate->RowCount=condTemp->RecNum+2;
    for(int i=1;i<=condTemp->RecNum;i++)
    {
     sgClimate->Cells[1][i+1]=condTemp->Day[i-1];
    }
  }
  delete frm;
}
//---------------------------------------------------------------------------

void __fastcall TfrmClimateAM::cmdMonthClick(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Month");
  if(frm->ShowModal()==mrOk)
  {
    edMonth->Text=frm->ReturnInformation();
    strcpy(condTemp->TitMonth, edMonth->Text.c_str());

    int numelem=condTemp->GetColumnData(condTemp->FileName,condTemp->TitMonth,condTemp->Month);
    if(numelem==0) numelem=condTemp->GetColumnDataFromCSVFile(condTemp->FileName,condTemp->TitMonth,condTemp->Month);

    sgClimate->RowCount=condTemp->RecNum+2;
    for(int i=1;i<=condTemp->RecNum;i++)
    {
     sgClimate->Cells[2][i+1]=condTemp->Month[i-1];
    }
  }
  delete frm;
}
//---------------------------------------------------------------------------

void __fastcall TfrmClimateAM::cmdYearClick(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Year");
  if(frm->ShowModal()==mrOk)
  {
    edYear->Text=frm->ReturnInformation();
    strcpy(condTemp->TitYear, edYear->Text.c_str());

    int numelem=condTemp->GetColumnData(condTemp->FileName,condTemp->TitYear,condTemp->Year);
    if(numelem==0) numelem=condTemp->GetColumnDataFromCSVFile(condTemp->FileName,condTemp->TitYear,condTemp->Year);

    sgClimate->RowCount=condTemp->RecNum+2;
    for(int i=1;i<=condTemp->RecNum;i++)
    {
     sgClimate->Cells[3][i+1]=condTemp->Year[i-1];
    }
  }
  delete frm;
}
//---------------------------------------------------------------------------

void __fastcall TfrmClimateAM::Button1Click(TObject *Sender)
{
//    TDateTime Start = StrToDate(edtStart->Text);
//    TDateTime End   = StrToDate(edtEnd->Text);
    TDateTime Start = dtpPlantingDate->Date;
    TDateTime End   = dtpHarvestDate->Date;
    TDateTime Diff  = End - Start;
    double d        = Diff.operator double();
    Edit15->Text = round(d);

    Edit17->Text=dtpPlantingDate->Date.DateString();
    TDateTime DateValue = StrToDate(Edit17->Text);
    ShortDateFormat = "d";
    Edit16->Text = DateValue;
}
//---------------------------------------------------------------------------
double TfrmClimateAM::round(double number)
{
    return number < 0.0 ? ceil(number - 0.5) : floor(number + 0.5);
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimateAM::sgClimateMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
TPoint RClkPoint;
if (Button != mbRight)
  return;
sgClimate->MouseToCell (X, Y, RClkCol, RClkRow);
//if ((RClkCol < 0) || (RClkRow < 0))
//{
//    return;
//}
if ((RClkCol < sgClimate->FixedCols) || (RClkRow < sgClimate->FixedRows))
{
  //  The user clicked on a fixed cell.
  //  Hide the convert items.
    SetPlantingDate->Visible = false;
    SetHarvestDate->Visible = false;
}
else
{
    SetPlantingDate->Visible = true;
    SetHarvestDate->Visible = true;
}
RClkPoint = sgClimate->ClientToScreen(Point (X, Y));
GridMenu->Popup (RClkPoint.x, RClkPoint.y);
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimateAM::SetHarvestDateClick(TObject *Sender)
{
if(!Mensajes()) return;
AnsiString fecha=sgClimate->Cells[2][RClkRow]+"/"+sgClimate->Cells[1][RClkRow]+"/"+sgClimate->Cells[3][RClkRow];
dtpHarvestDate->Date=StrToDate(fecha);
AnsiString mensaje="You have selected "+fecha+" like 'Harvest date'";
Application->MessageBox(mensaje.c_str(), "Done!", MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TfrmClimateAM::SetPlantingDateClick(TObject *Sender)
{
if(!Mensajes()) return;
AnsiString fecha=sgClimate->Cells[2][RClkRow]+"/"+sgClimate->Cells[1][RClkRow]+"/"+sgClimate->Cells[3][RClkRow];
dtpPlantingDate->Date=StrToDate(fecha);
AnsiString mensaje="You have selected "+fecha+" like 'Planting date'";
Application->MessageBox(mensaje.c_str(), "Done!", MB_OK);
}
//---------------------------------------------------------------------------
bool TfrmClimateAM::Mensajes()
{
if(sgClimate->Cells[1][RClkRow]=="")
{
  AnsiString mensaje="There is no information in the column of Day, load the information !!!";
  Application->MessageBox(mensaje.c_str(), "Warning!", MB_OK);
  return false;
}
if(sgClimate->Cells[2][RClkRow]=="")
{
  AnsiString mensaje="There is no information in the column of Month, load the information !!!";
  Application->MessageBox(mensaje.c_str(), "Warning!", MB_OK);
  return false;
}
if(sgClimate->Cells[3][RClkRow]=="")
{
  AnsiString mensaje="There is no information in the column of Year, load the information !!!";
  Application->MessageBox(mensaje.c_str(), "Warning!", MB_OK);
  return false;
}
return true;
}
//---------------------------------------------------------------------------

