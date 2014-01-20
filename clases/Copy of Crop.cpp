#ifndef CropCPP
#define CropCPP
#include "Crop.h"
Crop::Crop()
{
  plant=0;
  plant=new Plant();
  tuber=0;
  tuber=new Tuber();
  CropList[0]="Ndinamagara (SAS)";
  CropList[1]="Victoria (SAS)";
  CropList[2]="CIP388611.22 (SAS)";
  CropList[3]="Ndinamagara  (R-calculador de parametros)";
  CropList[4]="Victoria (R-calculador de parametros)";
  CropList[5]="CIP388611.22 (R-calculador de parametros)";
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
}
void Crop::CleanVariables()
{
  SelectedCrop=-1;
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
     SelectedCrop=0;
     plant->fcl=0.74;
     plant->F0=0.0034;
     plant->R0=0.0063;
     plant->d=253.0;
     plant->t50=1360.0;
     plant->LUE=2.8;
     tuber->M=0.8;
     tuber->A=944.0;
     tuber->b=-9.6;
     tuber->DMCont=0.33;
     tuber->Tcr=-2.4;
     tuber->Tld=-5.0;
     tuber->Trg=-7.0;

  }
  if(key==1)
  {
     SelectedCrop=1;
     plant->fcl=0.72;
     plant->F0=0.0026;
     plant->R0=0.0064;
     plant->d=249.0;
     plant->t50=1385.0;
     plant->LUE=2.72;
     tuber->M=0.74;
     tuber->A=1125;
     tuber->b=-8.1;
     tuber->DMCont=0.3;
     tuber->Tcr=-3.0;
     tuber->Tld=-5.0;
     tuber->Trg=-8.0;
  }
  if(key==2)
  {
     SelectedCrop=2;
     plant->fcl=0.78;
     plant->F0=0.0028;
     plant->R0=0.0072;
     plant->d=278.0;
     plant->t50=1358.0;
     plant->LUE=2.65;
     tuber->M=0.84;
     tuber->A=891.0;
     tuber->b=-7.5;
     tuber->DMCont=0.31;
     tuber->Tcr=-1.0;
     tuber->Tld=-4.0;
     tuber->Trg=-5.0;
  }
  if(key==3)
  {
     SelectedCrop=3;
     plant->fcl=0.74;
     plant->F0=0.0040;
     plant->R0=0.0064;
     plant->d=302.0;
     plant->t50=1369.0;
     plant->LUE=2.53;
     tuber->M=0.77;
     tuber->A=1061.0;
     tuber->b=-5.5;
     tuber->DMCont=0.25;
     tuber->Tcr=-1.0;
     tuber->Tld=-4.0;
     tuber->Trg=-5.0;
  }
  if(key==4)
  {
     SelectedCrop=4;
     plant->fcl=1.0;
     plant->F0=0.0049;
     plant->R0=0.0066;
     plant->d=425.0;
     plant->t50=1185.0;
     plant->LUE=2.88;
     tuber->M=0.86;
     tuber->A=822.0;
     tuber->b=-4.8;
     tuber->DMCont=0.22;
     tuber->Tcr=-0.7;
     tuber->Tld=-3.3;
     tuber->Trg=-4.0;
  }
  if(key==5)
  {
     SelectedCrop=5;
     plant->fcl=0.65;
     plant->F0=0.0033;
     plant->R0=0.0063;
     plant->d=278.0;
     plant->t50=1392.0;
     plant->LUE=2.69;
     tuber->M=0.74;
     tuber->A=1074.0;
     tuber->b=-7.4;
     tuber->DMCont=0.23;
     tuber->Tcr=-1.6;
     tuber->Tld=-3.6;
     tuber->Trg=-6.0;
  }
  if(key==6)
  {
     SelectedCrop=6;
     plant->fcl=0.63;
     plant->F0=0.0043;
     plant->R0=0.0061;
     plant->d=219.0;
     plant->t50=1417.0;
     plant->LUE=2.79;
     tuber->M=0.78;
     tuber->A=1083.0;
     tuber->b=-6.1;
     tuber->DMCont=0.23;
     tuber->Tcr=-1.8;
     tuber->Tld=-3.0;
     tuber->Trg=-6.0;
  }
  if(key==7)
  {
     SelectedCrop=7;
     plant->fcl=0.74;
     plant->F0=0.0043;
     plant->R0=0.0061;
     plant->d=229.0;
     plant->t50=1399.0;
     plant->LUE=2.85;
     tuber->M=0.77;
     tuber->A=1061.0;
     tuber->b=-8.1;
     tuber->DMCont=0.24;
     tuber->Tcr=-1.9;
     tuber->Tld=-3.8;
     tuber->Trg=-6.0;
  }
  if(key==8)
  {
     SelectedCrop=8;
     plant->fcl=0.66;
     plant->F0=0.0036;
     plant->R0=0.0064;
     plant->d=230.0;
     plant->t50=1410.0;
     plant->LUE=2.65;
     tuber->M=0.79;
     tuber->A=1098.0;
     tuber->b=-5.3;
     tuber->DMCont=0.24;
     tuber->Tcr=-1.9;
     tuber->Tld=-3.8;
     tuber->Trg=-6.0;
  }
  if(key==9)
  {
     SelectedCrop=9;
     plant->fcl=0.66;
     plant->F0=0.0036;
     plant->R0=0.0064;
     plant->d=230.0;
     plant->t50=1410.0;
     plant->LUE=2.65;
     tuber->M=0.79;
     tuber->A=1098.0;
     tuber->b=-5.3;
     tuber->DMCont=0.24;
     tuber->Tcr=-1.5;
     tuber->Tld=-3.0;
     tuber->Trg=-6.0;
  }
  if(key==10)
  {
     SelectedCrop=10;
     plant->fcl=0.9728;
     plant->F0=0.00591;
     plant->R0=0.00677;
     plant->d=612.0;
     plant->t50=1718.0;
     plant->LUE=5.5;
     tuber->M=0.8456;
     tuber->A=722.6;
     tuber->b=-2.4386;
     tuber->DMCont=0.21;
     tuber->Tcr=-1.0;
     tuber->Tld=-3.0;
     tuber->Trg=-4.0;
  }
}
#endif
