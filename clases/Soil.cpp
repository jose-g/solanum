#ifndef SoilCPP
#define SoilCPP
#include "Soil.h"
Soil::Soil()
{
  SoilList[0]="Silty Clay";
  SoilList[1]="Silty Clay Loam";
  SoilList[2]="Clay";
  SoilList[3]="Silt";
  SoilList[4]="Silty Loam";
  SoilList[5]="Clay Loam";
  SoilList[6]="Sand";
  SoilList[7]="Loam";
  SoilList[8]="Loamy Sand";
  SoilList[9]="Sandy Loam";
  SoilList[10]="Sandy Clay";
  SoilList[11]="Sandy Clay Loam";
  SoilNumber=12;


  CleanVariables();
}
Soil::~Soil()
{
}
void Soil::CleanVariables()
{
  SelectedSoil=-1;
  Moisture=0.0;
  OM=0.0;
  SoilDepth=0.0;
  Ph=0.0;
  MaxDepth=0.0;
  BD=0.0;
  k=0.0;
  c=0.0;
}
void Soil::Clone(Soil* other)
{
  other->SelectedSoil=SelectedSoil;
  other->Moisture=Moisture;
  other->OM=OM;
  other->SoilDepth=SoilDepth;
  other->Ph=Ph;
  other->MaxDepth=MaxDepth;
  other->BD=BD;
  other->k=k;
  other->c=c;
}
void Soil::SetVariables()
{
  switch(SelectedSoil)
  {
    case 0: // Silty Clay
      BD=1.24;  // BD, Bulk density  (g/cm3)
      k=15;   // k. thermal conductivity (W*m-1*K-1)
      c=10.9;   // C, thermal capacity (J*kg-1*K-1)
      break;
    case 1: // Silty Clay Loam
      BD=1.30;  // BD, Bulk density  (g/cm3)
      k=120;   // k. thermal conductivity (W*m-1*K-1)
      c=6.4;   // C, thermal capacity (J*kg-1*K-1)
      break;
    case 2: // Clay
      BD=1.36;  // BD, Bulk density  (g/cm3)
      k=2;   // k. thermal conductivity (W*m-1*K-1)
      c=11;   // C, thermal capacity (J*kg-1*K-1)
      break;
    case 3: // Silt
      BD=1.37;  // BD, Bulk density  (g/cm3)
      k=50;   // k. thermal conductivity (W*m-1*K-1)
      c=1.4;   // C, thermal capacity (J*kg-1*K-1)
      break;
    case 4: // Silty Loam
      BD=1.37;  // BD, Bulk density  (g/cm3)
      k=150;   // k. thermal conductivity (W*m-1*K-1)
      c=1.4;   // C, thermal capacity (J*kg-1*K-1)
      break;
    case 5: // Clay Loam
      BD=1.40;  // BD, Bulk density  (g/cm3)
      k=100;   // k. thermal conductivity (W*m-1*K-1)
      c=7;   // C, thermal capacity (J*kg-1*K-1)
      break;
    case 6: // Sand
      BD=1.42;  // BD, Bulk density  (g/cm3)
      k=1500;   // k. thermal conductivity (W*m-1*K-1)
      c=1.8;   // C, thermal capacity (J*kg-1*K-1)
      break;
    case 7: // Loam
      BD=1.44;  // BD, Bulk density  (g/cm3)
      k=250;   // k. thermal conductivity (W*m-1*K-1)
      c=2.8;   // C, thermal capacity (J*kg-1*K-1)
      break;
    case 8: // Loamy Sand
      BD=1.44;  // BD, Bulk density  (g/cm3)
      k=800;   // k. thermal conductivity (W*m-1*K-1)
      c=1.8;   // C, thermal capacity (J*kg-1*K-1)
      break;
    case 9: // Sandy Loam
      BD=1.46;  // BD, Bulk density  (g/cm3)
      k=500;   // k. thermal conductivity (W*m-1*K-1)
      c=1.7;   // C, thermal capacity (J*kg-1*K-1)
      break;
    case 10: // Sandy Clay
      BD=1.48;  // BD, Bulk density  (g/cm3)
      k=75;   // k. thermal conductivity (W*m-1*K-1)
      c=10.6;   // C, thermal capacity (J*kg-1*K-1)
      break;
    case 11: // Sandy Clay Loam
      BD=1.51;  // BD, Bulk density  (g/cm3)
      k=125;   // k. thermal conductivity (W*m-1*K-1)
      c=5.7;   // C, thermal capacity (J*kg-1*K-1)
      break;
  }
}
#endif
