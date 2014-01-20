#ifndef PlantH
#define PlantH
  class Plant
  {
    public:
      Plant();
      ~Plant();
      double N;
      double fcl;
      double F0;
      double R0;
      double d;
      double t50;
      double LUE;
      int EDay;
      double v;
      double t0;
      void CleanVariables();
      void Clone(Plant*);
  };
#endif
