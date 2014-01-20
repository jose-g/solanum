#ifndef ClimateH
#define ClimateH
  class Climate
  {
   public:
     Climate(int);
     ~Climate();
     double* MinTemp;
     double* MaxTemp;
     double* Precipit;
     double* Radiation;
     double* ET;
     double* Irri;
     double* SoilTemp;
     double* Sunshine;
     double* Day;
     double* Month;
     double* Year;
     double* Obs;
     double* ObsCC;
     int ThermalCond;
     void CleanVariables();
     void CleanVectorClimate();
     int RecNum;
     void CalcularET0();
     bool saveET0(char*);
     bool saveSoil(char*);
     int Hemisphere;
     double Lat_Degrees;
     double Lat_Minutes;
     double Lat_Seconds;
     int Select_Wind_cat;
     int Select_AP;
     double z;
     double G;
     double Albedo;
     int haveSunshine;
     void Clone(Climate*);
     double* tminSelected;
     double* tmaxSelected;
     double* TT;
     int numtt;
     int numregSelected;
     int setTmin(double*,int);
     int setTmax(double*,int);
     int setTT(double*,int);
     bool saveTT(char*);
   private:
  };
  class ClimateFile : public Climate
  {
    public:
      ClimateFile(int);
      ~ClimateFile();
      char* FileName;
      char* TitTMin;
      char* TitTMax;
      char* TitPrec;
      char* TitRad;
      char* TitET;
      char* TitIrri;
      char* TitSoilTemp;
      char* TitDay;
      char* TitMonth;
      char* TitYear;
      char* TitSunshine;
      char* TitObs;
      char* TitObsCC;

      void  CleanVariables();
      int   DeterminePosition(char*,char*);
      int   DeterminePositionFromCSVFile(char*,char*);
      int   GetColumnData(char*,char*,double*);
      int   GetColumnData(char*,char*,double*,int*);
      int   GetColumnDataFromCSVFile(char*,char*,double*);
      void  LoadClimateInformation();
      int CountRegisters(char*);
      int CountRegistersFromCSVFile(char*);
      void CleanTitles();
      void Clone(ClimateFile*);
 };
#endif
