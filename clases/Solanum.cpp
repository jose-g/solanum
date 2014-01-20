#ifndef SolanumCPP
#define SolanumCPP
#include "Solanum.h"
#include <string.h>
const int maxScenarios=30;
//---------------------------------------------------------
Solanum::Solanum()
{
  totalScenarios=0;
  scenario=0;
  scenario = new ManageDataPotato*[maxScenarios]; //
  for(int i=0;i<maxScenarios;i++)
  {
    scenario[i]=new ManageDataPotato(0);
  }
  condtemp=new ManageDataPotato(0);
}
//---------------------------------------------------------
Solanum::~Solanum()
{
 if (scenario != 0)
 {
  delete[] scenario;
  scenario=0;
 }
 delete condtemp;
}
//---------------------------------------------------------
int  Solanum::getmaxScenarios()
{
  return maxScenarios;
}
//---------------------------------------------------------
#endif
