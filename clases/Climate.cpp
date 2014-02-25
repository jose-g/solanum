#ifndef ClimateCPP
#define ClimateCPP
#include "Climate.h"
#include <fstream>
#include "vector.h"
#include "sstream.h"
#include "math.h"
#include "system.hpp"
#include <string>
//------------------------------------------------------------------------------
//  Climate class
//------------------------------------------------------------------------------
Climate::Climate(int rec)
{
 RecNum=rec;
 MinTemp=0;
 MaxTemp=0;
 Precipit=0;
 Radiation=0;
 ET=0;
 Irri=0;
 SoilTemp=0;
 Sunshine=0;
 Day=0;
 Month=0;
 Year=0;
 Obs=0;
 ObsCC=0;
 ThermalCond=0;
 z=433;
 G=0.0;
 Albedo=0.23;
 haveSunshine=0;
 tminSelected=0;
 tmaxSelected=0;
 TT=0;

 MinTemp=new double[RecNum];
 MaxTemp=new double[RecNum];
 Precipit=new double[RecNum];
 Radiation=new double[RecNum];
 ET=new double[RecNum];
 Irri=new double[RecNum];
 SoilTemp=new double[RecNum];
 Sunshine=new double[RecNum];
 Day=new double[RecNum];
 Month=new double[RecNum];
 Year=new double[RecNum];
 Obs=new double[RecNum];
 ObsCC=new double[RecNum];
 CleanVariables();
}
//------------------------------------------------------------------------------
Climate::~Climate()
{
 if (MinTemp != 0)
 {
  delete [ ]MinTemp;
  MinTemp=0;
 }
 if (MaxTemp != 0)
 {
  delete [ ]MaxTemp;
  MaxTemp=0;
 }
 if (Precipit != 0)
 {
  delete [ ]Precipit;
  Precipit=0;
 }
 if (Radiation != 0)
 {
  delete [ ]Radiation;
  Radiation=0;
 }
 if (ET != 0)
 {
  delete [ ]ET;
  ET=0;
 }
 if (Irri != 0)
 {
  delete [ ]Irri;
  Irri=0;
 }
 if (SoilTemp != 0)
 {
  delete [ ]SoilTemp;
  SoilTemp=0;
 }
 if (Sunshine != 0)
 {
  delete [ ]Sunshine;
  Sunshine=0;
 }
 if (Day != 0)
 {
  delete [ ]Day;
  Day=0;
 }
 if (Month != 0)
 {
  delete [ ]Month;
  Month=0;
 }
 if (Year != 0)
 {
  delete [ ]Year;
  Year=0;
 }
 if (Obs != 0)
 {
  delete [ ]Obs;
  Obs=0;
 }
 if (ObsCC != 0)
 {
  delete [ ]ObsCC;
  ObsCC=0;
 }
 if (tminSelected != 0)
 {
  delete []tminSelected;
  tminSelected=0;
 }
 if (tmaxSelected != 0)
 {
  delete []tmaxSelected;
  tmaxSelected=0;
 }
 if (TT != 0)
 {
  delete []TT;
  TT=0;
 }
}
//------------------------------------------------------------------------------
void Climate::CleanVectorClimate()
{
  // limpia variables igualandolas a cero
  int i=0;
  for(i=0;i<RecNum;i++)
  {
    Day[i]=0.0;
    Month[i]=0.0;
    Year[i]=0.0;
    MinTemp[i]=0.0;
    MaxTemp[i]=0.0;
    Precipit[i]=0.0;
    Radiation[i]=0.0;
    ET[i]=0.0;
    Irri[i]=0.0;
    SoilTemp[i]=0.0;
    Sunshine[i]=0.0;
    Obs[i]=0.0;
    ObsCC[i]=0.0;
  }
  RecNum=0;
}
//------------------------------------------------------------------------------
void Climate::CleanVariables()
{
  // limpia variables igualandolas a cero
  CleanVectorClimate();
  ThermalCond=0;
  Lat_Degrees=0;
  Lat_Minutes=0;
  Lat_Seconds=0;
  Hemisphere=1; // 1: Northern    -1:Southern
  z=0;
  G=0;
  Albedo=0;
  Select_Wind_cat=0;
  Select_AP=0;
  haveSunshine=0;
}
//------------------------------------------------------------------------------
void Climate::Clone(Climate* other)
{
other->ThermalCond=ThermalCond;
other->RecNum=RecNum;
other->Hemisphere=Hemisphere;
other->Lat_Degrees=Lat_Degrees;
other->Lat_Minutes=Lat_Minutes;
other->Lat_Seconds=Lat_Seconds;
other->Select_Wind_cat=Select_Wind_cat;
other->Select_AP=Select_AP;
other->z=z;
other->G=G;
other->Albedo=Albedo;
other->haveSunshine=haveSunshine;

for(int i=0;i<RecNum;i++)
{
  other->MinTemp[i]=MinTemp[i];
  other->MaxTemp[i]=MaxTemp[i];
  other->Precipit[i]=Precipit[i];
  other->Radiation[i]=Radiation[i];
  other->ET[i]=ET[i];
  other->Irri[i]=Irri[i];
  other->SoilTemp[i]=SoilTemp[i];
  other->Sunshine[i]=Sunshine[i];
  other->Day[i]=Day[i];
  other->Month[i]=Month[i];
  other->Year[i]=Year[i];
  other->Obs[i]=Obs[i];
  other->ObsCC[i]=ObsCC[i];
}
}
//------------------------------------------------------------------------------
//  ClimateFile class
//------------------------------------------------------------------------------
ClimateFile::ClimateFile(int rec):Climate(rec)
{
  FileName = 0;
  TitTMin  = 0;
  TitTMax  = 0;
  TitPrec  = 0;
  TitRad   = 0;
  TitET   = 0;
  TitIrri   = 0;
  TitSoilTemp   = 0;
  TitSunshine   = 0;
  TitDay   = 0;
  TitMonth   = 0;
  TitYear   = 0;
  TitObs = 0;
  TitObsCC = 0;
  FileName = new char[255];
  TitTMin  = new char[255];
  TitTMax  = new char[255];
  TitPrec  = new char[255];
  TitRad   = new char[255];
  TitET   = new char[255];
  TitIrri   = new char[255];
  TitSoilTemp   = new char[255];
  TitSunshine   = new char[255];
  TitDay   = new char[255];
  TitMonth   = new char[255];
  TitYear   = new char[255];
  TitObs   = new char[255];
  TitObsCC   = new char[255];
//  strcpy(TitDay,"Day");
//  strcpy(TitMonth,"Month");
//  strcpy(TitYear,"Year");
  strcpy(TitObs,"Obs");
  strcpy(TitObsCC,"ObsCC");
  CleanVariables();
}
//------------------------------------------------------------------------------
ClimateFile::~ClimateFile()
{
 if (FileName != 0)
 {
  delete [ ]FileName;
  FileName=0;
 }
 if (TitTMin != 0)
 {
  delete [ ]TitTMin;
  TitTMin=0;
 }
 if (TitTMax != 0)
 {
  delete [ ]TitTMax;
  TitTMax=0;
 }
 if (TitPrec != 0)
 {
  delete [ ]TitPrec;
  TitPrec=0;
 }
 if (TitRad != 0)
 {
  delete [ ]TitRad;
  TitRad=0;
 }
 if (TitET != 0)
 {
  delete [ ]TitET;
  TitET=0;
 }
 if (TitIrri != 0)
 {
  delete [ ]TitIrri;
  TitIrri=0;
 }
 if (TitSoilTemp != 0)
 {
  delete [ ]TitSoilTemp;
  TitSoilTemp=0;
 }
 if (TitSunshine != 0)
 {
  delete [ ]TitSunshine;
  TitSunshine=0;
 }
 if (TitDay != 0)
 {
  delete [ ]TitDay;
  TitDay=0;
 }
 if (TitMonth != 0)
 {
  delete [ ]TitMonth;
  TitMonth=0;
 }
 if (TitYear != 0)
 {
  delete [ ]TitYear;
  TitYear=0;
 }
 if (TitObs != 0)
 {
  delete [ ]TitObs;
  TitObs=0;
 }
 if (TitObsCC != 0)
 {
  delete [ ]TitObsCC;
  TitObsCC=0;
 }
}
//------------------------------------------------------------------------------
void ClimateFile::CleanVariables()
{
  strcpy (FileName, "");
  CleanTitles();
  Climate::CleanVariables();
}
//------------------------------------------------------------------------------
void ClimateFile::CleanTitles()
{
  strcpy (TitTMin, "");
  strcpy (TitTMax, "");
  strcpy (TitPrec, "");
  strcpy (TitRad, "");
  strcpy (TitET, "");
  strcpy (TitIrri, "");
  strcpy (TitSoilTemp, "");
  strcpy (TitSunshine, "");
  strcpy (TitDay, "");
  strcpy (TitMonth, "");
  strcpy (TitYear, "");
}
//------------------------------------------------------------------------------
int ClimateFile::DeterminePosition(char* archivo,char* campo)
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
//------------------------------------------------------------------------------
int ClimateFile::DeterminePositionFromCSVFile(char* archivo,char* campo)
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
int ClimateFile::GetColumnData(char* FileName,char* FieldName,double* vect)
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
  int cont=0;
  for(i=1;!in.eof();i++)
  {
      getline(in,linea,'\n');
      stringstream aStream;
      aStream << linea;
      ContCol=0;
      vect[i-1]=0.0;
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
           cont++;
         }
      }
  }
  in.close();
  return cont;
}
//------------------------------------------------------------------------------
int ClimateFile::GetColumnDataFromCSVFile(char* FileName,char* FieldName,double* vect)
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
int ClimateFile::GetColumnData(char* FileName,char* FieldName,double* vect,int* cant)
{
  int pos=DeterminePosition(FileName,FieldName);
  if(pos==0)
  {
    return -2;
  }
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
  int cantidad=0;
  for(i=1;!in.eof();i++)
  {
      getline(in,linea,'\n');
      stringstream aStream;
      aStream << linea;
      ContCol=0;
      vect[i-1]=0.0;
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
           cantidad++;
         }
      }
  }
  in.close();
  *cant=cantidad;
  return 0;
}
//------------------------------------------------------------------------------
void ClimateFile::LoadClimateInformation()
{
AnsiString nombre = AnsiString(FileName);
int posicion=nombre.Pos(".");
int longitud=nombre.Length();
int caract=longitud-posicion;
AnsiString ext=nombre.SubString(posicion+1,caract);
if(ext=="prn")
{
  RecNum=CountRegisters(FileName);
  GetColumnData(FileName , TitTMin , MinTemp  );
  GetColumnData(FileName , TitTMax , MaxTemp  );
  GetColumnData(FileName , TitPrec , Precipit );
  GetColumnData(FileName , TitRad  , Radiation);
  GetColumnData(FileName , TitET  , ET);
  GetColumnData(FileName , TitIrri  , Irri);
  GetColumnData(FileName , TitSoilTemp  , SoilTemp);
  GetColumnData(FileName , TitSunshine  , Sunshine);
  GetColumnData(FileName , TitDay  , Day);
  GetColumnData(FileName , TitMonth  , Month);
  GetColumnData(FileName , TitYear  , Year);
  GetColumnData(FileName , TitObs  , Obs);
  GetColumnData(FileName , TitObsCC  , ObsCC);
}
if(ext=="csv")
{
  RecNum=CountRegistersFromCSVFile(FileName);
  GetColumnDataFromCSVFile(FileName , TitTMin , MinTemp  );
  GetColumnDataFromCSVFile(FileName , TitTMax , MaxTemp  );
  GetColumnDataFromCSVFile(FileName , TitPrec , Precipit );
  GetColumnDataFromCSVFile(FileName , TitRad  , Radiation);
  GetColumnDataFromCSVFile(FileName , TitET  , ET);
  GetColumnDataFromCSVFile(FileName , TitIrri  , Irri);
  GetColumnDataFromCSVFile(FileName , TitSoilTemp  , SoilTemp);
  GetColumnDataFromCSVFile(FileName , TitSunshine  , Sunshine);
  GetColumnDataFromCSVFile(FileName , TitDay  , Day);
  GetColumnDataFromCSVFile(FileName , TitMonth  , Month);
  GetColumnDataFromCSVFile(FileName , TitYear  , Year);
  GetColumnDataFromCSVFile(FileName , TitObs  , Obs);
  GetColumnDataFromCSVFile(FileName , TitObsCC  , ObsCC);
}
}
//------------------------------------------------------------------------------
int ClimateFile::CountRegistersFromCSVFile(char* FileName)
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
int ClimateFile::CountRegisters(char* FileName)
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
void ClimateFile::Clone(ClimateFile* other)
{
  strcpy (other->FileName,FileName);
  strcpy (other->TitTMin,TitTMin);
  strcpy (other->TitTMax,TitTMax);
  strcpy (other->TitPrec,TitPrec);
  strcpy (other->TitRad,TitRad);
  strcpy (other->TitET,TitET);
  strcpy (other->TitIrri,TitIrri);
  strcpy (other->TitSoilTemp,TitSoilTemp);
  strcpy (other->TitDay,TitDay);
  strcpy (other->TitMonth,TitMonth);
  strcpy (other->TitYear,TitYear);
  strcpy (other->TitSunshine,TitSunshine);
  strcpy (other->TitObs,TitObs);
  strcpy (other->TitObsCC,TitObsCC);
  Climate::Clone(this);
}
//------------------------------------------------------------------------------
void Climate::CalcularET0()
{
// Declaracion de variables
  double Tmax,Tmin,SR,n,P,Lat_deg,Lat_rad,u2,Tx,Tb,To,Th,a,b,PC,ea;
  double Tc,Tav,W,Tac,Te,Rs,N;
  int day;
  double Xl,dp,PAR,eTx,eTm,es,S,Rnoc,TK4,dr,Ds,X,Ws,Ra,Max_Tr,Rso,Rnoc_rel,Rnol,Rn;
// constantes
  double pi=3.141592653589793;
  double Cp=1.013*pow(10,-3);
  double E=0.622;
  double L=2.45;
  double Gsc=0.0820;
  double BC=4.903*pow(10,-9);
// ----------------
  P=101.3*pow(((293-(0.0065*z))/293),5.26);
  Hemisphere=Hemisphere;
  Lat_deg=(Lat_Degrees+Lat_Minutes/60.0+Lat_Seconds/(60.0*60.0))*Hemisphere;
  Lat_rad=Lat_deg*(pi/180.0);
  switch(Select_Wind_cat)
  {
    case 1:
      u2=2.0;
    break;
    case 2:
      u2=6.0;
    break;
    case 3:
      u2=10.0;
    break;
    default:
    break;
  };
  switch(ThermalCond)
  {
    case 1:
      Tb=0;
      To=17;
      Th=25;
    break;
    case 2:
      Tb=2;
      To=20;
      Th=28;
    break;
    case 3:
      Tb=4;
      To=23;
      Th=30;
    break;
    default:
    break;
  };

  switch(Select_AP)
  {
    case 1:
      a=0.29;
      b=0.42;
    break;
    case 2:
      a=0.211;
      b=0.467;
    break;
    case 3:
      a=0.231;
      b=0.521;
    break;
    case 4:
      a=0.397;
      b=0.379;
    break;
    case 5:
      a=0.378;
      b=0.438;
    break;
    case 6:
      a=0.282;
      b=0.562;
    break;
    case 7:
      a=0.301;
      b=0.377;
    break;
    default:
    break;
  };
  PC=(Cp*P)/(E*L);
  day=0;  // falta definir
  Xl=0.0;
  for(int i=0;i<RecNum;i++)
  {
    day++;
    Tmin=MinTemp[i];
    Tmax=MaxTemp[i];
    SR=Radiation[i];
    n=Sunshine[i];
    dp=Tmin;
    PAR=Radiation[i]*0.5;
    Tx=(Tmin+Tmax)/2.0;
    W=0.0;
    if(Tx>=Tb && Tx<To)
    {
      W=1-pow(((Tx-To)/(To-Tb)),2);
    }
    if(Tx>=To && Tx<=Th)
    {
      W=-1*((Tx-Th)/(Th-To));  // verificar importante negativo
    }
    ea=0.6108*exp((17.27*dp)/(dp+237.3));
    eTx=0.6108*exp((17.27*Tmax)/(Tmax+237.3));
    eTm=0.6108*exp((17.27*Tmin)/(Tmin+237.3));
    es=(eTx+eTm)/2.0;
    S=(4098*es)/pow((Tx+237.3),2);
    TK4=((pow(Tmax+273.16,4)+pow(Tmin+273.16,4))/2)*BC;
    dr=(1+0.033*cos(2*pi*day/365.0));
    Ds=0.409*sin(2*pi/365.0*day-1.39);
    X=1-pow(tan(Lat_rad),2)*pow(tan(Ds),2);
    if(X<=0)
    {
      Xl=0.00001;
    }
    else
    {
      Xl=X;
    }
    Ws=(pi/2)-atan((-tan(Lat_rad) * tan(Ds) )/pow(Xl,0.5));
    N=(24.0/pi)*Ws;
    Ra=24.0*60.0/pi*Gsc*dr*(Ws*sin(Lat_rad)*sin(Ds)+cos(Lat_rad)*cos(Ds)*sin(Ws));
    Rs=0.0;
    if(haveSunshine==1)
    { // si el usuario dispone de datos horas sol (sunshine) entonces se calcula Rs
      Rs=(a+b*(n/N))*Ra;
    }
    Max_Tr=a+b;
    Rso=Max_Tr*Ra;
    if(haveSunshine==1)
    { // si el usuario dispone de datos horas sol (sunshine) entonces se calcula Rnoc en funcion de Rs
      Rnoc=(1-Albedo)*Rs;
      Rnoc_rel=Rs/Rso;
    }
    else
    {
      Rnoc=(1-Albedo)*SR;
      Rnoc_rel=SR/Rso;
    }
    Rnol=TK4*(0.34-(0.14*pow(ea,0.5)))*(1.35*Rnoc_rel-0.35);
    Rn=Rnoc-Rnol;
    double ET0=(0.408*S*(Rn-G)+PC*(900/(Tx+273))*u2*(es-ea))/(S+PC*(1+0.34*u2));
    ET[i] = floor(ET0 * 100.0 + 0.5) / 100.0;
    Sunshine[i]=N;
  }
}
//------------------------------------------------------------------------------
bool Climate::saveET0_N(char* pnombre)
{
  FILE *stream=NULL;
  stream = fopen (pnombre,"w");
  if (stream==NULL)
  {
     fclose(stream);
     return false;
  }
  rewind(stream);
  for(int i=1;i<=RecNum;i++)
  {
    fprintf(stream,"%lf %lf\n",ET[i-1],Sunshine[i-1]);
  }
  fclose(stream);
  return true;
}
//------------------------------------------------------------------------------
bool Climate::saveSoil(char* pnombre)
{
  FILE *stream=NULL;
  stream = fopen (pnombre,"w");
  if (stream==NULL)
  {
     fclose(stream);
     return false;
  }
  rewind(stream);
  for(int i=1;i<=RecNum;i++)
  {
    fprintf(stream,"%lf\n",SoilTemp[i-1]);
  }
  fclose(stream);
  return true;
}
//------------------------------------------------------------------------------
bool Climate::saveTT(char* pnombre)
{
  FILE *stream=NULL;
  stream = fopen (pnombre,"w");
  if (stream==NULL)
  {
     fclose(stream);
     return false;
  }
  rewind(stream);
  for(int i=1;i<=numtt;i++)
  {
    fprintf(stream,"%lf\n",TT[i-1]);
    double borrar=TT[i-1];
    borrar=borrar;
  }
  fclose(stream);
  return true;
}
//------------------------------------------------------------------------------
int Climate::setTmin(double* temp,int numreg)
{
  if(tminSelected!=0)
  {
   delete []tminSelected;
   tminSelected=0;
  }
  tminSelected=new double[numreg];
  for(int i=0;i<numreg;i++)
  {
    tminSelected[i]=temp[i];
  }
  numregSelected=numreg;
  return numreg;
}
//------------------------------------------------------------------------------
int Climate::setTmax(double* temp,int numreg)
{
  if(tmaxSelected!=0)
  {
   delete []tmaxSelected;
   tmaxSelected=0;
  }
  tmaxSelected=new double[numreg];
  for(int i=0;i<numreg;i++)
  {
    tmaxSelected[i]=temp[i];
  }
  numregSelected=numreg;
  return numreg;
}
//------------------------------------------------------------------------------
int Climate::setTT(double* temp,int numreg)
{
  if(numtt!=0)
  {
   delete []TT;
   TT=0;
  }
  TT=new double[numreg];
  for(int i=0;i<numreg;i++)
  {
    TT[i]=temp[i];
  }
  numtt=numreg;
  return numtt;
}
//------------------------------------------------------------------------------

#endif
