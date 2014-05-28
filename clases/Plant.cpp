#ifndef PlantCPP
#define PlantCPP
#include "Plant.h"
//------------------------------------------------------------------------------
Plant::Plant()
{
  CleanVariables();
}
//------------------------------------------------------------------------------
Plant::~Plant()
{
}
//------------------------------------------------------------------------------
void Plant::CleanVariables()
{
  N    =0.0;
  fcl  =0.0;
  F0   =0.0;
  R0   =0.0;
  d    =0.0;
  t50  =0.0;
  LUE  =0.0;
  EDay =0;
  v    =0.075; // by default is 0.075
  t0   =0.0;
}
void Plant::Clone(Plant* other)
{

  other->N    =N;
  other->fcl  =fcl;
  other->F0   =F0;
  other->R0   =R0;
  other->d    =d;
  other->t50  =t50;
  other->LUE  =LUE;
  other->EDay =EDay;
  other->v    =v;
  other->t0   =t0;

}

#endif
