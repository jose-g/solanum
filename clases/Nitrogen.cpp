#ifndef NitrogenCPP
#define NitrogenCPP
#include "Nitrogen.h"
Nitrogen::Nitrogen()
{
  OMList[0]="Humus";
  OMList[1]="Alfalfa hay";
  OMList[2]="Grass clippings";
  OMList[3]="Rotted manure";
  OMList[4]="Corn stalks";
  OMList[5]="Cereal straw";
  OMList[6]="Farm manure";
  OMList[7]="Alder sawdust";
  OMList[8]="Newspaper";
  OMNumber=9;

  FertList[0]="Urea";
  FertList[1]="Nitrato de amonio";
  FertList[2]="Fosfato monoamonico";
  FertNumber=3;

  CleanVariables();
}
Nitrogen::~Nitrogen()
{
}
void Nitrogen::CleanVariables()
{
  SelectedOM=-1;
  SelectedFert=-1;
  AmountFert=0;
  FOMi=0;
}
void Nitrogen::Clone(Nitrogen* other)
{
  other->SelectedOM=SelectedOM;
  other->SelectedFert=SelectedFert;
  other->AmountFert=AmountFert;
  other->FOMi=FOMi;
}
#endif
