//---------------------------------------------------------------------------
#include <vcl.h>
#include <string>
#include <io.h>
#pragma hdrstop
#include "UMainPG.h"
#include "USimulationTime.h"
#include "UCropParameterPG.h"
#include "UReportTXTMenu.h"
#include "UReportTXT.h"
#include "UAbout.h"
#include "UMenu.h"
//#include "UClimatePG.h"
#include "UReportGraphMenuPG.h"
#include "UGraph1PG.h"
#include "UGraph2PG.h"
#include "UGraph3PG.h"
#include "UGraph4PG.h"
#include "UGraph6PG.h"
#include "UClimate.h"
#include "UCalcParam.h"
#include "UEstadistico.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMainPG *frmMainPG;
const int IDmodel=1; // 1: Potential Growth , 2:Drought , 3:Nitrogen Stress , 4:Frost , 5:All models
//---------------------------------------------------------------------------
__fastcall TfrmMainPG::TfrmMainPG(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
__fastcall TfrmMainPG::TfrmMainPG(TfrmMenu* frm,Solanum* prj_Solanum)
        : TForm(Owner)
{
  menu=frm;
  WorkDir=ExtractFileDir(Application->ExeName)+"\\";
//  cond = new ManageDataPotato(IDmodel);
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
//  SelectReports();
//  cond->CleanCondition();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::FormShow(TObject *Sender)
{
  ModificarStatusBar(ArchivoDato);
}
//---------------------------------------------------------------------------
/*
void __fastcall TfrmMainPG::SpeedButton9Click(TObject *Sender)
{
  this->Visible=false;
}
*/
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::climate1Click(TObject *Sender)
{
//  TfrmClimatePG* frm = new TfrmClimatePG(this);
  TfrmClimate* frm = new TfrmClimate(this);
  frm->EnterInformation(cond->climate);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::Getdemo1Click(TObject *Sender)
{
  cond->DefaultCondition();
  ArchivoDato="Demo";
  ModificarStatusBar(ArchivoDato);
  Application->MessageBox("The example information was loaded!", "Demo!", MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::New1Click(TObject *Sender)
{
  if(Application->MessageBox("Are you sure that you want to clean the initial conditions?", "Warning!", MB_YESNO)==6)
  {
    cond->CleanCondition();
    ArchivoDato="";
    ModificarStatusBar(ArchivoDato);
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::Save1Click(TObject *Sender)
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
void __fastcall TfrmMainPG::Open1Click(TObject *Sender)
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
void TfrmMainPG::ModificarStatusBar(AnsiString InArchivoDato)
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
void __fastcall TfrmMainPG::Simulate1Click(TObject *Sender)
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
void __fastcall TfrmMainPG::CropParameter1Click(TObject *Sender)
{
  TfrmCropParameterPG* frm=new TfrmCropParameterPG(this);
  frm->EnterInformation(cond->crop,dbcultivo);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------
void TfrmMainPG::SelectReports()
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
void __fastcall TfrmMainPG::Drymatterproduction1Click(TObject *Sender)
{
  int existe=access(cond->report->Archivo6, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph6PG *frm = new TfrmGraph6PG(this);
    frm->EnterInformation(cond->report->Archivo6);
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::Clearall1Click(TObject *Sender)
{
  cond->report->DeleteReports();
  cond->simulation->NumberScenario=0;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::Drymatterproduction2Click(TObject *Sender)
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
void __fastcall TfrmMainPG::Drymatterproductionresume1Click(TObject *Sender)
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

void __fastcall TfrmMainPG::SpeedButton6Click(TObject *Sender)
{
    TfrmReportTXTMenu *frm = new TfrmReportTXTMenu(this);
    frm->EnterInformation(cond->report);
    frm->ShowModal();
    delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::Aboutmodel1Click(TObject *Sender)
{
  TfrmAbout* frm = new TfrmAbout(this);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------


void __fastcall TfrmMainPG::SpeedButton8Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  menu->CerrarTodo();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::SpeedButton7Click(TObject *Sender)
{
  TfrmReportGraphMenuPG *frm = new TfrmReportGraphMenuPG(this);
  frm->EnterInformation(cond->report);
  frm->ShowModal();
  delete frm;        
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainPG::Freshtuberyield1Click(TObject *Sender)
{
  int existe=access(cond->report->Archivo2, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph2PG *frm = new TfrmGraph2PG(this);
    frm->EnterInformation(cond->report->Archivo2);
    frm->ShowModal();
    delete frm;
  }

}
//---------------------------------------------------------------------------

void __fastcall TfrmMainPG::DrymatterproductionDrytuberyield1Click(
      TObject *Sender)
{
  int existe=access(cond->report->Archivo1, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph1PG *frm = new TfrmGraph1PG(this);
    frm->EnterInformation(cond->report->Archivo1);
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainPG::Drytuberyield1Click(TObject *Sender)
{
  int existe=access(cond->report->Archivo4, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph4PG *frm = new TfrmGraph4PG(this);
    frm->EnterInformation(cond->report->Archivo4);
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::Canopycover1Click(TObject *Sender)
{
  int existe=access(cond->report->Archivo3, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph3PG *frm = new TfrmGraph3PG(this);
    frm->EnterInformation(cond->report->Archivo3);
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::Exit1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::butAddScenarioClick(TObject *Sender)
{
/*
  int maxScenarios=prjSolanum->getmaxScenarios();
  if(prjSolanum->totalScenarios==maxScenarios)
  {
    AnsiString mensaje="Maximum number of scenarios is " + AnsiString(maxScenarios);
    mensaje= mensaje + ", you can not save more scenarios !";
    Application->MessageBox(mensaje.c_str(),"¡Warning!",MB_OK);
  }
  else
  {
    cond->Clone(prjSolanum->scenario[prjSolanum->totalScenarios]);
    prjSolanum->totalScenarios++;
  }
*/
}
//---------------------------------------------------------------------------



void __fastcall TfrmMainPG::Calculatorofparameters1Click(TObject *Sender)
{
  TfrmCalcParam* frm=new TfrmCalcParam(this);
  frm->EnterInformation(cond,dbcultivo);
  frm->ShowModal();
  delete frm;        
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainPG::sbEstadisticoClick(TObject *Sender)
{
    TfrmEstadistico *frm = new TfrmEstadistico(this);
    frm->EnterInformation(cond);
    frm->ShowModal();
    delete frm;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainPG::sbMenuClick(TObject *Sender)
{
  menu->Visible=true;
  this->Enabled=false;
}
//---------------------------------------------------------------------------

