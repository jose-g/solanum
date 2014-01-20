#ifndef ReportH
#define ReportH
#include "TimeSimulation.h"
  class Report
  {
   public:
     Report();
     ~Report();
     char* WorkDir;
     char* Archivo1;
     char* Archivo2;
     char* Archivo3;
     char* Archivo4;
     char* Archivo5;
     char* Archivo6;
     char* DMProd;
     char* DMProdResume;
     char* Estadistico;
     char* rBoxPlotfty;
     TimeSimulation* time;
     char* variety;
     int repetitions;
     int scenario;
     void CleanVariables();
     void DeleteReports();
     void GenerateTextReport();
     void GenerateDMProd();
     void GenerateDMProdResume();
     void GenerateEstadistico();
     void Clone(Report*);
     void SetReports();
// resultados estadisticos
// Fresh tuber yield
  double varObs;
  double varEst;
  double covObsEst;
  double avgObs;
  double avgEst;
  double BIAS;
  double MAE;
  double RMSE;
  double RRMSE;
  double EF;
  double rC;
// Canopy cover  
  double varObsCC;
  double varEstCC;
  double covObsEstCC;
  double avgObsCC;
  double avgEstCC;
  double BIASCC;
  double MAECC;
  double RMSECC;
  double RRMSECC;
  double EFCC;
  double rCCC;
  };
#endif
