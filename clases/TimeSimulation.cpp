#ifndef TimeSimulationCPP
#define TimeSimulationCPP
#include <string.h>
#include "TimeSimulation.h"
TimeSimulation::TimeSimulation()
{
 location = 0;
 location = new char[50];
 Month = 0;
 Month = new char[20];
 CleanVariables();
}
TimeSimulation::~TimeSimulation()
{
 if (location != 0)
 {
  delete [ ]location;
  location=0;
 }
 if (Month != 0)
 {
  delete [ ]Month;
  Month=0;
 }
}
void TimeSimulation::CleanVariables()
{
  DayStart   = 10;
  MonthStart = 10;
  duration   = 0;
  repetitions = 20;
  YearStart=1900;
  idYear=-1;
  strcpy(location,"");
  strcpy(Month,"");
}
void TimeSimulation::Clone(TimeSimulation* other)
{
  other->DayStart   = DayStart;
  other->MonthStart = MonthStart;
  other->duration   = duration;
  other->repetitions   = repetitions;
  other->YearStart=YearStart;
  other->idYear=idYear;
  strcpy(other->location,location);
  strcpy(other->Month,Month);
}
#endif
