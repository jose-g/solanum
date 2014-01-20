#ifndef SoilH
#define SoilH
  class Soil
  {
   public:
     Soil();
     ~Soil();
     char* SoilList[12];
     int SoilNumber;
     int SelectedSoil;

     double Moisture;
     double OM;
     double SoilDepth;
     double Ph;
     double MaxDepth;
     double BD;
     double k;
     double c;
     void CleanVariables();
     void SetVariables();
     void Clone(Soil*);
  };
#endif
