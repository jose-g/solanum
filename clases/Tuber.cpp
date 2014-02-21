#ifndef TuberCPP
#define TuberCPP
#include "Tuber.h"
Tuber::Tuber()
{
 CleanVariables();
}
Tuber::~Tuber()
{
}
void Tuber::CleanVariables()
{
  M      = 0.0;
  A      = 0.0;
  b      = 0.0;
  DMCont = 0.0;
  Tcr = -3;
  Tld = -5;
  Trg = -8;
  w=0.0;
  Pc=0.0;
}
void Tuber::Clone(Tuber* other)
{
  other->M      = M;
  other->A      = A;
  other->b      = b;
  other->DMCont = DMCont;
  other->Tcr = Tcr;
  other->Tld = Tld;
  other->Trg = Trg;
  other->w = w;
  other->Pc = Pc;
}
#endif
