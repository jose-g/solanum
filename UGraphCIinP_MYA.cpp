//---------------------------------------------------------------------------
#include <vcl.h>
#include <fstream>
#include "sstream.h"
#include <vector.h>
#include <math.h>
#pragma hdrstop
#include "UGraphCIinP_MYA.h"
#include <algorithm>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TeeComma"
#pragma link "TeeBoxPlot"
#pragma resource "*.dfm"
TfrmGraphCIinP_MYA *frmGraphCIinP_MYA;
class StdDeviation
{ 

private:
    int max;
    double *value;
    double mean;
public:
    StdDeviation()
    {
    }
    ~StdDeviation()
    {
      delete[] value;
    }
    double CalculateMean()
    {
        double sum = 0;
        for(int i = 0; i < max; i++)
            sum += value[i];
        return (sum / max);
    }

    double CalculateVariane()
    {
        mean = CalculateMean();

        double temp = 0;
        for(int i = 0; i < max; i++)
        {
             temp += (value[i] - mean) * (value[i] - mean) ;
        }
        return temp / max;
    }

    double CalculateSampleVariane()
    {
        mean = CalculateMean();

        double temp = 0;
        for(int i = 0; i < max; i++)
        {
             temp += (value[i] - mean) * (value[i] - mean) ;
        }
        return temp / (max - 1);
    }

    int SetValues(double **p, int count)
    {
        max = count;
        double* temp;
        temp=*p;
        value=new double(count);
        for(int i = 0; i < count; i++)
            value[i] = temp[i];
        return 0;
    }

    double GetStandardDeviation()
    {
        return sqrt(CalculateVariane());
    }

    double GetSampleStandardDeviation()
    {
        return sqrt(CalculateSampleVariane());
    }

};

//---------------------------------------------------------------------------
__fastcall TfrmGraphCIinP_MYA::TfrmGraphCIinP_MYA(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfrmGraphCIinP_MYA::EnterInformation(Simulation* simTemp,AnsiString texto,int type)
{
  sim=simTemp;
  this->Caption=texto;
  kind=type;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGraphCIinP_MYA::FormShow(TObject *Sender)
{
// graficar
  tc1->Panel=tch1;
// validar
  double data;
  int count=0;
  AnsiString titulo;
  int totreg;
  if(kind==1)
  {
    totreg=sim->totPastYear*sim->time->repetitions;
  }
  else
  {
    totreg=sim->totFutureYear*sim->time->repFuture;
  }

  double *vector=new double[totreg];
  if(kind==1)
  {
    for(int iyear=0;iyear<sim->totPastYear;iyear++)
    {
      for(int irep=0;irep<sim->time->repetitions;irep++)
      {
        data=sim->ult_fty_by_year[irep][iyear];
        vector[count]=data;
        count++;
        titulo=AnsiString(count);
        tch1->Series[0]->AddXY(count,data,titulo,tch1->Series[0]->Color);
      }
    }
  }
  else
  {
    for(int iyear=sim->totPastYear;iyear<sim->totPastYear+sim->totFutureYear;iyear++)
    {
      for(int irep=0;irep<sim->time->repFuture;irep++)
      {
        data=sim->ult_fty_by_year[irep][iyear];
        vector[count]=data;
        count++;
        titulo=AnsiString(count);
        tch1->Series[0]->AddXY(count,data,titulo,tch1->Series[0]->Color);
      }
    }
  }
  tch1->Axes->Bottom->Automatic=false;
  tch1->Axes->Bottom->Maximum=count+1;
// calculo del promedio
  double sum = 0;
  int max=count;
  for(int i = 0; i < max; i++)
    sum += vector[i];
  double mean=sum / max;
// calculate Sample Variance
  double temp = 0;
  for(int i = 0; i < max; i++)
  {
     temp += (vector[i] - mean) * (vector[i] - mean) ;
  }
  double variance=temp / (max - 1);

// calculate Sample Standard Deviation

  double sd=sqrt(variance);

  delete[] vector;

  double ls=mean+sd;
  double li=mean-sd;
  int cont=0;
  for(int i=0;i<count;i++)
  {
    cont++;
    titulo=AnsiString(cont);
    tch1->Series[1]->AddXY(cont,ls,titulo,tch1->Series[1]->Color);
    tch1->Series[2]->AddXY(cont,li,titulo,tch1->Series[2]->Color);
  }

}
//---------------------------------------------------------------------------
