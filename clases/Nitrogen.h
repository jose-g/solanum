#ifndef NitrogenH
#define NitrogenH
  class Nitrogen
  {
   public:
     Nitrogen();
     ~Nitrogen();
     char* OMList[9];
     int OMNumber;
     int SelectedOM;

     char* FertList[3];
     int FertNumber;
     int SelectedFert;

     double AmountFert;
     double FOMi;
     void CleanVariables();
     void Clone(Nitrogen*);
  };
#endif
