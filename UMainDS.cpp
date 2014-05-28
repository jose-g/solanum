//---------------------------------------------------------------------------
#include <vcl.h>
#include <string>
#include <io.h>
#pragma hdrstop
#include "UMainDS.h"
#include "USimulationTime.h"
#include "UCropParameterNS.h"
#include "UReportTXTMenu.h"
#include "UReportTXT.h"
#include "UAbout.h"
#include "UMenu.h"
//#include "UClimateDS.h"
#include "USoilDS.h"
#include "UReportGraphMenuTwoSeries.h"
#include "UCalcET0.h"
#include "UGraph6TwoSeries.h"
#include "UClimate.h"
#include "UClimateDS.h"
#include "UCalcParam.h"
#include "UEstadistico.h"
#include "UGraphBoxPlot.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TfrmMainDS *frmMainDS;
const int IDmodel=2; // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
__fastcall TfrmMainDS::TfrmMainDS(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
__fastcall TfrmMainDS::TfrmMainDS(TfrmMenu* frm,Solanum* prj_Solanum)
        : TForm(Owner)
{
  menu=frm;
  WorkDir=ExtractFileDir(Application->ExeName)+"\\";
  prjSolanum=prj_Solanum;
  cond = prjSolanum->condtemp;
  cond->idModel=IDmodel;
  cond->GetWorkDir(WorkDir.c_str());
  ArchivoDato="";
  dbcultivo=new DBCultivo();
  AnsiString ArchivoCultivos=WorkDir+"crops.csv";
  strcpy(dbcultivo->DBName,ArchivoCultivos.c_str());
  dbcultivo->LoadCrops(ArchivoCultivos.c_str());
  cond->report->DeleteReports();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainDS::FormShow(TObject *Sender)
{
  ModificarStatusBar(ArchivoDato);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainDS::climate1Click(TObject *Sender)
{
//  TfrmClimateDS* frm = new TfrmClimateDS(this);
  TfrmClimate* frm = new TfrmClimate(this);
  frm->EnterInformation(cond->climate);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainDS::Getdemo1Click(TObject *Sender)
{
  cond->DefaultCondition();
  ArchivoDato="Demo";
  ModificarStatusBar(ArchivoDato);
  Application->MessageBox("The example information was loaded!", "Demo!", MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainDS::New1Click(TObject *Sender)
{
  if(Application->MessageBox("Are you sure that you want to clean the initial conditions?", "Warning!", MB_YESNO)==6)
  {
    cond->CleanCondition();
    ArchivoDato="";
    ModificarStatusBar(ArchivoDato);
  }
}



//---------------------------------------------------------------------------
void __fastcall TfrmMainDS::Save1Click(TObject *Sender)
{
  AnsiString NomArchivo;
  bool exito=false;
  if(sdCond->Execute())
  {
    NomArchivo=sdCond->FileName;
    exito=cond->SaveCondition(NomArchivo.c_str());
    if(exito)
    {
      ArchivoDato=NomArchivo;
      ModificarStatusBar(ArchivoDato);
      Application->MessageBox("The initial conditions were saved!", "Warning!", MB_OK);
    }
    else
    {
      Application->MessageBox("There were problems saving initial conditions!", "Warning!", MB_OK);
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainDS::Open1Click(TObject *Sender)
{
  AnsiString NomArchivo;
  bool exito=false;
  if(odCond->Execute())
  {
    NomArchivo=odCond->FileName;
    exito=cond->LoadCondition(NomArchivo.c_str());
    if(exito)
    {
      ArchivoDato=NomArchivo;
      ModificarStatusBar(ArchivoDato);
      Application->MessageBox("The initial conditions were loaded!", "Warning!", MB_OK);
    }
    else
    {
      Application->MessageBox("There were problems loading initial conditions!", "Warning!", MB_OK);
    }
  }
}
//---------------------------------------------------------------------------
void TfrmMainDS::ModificarStatusBar(AnsiString InArchivoDato)
{
  if(InArchivoDato=="")
  {
    StatusBar1->Panels->Items[1]->Text=" There is no information!";
  }
  else
  {
    StatusBar1->Panels->Items[1]->Text=" "+InArchivoDato;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainDS::Simulate1Click(TObject *Sender)
{
  TfrmSimulationTime *frm = new TfrmSimulationTime(this);
  frm->EnterInformation(cond);
  if(frm->ShowModal()==mrOk)
  {
    int finished=cond->DoSimulation();
    if(finished==0)
    {
//       cond->simulation->Estadisticos();
       cond->simulation->NumberScenario++;
       cond->simulation->SaveOutputs();
       cond->report->time=cond->time;
       cond->report->scenario=cond->simulation->NumberScenario;
       cond->report->repetitions=cond->time->repetitions;
       cond->report->variety=cond->crop->cropname;
       cond->report->GenerateTextReport();
       ShowMessage("The simulation finished succesfully!");
    }
    else
    {
      if(finished==2) ShowMessage("The 'simulation start day' does not exist, please check input data and try again!");
      else ShowMessage("There were problems through simulation, check input data and try again!");
    }

  }
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainDS::CropParameter1Click(TObject *Sender)
{
  TfrmCropParameterNS* frm=new TfrmCropParameterNS(this);
  frm->EnterInformation(cond->crop,dbcultivo);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------
void TfrmMainDS::SelectReports()
{
/*
  archivo1=ExtractFileDir(Application->ExeName)+"\\archivo1.txt";
  archivo2=ExtractFileDir(Application->ExeName)+"\\archivo2.txt";
  archivo3=ExtractFileDir(Application->ExeName)+"\\archivo3.txt";
  archivo4=ExtractFileDir(Application->ExeName)+"\\archivo4.txt";
  archivo5=ExtractFileDir(Application->ExeName)+"\\archivo5.txt";
  archivo6=ExtractFileDir(Application->ExeName)+"\\archivo6.txt";
  DMProd=ExtractFileDir(Application->ExeName)+"\\DMProd.txt";
  DMProdResume=ExtractFileDir(Application->ExeName)+"\\DMProdResume.txt";
  cond->report->Archivo1=archivo1.c_str();
  cond->report->Archivo2=archivo2.c_str();
  cond->report->Archivo3=archivo3.c_str();
  cond->report->Archivo4=archivo4.c_str();
  cond->report->Archivo5=archivo5.c_str();
  cond->report->Archivo6=archivo6.c_str();
  cond->report->DMProd=DMProd.c_str();
  cond->report->DMProdResume=DMProdResume.c_str();
*/
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainDS::Drymatterproduction1Click(TObject *Sender)
{
  int existe=access(cond->report->Archivo6, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph6TwoSeries *frm = new TfrmGraph6TwoSeries(this);
    frm->EnterInformation(cond->report->Archivo6,IDmodel,1);  // 1: Total Dry Matter Production, 2: Dry tuber yield , 3: Fresh tuber yield , 4: Canopy Cover
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainDS::Clearall1Click(TObject *Sender)
{
  cond->report->DeleteReports();
  cond->simulation->NumberScenario=0;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainDS::Drymatterproduction2Click(TObject *Sender)
{
  int existe=access(cond->report->DMProd, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Advertencia!",MB_OK);
    return;
  }
  else
  {
    TfrmReportTXT *frm = new TfrmReportTXT(this);
    frm->EnterInformation(cond->report->DMProd,"Text report : Dry matter production");
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainDS::Drymatterproductionresume1Click(TObject *Sender)
{
  int existe=access(cond->report->DMProdResume, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Advertencia!",MB_OK);
    return;
  }
  else
  {
    TfrmReportTXT *frm = new TfrmReportTXT(this);
    frm->EnterInformation(cond->report->DMProdResume,"Text report : Dry matter production resume");
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainDS::SpeedButton6Click(TObject *Sender)
{
    TfrmReportTXTMenu *frm = new TfrmReportTXTMenu(this);
    frm->EnterInformation(cond->report);
    frm->ShowModal();
    delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainDS::Aboutmodel1Click(TObject *Sender)
{
  TfrmAbout* frm = new TfrmAbout(this);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainDS::SpeedButton8Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainDS::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  menu->CerrarTodo();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainDS::SpeedButton7Click(TObject *Sender)
{
  TfrmReportGraphMenuTwoSeries *frm = new TfrmReportGraphMenuTwoSeries(this);
  frm->EnterInformation(cond->report,IDmodel);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainDS::Freshtuberyield1Click(TObject *Sender)
{
  int existe=access(cond->report->Archivo5, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph6TwoSeries *frm = new TfrmGraph6TwoSeries(this);
    frm->EnterInformation(cond->report->Archivo5,IDmodel,3);  // 1: Total Dry Matter Production, 2: Dry tuber yield , 3: Fresh tuber yield , 4: Canopy Cover
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------



















//---------------------------------------------------------------------------
void __fastcall TfrmMainDS::Drytuberyield1Click(TObject *Sender)
{
  int existe=access(cond->report->Archivo4, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph6TwoSeries *frm = new TfrmGraph6TwoSeries(this);
    frm->EnterInformation(cond->report->Archivo4,IDmodel,2);  // 1: Total Dry Matter Production, 2: Dry tuber yield , 3: Fresh tuber yield , 4: Canopy Cover
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainDS::Canopycover1Click(TObject *Sender)
{
  int existe=access(cond->report->Archivo3, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph6TwoSeries *frm = new TfrmGraph6TwoSeries(this);
    frm->EnterInformation(cond->report->Archivo3,IDmodel,4);  // 1: Total Dry Matter Production, 2: Dry tuber yield , 3: Fresh tuber yield , 4: Canopy Cover
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainDS::Exit1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainDS::SpeedButton9Click(TObject *Sender)
{
  TfrmSoilDS* frm=new TfrmSoilDS(this);
  frm->EnterInformation(cond->soil);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainDS::CalculatorETo1Click(TObject *Sender)
{
  TfrmCalcET0* frm=new TfrmCalcET0(this);
  frm->EnterInformation(cond->climate);
  frm->ShowModal();
  delete frm;        
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainDS::sbMenuClick(TObject *Sender)
{
  menu->Visible=true;
  this->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainDS::sbEstadisticoClick(TObject *Sender)
{
    TfrmEstadistico *frm = new TfrmEstadistico(this);
    frm->EnterInformation(cond);
    frm->ShowModal();
    delete frm;        
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainDS::Calculatorofparameters1Click(TObject *Sender)
{
  TfrmCalcParam* frm=new TfrmCalcParam(this);
  frm->EnterInformation(cond,dbcultivo);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainDS::Boxplotting1Click(TObject *Sender)
{
  int existe=access(cond->report->rBoxPlotfty, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraphBoxPlot *frm = new TfrmGraphBoxPlot(this);
    frm->EnterInformation(cond->report->rBoxPlotfty);
    frm->ShowModal();
    delete frm;
  }        
}
//---------------------------------------------------------------------------


