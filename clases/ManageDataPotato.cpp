#ifndef ManageDataPotatoCPP
#define ManageDataPotatoCPP
#include "ManageDataPotato.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "sstream.h"
ManageDataPotato::ManageDataPotato(int IDmodel)
{
  int idModel=IDmodel;
  climate = 0;
  climate = new ClimateFile(15000); // 40 años de datos
  time    = 0;
  time    = new TimeSimulation();
  crop    = 0;
  crop    = new Crop();
  nitrogen    = 0;
  nitrogen    = new Nitrogen();
  soil    = 0;
  soil    = new Soil();
  report  = 0;
  report  = new Report();
  simulation = 0;
  simulation = new Simulation(idModel);
  workdir=0;
  workdir = new char[255];
  report->SetReports();
//  report->DeleteReports();
}
ManageDataPotato::~ManageDataPotato()
{
 if (climate != 0)
 {
  delete climate;
  climate=0;
 }
 if (time != 0)
 {
  delete time;
  time=0;
 }
 if (crop != 0)
 {
  delete crop;
  crop=0;
 }
 if (nitrogen != 0)
 {
  delete nitrogen;
  nitrogen=0;
 }
 if (soil != 0)
 {
  delete soil;
  soil=0;
 }
 if (report != 0)
 {
  delete report;
  report=0;
 }
 if (simulation != 0)
 {
  delete simulation;
  simulation=0;
 }
 if (workdir != 0)
 {
  delete workdir;
  workdir=0;
 }
}
void ManageDataPotato::CleanCondition()
{
  climate->CleanVariables();
  time->CleanVariables();
  crop->CleanVariables();
  nitrogen->CleanVariables();
  soil->CleanVariables();
  simulation->CleanVariables();
  report->DeleteReports();
}
void ManageDataPotato::DefaultCondition()
{
  time->DayStart    = 17;
  time->MonthStart  = 7;
  time->duration    = 144;
  time->repetitions    = 20;
  time->YearStart   = 2012;
  time->idYear=0;
  strcpy(time->location,"Lima-Peru");
  char ObsFile[255];
  strcpy(ObsFile,workdir);
  strncat(ObsFile,"observed.csv",14);
  strcpy(simulation->obsFileName,ObsFile);
  strcpy(simulation->TitObsFY,"Obs");
  strcpy(simulation->TitObsCC,"ObsCC");
  simulation->LoadObservedInformation();


  char clima[255];
  strcpy(clima,workdir);
  strncat(clima,"climate.prn",14);
  strcpy(climate->FileName,clima);

  strcpy(climate->TitDay,"Day");
  strcpy(climate->TitMonth,"Month");
  strcpy(climate->TitYear,"Year");
  strcpy(climate->TitTMin,"Tmin");
  strcpy(climate->TitTMax,"Tmax");
  strcpy(climate->TitPrec,"Prec");
  strcpy(climate->TitRad,"Rad");
  strcpy(climate->TitET,"ETo");
  strcpy(climate->TitIrri,"Irri");
  strcpy(climate->TitSoilTemp,"Tsoi");
  strcpy(climate->TitSunshine,"");
  climate->ThermalCond=2; // 1: Cold   2: Temperate     3: Warm
  climate->LoadClimateInformation();
  climate->Lat_Degrees=14;
  climate->Lat_Minutes=11;
  climate->Lat_Seconds=34;
  climate->Hemisphere=-1; // 1: Northern    -1:Southern
  climate->z=433;
  climate->G=0;
  climate->Albedo=0.23;
  climate->Select_Wind_cat=1;
  climate->Select_AP=2;

  crop->DefaultValuesForKindOfCrop(0);
  crop->plant->N=4.17; /////
  crop->plant->EDay=13;   /////
//  crop->plant->v=0.2;  /////
  crop->plant->v=0.075;  /////
  crop->plant->t0=0.0;
  nitrogen->SelectedOM=3; // Rotted manure
  nitrogen->SelectedFert=0;  //  Urea
  nitrogen->AmountFert=100;
  nitrogen->FOMi=2000;
  soil->SelectedSoil=8;
  soil->Moisture=35;
  soil->OM=39;
  soil->SoilDepth=0.5;
  soil->Ph=6;
  soil->MaxDepth=40;
}
int ManageDataPotato::DoSimulation()
{
    simulation->climate=climate;
    simulation->crop=crop;
    simulation->nitrogen=nitrogen;
    simulation->soil=soil;
    simulation->time=time;
    simulation->report=report;
    simulation->idModel=idModel;
    int finished;
    try
    {
      finished=simulation->simulate();
    }
    catch(...)
    {
      finished=-1;
    }
    return finished;
}
bool ManageDataPotato::SaveCondition(char* pnombre)
{
  FILE *stream=0;
  stream = fopen (pnombre,"w");
  if (stream==0)
  {
     fclose(stream);
     return false; // problema al abrir el archivo
  }
  rewind(stream);
//clima
  fprintf(stream,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",climate->FileName,climate->TitTMin,climate->TitTMax,climate->TitPrec,climate->TitRad,climate->TitET,climate->TitIrri,climate->TitSoilTemp,climate->TitSunshine,climate->TitDay,climate->TitMonth,climate->TitYear,climate->TitObs);
//crop
  fprintf(stream,"%i,%f,%f,%f,%f,%f,%f,%f,%f,%i,%f,%f,%f,%f,%f,%f,%f,%f\n",crop->SelectedCrop,float(crop->plant->N),float(crop->plant->fcl),float(crop->plant->F0),float(crop->plant->R0),float(crop->plant->d),float(crop->plant->t50),float(crop->plant->LUE),float(crop->plant->v),crop->plant->EDay,float(crop->plant->t0),float(crop->tuber->M),float(crop->tuber->A),float(crop->tuber->b),float(crop->tuber->DMCont),float(crop->tuber->Tcr),float(crop->tuber->Tld),float(crop->tuber->Trg));
//nitrogen, soil
  fprintf(stream,"%i,%i,%f,%f,%i,%f,%f,%f,%f,%f,%i,%i,%i,%i,%i,%i,%s,%s,%i\n",nitrogen->SelectedOM,nitrogen->SelectedFert,float(nitrogen->AmountFert),float(nitrogen->FOMi),soil->SelectedSoil,float(soil->Moisture),float(soil->OM),float(soil->SoilDepth),float(soil->Ph),float(soil->MaxDepth),time->DayStart,time->MonthStart,time->duration,climate->ThermalCond,time->YearStart,time->idYear,time->location,time->Month,time->repetitions);
  fclose(stream);
  return true; // se abrio correctamente el archivo y se guardo los datos
}
bool ManageDataPotato::LoadCondition(char* pnombre)
{
std::ifstream  data(pnombre);
int contLinea=0;
int contDatos;
int num;
std::string line;
while(std::getline(data,line))
{
  std::stringstream  lineStream(line);
  std::string        cell;
  contLinea++;
  contDatos=0;
  while(std::getline(lineStream,cell,','))
  {
    // Aqui obtenemos una celda
    contDatos++;
    num=strlen(cell.c_str());
    char* dato = new char[ num + 1 ];
    strcpy(dato,cell.c_str());
    if(contLinea==1) // datos de clima
    {
      switch (contDatos)
      {
        case 1 : strcpy(climate->FileName,dato);
        break;
        case 2 : strcpy(climate->TitTMin,dato);
        break;
        case 3 : strcpy(climate->TitTMax,dato);
        break;
        case 4 : strcpy(climate->TitPrec,dato);
        break;
        case 5 : strcpy(climate->TitRad,dato);
        break;
        case 6 : strcpy(climate->TitET,dato);
        break;
        case 7 : strcpy(climate->TitIrri,dato);
        break;
        case 8 : strcpy(climate->TitSoilTemp,dato);
        break;
        case 9 : strcpy(climate->TitSunshine,dato);
        break;
        case 10 : strcpy(climate->TitDay,dato);
        break;
        case 11 : strcpy(climate->TitMonth,dato);
        break;
        case 12 : strcpy(climate->TitYear,dato);
        break;
        case 13 : strcpy(climate->TitObs,dato);
                  climate->LoadClimateInformation();
      }
    }
    if(contLinea==2) // datos de cultivos
    {
      switch (contDatos)
      {
        case 1 : crop->SelectedCrop=atoi(dato);
        break;
        case 2 : crop->plant->N=atof(dato);
        break;
        case 3 : crop->plant->fcl=atof(dato);
        break;
        case 4 : crop->plant->F0=atof(dato);
        break;
        case 5 : crop->plant->R0=atof(dato);
        break;
        case 6 : crop->plant->d=atof(dato);
        break;
        case 7 : crop->plant->t50=atof(dato);
        break;
        case 8 : crop->plant->LUE=atof(dato);
        break;
        case 9 : crop->plant->v=atof(dato);
        break;
        case 10 : crop->plant->EDay=atoi(dato);
        break;
        case 11 : crop->plant->t0=atof(dato);
        break;
        case 12 : crop->tuber->M=atof(dato);
        break;
        case 13 : crop->tuber->A=atof(dato);
        break;
        case 14 : crop->tuber->b=atof(dato);
        break;
        case 15 : crop->tuber->DMCont=atof(dato);
        break;
        case 16 : crop->tuber->Tcr=atof(dato);
        break;
        case 17 : crop->tuber->Tld=atof(dato);
        break;
        case 18 : crop->tuber->Trg=atof(dato);
      }
    }
    if(contLinea==3) // datos de cultivos
    {
      switch (contDatos)
      {
        case 1 : nitrogen->SelectedOM=atoi(dato);
        break;
        case 2 : nitrogen->SelectedFert=atoi(dato);
        break;
        case 3 : nitrogen->AmountFert=atof(dato);
        break;
        case 4 : nitrogen->FOMi=atof(dato);
        break;
        case 5 : soil->SelectedSoil=atoi(dato);
        break;
        case 6 : soil->Moisture=atof(dato);
        break;
        case 7 : soil->OM=atof(dato);
        break;
        case 8 : soil->SoilDepth=atof(dato);
        break;
        case 9 : soil->Ph=atof(dato);
        break;
        case 10 : soil->MaxDepth=atof(dato);
        break;
        case 11 : time->DayStart=atoi(dato);
        break;
        case 12 : time->MonthStart=atoi(dato);
        break;
        case 13 : time->duration=atoi(dato);
        break;
        case 14 : climate->ThermalCond=atoi(dato);
        break;
        case 15 : time->YearStart=atoi(dato);
        break;
        case 16 : time->idYear=atoi(dato);
        break;
        case 17 : strcpy(time->location,dato);
        break;
        case 18 : strcpy(time->Month,dato);;
        break;
        case 19 : time->repetitions=atoi(dato);
      }
    }
  }
}
data.close();


/*

  FILE *stream=0;
  stream = fopen (pnombre,"r");
  if (stream==0)
  {
     fclose(stream);
     return false; // problema al abrir el archivo
  }
  rewind(stream);
  char data1[20];
  char data2[20];
  char data3[255];
// clima
  fscanf(stream,"%s",&data3);
  strcpy(climate->FileName,data3);
  fscanf(stream,"%s",&data3);
  strcpy(climate->TitTMin,data3);
  fscanf(stream,"%s",&data3);
  strcpy(climate->TitTMax,data3);
  fscanf(stream,"%s",&data3);
  strcpy(climate->TitPrec,data3);
  fscanf(stream,"%s",&data3);
  strcpy(climate->TitRad,data3);
  fscanf(stream,"%s",&data3);
  strcpy(climate->TitET,data3);
  fscanf(stream,"%s",&data3);
  strcpy(climate->TitIrri,data3);
  fscanf(stream,"%s",&data3);
  strcpy(climate->TitSoilTemp,data3);
  climate->LoadClimateInformation();
// crop
  fscanf(stream,"%i\n",&crop->SelectedCrop);
  fscanf(stream,"%s %s\n",&data1,&data2);
  crop->plant->N=strtod(data1,0);
  crop->plant->fcl=strtod(data2,0);
  fscanf(stream,"%s %s\n",&data1,&data2);
  crop->plant->F0=strtod(data1,0);
  crop->plant->R0=strtod(data2,0);
  fscanf(stream,"%s %s\n",&data1,&data2);
  crop->plant->d=strtod(data1,0);
  crop->plant->t50=strtod(data2,0);
  fscanf(stream,"%s %s\n",&data1,&data2);
  crop->plant->LUE=strtod(data1,0);
  crop->plant->v=strtod(data2,0);
  fscanf(stream,"%i %s\n",&crop->plant->EDay,&data2);
  crop->plant->t0=strtod(data2,0);
  fscanf(stream,"%s %s\n",&data1,&data2);
  crop->tuber->M=strtod(data1,0);
  crop->tuber->A=strtod(data2,0);
  fscanf(stream,"%s %s\n",&data1,&data2);
  crop->tuber->b=strtod(data1,0);
  crop->tuber->DMCont=strtod(data2,0);
  fscanf(stream,"%s %s\n",&data1,&data2);
  crop->tuber->Tcr=strtod(data1,0);
  crop->tuber->Tld=strtod(data2,0);
  fscanf(stream,"%s\n",&data1);
  crop->tuber->Trg=strtod(data1,0);




  fscanf(stream,"%i %i %s %s\n",&nitrogen->SelectedOM,&nitrogen->SelectedFert,&data1,&data2);
  nitrogen->AmountFert=strtod(data1,0);
  nitrogen->FOMi=strtod(data2,0);

  char data4[20];
  char data5[20];
  char data6[20];
  char data7[20];
  fscanf(stream,"%i %s %s %s %s %s\n",&soil->SelectedSoil,&data2,&data4,&data5,&data6,&data7);
  soil->Moisture=strtod(data2,0);
  soil->OM=strtod(data4,0);
  soil->SoilDepth=strtod(data5,0);
  soil->Ph=strtod(data6,0);
  soil->MaxDepth=strtod(data7,0);

  fscanf(stream,"%i %i %i %i\n",&time->DayStart,&time->MonthStart,&time->duration, &climate->ThermalCond);
  fclose(stream);
*/
  return true; // se abrio correctamente el archivo y se levanto los datos
}
void ManageDataPotato::GetWorkDir(char* workDir)
{
  strcpy(workdir,workDir);
  strcpy(report->WorkDir,workDir);
  report->SetReports();
}
void ManageDataPotato::Clone(ManageDataPotato* other)
{
  crop->Clone(other->crop);
  climate->Clone(other->climate);
  time->Clone(other->time);
  nitrogen->Clone(other->nitrogen);
  soil->Clone(other->soil);
  report->Clone(other->report);
  simulation->Clone(other->simulation);
}
#endif
