#ifndef ReportCPP
#define ReportCPP
#include <string.h>
#include <fstream.h>
#include <SysUtils.hpp>
#include <Report.h>
Report::Report()
{
 WorkDir = 0;
 WorkDir = new char[255];
 Archivo1 = 0;
 Archivo1 = new char[255];
 Archivo2 = 0;
 Archivo2 = new char[255];
 Archivo3 = 0;
 Archivo3 = new char[255];
 Archivo4 = 0;
 Archivo4 = new char[255];
 Archivo5 = 0;
 Archivo5 = new char[255];
 Archivo6 = 0;
 Archivo6 = new char[255];
 DMProd   = 0;
 DMProd   = new char[255];
 DMProdResume = 0;
 DMProdResume = new char[255];
 variety = 0;
 variety = new char[20];
 Estadistico = 0;
 Estadistico = new char[255];
 rBoxPlotfty=0;
 rBoxPlotfty = new char[255];
 CleanVariables();
}
Report::~Report()
{
 if (WorkDir != 0)
 {
  delete [ ]WorkDir;
  WorkDir=0;
 }
 if (Archivo1 != 0)
 {
  delete [ ]Archivo1;
  Archivo1=0;
 }
 if (Archivo2 != 0)
 {
  delete [ ]Archivo2;
  Archivo2=0;
 }
 if (Archivo3 != 0)
 {
  delete [ ]Archivo3;
  Archivo3=0;
 }
 if (Archivo4 != 0)
 {
  delete [ ]Archivo4;
  Archivo4=0;
 }
 if (Archivo5 != 0)
 {
  delete [ ]Archivo5;
  Archivo5=0;
 }
 if (Archivo6 != 0)
 {
  delete [ ]Archivo6;
  Archivo6=0;
 }
 if (DMProd != 0)
 {
  delete [ ]DMProd;
  DMProd=0;
 }
 if (DMProdResume != 0)
 {
  delete [ ]DMProdResume;
  DMProdResume=0;
 }
 if (variety != 0)
 {
  delete [ ]variety;
  variety=0;
 }
 if (Estadistico != 0)
 {
  delete [ ]Estadistico;
  Estadistico=0;
 }
 if (rBoxPlotfty != 0)
 {
  delete [ ]rBoxPlotfty;
  rBoxPlotfty=0;
 }
}
void Report::CleanVariables()
{
  strcpy(Archivo1,"");
  strcpy(Archivo2,"");
  strcpy(Archivo3,"");
  strcpy(Archivo4,"");
  strcpy(Archivo5,"");
  strcpy(Archivo6,"");
  strcpy(DMProd,"");
  strcpy(DMProdResume,"");
  strcpy(Estadistico,"");
  strcpy(rBoxPlotfty,"");

}
void Report::DeleteReports()
{
  DeleteFile(Archivo1);
  DeleteFile(Archivo2);
  DeleteFile(Archivo3);
  DeleteFile(Archivo4);
  DeleteFile(Archivo5);
  DeleteFile(Archivo6);
  DeleteFile(DMProd);
  DeleteFile(DMProdResume);
  DeleteFile(Estadistico);
  DeleteFile(rBoxPlotfty);
}
void Report::GenerateTextReport()
{
  GenerateDMProd();
  GenerateDMProdResume();
//  GenerateEstadistico();
}
void Report::GenerateDMProd()
{
  using namespace std;
  FILE * pFileOutput=0;
  pFileOutput = fopen (DMProd,"w");
  FILE * pFile=0;
  pFile = fopen (Archivo1,"r");
  ifstream in(Archivo1);
  int i;
  string line;
  char data1[20];
  char data2[20];
  char data3[20];
  int day;
  double dwtot,dwtbf;
  getline(in,line,'\n');
  fscanf(pFile,"%s\n",&data1);
  fprintf(pFileOutput,"%s\n","        DRY MATTER PRODUCTION");
  fprintf(pFileOutput,"%s\n","  ");
  fprintf(pFileOutput,"%s %i\n","Scenario             :" , scenario);
  fprintf(pFileOutput,"%s %s\n","Location             :",time->location);
  fprintf(pFileOutput,"%s %s\n","Variety              :",variety);
  fprintf(pFileOutput,"%s %i %s\n","Starting date        :",time->DayStart,time->Month);
  fprintf(pFileOutput,"%s %i\n","Simulated days       :",time->duration);
  fprintf(pFileOutput,"%s %i\n","Number of runs       :",time->repetitions);
  fprintf(pFileOutput,"%s\n","  ");
  fprintf(pFileOutput,"%s\n"," Simulation       Total        Dry            ");
  fprintf(pFileOutput,"%s\n","    day        Dry biomass  Tuber yield      ");
  fprintf(pFileOutput,"%s\n","                  t/ha         t/ha            ");
  fprintf(pFileOutput,"%s\n","  ");
  for(i=1;!in.eof();i++)
  {
    getline(in,line,'\n');
    int valor=fscanf(pFile,"%s %s\n",&data1,&data2);
    if(valor==-1) break;
    dwtot=strtod(data1,0);
    dwtbf=strtod(data2,0);
    fprintf(pFileOutput,"    %s          %s       %s\n",FormatFloat("000",float(i-1)),FormatFloat("00.000",dwtot),FormatFloat("00.000",dwtbf));
  }
  in.close();
  fclose(pFile);
  fclose(pFileOutput);
}
void Report::GenerateDMProdResume()
{
  using namespace std;
  FILE * pFileOutput=0;
  pFileOutput = fopen (DMProdResume,"a");
  FILE * pFile=0;
  pFile = fopen (Archivo1,"r");
  ifstream in(Archivo1);
  int i;
  string line;
  char data1[20];
  char data2[20];
  char data3[20];
  int day;
  double dwtot,dwtbf;
  getline(in,line,'\n');
  fscanf(pFile,"%s\n",&data1);
  double DMCont=strtod(data1,0);
  fprintf(pFileOutput,"%s\n","  ");
  fprintf(pFileOutput,"%s %i\n","Scenario                   :" , scenario);
  fprintf(pFileOutput,"%s %s\n","Location                   :",time->location);
  fprintf(pFileOutput,"%s %s\n","Variety                    :",variety);
  fprintf(pFileOutput,"%s %i %s\n","Starting date              :",time->DayStart,time->Month);
  fprintf(pFileOutput,"%s %i\n","Simulated days             :",time->duration);
  fprintf(pFileOutput,"%s %i\n","Number of runs             :",time->repetitions);
  for(i=1;!in.eof();i++)
  {
    getline(in,line,'\n');
    int valor=fscanf(pFile,"%s %s\n",&data1,&data2);
    if(valor==-1) break;
    dwtot=strtod(data1,0);
    dwtbf=strtod(data2,0);
//    fprintf(pFileOutput,"    %s          %s       %s\n",FormatFloat("000",float(i)),FormatFloat("00.000",dwtot),FormatFloat("00.000",dwtbf));
  }
  in.close();
  fprintf(pFileOutput,"%s %s\n","Total dry biomass (t/ha)   :",FormatFloat("00.00",dwtot));
  fprintf(pFileOutput,"%s %s\n","Dry tuber yield (t/ha)     :",FormatFloat("00.00",dwtbf));
  fprintf(pFileOutput,"%s %s\n","Fresh tuber yield (t/ha)   :",FormatFloat("00.00",dwtbf/DMCont));
  fprintf(pFileOutput,"%s\n","  ");
  fclose(pFile);
  fclose(pFileOutput);
}
void Report::GenerateEstadistico()
{
  using namespace std;
  FILE * pFileOutput=0;
  pFileOutput = fopen (Estadistico,"a");
  fprintf(pFileOutput,"%s\n","  ");
  fprintf(pFileOutput,"%s %i\n","Scenario                   :" , scenario);
  fprintf(pFileOutput,"%s %s\n","Location                   :",time->location);
  fprintf(pFileOutput,"%s %s\n","Variety                    :",variety);
  fprintf(pFileOutput,"%s %i %s\n","Starting date              :",time->DayStart,time->Month);
  fprintf(pFileOutput,"%s %i\n","Simulated days             :",time->duration);
  fprintf(pFileOutput,"%s %i\n\n","Number of runs             :",time->repetitions);

  fprintf(pFileOutput,"%s\n","Fresh tuber yield");
  fprintf(pFileOutput,"%s\n","-----------------");
  fprintf(pFileOutput,"%s %s\n","Variance of observed                :",FormatFloat("00.000",varObs));
  fprintf(pFileOutput,"%s %s\n","Variance of predicted               :",FormatFloat("00.000",varEst));
  fprintf(pFileOutput,"%s %s\n","Covariance of observed vs predicted :",FormatFloat("00.000",covObsEst));
  fprintf(pFileOutput,"%s %s\n","Average of observed                 :",FormatFloat("00.000",avgObs));
  fprintf(pFileOutput,"%s %s\n","Average of predicted                :",FormatFloat("00.000",avgEst));
  fprintf(pFileOutput,"%s %s\n","BIAS                                :",FormatFloat("00.000",BIAS));
  fprintf(pFileOutput,"%s %s\n","MAE                                 :",FormatFloat("00.000",MAE));
  fprintf(pFileOutput,"%s %s\n","RMSE                                :",FormatFloat("00.000",RMSE));
  fprintf(pFileOutput,"%s %s\n","RRMSE                               :",FormatFloat("00.000",RRMSE));
  fprintf(pFileOutput,"%s %s\n","EF                                  :",FormatFloat("00.000",EF));
  fprintf(pFileOutput,"%s %s\n","rC                                  :",FormatFloat("00.000",rC));
  fprintf(pFileOutput,"%s\n","  ");

  fprintf(pFileOutput,"%s\n","Canopy cover");
  fprintf(pFileOutput,"%s\n","------------");
  fprintf(pFileOutput,"%s %s\n","Variance of observed                :",FormatFloat("00.000",varObsCC));
  fprintf(pFileOutput,"%s %s\n","Variance of predicted               :",FormatFloat("00.000",varEstCC));
  fprintf(pFileOutput,"%s %s\n","Covariance of observed vs predicted :",FormatFloat("00.000",covObsEstCC));
  fprintf(pFileOutput,"%s %s\n","Average of observed                 :",FormatFloat("00.000",avgObsCC));
  fprintf(pFileOutput,"%s %s\n","Average of predicted                :",FormatFloat("00.000",avgEstCC));
  fprintf(pFileOutput,"%s %s\n","BIAS                                :",FormatFloat("00.000",BIASCC));
  fprintf(pFileOutput,"%s %s\n","MAE                                 :",FormatFloat("00.000",MAECC));
  fprintf(pFileOutput,"%s %s\n","RMSE                                :",FormatFloat("00.000",RMSECC));
  fprintf(pFileOutput,"%s %s\n","RRMSE                               :",FormatFloat("00.000",RRMSECC));
  fprintf(pFileOutput,"%s %s\n","EF                                  :",FormatFloat("00.000",EFCC));
  fprintf(pFileOutput,"%s %s\n","rC                                  :",FormatFloat("00.000",rCCC));
  fprintf(pFileOutput,"%s\n","  ");
  fclose(pFileOutput);
}
void Report::Clone(Report* other)
{
  strcpy(other->Archivo1,Archivo1);
  strcpy(other->Archivo2,Archivo2);
  strcpy(other->Archivo3,Archivo3);
  strcpy(other->Archivo4,Archivo4);
  strcpy(other->Archivo5,Archivo5);
  strcpy(other->Archivo6,Archivo6);
  strcpy(other->DMProd,DMProd);
  strcpy(other->DMProdResume,DMProdResume);
  strcpy(other->variety,variety);
  strcpy(other->Estadistico,Estadistico);
  strcpy(other->rBoxPlotfty,rBoxPlotfty);
  other->scenario=scenario;
  other->repetitions=repetitions;
}
void Report::SetReports()
{
  char* direc=new char[255];
  strcpy(direc,WorkDir);
  strcpy(Archivo1,strcat(direc,"archivo1.txt"));

  strcpy(direc,WorkDir);
  strcpy(Archivo2,strcat(direc,"archivo2.txt"));

  strcpy(direc,WorkDir);
  strcpy(Archivo3,strcat(direc,"archivo3.txt"));

  strcpy(direc,WorkDir);
  strcpy(Archivo4,strcat(direc,"archivo4.txt"));

  strcpy(direc,WorkDir);
  strcpy(Archivo5,strcat(direc,"archivo5.txt"));

  strcpy(direc,WorkDir);
  strcpy(Archivo6,strcat(direc,"archivo6.txt"));

  strcpy(direc,WorkDir);
  strcpy(DMProd,strcat(direc,"DMProd.txt"));

  strcpy(direc,WorkDir);
  strcpy(DMProdResume,strcat(direc,"DMProdResume.txt"));

  strcpy(direc,WorkDir);
  strcpy(Estadistico,strcat(direc,"Estadistico.txt"));

  strcpy(direc,WorkDir);
  strcpy(rBoxPlotfty,strcat(direc,"rBoxPlotfty.txt"));

  delete[] direc;
  direc=0;
}
#endif
