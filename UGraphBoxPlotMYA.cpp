//---------------------------------------------------------------------------
#include <vcl.h>
#include <fstream>
#include "sstream.h"
#include <vector.h>
#pragma hdrstop
#include "UGraphBoxPlotMYA.h"
#include <algorithm>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TeeComma"
#pragma link "TeeBoxPlot"
#pragma resource "*.dfm"
TfrmGraphBoxPlotMYA *frmGraphBoxPlotMYA;
struct myclass {
  bool operator() (double i,double j) { return (i<j);}
} myobject;

//---------------------------------------------------------------------------
__fastcall TfrmGraphBoxPlotMYA::TfrmGraphBoxPlotMYA(TComponent* Owner)
        : TForm(Owner)
{
    int numbox;

    numbox=1;
    box[numbox]=new TBoxSeries(tch1);
    box[numbox]->Position=numbox+1;
    box[numbox]->Box->Color=0x0080FFFF;
    box[numbox]->WhiskerPen->Color=clYellow;
    box[numbox]->ExtrOut->Style=psCircle;
    box[numbox]->ExtrOut->Color=clRed;
    box[numbox]->ExtrOut->Size=2;
    box[numbox]->MildOut->Style=psCircle;
    box[numbox]->MildOut->Color=clYellow;
    box[numbox]->MildOut->Size=2;

    tch1->AddSeries(box[numbox]);

    numbox=2;
    box[numbox]=new TBoxSeries(tch1);
    box[numbox]->Position=numbox+1;
    box[numbox]->Box->Color=0x0080FFFF;
    box[numbox]->WhiskerPen->Color=clYellow;
    box[numbox]->ExtrOut->Style=psCircle;
    box[numbox]->ExtrOut->Color=clRed;
    box[numbox]->ExtrOut->Size=2;
    box[numbox]->MildOut->Style=psCircle;
    box[numbox]->MildOut->Color=clYellow;
    box[numbox]->MildOut->Size=2;



    tch1->AddSeries(box[numbox]);
}
//---------------------------------------------------------------------------
void TfrmGraphBoxPlotMYA::EnterInformation(Simulation* simTemp)
{
  sim=simTemp;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGraphBoxPlotMYA::FormShow(TObject *Sender)
{
// graficar
  tc1->Panel=tch1;
// validar
  int numregPast=sim->totPastYear*sim->time->repetitions;
  int numregFuture=sim->totFutureYear*sim->time->repFuture;
  if(numregPast==0)
  {
    Application->MessageBox("There is not information of past year outputs!!!","¡Warning!",MB_OK);
    return;
  }
  if(numregFuture==0)
  {
    Application->MessageBox("There is not information of future year outputs!!!","¡Warning!",MB_OK);
    return;
  }
// poblar vector correspondiente al pasado
  std::vector<double> pastData;
  double data;
  int i;
  for(i=0;i<sim->totPastYear;i++)
  {
    i=i;
    for(int j=0;j<sim->time->repetitions;j++)
    {
      data=sim->ult_fty_by_year[j][i];
      pastData.push_back(data);
    }
  }
// poblar vector correspondiente al futuro
  std::vector<double> futureData;
  for(int z=i;z<sim->totFutureYear+i;z++)
  {
    z=z;
    for(int j=0;j<sim->time->repFuture;j++)
    {
      data=sim->ult_fty_by_year[j][z];
      futureData.push_back(data);
    }
  }
// ordeno los dos vectores con datos.
  sort (pastData.begin(), pastData.end(), myobject);
  sort (futureData.begin(), futureData.end(), myobject);
// graficar
  int nummbox;

  nummbox=0;
  tch1->Series[nummbox]->Clear();

    for(int idato=0;idato<pastData.size();idato++)
    {

      tch1->Series[nummbox]->Add(pastData[idato],nummbox+1,clRed);
    }

    nummbox=1;
    tch1->Series[nummbox]->Clear();
    for(int idato=0;idato<futureData.size();idato++)
    {
      tch1->Series[nummbox]->Add(futureData[idato],nummbox+1,clRed);
    }

}
//---------------------------------------------------------------------------



