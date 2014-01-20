#ifndef CropH
#define CropH
#include "Plant.h"
#include "Tuber.h"
  class Crop
  {
   public:
     Crop();
     ~Crop();
     char* CropList[11];
     int CropNumber;
     int SelectedCrop;
     char* cropname;
     Plant* plant;
     Tuber* tuber;
     void CleanVariables();
     void DefaultValuesForKindOfCrop(int);
     void Clone(Crop*);
     bool saveParameters(char* pnombre,int,int,int);
  };
  class Cultivo
  {
  public:
     Cultivo();
     ~Cultivo();
     Plant* plant;
     Tuber* tuber;
     char* cropname;
     void CleanVariables();
  };
  class DBCultivo
  {
  public:
     DBCultivo();
     ~DBCultivo();
     char* DBName;
     Cultivo Item[100];
     int numreg;
     bool LoadCrops(char*);
     bool saveAllParameters(char*);
     bool deleteReg(int);
  };
#endif
