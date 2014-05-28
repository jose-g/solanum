#ifndef CropCPP
#define CropCPP
#include "Crop.h"
#include <fstream>
#include "sstream.h"
Crop::Crop()
{
  plant=0;
  plant=new Plant();
  tuber=0;
  tuber=new Tuber();
  cropname = 0;
  cropname = new char[30];
  CropList[0]="Waycha";
  CropList[1]="Alpha";
  CropList[2]="Chaska";
  CropList[3]="Luki";
  CropList[4]="Victoria";
  CropList[5]="Ndinamagara";
  CropNumber=6;
  CleanVariables();
}
Crop::~Crop()
{
 if (plant != 0)
 {
  delete plant;
  plant=0;
 }
 if (tuber != 0)
 {
  delete tuber;
  tuber=0;
 }
 if (cropname != 0)
 {
  delete [ ]cropname;
  cropname=0;
 }
}
void Crop::CleanVariables()
{
  SelectedCrop=-1;
  strcpy(cropname,"");
  plant->CleanVariables();
  tuber->CleanVariables();
}
void Crop::DefaultValuesForKindOfCrop(int key)
{
// Kind of crops:
// 0 : Ajahuiri
// 1 : Luki
// 2 : Gendarme
// 3 : Waycha
// 4 : Alpha
// 5 : Condori
// 6 : Tunari
// 7 : Sajama
// 8 : Illimani
// 9 : Totorena
// 10: Canchan
  if(key==0)
  {
     SelectedCrop=16;
     plant->fcl=0.89;
     plant->F0=536;
     plant->R0=1045;
     tuber->M=0.77;
     tuber->A=880;
     tuber->b=175;
     tuber->DMCont=0.21;
     plant->LUE=2.8;
     tuber->Tcr=-3;
     tuber->Tld=-5;
     tuber->Trg=-8;
     tuber->w=0.5;
     tuber->Pc=15;
     strcpy(cropname,"Yungay");
  }
/*
  if(key==1)
  {
     SelectedCrop=1;
     plant->fcl=0.5169;
     plant->F0=394;
     plant->R0=761;
     plant->LUE=2.88;
     tuber->M=0.9152;
     tuber->A=526.6;
     tuber->b=154.9;
     tuber->DMCont=0.22;
     tuber->Tcr=-0.7;
     tuber->Tld=-3.3;
     tuber->Trg=-4;
     strcpy(cropname,"Alpha");
  }
  if(key==2)
  {
     SelectedCrop=2;
     plant->fcl=0.6625;
     plant->F0=398;
     plant->R0=1011;
     plant->LUE=2.65;
     tuber->M=0.6637;
     tuber->A=817.5;
     tuber->b=153.8;
     tuber->DMCont=0.24;
     tuber->Tcr=-1.9;
     tuber->Tld=-3.8;
     tuber->Trg=-6;
     strcpy(cropname,"Chaska");
  }
  if(key==3)
  {
     SelectedCrop=3;
     plant->fcl=0.8989;
     plant->F0=560;
     plant->R0=847;
     plant->LUE=2.72;
     tuber->M=0.7907;
     tuber->A=744.6;
     tuber->b=147.9;
     tuber->DMCont=0.3;
     tuber->Tcr=-3;
     tuber->Tld=-5;
     tuber->Trg=-8;
     strcpy(cropname,"Luki");
  }
  if(key==4)
  {
     SelectedCrop=4;
     plant->fcl=0.9259;
     plant->F0=281;
     plant->R0=807;
     plant->LUE=2.8;
     tuber->M=0.8055;
     tuber->A=711.4;
     tuber->b=127.8;
     tuber->DMCont=0.2;
     tuber->Tcr=-3;
     tuber->Tld=-5;
     tuber->Trg=-8;
     strcpy(cropname,"Victoria");
  }
  if(key==5)
  {
     SelectedCrop=5;
     plant->fcl=0.9003;
     plant->F0=206;
     plant->R0=824;
     plant->LUE=2.8;
     tuber->M=0.9528;
     tuber->A=447.4;
     tuber->b=337.1;
     tuber->DMCont=0.2;
     tuber->Tcr=-3.0;
     tuber->Tld=-5.0;
     tuber->Trg=-8.0;
     strcpy(cropname,"Ndinamagara");
  }
*/
}
//------------------------------------------------------------------------------
void Crop::Clone(Crop* other)
{
  other->SelectedCrop=SelectedCrop;
  strcpy(other->cropname,cropname);
  plant->Clone(other->plant);
  tuber->Clone(other->tuber);
}
//------------------------------------------------------------------------------
bool Crop::saveParameters(char* pnombre,int cover1p,int GrowthZero,int GrowthZero2,double photosen,double photocrit)
{
  FILE *stream=NULL;
  stream = fopen (pnombre,"w");
  if (stream==NULL)
  {
     fclose(stream);
     return false;
  }
  rewind(stream);
//  fprintf(stream,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n","Emergence day","Maximun canopy cover index","Maximum harvest index","1% canopy cover","day at maximum canopy cover value","Tt at maximum tuber growth rate","Inversal rate at the maximum tuber growth","Tt at the end of the growth period","Tt at the maximum canopy cover growth rate","Average light use efficiency","Dry matter concentration");
//  fprintf(stream,"%i,%lf,%lf,%i,%i,%lf,%lf,%lf,%lf,%lf,%lf\n",plant->EDay,plant->fcl,tuber->M,tuber->cover1p,tuber->GrowthZero,tuber->A,tuber->b,plant->R0,plant->F0,plant->LUE,tuber->DMCont);
  fprintf(stream,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n","Name of the crop","Maximun canopy cover index","Tt at the maximum canopy cover growth rate","Tt at the maximum canopy cover value","Maximum harvest index","Tt at maximum tuber partition rate","TT just before the tuber initiation process","Dry matter concentration","Average light use efficiency","Tcr","Tld","Trg","Emergence day","1% canopy cover","day at maximum canopy cover value","day at maximum tuberization","Photoperiod sensitivity","Critical photoperiod");
  fprintf(stream,"%s,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%i,%lf,%lf,%i,%i,%i\n", cropname,plant->fcl, plant->F0, plant->R0, tuber->M, tuber->A, tuber->b, tuber->DMCont, plant->LUE,tuber->Tcr,tuber->Tld,tuber->Trg, plant->EDay,photosen,photocrit,cover1p,GrowthZero,GrowthZero2);
  fclose(stream);
  return true;
}
//------------------------------------------------------------------------------
Cultivo::Cultivo()
{
  plant=0;
  plant=new Plant();
  tuber=0;
  tuber=new Tuber();
  cropname = 0;
  cropname = new char[30];
  CleanVariables();
}
//------------------------------------------------------------------------------
Cultivo::~Cultivo()
{
 if (plant != 0)
 {
  delete plant;
  plant=0;
 }
 if (tuber != 0)
 {
  delete tuber;
  tuber=0;
 }
 if (cropname != 0)
 {
  delete [ ]cropname;
  cropname=0;
 }
}
//------------------------------------------------------------------------------
void Cultivo::CleanVariables()
{
  strcpy (cropname, "");
  plant->CleanVariables();
  tuber->CleanVariables();
}
//------------------------------------------------------------------------------
DBCultivo::DBCultivo()
{
//  Item=0;
//  Item=new Cultivo[100];
  DBName=0;
  DBName= new char[255];

  numreg=0;
}
//------------------------------------------------------------------------------
DBCultivo::~DBCultivo()
{
/*
 if (Item != 0)
 {
  delete []Item;
  Item=0;
 }
 */
 if (DBName != 0)
 {
  delete DBName;
  DBName=0;
 }

}
//------------------------------------------------------------------------------
bool DBCultivo::LoadCrops(char* pnombre)
{
std::ifstream  data(pnombre);
int contDatos;
int num;
std::string line;
int numlin=0;
int indice=-1;
  while(std::getline(data,line))
  {
    std::stringstream  lineStream(line);
    std::string        cell;
    numlin++;
    int cont=0;
    if(numlin>1)
    {
    indice++;
    while(std::getline(lineStream,cell,','))
    {
      cont++;
      // Aqui obtenemos una celda
      num=strlen(cell.c_str());
      char* dato = new char[ num + 1 ];
      strcpy(dato,cell.c_str());
      if(cont==1)
      {
        strcpy(Item[indice].cropname,dato);
      }
      if(cont==2)
      {
        Item[indice].plant->fcl=atof(dato);
      }
      if(cont==3)
      {
        Item[indice].plant->F0=atof(dato);
      }
      if(cont==4)
      {
        Item[indice].plant->R0=atof(dato);
      }
      if(cont==5)
      {
        Item[indice].tuber->M=atof(dato);
      }
      if(cont==6)
      {
        Item[indice].tuber->A=atof(dato);
      }
      if(cont==7)
      {
        Item[indice].tuber->b=atof(dato);
      }
      if(cont==8)
      {
        Item[indice].tuber->DMCont=atof(dato);
      }
      if(cont==9)
      {
        Item[indice].plant->LUE=atof(dato);
      }
      if(cont==10)
      {
        Item[indice].tuber->Tcr=atof(dato);
      }
      if(cont==11)
      {
        Item[indice].tuber->Tld=atof(dato);
      }
      if(cont==12)
      {
        Item[indice].tuber->Trg=atof(dato);
      }
      if(cont==13)
      {
        Item[indice].plant->EDay=atoi(dato);
      }
      if(cont==14)
      {
        Item[indice].tuber->w=atof(dato);
      }
      if(cont==15)
      {
        Item[indice].tuber->Pc=atof(dato);
      }
    }
    }
  }
data.close();
numreg=numlin-1;
return true; // se abrio correctamente el archivo y se levanto los datos
}
//------------------------------------------------------------------------------
bool DBCultivo::saveAllParameters(char* pnombre)
{
  FILE *stream=NULL;
  stream = fopen (pnombre,"w");
  if (stream==NULL)
  {
     fclose(stream);
     return false;
  }
  rewind(stream);
  fprintf(stream,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n","Name of the crop","Maximun canopy cover index","Tt at the maximum canopy cover growth rate","Tt at the maximum canopy cover value","Maximum harvest index","Tt at maximum tuber partition rate","TT just before the tuber initiation process","Dry matter concentration","Average light use efficiency","Trc","Tld","Trg","Emergence day","Photoperiod sensitivity","Critical photoperiod");
  for(int i=0;i<numreg;i++)
  {
//    fprintf(stream,"%s,%i,%lf,%lf,%i,%i,%lf,%lf,%lf,%lf,%lf,%lf\n",Item[i].cropname,Item[i].plant->EDay,plant->fcl,tuber->M,tuber->cover1p,tuber->GrowthZero,tuber->A,tuber->b,plant->R0,plant->F0,plant->LUE,tuber->DMCont);
    fprintf(stream,"%s,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%i,%lf,%lf\n", Item[i].cropname,Item[i].plant->fcl, Item[i].plant->F0, Item[i].plant->R0, Item[i].tuber->M, Item[i].tuber->A, Item[i].tuber->b, Item[i].tuber->DMCont, Item[i].plant->LUE, Item[i].tuber->Tcr, Item[i].tuber->Tld, Item[i].tuber->Trg, Item[i].plant->EDay, Item[i].tuber->w, Item[i].tuber->Pc);
  }
  fclose(stream);
  return true;
}
//------------------------------------------------------------------------------
bool DBCultivo::deleteReg(int reg) // el valor de reg va desde cero, el primer registro seria cero
{
  if(reg==numreg-1)
  {
    strcpy(Item[reg].cropname,"");
    Item[reg].plant->fcl=0.0;
    Item[reg].plant->F0=0.0;
    Item[reg].plant->R0=0.0;
    Item[reg].tuber->M=0.0;
    Item[reg].tuber->A=0.0;
    Item[reg].tuber->b=0.0;
    Item[reg].tuber->DMCont=0.0;
    Item[reg].plant->LUE=0.0;
    Item[reg].tuber->Tcr=0.0;
    Item[reg].tuber->Tld=0.0;
    Item[reg].tuber->Trg=0.0;
    Item[reg].plant->EDay=0;
    Item[reg].tuber->w=0;
    Item[reg].tuber->Pc=0;
    numreg--;
  }
  else
  {
    int ultind=numreg-1;
    for(int i=reg;i<=ultind-1;i++)
    {
      strcpy(Item[i].cropname,Item[i+1].cropname);
      Item[i].plant->fcl=Item[i+1].plant->fcl;
      Item[i].plant->F0=Item[i+1].plant->F0;
      Item[i].plant->R0=Item[i+1].plant->R0;
      Item[i].tuber->M=Item[i+1].tuber->M;
      Item[i].tuber->A=Item[i+1].tuber->A;
      Item[i].tuber->b=Item[i+1].tuber->b;
      Item[i].tuber->DMCont=Item[i+1].tuber->DMCont;
      Item[i].plant->LUE=Item[i+1].plant->LUE;
      Item[i].tuber->Tcr=Item[i+1].tuber->Tcr;
      Item[i].tuber->Tld=Item[i+1].tuber->Tld;
      Item[i].tuber->Trg=Item[i+1].tuber->Trg;
      Item[i].plant->EDay=Item[i+1].plant->EDay;
      Item[i].tuber->w=Item[i+1].tuber->w;
      Item[i].tuber->Pc=Item[i+1].tuber->Pc;
    }
    strcpy(Item[ultind].cropname,"");
    Item[ultind].plant->fcl=0.0;
    Item[ultind].plant->F0=0.0;
    Item[ultind].plant->R0=0.0;
    Item[ultind].tuber->M=0.0;
    Item[ultind].tuber->A=0.0;
    Item[ultind].tuber->b=0.0;
    Item[ultind].tuber->DMCont=0.0;
    Item[ultind].plant->LUE=0.0;
    Item[ultind].tuber->Tcr=0.0;
    Item[ultind].tuber->Tld=0.0;
    Item[ultind].tuber->Trg=0.0;
    Item[ultind].plant->EDay=0;
    Item[ultind].tuber->w=0.0;
    Item[ultind].tuber->Pc=0.0;
    numreg--;

  }
  return true;
}
//------------------------------------------------------------------------------

#endif
