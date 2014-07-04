//---------------------------------------------------------------------------
#include <vcl.h>
#include <string>
#include <fstream.h>
#include <io.h>
#include <math.h>
#pragma hdrstop
#include "UMainPG_AMY.h"
#include "USimulationTime.h"
#include "UCropParameterPG.h"
//#include "UReportTXTMenu.h"
#include "UReportTXT.h"
#include "UAbout.h"
#include "UMenu.h"
//#include "UClimatePG.h"
#include "UGraph1PG.h"
#include "UGraph2PG.h"
#include "UGraph3PG.h"
#include "UGraph4PG.h"
#include "UGraph6PG.h"
#include "UClimate.h"
#include "UCalcParam.h"
#include "UEstadistico.h"
#include "UReportTableMYA_PG.h"
#include "USelYear.h"
#include "UReportGraphMenuMYA.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMainPG_AMY *frmMainPG_AMY;
const int IDmodel=6; // 1: Potential Growth , 2:Drought , 3:Nitrogen Stress , 4:Frost , 5:All models, 6:Potential growth - Multi-year Analysis
//---------------------------------------------------------------------------
__fastcall TfrmMainPG_AMY::TfrmMainPG_AMY(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
__fastcall TfrmMainPG_AMY::TfrmMainPG_AMY(TfrmMenu* frm,Solanum* prj_Solanum)
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
void __fastcall TfrmMainPG_AMY::FormShow(TObject *Sender)
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
void __fastcall TfrmMainPG_AMY::climate1Click(TObject *Sender)
{
//  TfrmClimatePG* frm = new TfrmClimatePG(this);
  TfrmClimate* frm = new TfrmClimate(this);
  frm->EnterInformation(cond->climate);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG_AMY::Getdemo1Click(TObject *Sender)
{
  cond->DefaultCondition();
  ArchivoDato="Demo";
  ModificarStatusBar(ArchivoDato);
  Application->MessageBox("The example information was loaded!", "Demo!", MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG_AMY::New1Click(TObject *Sender)
{
  if(Application->MessageBox("Are you sure that you want to clean the initial conditions?", "Warning!", MB_YESNO)==6)
  {
    cond->CleanCondition();
    ArchivoDato="";
    ModificarStatusBar(ArchivoDato);
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG_AMY::Save1Click(TObject *Sender)
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
void __fastcall TfrmMainPG_AMY::Open1Click(TObject *Sender)
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
void TfrmMainPG_AMY::ModificarStatusBar(AnsiString InArchivoDato)
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
void __fastcall TfrmMainPG_AMY::Simulate1Click(TObject *Sender)
{
  TfrmSimulationTime *frm = new TfrmSimulationTime(this);
  frm->EnterInformation(cond);
  if(frm->ShowModal()==mrOk)
  {
    randomize();  // semilla para la aleatoriedad
    cond->simulation->contYear=0;
    cond->simulation->NumberScenario++;
// poblar listYear[]
    int totPastYear=cond->simulation->totPastYear;
    int index=0;
    int totYearToSimulate=0;
    if(totPastYear>0)
    {
      for(int i=0;i<totPastYear;i++)
      {
        cond->simulation->listYear[index]=cond->simulation->listPastYear[i];
        index++;
        totYearToSimulate++;
      }
    }
    int totFutureYear=cond->simulation->totFutureYear;
    if(totFutureYear>0)
    {
      for(int i=0;i<totFutureYear;i++)
      {
        cond->simulation->listYear[index]=cond->simulation->listFutureYear[i];
        index++;
        totYearToSimulate++;
      }
    }
    cond->simulation->totYearToSimulate=totYearToSimulate;
// simulacion
    int finished;
    int numrep=cond->time->repetitions;
    int numrepFuture=cond->time->repFuture;
    totPastYear=cond->simulation->totPastYear;
    totFutureYear=cond->simulation->totFutureYear;
    int res=(numrep*totPastYear)%totFutureYear;
    int numrepSugerido=0;
    if(res>0)
    {
      int numrepTemp=numrep;
      for(int i=numrep;i<numrep+totFutureYear;i++)
      {
        res=(i*totPastYear)%totFutureYear;
        if(res==0)
        {
          numrepSugerido=i;
          break;
        }
      }
      AnsiString texto="Number of repetitions do not apply, try with " + AnsiString(numrepSugerido);
      texto = texto + " repetitions, you can set this value in the box 'Number of runs' in the 'simulation form'.";
      ShowMessage(texto);
      finished=3;
    }
    else
    {
      cond->time->repFuture=(numrep*totPastYear)/totFutureYear; // se define el numero de repeticiones para los años futuros
      int cont=0;
      int numrepBak=cond->time->repetitions; // backup del datos de repeticiones para años pasados
      for(int i=0;i<cond->simulation->totYearToSimulate;i++)
      {
        // los años futuros se simularan con repeticiones definidas en lineas anteriores
        cont++;
        if(cont>totPastYear) cond->time->repetitions=cond->time->repFuture; // asignamos temporalmente el numero de repeticiones calculado para los años futuros, posteriormente se tiene que reponer el valor original para mantener la integridad de la informacion de entrada
        cond->time->YearStart=cond->simulation->listYear[i];
        // antes de hacer la simulacion calculamos las repeticiones para los
        // años futuros
        finished=cond->DoSimulation();
        if(finished==0)
        {
           cond->simulation->contYear++;
           cond->simulation->multiYearAnalysis_PG();
           cond->time->repetitions=numrepBak; // reponemos el valor de repeticiones original
/*
           cond->simulation->SaveOutputs();
           cond->report->time=cond->time;
           cond->report->scenario=cond->simulation->NumberScenario;
           cond->report->repetitions=cond->time->repetitions;
           cond->report->variety=cond->crop->cropname;
           cond->report->GenerateTextReport();
*/
        }
        else
        {
          if(finished==2) ShowMessage("The 'simulation start day' does not exist, please check input data and try again!");
          else ShowMessage("There were problems through simulation, check input data and try again!");
          cond->simulation->NumberScenario--;
          cond->time->repetitions=numrepBak; // reponemos el valor de repeticiones original
          break;
        }
      }
    }
    if(finished==0)
    {
      ShowMessage("The simulation finished succesfully!");
    }
  }
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG_AMY::CropParameter1Click(TObject *Sender)
{
  TfrmCropParameterPG* frm=new TfrmCropParameterPG(this);
  frm->EnterInformation(cond->crop,dbcultivo);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------
void TfrmMainPG_AMY::SelectReports()
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
void __fastcall TfrmMainPG_AMY::Drymatterproduction1Click(TObject *Sender)
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
void __fastcall TfrmMainPG_AMY::Clearall1Click(TObject *Sender)
{
  cond->report->DeleteReports();
  cond->simulation->NumberScenario=0;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG_AMY::Drymatterproduction2Click(TObject *Sender)
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
void __fastcall TfrmMainPG_AMY::Drymatterproductionresume1Click(TObject *Sender)
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

void __fastcall TfrmMainPG_AMY::SpeedButton6Click(TObject *Sender)
{

    TfrmReportTableMYA_PG *frm = new TfrmReportTableMYA_PG(this);
    frm->EnterInformation(cond->simulation);
    frm->ShowModal();
    delete frm;
/*
    TfrmReportTXTMenu *frm = new TfrmReportTXTMenu(this);
    frm->EnterInformation(cond->report);
    frm->ShowModal();
    delete frm;
*/
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG_AMY::Aboutmodel1Click(TObject *Sender)
{
  TfrmAbout* frm = new TfrmAbout(this);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------


void __fastcall TfrmMainPG_AMY::SpeedButton8Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG_AMY::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  menu->CerrarTodo();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG_AMY::SpeedButton7Click(TObject *Sender)
{
  TfrmReportGraphMenuMYA *frm = new TfrmReportGraphMenuMYA(this);
  frm->EnterInformation(cond);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainPG_AMY::Freshtuberyield1Click(TObject *Sender)
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

void __fastcall TfrmMainPG_AMY::DrymatterproductionDrytuberyield1Click(
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

void __fastcall TfrmMainPG_AMY::Drytuberyield1Click(TObject *Sender)
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
void __fastcall TfrmMainPG_AMY::Canopycover1Click(TObject *Sender)
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
void __fastcall TfrmMainPG_AMY::Exit1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------



void __fastcall TfrmMainPG_AMY::Calculatorofparameters1Click(TObject *Sender)
{
  TfrmCalcParam* frm=new TfrmCalcParam(this);
  frm->EnterInformation(cond,dbcultivo);
  frm->ShowModal();
  delete frm;        
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainPG_AMY::sbEstadisticoClick(TObject *Sender)
{
    TfrmEstadistico *frm = new TfrmEstadistico(this);
    frm->EnterInformation(cond);
    frm->ShowModal();
    delete frm;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainPG_AMY::sbMenuClick(TObject *Sender)
{
  menu->Visible=true;
  this->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainPG_AMY::sbSelectYearsClick(TObject *Sender)
{
  TfrmSelYear *frm = new TfrmSelYear(this);
  frm->EnterInformation(cond->simulation,cond->climate);
  frm->ShowModal();
  delete frm;
}
//---------------------------------------------------------------------------

