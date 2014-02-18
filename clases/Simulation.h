#ifndef SimulationH
#define SimulationH
#include "Climate.h"
#include "TimeSimulation.h"
#include "Crop.h"
#include "Nitrogen.h"
#include "Soil.h"
#include "Report.h"
  class Simulation
  {
   public:
     Simulation(int);
     ~Simulation();
     ClimateFile *climate;
     Crop *crop;
     Nitrogen *nitrogen;
     Soil *soil;
     TimeSimulation *time;
     Report* report;
     int NumberScenario;

     int simulate();
     int Just_simulate();
     int Just_simulate2();
     int CalculatesAfterSimulation();

     int Month(int);
     double Random();
     void CleanVariables();
     int DeterminePosition(char*,char*);
     int GetColumnData(char*,char*,double*);
     int idModel;
     void Clone(Simulation*);
     char* obsFileName;
     char* TitObsFY;
     char* TitObsCC;
     void CleanTitles();

    double tdm[100][365];
    double tdmw[100][365];
    double tdmn[100][365];
    double tdmf[100][365];

    double dty[100][365];
    double dtyw[100][365];
    double dtyn[100][365];
    double dtyf[100][365];

    double fty[100][365];
    double ftyw[100][365];
    double ftyn[100][365];
    double ftyf[100][365];

    double cc[100][365];
    double ccw[100][365];
    double ccn[100][365];
    double ccf[100][365];
// promedios
    double Xtdm[365];
    double Xtdmw[365];
    double Xtdmn[365];
    double Xtdmf[365];

    double Xdty[365];
    double Xdtyw[365];
    double Xdtyn[365];
    double Xdtyf[365];

    double Xfty[365];
    double Xftyw[365];
    double Xftyn[365];
    double Xftyf[365];

    double Xcc[365];
    double Xccw[365];
    double Xccn[365];
    double Xccf[365];

    double LC1[365];
    double LC2[365];
// estadisticos
  double varObs;
  double varEst;
  double covObsEst;
  double avgObs;
  double avgEst;
  double BIAS;
  double MAE;
  double MSE;
  double RMSE;
  double RRMSE;
  double EF;
  double rC;
  double Obs[365];

  double varObsCC;
  double varEstCC;
  double covObsEstCC;
  double avgObsCC;
  double avgEstCC;
  double BIASCC;
  double MAECC;
  double MSECC;
  double RMSECC;
  double RRMSECC;
  double EFCC;
  double rCCC;
  double ObsCC[365];

  void Estadisticos();
  void CalcularTT(double*,double*);
  double GetMedian(double*,int);
  double ult_fty[100];
  double ExpFreshYield;
  double MinFreshYield;
  double MaxFreshYield;
  void LoadObservedInformation();
  int RecNum;
  int CountRegisters(char*);
  int CountRegistersFromCSVFile(char*);
  int GetColumnDataFromCSVFile(char*,char*,double*);
  int DeterminePositionFromCSVFile(char*,char*);
  void CleanVectorObserved();
  int SaveOutputs();

  };
#endif
