#ifndef SimulationCPP
#define SimulationCPP
#include "Simulation.h"
#include <math.h>
#include <fstream.h>
#include <vector.h>
#include <sstream.h>
#include "system.hpp"
#include <algorithm>

#include "Sol integral 2012 Tor 9394 9.cpp"

double aleatorio(double lo, double hi) {
   double valor=(rand() % 100);
   valor=valor/100.0;
   return valor;
}
struct myclass {
  bool operator() (double i,double j) { return (i<j);}
} myobject;

// --------------------------------------------------------------------------------------------------------
Simulation::Simulation(int IDmodel)
{
  obsFileName = 0;
  obsFileName = new char[255];
  TitObsFY  = 0;
  TitObsCC  = 0;
  TitObsFY  = new char[255];
  TitObsCC  = new char[255];

  NumberScenario=0;
  idModel=IDmodel; // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
for(int isim=0;isim<100;isim++)
{
  for(int i=0;i<365;i++)
  {
    tdm[isim][i]=0.0;
    tdmw[isim][i]=0.0;
    tdmn[isim][i]=0.0;
    tdmf[isim][i]=0.0;


    dty[isim][i]=0.0;
    dtyw[isim][i]=0.0;
    dtyn[isim][i]=0.0;
    dtyf[isim][i]=0.0;


    fty[isim][i]=0.0;
    ftyw[isim][i]=0.0;
    ftyn[isim][i]=0.0;
    ftyf[isim][i]=0.0;

    cc[isim][i]=0.0;
    ccw[isim][i]=0.0;
    ccn[isim][i]=0.0;
    ccf[isim][i]=0.0;
  }
}
  for(int i=0;i<365;i++)
  {
    Xtdm[i]=0.0;
    Xtdmw[i]=0.0;
    Xtdmn[i]=0.0;
    Xtdmf[i]=0.0;

    Xdty[i]=0.0;
    Xdtyw[i]=0.0;
    Xdtyn[i]=0.0;
    Xdtyf[i]=0.0;

    Xfty[i]=0.0;
    Xftyw[i]=0.0;
    Xftyn[i]=0.0;
    Xftyf[i]=0.0;

    Xcc[i]=0.0;
    Xccw[i]=0.0;
    Xccn[i]=0.0;
    Xccf[i]=0.0;
  }


}
// --------------------------------------------------------------------------------------------------------
Simulation::~Simulation()
{
 if (obsFileName != 0)
 {
  delete [ ]obsFileName;
  obsFileName=0;
 }
 if (TitObsFY != 0)
 {
  delete [ ]TitObsFY;
  TitObsFY=0;
 }
 if (TitObsCC != 0)
 {
  delete [ ]TitObsCC;
  TitObsCC=0;
 }

}
// -----------------------------------------------------------------------------
void Simulation::CleanTitles()
{
  strcpy (TitObsFY, "");
  strcpy (TitObsCC, "");
}
//------------------------------------------------------------------------------
int Simulation::Just_simulate()
{
for(int isim=0;isim<time->repetitions;isim++)
{ // begin for isim
  AME_model* test=new AME_model();
  int valor = do_setstep(1,1);
  for(int i=0;i<365;i++)
  {
    test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.MinTemp[i]   = 0;
    test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.MaxTemp[i]   = 0;
    test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.Rainfall[i]  = 0;
    test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.Radiation[i] = 0;
    test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.PET[i] = 0;
    test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.Irrigation[i] = 0;
//    test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.SoilTemp[i] = 0;
  }
  int reg=-1;
  for(int i=0;i<climate->RecNum;i++)
  {
    if(climate->Day[i]==time->DayStart && climate->Month[i]==time->MonthStart && climate->Year[i]==time->YearStart)
    {
      reg=i;
      break;
    }
  }
  if(reg==-1)
  {
    return 2; // La fecha ingresada no existe
  }
  int newItem=-1;
//
  int numdias=time->duration;
  double* datTmin=new double[numdias];
  double* datTmax=new double[numdias];

  for(int i=reg;i<climate->RecNum;i++)
  {
      newItem++;
      if(newItem<365)
      {
        if(newItem<time->duration)
        {
          datTmin[newItem]=climate->MinTemp[i];
          datTmax[newItem]=climate->MaxTemp[i];
        }
      test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.MinTemp[newItem]   = climate->MinTemp[i];
      test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.MaxTemp[newItem]   = climate->MaxTemp[i];
      test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.Rainfall[newItem]  = climate->Precipit[i];
      test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.Radiation[newItem] = climate->Radiation[i];
      test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.PET[newItem] = climate->ET[i];
      test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.Irrigation[newItem] = climate->Irri[i];
//      Obs[newItem]=climate->Obs[i];
//      ObsCC[newItem]=climate->ObsCC[i];
//      test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.SoilTemp[newItem] = climate->SoilTemp[i];
      }
  }
//
//  climate->setTmin(datTmin,cont+1);
//  climate->setTmax(datTmax,cont+1);
//
  CalcularTT(datTmin,datTmax);

  delete []datTmin;
  delete []datTmax;

  for(int i=0;i<numdias;i++)
  {
      test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.TT[i]   = climate->TT[i];
  }


//
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Time.EDay=crop->plant->EDay;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Randomize.v=crop->plant->v;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Canopy_cover.ym=crop->plant->fcl;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Canopy_cover.N=crop->plant->N;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Canopy_cover.te=crop->plant->R0;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Canopy_cover.tm=crop->plant->F0;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Total_dry_matter_production.RUE=crop->plant->LUE;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Tuber_production.s_0=crop->tuber->A;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Tuber_production.DMcont=crop->tuber->DMCont;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Tuber_production.r=crop->tuber->M;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Tuber_production.t=crop->tuber->b;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Frost_limited_production.Tcr=crop->tuber->Tcr;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Frost_limited_production.Tld=crop->tuber->Tld;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Frost_limited_production.Trg=crop->tuber->Trg;

  test->Sol_integral_2012_Tor_9394_9_NewEq2013.N_dynamics.MIN_FOMA.Type_of_OM_added.Type=nitrogen->SelectedOM;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.N_dynamics.FERTILIZERS.Fert=nitrogen->SelectedFert;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.N_dynamics.FERTILIZERS.amount=nitrogen->AmountFert;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.N_dynamics.MIN_FOMA.FOMi=nitrogen->FOMi;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Time.Planting_Date.dd=1;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Time.Planting_Date.mm=1;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Soil_parameters.ISM=soil->Moisture;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Soil_parameters.OM=soil->OM;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Soil_parameters.Soil_depth=soil->SoilDepth;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Soil_parameters.Soil_texture=soil->SelectedSoil;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Soil_parameters.pH=soil->Ph;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Soil_parameters.Soil_temp_est.Dl=soil->MaxDepth;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Thermal_time.Thermal_conditions=climate->ThermalCond;


  ame_rand_ref=&aleatorio;

  for(int i=0;i<time->duration;i++)
  { // begin for i
    int phasecont=do_setstep(i,-1);
    test->advancemodel(i,phasecont);
    if(i==0)
    {
      test->int_evalmodel(0,-2);
    }
    else
    {
      //test->int_evalmodel(i-1,1);
      test->int_evalmodel(i,1);

    }

    /*    SALIDAS    */
    tdm[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Total_dry_matter_production.TDM;
    tdmw[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Water_limited_production.Total_dry_matter_production_W.TDMw;
    tdmn[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Nitrogen_limited_production.Total_dry_matter_production_N.TDMn;
    tdmf[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Frost_limited_production.Total_dry_matter_prod_F.TDMf;


    dty[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Tuber_production.DTY;
    dtyw[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Water_limited_production.Tuber_production_W.DTYw;
    dtyn[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Nitrogen_limited_production.Tuber_production_N.DTYn;
    dtyf[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Frost_limited_production.Tuber_production_F.DTYf;


    fty[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Tuber_production.FTY;
    ftyw[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Water_limited_production.Tuber_production_W.FTYw;
    ftyn[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Nitrogen_limited_production.Tuber_production_N.FTYn;
    ftyf[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Frost_limited_production.Tuber_production_F.FTYf;

    cc[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Canopy_cover.CC;
    ccw[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Water_limited_production.Canopy_Cover_W.CCw;
    ccn[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Nitrogen_limited_production.Canopy_cover_N.CCn;
    ccf[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Frost_limited_production.CCf;

    test->updatemodel(0, 1);
  } // end for i

  delete test;

      switch (idModel)  // 1: Potential Growth , 2:Drought , 3:Nitrogen Stress , 4:Frost
      {
        case 1 : ult_fty[isim]=fty[isim][time->duration-1];
        break;
        case 2 : ult_fty[isim]=ftyw[isim][time->duration-1];
        break;
        case 3 : ult_fty[isim]=ftyn[isim][time->duration-1];
        break;
        case 4 : ult_fty[isim]=ftyf[isim][time->duration-1];
      }

} // end for isim
}
//------------------------------------------------------------------------------
int Simulation::CalculatesAfterSimulation()
{
// se promedia los resultados
  for(int i=0;i<365;i++)
  {
    Xtdm[i]=0.0;
    Xtdmw[i]=0.0;
    Xtdmn[i]=0.0;
    Xtdmf[i]=0.0;

    Xdty[i]=0.0;
    Xdtyw[i]=0.0;
    Xdtyn[i]=0.0;
    Xdtyf[i]=0.0;

    Xfty[i]=0.0;
    Xftyw[i]=0.0;
    Xftyn[i]=0.0;
    Xftyf[i]=0.0;

    Xcc[i]=0.0;
    Xccw[i]=0.0;
    Xccn[i]=0.0;
    Xccf[i]=0.0;
  }
  for(int i=0;i<time->duration;i++)
  {
    for(int isim=0;isim<time->repetitions;isim++)
    {
      Xtdm[i]=Xtdm[i]+tdm[isim][i];
      Xtdmw[i]=Xtdmw[i]+tdmw[isim][i];
      Xtdmn[i]=Xtdmn[i]+tdmn[isim][i];
      Xtdmf[i]=Xtdmf[i]+tdmf[isim][i];

      Xdty[i]=Xdty[i]+dty[isim][i];
      Xdtyw[i]=Xdtyw[i]+dtyw[isim][i];
      Xdtyn[i]=Xdtyn[i]+dtyn[isim][i];
      Xdtyf[i]=Xdtyf[i]+dtyf[isim][i];

      Xfty[i]=Xfty[i]+fty[isim][i];
      Xftyw[i]=Xftyw[i]+ftyw[isim][i];
      Xftyn[i]=Xftyn[i]+ftyn[isim][i];
      Xftyf[i]=Xftyf[i]+ftyf[isim][i];

      Xcc[i]=Xcc[i]+cc[isim][i];
      Xccw[i]=Xccw[i]+ccw[isim][i];
      Xccn[i]=Xccn[i]+ccn[isim][i];
      Xccf[i]=Xccf[i]+ccf[isim][i];
    }
  }

  for(int i=0;i<time->duration;i++)
  {
  Xtdm[i]=Xtdm[i]/time->repetitions;
  Xtdmw[i]=Xtdmw[i]/time->repetitions;
  Xtdmn[i]=Xtdmn[i]/time->repetitions;
  Xtdmf[i]=Xtdmf[i]/time->repetitions;

  Xdty[i]=Xdty[i]/time->repetitions;
  Xdtyw[i]=Xdtyw[i]/time->repetitions;
  Xdtyn[i]=Xdtyn[i]/time->repetitions;
  Xdtyf[i]=Xdtyf[i]/time->repetitions;

  Xfty[i]=Xfty[i]/time->repetitions;
  Xftyw[i]=Xftyw[i]/time->repetitions;
  Xftyn[i]=Xftyn[i]/time->repetitions;
  Xftyf[i]=Xftyf[i]/time->repetitions;

  Xcc[i]=Xcc[i]/time->repetitions;
  Xccw[i]=Xccw[i]/time->repetitions;
  Xccn[i]=Xccn[i]/time->repetitions;
  Xccf[i]=Xccf[i]/time->repetitions;
  }
//
// calculo de los limites de confianza solo para modelo 1 : Potential Growth

//  double* LC1=new double[time->duration];
//  double* LC2=new double[time->duration];

  if(idModel==1) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
  {
    for(int iday=0;iday<time->duration;iday++)
    {
      double* diffEstX=new double[time->repetitions];
      double* diffEstXPow2=new double[time->repetitions];
      double sumatoria=0.0;
      for(int irep=0;irep<time->repetitions;irep++)
      {
        double borrar1=fty[irep][iday];
        double borrar2=Xfty[iday];

        diffEstX[irep]=fty[irep][iday]-Xfty[iday];
        diffEstXPow2[irep]=pow(diffEstX[irep],2);
        sumatoria=sumatoria+diffEstXPow2[irep];
      }
      double varianza=sumatoria/double(time->repetitions);
      double devstd=sqrt(varianza);
      delete[] diffEstX;
      delete[] diffEstXPow2;

      LC1[iday]=Xfty[iday]-(devstd/sqrt(time->repetitions));
      LC2[iday]=Xfty[iday]+(devstd/sqrt(time->repetitions));
    }
  }
//
  if(idModel==1) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
  {
    ExpFreshYield=Xfty[time->duration-1];
  }
  if(idModel==2) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
  {
    ExpFreshYield=Xftyw[time->duration-1];
  }
  if(idModel==3) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
  {
    ExpFreshYield=Xftyn[time->duration-1];
  }
  if(idModel==4) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
  {
    ExpFreshYield=Xftyf[time->duration-1];
  }
  if(idModel==5) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
  {
    ExpFreshYield=Xfty[time->duration-1];
  }
// Hallar el valor maximo y minimo de fresh yield en todas las repeticiones
  MinFreshYield=1000;
  MaxFreshYield=0;
  for(int i=0;i<time->duration;i++)
  {
   for(int isim=0;isim<time->repetitions;isim++)
   {
    if(idModel==1) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
    {
      if(fty[isim][i]<MinFreshYield)
      {
        MinFreshYield=fty[isim][i];
      }
      if(fty[isim][i]>MaxFreshYield)
      {
        MaxFreshYield=fty[isim][i];
      }
    }
    if(idModel==2) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
    {
      if(ftyw[isim][i]<MinFreshYield)
      {
        MinFreshYield=ftyw[isim][i];
      }
      if(ftyw[isim][i]>MaxFreshYield)
      {
        MaxFreshYield=ftyw[isim][i];
      }
    }
    if(idModel==3) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
    {
      if(ftyn[isim][i]<MinFreshYield)
      {
        MinFreshYield=ftyn[isim][i];
      }
      if(ftyn[isim][i]>MaxFreshYield)
      {
        MaxFreshYield=ftyn[isim][i];
      }
    }
    if(idModel==4) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
    {
      if(ftyf[isim][i]<MinFreshYield)
      {
        MinFreshYield=ftyf[isim][i];
      }
      if(ftyf[isim][i]>MaxFreshYield)
      {
        MaxFreshYield=ftyf[isim][i];
      }
    }
    if(idModel==5) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
    {
      if(fty[isim][i]<MinFreshYield)
      {
        MinFreshYield=fty[isim][i];
      }
      if(fty[isim][i]>MaxFreshYield)
      {
        MaxFreshYield=fty[isim][i];
      }
    }
   }
  }
}
//------------------------------------------------------------------------------
int Simulation::simulate()
{
Just_simulate();
//NumberScenario++;
CalculatesAfterSimulation();
//SaveOutputs();
return 0;
}
//------------------------------------------------------------------------------
int Simulation::SaveOutputs()
{
//  Se guarda los resultados en los archivos
// Se abre los archivos de salida
  FILE *stream1=0;
  FILE *stream2=0;
  FILE *stream3=0;
  FILE *stream4=0;
  FILE *stream5=0;
  FILE *stream6=0;
  FILE *streamBoxPlotfty=0;

  stream1=fopen(report->Archivo1,"w");
  rewind(stream1);
  stream2=fopen(report->Archivo2,"w");
  rewind(stream2);
  stream3=fopen(report->Archivo3,"w");
  rewind(stream3);
  stream4=fopen(report->Archivo4,"w");
  rewind(stream4);
  stream5=fopen(report->Archivo5,"w");
  rewind(stream5);
  stream6=fopen(report->Archivo6,"w");
  rewind(stream6);
  streamBoxPlotfty=fopen(report->rBoxPlotfty,"a");
  rewind(streamBoxPlotfty);

  double DMCont = crop->tuber->DMCont;
  fprintf(stream1,"%f\n",float(DMCont));

  for(int i=0;i<time->duration;i++)
  {

    if(idModel==1) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
    {
      fprintf(stream1,"%f %f\n",float(Xtdm[i]),float(Xdty[i]));
      fprintf(stream2,"%f %f %f\n",float(Xfty[i]),float(LC1[i]),float(LC2[i]));
    }
    if(idModel==2) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
    {
      fprintf(stream1,"%f %f\n",float(Xtdmw[i]),float(Xdtyw[i]));
      fprintf(stream2,"%f\n",float(Xftyw[i]));
    }
    if(idModel==3) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
    {
      fprintf(stream1,"%f %f\n",float(Xtdmn[i]),float(Xdtyn[i]));
      fprintf(stream2,"%f\n",float(Xftyn[i]));
    }
    if(idModel==4) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
    {
      fprintf(stream1,"%f %f\n",float(Xtdmf[i]),float(Xdtyf[i]));
      fprintf(stream2,"%f\n",float(Xftyf[i]));
    }
    if(idModel==5) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
    {
      fprintf(stream1,"%f %f\n",float(Xtdm[i]),float(Xdty[i]));
      fprintf(stream2,"%f\n",float(Xfty[i]));
    }
    fprintf(stream3,"%f %f %f %f\n",float(Xcc[i]),float(Xccw[i]),float(Xccn[i]),float(Xccf[i]));
    fprintf(stream4,"%f %f %f %f\n",float(Xdty[i]),float(Xdtyw[i]),float(Xdtyn[i]),float(Xdtyf[i]));
    fprintf(stream5,"%f %f %f %f\n",float(Xfty[i]),float(Xftyw[i]),float(Xftyn[i]),float(Xftyf[i]));
    fprintf(stream6,"%f %f %f %f\n",float(Xtdm[i]),float(Xtdmw[i]),float(Xtdmn[i]),float(Xtdmf[i]));
  }
//  delete[] LC1;
//  delete[] LC2;
//
  // ordenar vector antes de guardar en archivo
  std::vector<double> myvector (ult_fty, ult_fty+time->repetitions);
  sort (myvector.begin(), myvector.end(), myobject);
  //
  fprintf(streamBoxPlotfty,"%i\n",time->repetitions);
  for(int irep=0;irep<time->repetitions;irep++)
  {
//    fprintf(streamBoxPlotfty,"%f\n",float(ult_fty[irep]));
    fprintf(streamBoxPlotfty,"%f\n",float(myvector[irep]));
  }
//
  fclose(stream1);
  fclose(stream2);
  fclose(stream3);
  fclose(stream4);
  fclose(stream5);
  fclose(stream6);
  fclose(streamBoxPlotfty);
  return 0;
}
// --------------------------------------------------------------------------------------------------------
void Simulation::Estadisticos()
{
// selecciono los valores observados y los estimados
// Fresh tuber yield
  int contObs=0;
  for(int i=0;i<time->duration;i++)
  {
    if(Obs[i]!=0.0) contObs++;
  }
  double* valObs=new double[contObs];
  double* valEst=new double[contObs];

  int idObs=0;
  double fty;
  for(int i=0;i<time->duration;i++)
  {
    if(Obs[i]!=0.0)
    {
      valObs[idObs]=Obs[i];
      switch (idModel)  // 1: Potential Growth , 2:Drought , 3:Nitrogen Stress , 4:Frost
      {
        case 1 : fty=Xfty[i];
        break;
        case 2 : fty=Xftyw[i];
        break;
        case 3 : fty=Xftyn[i];
        break;
        case 4 : fty=Xftyf[i];
      }
      valEst[idObs]=fty;
      idObs++;
    }
  }
// Canopy cover
  int contObsCC=0;
  for(int i=0;i<time->duration;i++)
  {
    if(ObsCC[i]!=0.0) contObsCC++;
  }
  double* valObsCC=new double[contObsCC];
  double* valEstCC=new double[contObsCC];

  int idObsCC=0;
  double cc;
  for(int i=0;i<time->duration;i++)
  {
    if(ObsCC[i]!=0.0)
    {
      valObsCC[idObsCC]=ObsCC[i];
      switch (idModel)  // 1: Potential Growth , 2:Drought , 3:Nitrogen Stress , 4:Frost
      {
        case 1 : cc=Xcc[i];
        break;
        case 2 : cc=Xccw[i];
        break;
        case 3 : cc=Xccn[i];
        break;
        case 4 : cc=Xccf[i];
      }
      valEstCC[idObsCC]=cc;
      idObsCC++;
    }
  }
// Calculo de los estadisticos
//Fresh tuber yield
  double sumObs=0.0;
  double sumEst=0.0;
  double diff=0.0;
  double sumDiff=0.0;
  double diffAbs=0.0;
  double sumDiffAbs=0.0;
  double sumDiffPow2=0.0;
  for(int i=0;i<contObs;i++)
  {
    sumObs=sumObs+valObs[i];
    sumEst=sumEst+valEst[i];
    diff=valObs[i]-valEst[i];
    sumDiff=sumDiff+diff;
    diffAbs=fabs(diff);
    sumDiffAbs=sumDiffAbs+diffAbs;
    sumDiffPow2=sumDiffPow2+(pow(diff,2));
  }
  avgObs=sumObs/double(contObs);
  avgEst=sumEst/double(contObs);
  BIAS=sumDiff/double(contObs);
  MAE=sumDiffAbs/double(contObs);
  MSE=sumDiffPow2/double(contObs);
  RMSE=sqrt(MSE);
  RRMSE=RMSE/avgObs;
  double diffObsX=0.0;
  double diffObsXPow2=0.0;
  double sum_diffObsXPow2=0.0;
  double diffEstX=0.0;
  double diffEstXPow2=0.0;
  double sum_diffEstXPow2=0.0;
  double sum_diff_obs_est=0.0;
  for(int i=0;i<contObs;i++)
  {
    diffObsX=valObs[i]-avgObs;
    diffObsXPow2=pow(diffObsX,2);
    sum_diffObsXPow2=sum_diffObsXPow2+diffObsXPow2;

    diffEstX=valEst[i]-avgEst;
    diffEstXPow2=pow(diffEstX,2);
    sum_diffEstXPow2=sum_diffEstXPow2+diffEstXPow2;

    sum_diff_obs_est+=(diffObsX*diffEstX);
  }
  EF=1-(sumDiffPow2/sum_diffObsXPow2);
  varObs=sum_diffObsXPow2/double(contObs);  // varianza poblacional de las observaciones
  varEst=sum_diffEstXPow2/double(contObs);  // varianza poblacional de las estimaciones
  covObsEst=sum_diff_obs_est/double(contObs); // covarianza
  double diffavg=avgEst-avgObs;
  rC=2.0*covObsEst/(varEst+varObs+pow(diffavg,2));

//Canopy cover
  double sumObsCC=0.0;
  double sumEstCC=0.0;
  double diffCC=0.0;
  double sumDiffCC=0.0;
  double diffAbsCC=0.0;
  double sumDiffAbsCC=0.0;
  double sumDiffPow2CC=0.0;
  for(int i=0;i<contObsCC;i++)
  {
    sumObsCC=sumObsCC+valObsCC[i];
    sumEstCC=sumEstCC+valEstCC[i];
    diffCC=valObsCC[i]-valEstCC[i];
    sumDiffCC=sumDiffCC+diffCC;
    diffAbsCC=fabs(diffCC);
    sumDiffAbsCC=sumDiffAbsCC+diffAbsCC;
    sumDiffPow2CC=sumDiffPow2CC+(pow(diffCC,2));
  }
  avgObsCC=sumObsCC/double(contObsCC);
  avgEstCC=sumEstCC/double(contObsCC);
  BIASCC=sumDiffCC/double(contObsCC);
  MAECC=sumDiffAbsCC/double(contObsCC);
  MSECC=sumDiffPow2CC/double(contObsCC);
  RMSECC=sqrt(MSECC);
  RRMSECC=RMSECC/avgObsCC;
  double diffObsXCC=0.0;
  double diffObsXPow2CC=0.0;
  double sum_diffObsXPow2CC=0.0;
  double diffEstXCC=0.0;
  double diffEstXPow2CC=0.0;
  double sum_diffEstXPow2CC=0.0;
  double sum_diff_obs_estCC=0.0;
  for(int i=0;i<contObsCC;i++)
  {
    diffObsXCC=valObsCC[i]-avgObsCC;
    diffObsXPow2CC=pow(diffObsXCC,2);
    sum_diffObsXPow2CC=sum_diffObsXPow2CC+diffObsXPow2CC;

    diffEstXCC=valEstCC[i]-avgEstCC;
    diffEstXPow2CC=pow(diffEstXCC,2);
    sum_diffEstXPow2CC=sum_diffEstXPow2CC+diffEstXPow2CC;

    sum_diff_obs_estCC+=(diffObsXCC*diffEstXCC);
  }
  EFCC=1-(sumDiffPow2CC/sum_diffObsXPow2CC);
  varObsCC=sum_diffObsXPow2CC/double(contObsCC);  // varianza poblacional de las observaciones
  varEstCC=sum_diffEstXPow2CC/double(contObsCC);  // varianza poblacional de las estimaciones
  covObsEstCC=sum_diff_obs_estCC/double(contObsCC); // covarianza
  double diffavgCC=avgEstCC-avgObsCC;
  rCCC=2.0*covObsEstCC/(varEstCC+varObsCC+pow(diffavgCC,2));



  delete[] valObs;
  delete[] valEst;
  delete[] valObsCC;
  delete[] valEstCC;
}
// --------------------------------------------------------------------------------------------------------
int Simulation::Month(int day)
{
  int month=0;
  if(day<=31)           {month= 1;}
  if(day>31&&day<=59)   {month= 2;}
  if(day>59&&day<=90)   {month= 3;}
  if(day>90&&day<=120)  {month= 4;}
  if(day>120&&day<=151) {month= 5;}
  if(day>151&&day<=181) {month= 6;}
  if(day>181&&day<=212) {month= 7;}
  if(day>212&&day<=243) {month= 8;}
  if(day>243&&day<=273) {month= 9;}
  if(day>273&&day<=304) {month=10;}
  if(day>304&&day<=334) {month=11;}
  if(day>334)           {month=12;}
  return month;
}
// --------------------------------------------------------------------------------------------------------
double Simulation::Random()
{
  int valor=0.0;
  double ran=0.0;
  double Z0=0.0,Z1=0.0,Z2=0.0;
  begin:
  randomize();
  valor=random(50001);
  ran=double(valor)/50000.00;
  Z0=2*ran-1;
  if(Z0==1.0){goto begin;}
  if(Z0==-1.0){goto begin;}
  Z2=(1+Z0)/(1-Z0);
  Z1=log10(Z2)/1.82;
  return Z1;
}
// --------------------------------------------------------------------------------------------------------
void Simulation::CleanVariables()
{
  NumberScenario=0;
  strcpy (obsFileName, "");
}
// --------------------------------------------------------------------------------------------------------
int Simulation::DeterminePosition(char* archivo,char* campo)
{
  fstream FicheroGrafo;
  FicheroGrafo.open(archivo, ios::in);
  char p[100];
  int tam=strlen(campo);
  char valor[100]="";
  int i,j,z;
  FicheroGrafo.getline(p,100);
  int contPal=0;
  int OrdenCampo=0;
  bool encontro=false;
  bool finalizo=false;
  for (i=0;i<100;i++)
  {
     if(p[i] == '\0'){finalizo=true;}
     if (p[i] != ' ' && p[i] != '\0')
     {
       contPal++;
       valor[contPal-1]=p[i];
     }
     else
     {
       if(contPal>0)
       {
          OrdenCampo++;
          encontro=false;
          if(tam==contPal)
          {
            for(j=0;j<tam;j++)
            {
              if(valor[j]!=campo[j])
              {
                encontro=false;
                break;
              }
              encontro=true;
            }
          }
          for(z=0;z<contPal;z++){valor[z]=' ';}
          contPal=0;
       }
     }
     if(encontro){break;}
     if(finalizo && !encontro){OrdenCampo=0;break;}
  }
  FicheroGrafo.close();
  return OrdenCampo;
}
// --------------------------------------------------------------------------------------------------------
int Simulation::GetColumnData(char* FileName,char* FieldName,double* vect)
{
  int pos=DeterminePosition(FileName,FieldName);
  FILE *pFile=0;
  pFile = fopen (FileName,"r");
  if (pFile==0)
  {
     fclose(pFile);
     return -1; // problema al abrir el archivo
  }
  fclose(pFile);
  ifstream in(FileName);
  string linea;
  vector<string> v;
  string buffer;
  char* pEnd=0;
  int i,j=0,ContCol=0;
  getline(in,linea,'\n');
  for(i=1;!in.eof();i++)
  {
      getline(in,linea,'\n');
      stringstream aStream;
      aStream << linea;
      ContCol=0;
      while(!aStream.eof())
      {
         ContCol++;
         j++;
         buffer="";
         aStream >> buffer;
         v.push_back(buffer);
         if(ContCol==pos)
         {
           vect[i-1]=strtod(v[j-1].c_str(),&pEnd);
         }
      }
  }
  in.close();
  return 0;
}
// --------------------------------------------------------------------------------------------------------
void Simulation::Clone(Simulation* other)
{
 other->NumberScenario=NumberScenario;
 other->idModel=idModel;
for(int isim=0;isim<100;isim++)
{
  for(int i=0;i<365;i++)
  {
    other->tdm[isim][i]=tdm[isim][i];
    other->tdmw[isim][i]=tdmw[isim][i];
    other->tdmn[isim][i]=tdmn[isim][i];
    other->tdmf[isim][i]=tdmf[isim][i];

    other->dty[isim][i]=dty[isim][i];
    other->dtyw[isim][i]=dtyw[isim][i];
    other->dtyn[isim][i]=dtyn[isim][i];
    other->dtyf[isim][i]=dtyf[isim][i];

    other->fty[isim][i]=fty[isim][i];
    other->ftyw[isim][i]=ftyw[isim][i];
    other->ftyn[isim][i]=ftyn[isim][i];
    other->ftyf[isim][i]=ftyf[isim][i];

    other->cc[isim][i]=cc[isim][i];
    other->ccw[isim][i]=ccw[isim][i];
    other->ccn[isim][i]=ccn[isim][i];
    other->ccf[isim][i]=ccf[isim][i];
  }
}
for(int i=0;i<365;i++)
{
    other->Xtdm[i]=Xtdm[i];
    other->Xtdmw[i]=Xtdmw[i];
    other->Xtdmn[i]=Xtdmn[i];
    other->Xtdmf[i]=Xtdmf[i];

    other->Xdty[i]=Xdty[i];
    other->Xdtyw[i]=Xdtyw[i];
    other->Xdtyn[i]=Xdtyn[i];
    other->Xdtyf[i]=Xdtyf[i];

    other->Xfty[i]=Xfty[i];
    other->Xftyw[i]=Xftyw[i];
    other->Xftyn[i]=Xftyn[i];
    other->Xftyf[i]=Xftyf[i];

    other->Xcc[i]=Xcc[i];
    other->Xccw[i]=Xccw[i];
    other->Xccn[i]=Xccn[i];
    other->Xccf[i]=Xccf[i];
}

}
// --------------------------------------------------------------------------------------------------------
void Simulation::CalcularTT(double* tempMin,double* tempMax)
{
// --------------------------------------------------------------------------
//
//                             THERMAL TIME
//
// --------------------------------------------------------------------------
    int diassim=time->duration;
    int EmergencyDays=crop->plant->EDay;
    int ndays=diassim-EmergencyDays;
    double* tmin=new double[ndays];
    double* tmax=new double[ndays];
    for(int i=0;i<ndays;i++)
    {
      double borrar1=tempMin[i+EmergencyDays];
      double borrar2=tempMax[i+EmergencyDays];

      tmin[i]=tempMin[i+EmergencyDays];
      tmax[i]=tempMax[i+EmergencyDays];
    }

    double parameters1,parameters2,parameters3,parameters4;
    parameters1=0.0;
    parameters2=12.0;
    parameters3=24.0;
    parameters4=35.0;
    double b1 = 1.0/(parameters2 - parameters1);
    double a1 = -1.0 * b1 * parameters1;
    double b2 = 1.0/(parameters3 - parameters4);
    double a2 = -1.0 * b2 * parameters4;
    double minimo=GetMedian(tmin,ndays);
    double base = 0.0;
    if (minimo > 10.0) base = 2.0;
//    TT <- NULL
//    peso <- NULL
//    day <- NULL
    double Y0 = (tmin[0] + tmax[0])/2.0;
    double k = 1.0;
    if (Y0 < parameters2) {
        k = a1 + b1 * Y0 ;
    }
    if (Y0 > parameters3) {
        k = a2 + b2 * Y0;
    }
    if (Y0 < parameters1 || Y0 > parameters4) {
        k = 0;
    }
    double* peso=new double[ndays];
    double* TT=new double[ndays];
    int* day=new int[ndays];
    peso[0]= k;
    TT[0]  = peso[0] * (Y0 - base);
    day[0] = EmergencyDays;
    for(int i=1;i<ndays;i++)
    {
        Y0 = (tmin[i] + tmax[i])/2.0;
        k = 1.0;
        if (Y0 < parameters2) {
            k = a1 + b1 * Y0;
        }
        if (Y0 > parameters3) {
            k = a2 + b2 * Y0;
        }
        if (Y0 < parameters1 || Y0 > parameters4) {
            k = 0.0;
        }
        peso[i] = k;
        TT[i] = TT[i - 1] + peso[i] * (Y0 - base);
        day[i] = day[i - 1] + 1.0;
    }

  double* TTtemp=new double[diassim];
  int contTT=-1;
  for(int i=0;i<diassim;i++)
  {
    if(i<EmergencyDays)
    {
     TTtemp[i]=0.00001;
    }
    else
    {
      contTT++;
      TTtemp[i]=TT[contTT];
    }
  }
  climate->setTT(TTtemp,diassim);
  delete[] TTtemp;
    delete []peso;
    delete []day;
    delete []TT;
    delete []tmin;
    delete []tmax;
}
// --------------------------------------------------------------------------------------------------------
double Simulation::GetMedian(double* daArray, int iSize) {
    // Allocate an array of the same size and sort it.
    double* dpSorted = new double[iSize];
    for (int i = 0; i < iSize; ++i) {
        dpSorted[i] = daArray[i];
    }
    for (int i = iSize - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (dpSorted[j] > dpSorted[j+1]) {
                double dTemp = dpSorted[j];
                dpSorted[j] = dpSorted[j+1];
                dpSorted[j+1] = dTemp;
            }
        }
    }
    // Middle or average of middle values in the sorted array.
    double dMedian = 0.0;
    if ((iSize % 2) == 0) {
        dMedian = (dpSorted[iSize/2] + dpSorted[(iSize/2) - 1])/2.0;
    } else {
        dMedian = dpSorted[iSize/2];
    }
    delete [] dpSorted;
    return dMedian;
}
//---------------------------------------------------------------------------
void Simulation::LoadObservedInformation()
{
AnsiString nombre = AnsiString(obsFileName);
int posicion=nombre.Pos(".");
int longitud=nombre.Length();
int caract=longitud-posicion;
AnsiString ext=nombre.SubString(posicion+1,caract);
if(ext=="prn")
{
  RecNum=CountRegisters(obsFileName);
  GetColumnData(obsFileName , TitObsFY , Obs  );
  GetColumnData(obsFileName , TitObsCC , ObsCC  );
}
if(ext=="csv")
{
  RecNum=CountRegistersFromCSVFile(obsFileName);
  GetColumnDataFromCSVFile(obsFileName , TitObsFY , Obs  );
  GetColumnDataFromCSVFile(obsFileName , TitObsCC , ObsCC  );
}
}
//------------------------------------------------------------------------------
int Simulation::CountRegistersFromCSVFile(char* FileName)
{
  int cont=0;
  std::ifstream  data(FileName);
  int num;
  std::string line;
  std::getline(data,line); // la primera linea no debe contabilizarse ya que es cabecera
  int numelem=0;
  while(std::getline(data,line))
  {
    cont++;
  }
  data.close();
  return cont;
}
//------------------------------------------------------------------------------
int Simulation::CountRegisters(char* FileName)
{
  ifstream in(FileName);
  string linea;
  vector<string> v;
  string buffer;
  int i,j=0;
  getline(in,linea,'\n');
  string dato;
  bool esdigito;
  int cont=0;
  for(i=1;!in.eof();i++)
  {
      getline(in,linea,'\n');
      stringstream aStream;
      aStream << linea;
      while(!aStream.eof())
      {
         j++;
         buffer="";
         aStream >> buffer;
         v.push_back(buffer);
         dato=v[j-1].c_str();
         esdigito=false;
         esdigito=isdigit(dato[0]);
         if(esdigito)
         {
           cont++;
           break;
         }
      }
  }
  in.close();
  return cont;
}
//------------------------------------------------------------------------------
int Simulation::GetColumnDataFromCSVFile(char* FileName,char* FieldName,double* vect)
{
  int pos=DeterminePositionFromCSVFile(FileName,FieldName);
  int cont;
  std::ifstream  data(FileName);
  int num;
  std::string line;
  std::getline(data,line); // la primera linea no debe contabilizarse ya que es cabecera
  int numelem=0;
  while(std::getline(data,line))
  {
    std::stringstream  lineStream(line);
    std::string        cell;
    numelem++;
    int cont=0;
    while(std::getline(lineStream,cell,','))
    {
      cont++;
      // Aqui obtenemos una celda
      num=strlen(cell.c_str());
      char* dato = new char[ num + 1 ];
      strcpy(dato,cell.c_str());
      if(cont==pos)
      {
        vect[numelem-1]=atof(dato);
      }
    }
  }
  data.close();
  return numelem;
}
//------------------------------------------------------------------------------
int Simulation::DeterminePositionFromCSVFile(char* archivo,char* campo)
{
std::ifstream  data(archivo);
int cont=0;
int num;
std::string line;
std::getline(data,line);
std::stringstream  lineStream(line);
std::string        cell;
int tam=strlen(campo);
int OrdenCampo=0;
  bool encontro=false;

while(std::getline(lineStream,cell,','))
{
  cont++;
  // Aqui obtenemos una celda
  num=strlen(cell.c_str());
  char* dato = new char[ num + 1 ];
  strcpy(dato,cell.c_str());
  for(int j=0;j<tam;j++)
  {
    if(cell[j]!=campo[j])
    {
      encontro=false;
      break;
    }
    encontro=true;
  }
  OrdenCampo++;
  if(encontro) break;
}
if(!encontro) OrdenCampo=0;
data.close();
return OrdenCampo;
}
//------------------------------------------------------------------------------
void Simulation::CleanVectorObserved()
{
  for(int i=0;i<365;i++)
  {
    Obs[i]=0.0;
    ObsCC[i]=0.0;
  }
}
//------------------------------------------------------------------------------












#endif

