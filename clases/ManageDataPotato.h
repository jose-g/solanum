#ifndef ManageDataPotatoH
#define ManageDataPotatoH
#include "Climate.h"
#include "TimeSimulation.h"
#include "Crop.h"
#include "Nitrogen.h"
#include "Soil.h"
#include "Report.h"
#include "Simulation.h"
  class ManageDataPotato
  {
   private:
     char* workdir;
   public:
     ManageDataPotato(int);
     ~ManageDataPotato();
     int idModel;
     ClimateFile *climate;
     TimeSimulation *time;
     Crop *crop;
     Nitrogen *nitrogen;
     Soil *soil;
     Report *report;
     Simulation *simulation;
     void CleanCondition();
     void DefaultCondition();
     void GetWorkDir(char*);
     bool SaveCondition(char*);
     bool LoadCondition(char*);
     int DoSimulation();
     void Clone(ManageDataPotato*);
  };
#endif
