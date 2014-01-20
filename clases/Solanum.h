#ifndef SolanumH
#define SolanumH
#include "ManageDataPotato.h"
  class Solanum
  {
   private:
   public:
     Solanum();
     ~Solanum();
     int totalScenarios;
     ManageDataPotato** scenario;
     ManageDataPotato* condtemp;
     int getmaxScenarios();
  };
#endif
