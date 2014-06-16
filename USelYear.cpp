//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "USelYear.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSelYear *frmSelYear;
//---------------------------------------------------------------------------
__fastcall TfrmSelYear::TfrmSelYear(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfrmSelYear::EnterInformation(Simulation* simTemp,Climate* climateTemp)
{
  sim=simTemp;
  climate=climateTemp;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSelYear::cmdCancelClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmSelYear::cmdApplyClick(TObject *Sender)
{

//  bool exitoso=false;
//  exitoso=Validate();
//  if(exitoso)
//  {
    SaveData();
    Close();
//  }

}
//---------------------------------------------------------------------------
void TfrmSelYear::SaveData()
{
 int contlbPast=lbPast->Items->Count;
 for(int i=0;i<contlbPast;i++)
 {
   sim->listPastYear[i]=lbPast->Items->Strings[i].ToInt();
 }
 sim->totPastYear=contlbPast;

 int contlbFuture=lbFuture->Items->Count;
 for(int i=0;i<contlbFuture;i++)
 {
   sim->listFutureYear[i]=lbFuture->Items->Strings[i].ToInt();
 }
 sim->totFutureYear=contlbFuture;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSelYear::FormShow(TObject *Sender)
{
  int totYear=climate->totYear;
  for(int i=0;i<totYear;i++)
  {
   lbAllYears->Items->Add(climate->listYear[i]);
  }
  int totPastYear=sim->totPastYear;
  for(int i=0;i<totPastYear;i++)
  {
   lbPast->Items->Add(sim->listPastYear[i]);
  }
  int totFutureYear=sim->totFutureYear;
  for(int i=0;i<totFutureYear;i++)
  {
   lbFuture->Items->Add(sim->listFutureYear[i]);
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmSelYear::buAddOneItemToPastClick(TObject *Sender)
{
  int ind=lbAllYears->ItemIndex;
  int totReg=lbAllYears->Items->Count;
  if(totReg==0)
  {
    Application->MessageBox("There is not information to select from 'All years' list box!!!","¡Warning!",MB_OK);
    return;
  }
  if(ind<0)
  {
    Application->MessageBox("You should select an item in the 'All years' list box !!!","¡Warning!",MB_OK);
    return;
  }
  lbPast->Items->Add(lbAllYears->Items->Strings[ind]);
}
//---------------------------------------------------------------------------
void __fastcall TfrmSelYear::butAddAllToPastClick(TObject *Sender)
{
  int totReg=lbAllYears->Items->Count;
  if(totReg==0)
  {
    Application->MessageBox("There is not information to select from 'All years' list box!!!","¡Warning!",MB_OK);
    return;
  }

  lbPast->Items->Clear();
  for(int i=0;i<totReg;i++)
  {
    lbPast->Items->Add(lbAllYears->Items->Strings[i]);
  }        
}
//---------------------------------------------------------------------------
void __fastcall TfrmSelYear::butDelItemFromPastClick(TObject *Sender)
{
  int ind=lbPast->ItemIndex;
  int totReg=lbPast->Items->Count;
  if(totReg==0)
  {
    Application->MessageBox("There is not information to select from Past list box!!!","¡Warning!",MB_OK);
    return;
  }
  if(ind<0)
  {
    Application->MessageBox("You should select an item in the Past list box !!!","¡Warning!",MB_OK);
    return;
  }
  lbPast->Items->Delete(ind);        
}
//---------------------------------------------------------------------------
void __fastcall TfrmSelYear::butDelAllItemsFromPastClick(TObject *Sender)
{
  int totReg=lbPast->Items->Count;
  if(totReg==0)
  {
    Application->MessageBox("There is not information to select from Past list box!!!","¡Warning!",MB_OK);
    return;
  }
  lbPast->Items->Clear();        
}
//---------------------------------------------------------------------------
void __fastcall TfrmSelYear::buAddOneItemToFutureClick(TObject *Sender)
{
  int ind=lbAllYears->ItemIndex;
  int totReg=lbAllYears->Items->Count;
  if(totReg==0)
  {
    Application->MessageBox("There is not information to select from 'All years' list box!!!","¡Warning!",MB_OK);
    return;
  }
  if(ind<0)
  {
    Application->MessageBox("You should select an item in the 'All years' list box !!!","¡Warning!",MB_OK);
    return;
  }
  lbFuture->Items->Add(lbAllYears->Items->Strings[ind]);        
}
//---------------------------------------------------------------------------
void __fastcall TfrmSelYear::butAddAllToFutureClick(TObject *Sender)
{
  int totReg=lbAllYears->Items->Count;
  if(totReg==0)
  {
    Application->MessageBox("There is not information to select from 'All years' list box!!!","¡Warning!",MB_OK);
    return;
  }

  lbFuture->Items->Clear();
  for(int i=0;i<totReg;i++)
  {
    lbFuture->Items->Add(lbAllYears->Items->Strings[i]);
  }        
}
//---------------------------------------------------------------------------
void __fastcall TfrmSelYear::butDelItemFromFutureClick(TObject *Sender)
{
  int ind=lbFuture->ItemIndex;
  int totReg=lbFuture->Items->Count;
  if(totReg==0)
  {
    Application->MessageBox("There is not information to select from Future list box!!!","¡Warning!",MB_OK);
    return;
  }
  if(ind<0)
  {
    Application->MessageBox("You should select an item in the Future list box !!!","¡Warning!",MB_OK);
    return;
  }
  lbFuture->Items->Delete(ind);        
}
//---------------------------------------------------------------------------
void __fastcall TfrmSelYear::butDelAllItemsFromFutureClick(TObject *Sender)
{
  int totReg=lbFuture->Items->Count;
  if(totReg==0)
  {
    Application->MessageBox("There is not information to select from Future list box!!!","¡Warning!",MB_OK);
    return;
  }
  lbFuture->Items->Clear();
}
//---------------------------------------------------------------------------
