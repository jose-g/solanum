//---------------------------------------------------------------------------
#include <vcl.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include "sstream.h"
#pragma hdrstop
#include "UGraphBoxPlotMYA_Yearly.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TeeComma"
#pragma link "TeeBoxPlot"
#pragma resource "*.dfm"
TfrmGraphBoxPlotMYA_Yearly *frmGraphBoxPlotMYA_Yearly;
struct myclass {
  bool operator() (double i,double j) { return (i<j);}
} myobject;
//---------------------------------------------------------------------------
__fastcall TfrmGraphBoxPlotMYA_Yearly::TfrmGraphBoxPlotMYA_Yearly(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void TfrmGraphBoxPlotMYA_Yearly::EnterInformation(Simulation* simTemp)
{
  sim=simTemp;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGraphBoxPlotMYA_Yearly::FormShow(TObject *Sender)
{
  tc1->Panel=tch1;
  int contScenario=0;
  vector<double> data;
  for(int iyear=0;iyear<sim->totPastYear;iyear++)
  {
    box[contScenario]=new TBoxSeries(tch1);
    box[contScenario]->Position=contScenario+1;
    box[contScenario]->Box->Color=0x0080FFFF;
    box[contScenario]->WhiskerPen->Color=clYellow;

    box[contScenario]->ExtrOut->Style=psCircle;
    box[contScenario]->ExtrOut->Color=clRed;
    box[contScenario]->ExtrOut->Size=2;

    box[contScenario]->MildOut->Style=psCircle;
    box[contScenario]->MildOut->Color=clYellow;
    box[contScenario]->MildOut->Size=2;

    tch1->AddSeries(box[contScenario]);
    tch1->Series[contScenario]->Clear();

    for(int irep=0;irep<sim->time->repetitions;irep++)
    {
      data.push_back(sim->ult_fty_by_year[irep][iyear]);
    }
    sort(data.begin(), data.end(), myobject);

    for(int irep=0;irep<sim->time->repetitions;irep++)
    {
      tch1->Series[contScenario]->Add(data[irep],contScenario+1,clRed);
    }
    contScenario++;
    data.clear();
  }


}
//---------------------------------------------------------------------------
