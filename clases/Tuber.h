#ifndef TuberH
#define TuberH
  class Tuber
  {
   public:
     Tuber();
     ~Tuber();
     double M;
     double A;
     double b;
     double DMCont;
     double Tcr;
     double Tld;
     double Trg;
     double w;
     double Pc;
     void CleanVariables();
     void Clone(Tuber*);
  };
#endif
