//---------------------------------------------------------------------------
#include <io.h>
#include <vcl.h>
#pragma hdrstop

#include "UEstadistico.h"
#include "UReportTXT.h"
#include "UCampo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmEstadistico *frmEstadistico;
//---------------------------------------------------------------------------
__fastcall TfrmEstadistico::TfrmEstadistico(TComponent* Owner)
        : TForm(Owner)
{
Initialize();
}
//---------------------------------------------------------------------------
void TfrmEstadistico::EnterInformation(ManageDataPotato *_cond)
{
cond=_cond;
CopyValuesToCondTemp();
}
//---------------------------------------------------------------------------
void TfrmEstadistico::Initialize()
{
   condTemp=new Simulation(0);
   sgFY->RowCount=3;
   sgFY->RowHeights[0]=18;
   sgFY->RowHeights[1]=18;
   sgFY->Cells[0][1]="#";
   sgFY->Cells[1][0]="Fresh yield";
   sgFY->Cells[2][0]="Fresh yield";
   sgFY->Cells[1][1]="Estimated";
   sgFY->Cells[2][1]="Observed";
   sgFY->ColWidths[0]=30;
   sgFY->ColWidths[1]=84;
   sgFY->ColWidths[2]=84;

   sgCC->RowCount=3;
   sgCC->RowHeights[0]=18;
   sgCC->RowHeights[1]=18;
   sgCC->Cells[0][1]="#";
   sgCC->Cells[1][0]="Canopy cover";
   sgCC->Cells[2][0]="Canopy cover";
   sgCC->Cells[1][1]="Estimated";
   sgCC->Cells[2][1]="Observed";
   sgCC->ColWidths[0]=30;
   sgCC->ColWidths[1]=102;
   sgCC->ColWidths[2]=102;
}
//---------------------------------------------------------------------------
void TfrmEstadistico::CopyValuesToCondTemp()
{
   strcpy(condTemp->obsFileName,cond->simulation->obsFileName);
   strcpy(condTemp->TitObsFY,cond->simulation->TitObsFY);
   strcpy(condTemp->TitObsCC,cond->simulation->TitObsCC);
   for(int i=1;i<=cond->time->duration;i++)
   {
     if(cond->simulation->idModel==1)
     {
      condTemp->Xfty[i-1]=cond->simulation->Xfty[i-1];
      condTemp->Xcc[i-1]=cond->simulation->Xcc[i-1];
     }
     if(cond->simulation->idModel==2)
     {
      condTemp->Xftyw[i-1]=cond->simulation->Xftyw[i-1];
      condTemp->Xccw[i-1]=cond->simulation->Xccw[i-1];
     }
     if(cond->simulation->idModel==3)
     {
      condTemp->Xftyn[i-1]=cond->simulation->Xftyn[i-1];
      condTemp->Xccn[i-1]=cond->simulation->Xccn[i-1];
     }
     if(cond->simulation->idModel==4)
     {
      condTemp->Xftyf[i-1]=cond->simulation->Xftyf[i-1];
      condTemp->Xccf[i-1]=cond->simulation->Xccf[i-1];
     }
     if(cond->simulation->idModel==5)
     {
      condTemp->Xfty[i-1]=cond->simulation->Xfty[i-1];
      condTemp->Xcc[i-1]=cond->simulation->Xcc[i-1];
     }
   }
   for(int i=1;i<=365;i++)
   {
     condTemp->Obs[i-1]=cond->simulation->Obs[i-1];
     condTemp->ObsCC[i-1]=cond->simulation->ObsCC[i-1];
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmEstadistico::butShowStatisticsClick(TObject *Sender)
{
// se dispara proceso para el calculo de los estadisticos
       cond->simulation->Estadisticos();
       // REPORTES
       // fresh tuber yield
       cond->report->varObs=cond->simulation->varObs;
       cond->report->varEst=cond->simulation->varEst;
       cond->report->covObsEst=cond->simulation->covObsEst;
       cond->report->avgObs=cond->simulation->avgObs;
       cond->report->avgEst=cond->simulation->avgEst;
       cond->report->BIAS=cond->simulation->BIAS;
       cond->report->MAE=cond->simulation->MAE;
       cond->report->RMSE=cond->simulation->RMSE;
       cond->report->RRMSE=cond->simulation->RRMSE;
       cond->report->EF=cond->simulation->EF;
       cond->report->rC=cond->simulation->rC;
       // canopy cover
       cond->report->varObsCC=cond->simulation->varObsCC;
       cond->report->varEstCC=cond->simulation->varEstCC;
       cond->report->covObsEstCC=cond->simulation->covObsEstCC;
       cond->report->avgObsCC=cond->simulation->avgObsCC;
       cond->report->avgEstCC=cond->simulation->avgEstCC;
       cond->report->BIASCC=cond->simulation->BIASCC;
       cond->report->MAECC=cond->simulation->MAECC;
       cond->report->RMSECC=cond->simulation->RMSECC;
       cond->report->RRMSECC=cond->simulation->RRMSECC;
       cond->report->EFCC=cond->simulation->EFCC;
       cond->report->rCCC=cond->simulation->rCCC;

       cond->report->GenerateEstadistico();
// muestra reporte
  int existe=access(cond->report->Estadistico, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmReportTXT *frm = new TfrmReportTXT(this);
    frm->EnterInformation(cond->report->Estadistico,"Text report : Statisitics resume");
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmEstadistico::FormShow(TObject *Sender)
{
  int cant=AnsiString(cond->simulation->obsFileName).Length();
  if (cant==0)
  {
  }
  else
  {
    int existe=access(cond->simulation->obsFileName, 0);
    if(existe==-1) // el archivo no existe
    {
      Application->MessageBox("The specified file does not exist!!!","¡Advertencia!",MB_OK);
      return;
    }
    else
    {
      FileData *util=new FileData();
      AnsiString nombre = AnsiString(cond->simulation->obsFileName);
      int posicion=nombre.Pos(".");
      int longitud=nombre.Length();
      int caract=longitud-posicion;
      AnsiString ext=nombre.SubString(posicion+1,caract);
      if(ext=="prn") num=util->GetFieldsName(List,cond->simulation->obsFileName);
      if(ext=="csv") num=util->GetFieldsNameFromCSVFile(List,cond->simulation->obsFileName);
      delete util;
    }
  }
  PutValuesOnForm();
}
//---------------------------------------------------------------------------
void TfrmEstadistico::PutValuesOnForm()
{
   edPathFile->Text=condTemp->obsFileName;
   edOFY->Text=condTemp->TitObsFY;
   edOCC->Text=condTemp->TitObsCC;

   if(cond->time->duration==0)
   {
     sgFY->RowCount=3;
     sgCC->RowCount=3;
   }
   else
   {
     sgFY->RowCount=cond->time->duration+2;
     sgCC->RowCount=cond->time->duration+2;
   }
   for(int i=1;i<=cond->time->duration;i++)
   {
     sgFY->RowHeights[i+1] = 18;
     sgFY->Cells[0][i+1]   = i;
//     sgFY->Cells[1][i+1]   = FormatFloat("0.00",condTemp->Xfty[i-1]);
     sgFY->Cells[2][i+1]   = FormatFloat("0.00",condTemp->Obs[i-1]);

     sgCC->RowHeights[i+1] = 18;
     sgCC->Cells[0][i+1]   = i;
//     sgCC->Cells[1][i+1]   = FormatFloat("0.00",condTemp->Xcc[i-1]);
     sgCC->Cells[2][i+1]   = FormatFloat("0.00",condTemp->ObsCC[i-1]);


     if(cond->simulation->idModel==1)
     {
      sgFY->Cells[1][i+1]   = FormatFloat("0.00",condTemp->Xfty[i-1]);
      sgCC->Cells[1][i+1]   = FormatFloat("0.00",condTemp->Xcc[i-1]);
     }
     if(cond->simulation->idModel==2)
     {
      sgFY->Cells[1][i+1]   = FormatFloat("0.00",condTemp->Xftyw[i-1]);
      sgCC->Cells[1][i+1]   = FormatFloat("0.00",condTemp->Xccw[i-1]);
     }
     if(cond->simulation->idModel==3)
     {
      sgFY->Cells[1][i+1]   = FormatFloat("0.00",condTemp->Xftyn[i-1]);
      sgCC->Cells[1][i+1]   = FormatFloat("0.00",condTemp->Xccn[i-1]);
     }
     if(cond->simulation->idModel==4)
     {
      sgFY->Cells[1][i+1]   = FormatFloat("0.00",condTemp->Xftyf[i-1]);
      sgCC->Cells[1][i+1]   = FormatFloat("0.00",condTemp->Xccf[i-1]);
     }
     if(cond->simulation->idModel==5)
     {
      sgFY->Cells[1][i+1]   = FormatFloat("0.00",condTemp->Xfty[i-1]);
      sgCC->Cells[1][i+1]   = FormatFloat("0.00",condTemp->Xcc[i-1]);
     }




   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmEstadistico::cmdOpenObservedClick(TObject *Sender)
{
  if(odObserved->Execute())
  {
     FileData *util=new FileData();
     int numTemp=0;
     if(odObserved->FilterIndex==1)
     {
       numTemp = util->GetFieldsNameFromCSVFile(ListTemp,odObserved->FileName.c_str());
     }
     if(odObserved->FilterIndex==2)
     {
       numTemp = util->GetFieldsName(ListTemp,odObserved->FileName.c_str());
     }
     delete util;
     // si se captura los titulos
if(numTemp>0)
{
     FileData *util=new FileData();
     if(odObserved->FilterIndex==1)
     {
       num = util->GetFieldsNameFromCSVFile(List,odObserved->FileName.c_str());
     }
     if(odObserved->FilterIndex==2)
     {
       num = util->GetFieldsName(List,odObserved->FileName.c_str());
     }
     delete util;

   edPathFile -> Text = odObserved->FileName;
   strcpy(condTemp->obsFileName,odObserved->FileName.c_str());

   condTemp->CleanTitles();
   edOFY  -> Text = "";
   edOCC  -> Text = "";
   condTemp->CleanVectorObserved();

   if(odObserved->FilterIndex==1)
   {
     int cont=condTemp->CountRegistersFromCSVFile(condTemp->obsFileName);
   }
   if(odObserved->FilterIndex==2)
   {
     int cont=condTemp->CountRegisters(condTemp->obsFileName);
   }
   if(cond->time->duration==0)
   {
     sgFY->RowCount=3;
     sgCC->RowCount=3;
   }
   else
   {
     sgFY->RowCount=cond->time->duration+2;
     sgCC->RowCount=cond->time->duration+2;
   }
   for(int i=2;i<=sgFY->RowCount-1;i++)
   {
     sgFY->Cells[2][i]="";
     sgFY->Cells[0][i]=i-1;
     sgCC->Cells[2][i]="";
     sgCC->Cells[0][i]=i-1;
   }
}
else
{
  Application->MessageBox("No information on the observef file!", "Warning!", MB_OK);
}
}
}
//---------------------------------------------------------------------------
void __fastcall TfrmEstadistico::cmdOFYClick(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Observed Fresh Yield");
  if(frm->ShowModal()==mrOk)
  {
    edOFY->Text=frm->ReturnInformation();
    strcpy(condTemp->TitObsFY, edOFY->Text.c_str());

    int numelem=condTemp->GetColumnData(condTemp->obsFileName,condTemp->TitObsFY,condTemp->Obs);
    if(numelem==0) numelem=condTemp->GetColumnDataFromCSVFile(condTemp->obsFileName,condTemp->TitObsFY,condTemp->Obs);

    sgFY->RowCount=numelem+2;
    for(int i=1;i<=numelem;i++)
    {
     sgFY->Cells[2][i+1]=FormatFloat("0.00",condTemp->Obs[i-1]);
    }
  }
  delete frm;

}
//---------------------------------------------------------------------------
void __fastcall TfrmEstadistico::cmdOCCClick(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Observed Canopy Cover");
  if(frm->ShowModal()==mrOk)
  {
    edOCC->Text=frm->ReturnInformation();
    strcpy(condTemp->TitObsCC, edOCC->Text.c_str());

    int numelem=condTemp->GetColumnData(condTemp->obsFileName,condTemp->TitObsCC,condTemp->ObsCC);
    if(numelem==0) numelem=condTemp->GetColumnDataFromCSVFile(condTemp->obsFileName,condTemp->TitObsCC,condTemp->ObsCC);

    sgCC->RowCount=numelem+2;
    for(int i=1;i<=numelem;i++)
    {
     sgCC->Cells[2][i+1]=FormatFloat("0.00",condTemp->ObsCC[i-1]);
    }
  }
  delete frm;

}
//---------------------------------------------------------------------------
void __fastcall TfrmEstadistico::cmdApplyClick(TObject *Sender)
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
bool TfrmEstadistico::Validate()
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
TEdit* TfrmEstadistico::FindDataError(int* _cod)
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
void TfrmEstadistico::ShowMessageError(int _cod)
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
void TfrmEstadistico::SaveData()
{
   strcpy( cond->simulation->obsFileName,condTemp->obsFileName);
   strcpy( cond->simulation->TitObsFY,condTemp->TitObsFY);
   strcpy( cond->simulation->TitObsCC,condTemp->TitObsCC);
   for(int i=1;i<=cond->time->duration;i++)
   {
     cond->simulation->Obs[i-1]=condTemp->Obs[i-1];
     cond->simulation->ObsCC[i-1]=condTemp->ObsCC[i-1];
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmEstadistico::cmdCancelClick(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------
