//---------------------------------------------------------------------------
#include <vcl.h>
#include <string>
#include <io.h>
#pragma hdrstop
#include "UMainAM.h"
#include "USimulationTime.h"
#include "UCropParameterAM.h"
#include "UReportTXTMenu.h"
#include "UReportTXT.h"
#include "UAbout.h"
#include "UMenu.h"
//#include "UClimateAM.h"
#include "UNitrogenAM.h"
#include "USoilAM.h"
#include "UReportGraphMenuAM.h"
#include "UCalcSoilTemp.h"
#include "UCalcET0.h"
#include "UGraph1AM.h"
#include "UGraph2AM.h"
#include "UGraph3AM.h"
#include "UGraph4AM.h"
#include "UGraph5AM.h"
#include "UGraph6AM.h"
#include "UClimate.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TfrmMainAM *frmMainAM;
const int IDmodel=5; // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
__fastcall TfrmMainAM::TfrmMainAM(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
__fastcall TfrmMainAM::TfrmMainAM(TfrmMenu* frm,Solanum* prj_Solanum)
        : TForm(Owner)
{
  menu=frm;
  WorkDir=ExtractFileDir(Application->ExeName)+"\\";
//  int IDmodel=5; // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
//  cond = new ManageDataPotato(IDmodel);
  prjSolanum=prj_Solanum;
  cond = prjSolanum->condtemp;
  cond->idModel=IDmodel;
  cond->GetWorkDir(WorkDir.c_str());
  ArchivoDato="";
  char* Arch=new char[255];
  Arch=ArchivoDato.c_str();
//  SelectReports();
//  cond->CleanCondition();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainAM::FormShow(TObject *Sender)
{
  ModificarStatusBar(ArchivoDato);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainAM::climate1Click(TObject *Sender)
{
//  TfrmClimateAM* frm = new TfrmClimateAM(this);
  TfrmClimate* frm = new TfrmClimate(this);
  frm->EnterInformation(cond->climate);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainAM::Getdemo1Click(TObject *Sender)
{
  cond->DefaultCondition();
  ArchivoDato="Demo";
  ModificarStatusBar(ArchivoDato);
  Application->MessageBox("The example information was loaded!", "Demo!", MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainAM::New1Click(TObject *Sender)
{
  if(Application->MessageBox("Are you sure that you want to clean the initial conditions?", "Warning!", MB_YESNO)==6)
  {
    cond->CleanCondition();
    ArchivoDato="";
    ModificarStatusBar(ArchivoDato);
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainAM::Save1Click(TObject *Sender)
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
void __fastcall TfrmMainAM::Open1Click(TObject *Sender)
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
void TfrmMainAM::ModificarStatusBar(AnsiString InArchivoDato)
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
void __fastcall TfrmMainAM::Simulate1Click(TObject *Sender)
{
  TfrmSimulationTime *frm = new TfrmSimulationTime(this);
  frm->EnterInformation(cond);
  if(frm->ShowModal()==mrOk)
  {
    int finished=cond->DoSimulation();
    if(finished==0)
    {
       cond->simulation->Estadisticos();
       cond->report->time=cond->time;
       cond->report->scenario=cond->simulation->NumberScenario;
       cond->report->repetitions=cond->time->repetitions;
       cond->report->variety=cond->crop->CropList[cond->crop->SelectedCrop];

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
void __fastcall TfrmMainAM::CropParameter1Click(TObject *Sender)
{
  TfrmCropParameterAM* frm=new TfrmCropParameterAM(this);
  frm->EnterInformation(cond->crop);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------
void TfrmMainAM::SelectReports()
{
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
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainAM::Drymatterproduction1Click(TObject *Sender)
{
  int existe=access(cond->report->Archivo1, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph1AM *frm = new TfrmGraph1AM(this);
    frm->EnterInformation(cond->report->Archivo1);
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainAM::Clearall1Click(TObject *Sender)
{
  cond->report->DeleteReports();
  cond->simulation->NumberScenario=0;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainAM::Drymatterproduction2Click(TObject *Sender)
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
void __fastcall TfrmMainAM::Drymatterproductionresume1Click(TObject *Sender)
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

void __fastcall TfrmMainAM::SpeedButton6Click(TObject *Sender)
{
    TfrmReportTXTMenu *frm = new TfrmReportTXTMenu(this);
    frm->EnterInformation(cond->report);
    frm->ShowModal();
    delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainAM::Aboutmodel1Click(TObject *Sender)
{
  TfrmAbout* frm = new TfrmAbout(this);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainAM::SpeedButton8Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainAM::Button1Click(TObject *Sender)
{
  menu->Visible=true;
  this->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainAM::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  menu->CerrarTodo();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainAM::SpeedButton4Click(TObject *Sender)
{
  TfrmNitrogenAM* frm=new TfrmNitrogenAM(this);
  frm->EnterInformation(cond->nitrogen);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainAM::SpeedButton9Click(TObject *Sender)
{
  TfrmSoilAM* frm=new TfrmSoilAM(this);
  frm->EnterInformation(cond->soil);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainAM::CalculatorSoilTemperature1Click(
      TObject *Sender)
{
  TfrmCalcSoilTemp* frm=new TfrmCalcSoilTemp(this);
  frm->EnterInformation(cond);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainAM::CalculatorETo1Click(TObject *Sender)
{
  TfrmCalcET0* frm=new TfrmCalcET0(this);
  frm->EnterInformation(cond->climate);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainAM::SpeedButton7Click(TObject *Sender)
{
  TfrmReportGraphMenuAM *frm = new TfrmReportGraphMenuAM(this);
  frm->EnterInformation(cond->report);
  frm->ShowModal();
  delete frm;        
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainAM::Freshtuberyield1Click(TObject *Sender)
{
  int existe=access(cond->report->Archivo2, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph2AM *frm = new TfrmGraph2AM(this);
    frm->EnterInformation(cond->report->Archivo2);
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainAM::ComparisonCanopycover1Click(TObject *Sender)
{
  int existe=access(cond->report->Archivo3, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph3AM *frm = new TfrmGraph3AM(this);
    frm->EnterInformation(cond->report->Archivo3);
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainAM::ComparisonDrytuberyield1Click(TObject *Sender)
{
  int existe=access(cond->report->Archivo4, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph4AM *frm = new TfrmGraph4AM(this);
    frm->EnterInformation(cond->report->Archivo4);
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainAM::ComparisonFreshtuberyield1Click(
      TObject *Sender)
{
  int existe=access(cond->report->Archivo5, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph5AM *frm = new TfrmGraph5AM(this);
    frm->EnterInformation(cond->report->Archivo5);
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainAM::ComparisonTotaldrymatterproduction1Click(
      TObject *Sender)
{
  int existe=access(cond->report->Archivo6, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Warning!",MB_OK);
    return;
  }
  else
  {
    TfrmGraph6AM *frm = new TfrmGraph6AM(this);
    frm->EnterInformation(cond->report->Archivo6);
    frm->ShowModal();
    delete frm;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainAM::Exit1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

