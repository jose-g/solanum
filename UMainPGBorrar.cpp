//---------------------------------------------------------------------------
#include <vcl.h>
#include <string>
#include <io.h>
#pragma hdrstop
#include "UMainPGBorrar.h"
//#include "UClimatePG.h"
//#include "USimulationTimePG.h"
//#include "UCropParameterPG.h"
//#include "UReportTXTMenuPG.h"
//#include "UReportTXTPG.h"
//#include "UDMProdPG.h"
//#include "UAboutPG.h"
#include "UMenu.h"
//#include "UReportGraphMenuPG.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMainPG *frmMainPG;
//---------------------------------------------------------------------------
__fastcall TfrmMainPG::TfrmMainPG(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
__fastcall TfrmMainPG::TfrmMainPG(TfrmMenu* frm)
        : TForm(Owner)
{
  menu=frm;
/*
  WorkDir=ExtractFileDir(Application->ExeName)+"\\";
  cond = new ManageDataPotato();
  cond->GetWorkDir(WorkDir.c_str());
  ArchivoDato="";
  SelectReports();
  cond->CleanCondition();
*/
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::FormShow(TObject *Sender)
{
  ModificarStatusBar(ArchivoDato);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::SpeedButton9Click(TObject *Sender)
{
  this->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::climate1Click(TObject *Sender)
{
/*
  TfrmClimatePG* frm = new TfrmClimatePG(this);
  frm->EnterInformation(cond->climate);
  frm->ShowModal();
  delete frm;
*/
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::Getdemo1Click(TObject *Sender)
{
/*
  cond->DefaultCondition();
  ArchivoDato="Demo";
  ModificarStatusBar(ArchivoDato);
  Application->MessageBox("The example information was loaded!", "Demo!", MB_OK);
*/
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::New1Click(TObject *Sender)
{
/*
  if(Application->MessageBox("Are you sure that you want to clean the initial conditions?", "Warning!", MB_YESNO)==6)
  {
    cond->CleanCondition();
    ArchivoDato="";
    ModificarStatusBar(ArchivoDato);
  }
*/
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::Save1Click(TObject *Sender)
{
/*
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
*/
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::Open1Click(TObject *Sender)
{
/*
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
*/
}
//---------------------------------------------------------------------------
void TfrmMainPG::ModificarStatusBar(AnsiString InArchivoDato)
{
/*
  if(InArchivoDato=="")
  {
    StatusBar1->Panels->Items[1]->Text=" There is no information!";
  }
  else
  {
    StatusBar1->Panels->Items[1]->Text=" "+InArchivoDato;
  }
*/
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::Simulate1Click(TObject *Sender)
{
/*
  TfrmSimulationTimePG *frm = new TfrmSimulationTimePG(this);
  frm->EnterInformation(cond->time);
  if(frm->ShowModal()==mrOk)
  {
    bool finished=cond->DoSimulation();

    if(finished)
    {
       cond->report->time=cond->time;
       cond->report->scenario=cond->simulation->NumberScenario;
       cond->report->variety=cond->crop->CropList[cond->crop->SelectedCrop];
       cond->report->GenerateTextReport();
       ShowMessage("The simulation finished succesfully!");
    }
    else
    {
      ShowMessage("There were problems through simulation, check input data and try again!");
    }

  }
  delete frm;
*/
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::CropParameter1Click(TObject *Sender)
{
/*
  TfrmCropParameterPG* frm=new TfrmCropParameterPG(this);
  frm->EnterInformation(cond->crop);
  frm->ShowModal();
  delete frm;
*/
}
//---------------------------------------------------------------------------
void TfrmMainPG::SelectReports()
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
void __fastcall TfrmMainPG::Drymatterproduction1Click(TObject *Sender)
{
/*
  TfrmReportGraphMenuPG *frm = new TfrmReportGraphMenuPG(this);
  frm->EnterInformation(cond->report);
  frm->ShowModal();
  delete frm;
*/
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::Clearall1Click(TObject *Sender)
{
  cond->report->DeleteReports();
//  cond->simulation->NumberScenario=0;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::Drymatterproduction2Click(TObject *Sender)
{
/*
  int existe=access(cond->report->DMProd, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Advertencia!",MB_OK);
    return;
  }
  else
  {
    TfrmReportTXTPG *frm = new TfrmReportTXTPG(this);
    frm->EnterInformation(cond->report->DMProd,"Text report : Dry matter production");
    frm->ShowModal();
    delete frm;
  }
*/
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::Drymatterproductionresume1Click(TObject *Sender)
{
/*
  int existe=access(cond->report->DMProdResume, 0);
  if(existe==-1) // el archivo no existe
  {
    Application->MessageBox("There is not information to show!!!","¡Advertencia!",MB_OK);
    return;
  }
  else
  {
    TfrmReportTXTPG *frm = new TfrmReportTXTPG(this);
    frm->EnterInformation(cond->report->DMProdResume,"Text report : Dry matter production resume");
    frm->ShowModal();
    delete frm;
  }
*/
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainPG::SpeedButton6Click(TObject *Sender)
{
/*
    TfrmReportTXTMenuPG *frm = new TfrmReportTXTMenuPG(this);
    frm->EnterInformation(cond->report);
    frm->ShowModal();
    delete frm;
*/
}
//---------------------------------------------------------------------------
void __fastcall TfrmMainPG::Aboutmodel1Click(TObject *Sender)
{
/*
  TfrmAboutPG* frm = new TfrmAboutPG(this);
  frm->ShowModal();
  delete frm;
*/
}
//---------------------------------------------------------------------------


void __fastcall TfrmMainPG::SpeedButton8Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------







void __fastcall TfrmMainPG::Button1Click(TObject *Sender)
{
  menu->Visible=true;
  this->Enabled=false;        
}
//---------------------------------------------------------------------------



void __fastcall TfrmMainPG::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  menu->CerrarTodo();
}
//---------------------------------------------------------------------------
