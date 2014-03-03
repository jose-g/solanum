#ifndef SimulationCPP
#define SimulationCPP
#include "Simulation.h"
#include <math.h>
#include <fstream.h>
#include <vector.h>
#include <sstream.h>
#include "system.hpp"
#include <algorithm>

#include "Sol integral 2012 Tor 9394 9.cpp"

double aleatorio(double lo, double hi) {
   double valor=(rand() % 100);
   valor=valor/100.0;
   return valor;
}
struct myclass {
  bool operator() (double i,double j) { return (i<j);}
} myobject;

// --------------------------------------------------------------------------------------------------------
Simulation::Simulation(int IDmodel)
{
  obsFileName = 0;
  obsFileName = new char[255];
  TitObsFY  = 0;
  TitObsCC  = 0;
  TitObsFY  = new char[255];
  TitObsCC  = new char[255];

  NumberScenario=0;
  idModel=IDmodel; // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
for(int isim=0;isim<100;isim++)
{
  for(int i=0;i<365;i++)
  {
    tdm[isim][i]=0.0;
    tdmw[isim][i]=0.0;
    tdmn[isim][i]=0.0;
    tdmf[isim][i]=0.0;


    dty[isim][i]=0.0;
    dtyw[isim][i]=0.0;
    dtyn[isim][i]=0.0;
    dtyf[isim][i]=0.0;


    fty[isim][i]=0.0;
    ftyw[isim][i]=0.0;
    ftyn[isim][i]=0.0;
    ftyf[isim][i]=0.0;

    cc[isim][i]=0.0;
    ccw[isim][i]=0.0;
    ccn[isim][i]=0.0;
    ccf[isim][i]=0.0;
  }
}
  for(int i=0;i<365;i++)
  {
    Xtdm[i]=0.0;
    Xtdmw[i]=0.0;
    Xtdmn[i]=0.0;
    Xtdmf[i]=0.0;

    Xdty[i]=0.0;
    Xdtyw[i]=0.0;
    Xdtyn[i]=0.0;
    Xdtyf[i]=0.0;

    Xfty[i]=0.0;
    Xftyw[i]=0.0;
    Xftyn[i]=0.0;
    Xftyf[i]=0.0;

    Xcc[i]=0.0;
    Xccw[i]=0.0;
    Xccn[i]=0.0;
    Xccf[i]=0.0;
  }


}
// --------------------------------------------------------------------------------------------------------
Simulation::~Simulation()
{
 if (obsFileName != 0)
 {
  delete [ ]obsFileName;
  obsFileName=0;
 }
 if (TitObsFY != 0)
 {
  delete [ ]TitObsFY;
  TitObsFY=0;
 }
 if (TitObsCC != 0)
 {
  delete [ ]TitObsCC;
  TitObsCC=0;
 }

}
// -----------------------------------------------------------------------------
void Simulation::CleanTitles()
{
  strcpy (TitObsFY, "");
  strcpy (TitObsCC, "");
}
//------------------------------------------------------------------------------
int Simulation::Just_simulate2()
{
randomize();
for(int isim=0;isim<time->repetitions;isim++)
{ // begin for isim

double MinTemp[365];
double MaxTemp[365];
double Rainfall[365];
double Radiation[365];
double PET[365];
double Irrigation[365];
double TT[365];

// locate the record with start date
  int reg=-1;
  for(int i=0;i<climate->RecNum;i++)
  {
    if(climate->Day[i]==time->DayStart && climate->Month[i]==time->MonthStart && climate->Year[i]==time->YearStart)
    {
      reg=i; // get record
      break;
    }
  }
  if(reg==-1)
  {
    return 2; // start date does not exist
  }

//
  int newItem=-1;
//
  int numdias=time->duration;
  double* datTmin=new double[numdias];
  double* datTmax=new double[numdias];

  for(int i=reg;i<climate->RecNum;i++)
  {
      newItem++;
      if(newItem<365)
      {
        if(newItem<time->duration)
        {
          datTmin[newItem]=climate->MinTemp[i];
          datTmax[newItem]=climate->MaxTemp[i];
        }
        MinTemp[newItem]= climate->MinTemp[i];
        MaxTemp[newItem]= climate->MaxTemp[i];
        Rainfall[newItem]= climate->Precipit[i];
        Radiation[newItem]= climate->Radiation[i];
        PET[newItem]= climate->ET[i];
        Irrigation[newItem]= climate->Irri[i];
      }
  }
  CalcularTT(datTmin,datTmax);

  delete []datTmin;
  delete []datTmax;

  for(int i=0;i<numdias;i++)
  {
      TT[i]   = climate->TT[i];
  }

//  ASIGNACION DE INPUTS

  int EDay=crop->plant->EDay;
  double v=crop->plant->v;
  double ym=crop->plant->fcl;
  double N=crop->plant->N;
  double te=crop->plant->R0;
  double tm=crop->plant->F0;
  double RUE=crop->plant->LUE;
  double s_0=crop->tuber->A;
  double DMcont=crop->tuber->DMCont;
  double r=crop->tuber->M;
  double t=crop->tuber->b;
  double Tcr=crop->tuber->Tcr;
  double Tld=crop->tuber->Tld;
  double Trg=crop->tuber->Trg;
  double RUE_0=crop->tuber->A;

  int Type=nitrogen->SelectedOM;
  int Fert=nitrogen->SelectedFert;
  double amount=nitrogen->AmountFert;
  double FOMi=nitrogen->FOMi;
  int dd=1;
  int mm=1;
  double ISM=soil->Moisture;
  double OM=soil->OM;
  double Soil_depth=soil->SoilDepth;
  int Soil_texture=soil->SelectedSoil;
  double pH=soil->Ph;
  double Dl=soil->MaxDepth;
  int Thermal_conditions=climate->ThermalCond;

//  declaracion de variables  (Posibles constantes)
double DMINR;  // humic frax decay rate
double DMOD;  // (0-1) factor decrease to rate of mineralix special cases (volcanic soil: less than 1), virgin soils (more than 1)
double _C;  //  % C org matt added Asumiendo como en la ecuacion que CN es 60
double FOCi;
double UREA;
double NUREAi;
double NH4_fert;
double NH4am;
double NO3fert;
double NO3am;
int PDate;
double OC;
double phn;
double AK;
double AKU;
double Area;
double D;
double Soil_Vol;
double RUEs;
double RUEs_0;
double GC0;
double GC250;
double hydric1;
double hydric2;
double hydric3;
double hydric4;
double hydric5;
double hydric6;
double hydric7;

double k;
double c;
double cl;
double CL;
double FC;
double WP;
double fc;
double wp;
double BD;
double Po;
double SWeight;
double OMw;
double NHUMi;
double CHUMi;

double Tb;
double To;
double Th;

double OM_CN1;
double OM_CN2;

double CN;

double _N;
// declaracion de variables

double HUM;
double NHUM;
double CS;
double NO3POOL;
double NUREA;
double FOM;
double FPOOLCE;
double FPOOLLI;
double FPOOLCA;
double RHMINacum;
double Hum_decomp__acum;
double NCE_acum;
double NLI_acum;
double acumGRNOM;
double NCA_acum;
double acumGRCOM;
double comp2;
double cd108;
double N_lib_acum;
double NH4POOL;
double Tac;
double rnd;
double rdm;
double TDMw;
double TDM;
double TDMf;
double c1;
double c2;
double C3;
double REB;
double TDMn;

double reba;
double fccf;
double ay2;
double ay1;
double Npc;
double Npot;
double canopy;
double canopy1;
double Part;
double DTYw;
double FTYw;
double DTY;
double FTY;
double DTYf;
double FTYf;
double DTYn;
double FTYn;
double NH4ppm;
double var1;
double FONi;
double NO3ppm;
double Nac;
double NacNpot;
double Ns;
double TOTN;
double CNR;
double CNRF;
double s;
double WFD;
double MF;
double SWF;
double MFU;
int day;
double Irri;
double ETo;
double Tmax;
double Tmin;
double tt;
double Tav;
double W;
double Tl;
double Stemp;
double TF;
double min;
double min1;
double RHMIN;
double flow109;
double flow105;
double flow102;
double flow103;
double MFTF;
double G1CA;
double CA;
double flow6;
double G1CE;
double CE;
double flow1;
double G1LI;
double LI;
double flow2;
double GRCOM;
double grcom;
double flow108;
double TFF;
double TFU;
double UHYDR;
double flow1_0;
double flow2_0;
double NH4u;
double var13;
double Tmin_0;
double CCRF;
double Reb;
double CCL;
double Rain;
double PAR;
int month;
int PDay;
int DAE;
double Te;
double CC;
double Eo;
double To_0;
double T;
double S;
double Ws;
double RUEw;
double dW;
double CC_0;
double CCf;
double dTDM_0;
double CCn;
double dTDM_1;

double delayCCf;
double fay1;
double delayCC;
double dCC;
double fay2;

double CWs;
double FON;

double REST;
double RNACp;
double RNAC;
double rnac;
double GRNOMCE;
double flow3;
double GRNOMLI;
double flow4;
double GRNOMCA;
double GRNOM;
double flow110;
double flow101;
double grnom;
double flow107;
double NNOM;
double NH4o;
double var19;
double SNH4;
double SANC;
double ELNC;
double RP2;
double RP22;
double A;
double bb;
double RNTRF;
double dNO3;
double flow2_1;
double flow205;
double flow4_0;
double flow102_0;
double flow7;
double CCw;
double dTDM;


// asignaciones realizadas antes de incio de la simulacion

DMINR = 8.3*pow(10,-5);
DMOD = 1;
_C = 60;
FOCi = FOMi*_C/100.0;
UREA = (Fert==1?amount:0);
NUREAi = UREA;
NH4_fert = (Fert==2?0.225:(Fert==3?0.15:0));
NH4am = NH4_fert*amount;
NO3fert = (Fert==2?0.775:0);
NO3am = NO3fert*amount;
PDate = (mm==1?dd:(mm==2?dd+31:(mm==3?dd+59:(mm==4?dd+90:(mm==5?dd+120:(mm==6?dd+151:(mm==7?dd+181:(mm==8?dd+212:(mm==9?dd+243:(mm==10?dd+273:(mm==11?dd+304:dd+334)))))))))));
OC = 0.58*OM;
phn = pH*0.05;
AK = -1.12+1.31*OC+0.203*pH-0.155*OC*pH;
AKU = (AK<0.25?0.25:AK);
Area = 10000;
D = Soil_depth*100;
Soil_Vol = Area*Soil_depth;
RUEs = 1;
RUEs_0 = RUEs;
GC0 = 0.6;
GC250 = 1;
switch (Soil_texture)
{
    case 1:
      hydric1=1.24;
      hydric2=54;
      hydric3=50;
      hydric4=32;
      hydric5=15;
      hydric6=10.9;
      hydric7=3845.3;
      break;
    case 2:
      hydric1=1.30;
      hydric2=52;
      hydric3=44;
      hydric4=23;
      hydric5=120;
      hydric6=6.4;
      hydric7=3862.5;
      break;
    case 3:
      hydric1=1.36;
      hydric2=55;
      hydric3=54;
      hydric4=39;
      hydric5=2;
      hydric6=11;
      hydric7=4567.7;
      break;
    case 4:
      hydric1=1.37;
      hydric2=43;
      hydric3=33;
      hydric4=9;
      hydric5=50;
      hydric6=1.4;
      hydric7=3404.6;
      break;
    case 5:
      hydric1=1.37;
      hydric2=46;
      hydric3=33;
      hydric4=13;
      hydric5=150;
      hydric6=1.4;
      hydric7=3404.6;
      break;
    case 6:
      hydric1=1.40;
      hydric2=50;
      hydric3=39;
      hydric4=23;
      hydric5=100;
      hydric6=7;
      hydric7=3863.0;
      break;
    case 7:
      hydric1=1.42;
      hydric2=36;
      hydric3=13;
      hydric4=6;
      hydric5=1500;
      hydric6=1.8;
      hydric7=2390.6;
      break;
    case 8:
      hydric1=1.44;
      hydric2=46;
      hydric3=31;
      hydric4=15;
      hydric5=250;
      hydric6=2.8;
      hydric7=3533.1;
      break;
    case 9:
      hydric1=1.44;
      hydric2=38;
      hydric3=16;
      hydric4=8;
      hydric5=800;
      hydric6=1.8;
      hydric7=2627.0;
      break;
    case 10:
      hydric1=1.46;
      hydric2=41;
      hydric3=22;
      hydric4=10;
      hydric5=500;
      hydric6=1.7;
      hydric7=3052.8;
      break;
    case 11:
      hydric1=1.48;
      hydric2=50;
      hydric3=39;
      hydric4=27;
      hydric5=75;
      hydric6=10.6;
      hydric7=4172.3;
      break;
    default:
      hydric1=1.51;
      hydric2=47;
      hydric3=32;
      hydric4=20;
      hydric5=125;
      hydric6=5.7;
      hydric7=3847.3;
}
k = hydric5;
c = hydric6;
cl = hydric3-0.5*(hydric3-hydric4);
CL = (double)(Soil_Vol*cl)/1000;
FC = (double)(Soil_Vol*hydric3)/1000;
WP = (double)(Soil_Vol*hydric4)/1000;
fc = hydric3;
wp = hydric4;
BD = hydric1*1000;
Po = (double)(100*(2.65-(double)(BD)/1000))/2.65;
SWeight = (double)(Soil_Vol*BD)/1000;
OMw = (double)(OM)/100*SWeight;
NHUMi = (double)(OMw*1000)/10;
CHUMi = OMw*1000;
switch (Thermal_conditions)
{
    case 1:
      Tb=0;
      To=17;
      Th=25;
      break;
    case 2:
      Tb=2;
      To=20;
      Th=28;
      break;
    default:
      Tb=4;
      To=23;
      Th=30;
}

switch (Type)
{
    case 1:
      OM_CN1=10;
      OM_CN2=1;
      break;
    case 2:
      OM_CN1=18;
      OM_CN2=1;
      break;
    case 3:
      OM_CN1=19;
      OM_CN2=1;
      break;
    case 4:
      OM_CN1=20;
      OM_CN2=1;
      break;
    case 5:
      OM_CN1=60;
      OM_CN2=1;
      break;
    case 6:
      OM_CN1=80;
      OM_CN2=1;
      break;
    case 7:
      OM_CN1=90;
      OM_CN2=1;
      break;
    case 8:
      OM_CN1=134;
      OM_CN2=1;
      break;
    default:
      OM_CN1=170;
      OM_CN2=1;
}

CN = OM_CN1;

_N = (double)(_C)/CN;

//  0 >= phase

        HUM = CHUMi;
        NHUM = NHUMi;
        CS = ISM;
        NO3POOL = NO3am;
        NUREA = NUREAi;
        FOM = FOMi;
        FPOOLCE = FOMi*0.7;
        FPOOLLI = FOMi*0.1;
        FPOOLCA = FOMi*0.2;
        RHMINacum = 0;
        Hum_decomp__acum = 0;
        NCE_acum = 0;
        NLI_acum = 0;
        acumGRNOM = 0;
        NCA_acum = 0;
        acumGRCOM = 0;
        comp2 = 0;
        cd108 = 0;
        N_lib_acum = 0;
        NH4POOL = 0;
        Tac = 1.0E-05;

        //Randomizepointer_0->rnd = 2*Randomizepointer_0->rnd_at_init-1;
        //Randomizepointer_0->rnd = 2*Randomizepointer_0->rnd_at_init-1;
        rnd=random(5001);
        rnd=rnd/5000;
//        rnd = 0.4;  // cambiado para efecto de prueba
        rdm = (double)(log((double)(1+rnd)/(1-rnd)))/1.82; // log: es logaritmo natural
        TDMw = 0;
        TDM = 1.0E-37;
        TDMf = 0;
        c1 = 0;
        c2 = 0;
        C3 = 0.00368;
        REB = 1;
        TDMn = 0;

//  INICIO DE LAS ITERACIONES
day=PDate-1;
PDay=-1;

  for(int i=0;i<time->duration;i++)
  { // begin for i
        day++;
        if(day==366) day=1;
    /* modelo matematico  */

        reba = REB;
        fccf = C3;
        ay2 = c2;
        ay1 = c1;
        Npc = 1.35+4.05*exp(-0.26*TDM);
        Npot = (double)(Npc*TDM)/100;
        canopy = ym*(1+(double)(te-Tac)/(te-tm))*pow((double)(Tac)/te,(double)(te)/(te-tm));
        canopy1 = rdm*v*canopy+canopy;
        Part = r*exp(-(exp((double)(-(Tac-s_0))/t)));
        DTYw = TDMw*Part;
        FTYw = (double)(DTYw)/DMcont;
        DTY = TDM*Part;
        FTY = (double)(DTY)/DMcont;
        DTYf = TDMf*Part;
        FTYf = (double)(DTYf)/DMcont;
        DTYn = TDMn*Part;
        FTYn = (double)(DTYn)/DMcont;
        NH4ppm = (double)(NH4POOL)/SWeight*1000;
        var1 = (FOM<5?0:FOM);
        FONi = (double)(FOM*_N)/100;
        NO3ppm = (double)(NO3POOL)/SWeight*1000;
        Nac = (double)(NO3POOL)/1000;
        NacNpot = (double)(Nac)/Npot;
        Ns = (NacNpot>1?1:(GC250-GC0)*NacNpot+GC0);
        TOTN = (NO3POOL>0?NO3POOL:0);
        CNR = (double)(FOCi)/(TOTN+FONi);
        CNRF = exp((double)(-0.963*(CNR-25))/25);
        s = CS;
        WFD = 1-(double)(s-FC)/(Po-FC);
        MF = (s>FC?(double)(s-FC)/(Po-FC):(s<=FC&&s>WP?1-0.5*((double)(s-WP)/(FC-WP)):0));
        SWF = MF+0.2;
        MFU = (SWF>1?1:(SWF<0?0:SWF));
        //day = fmod(glob_element(ts, 1)+PDate-1,365)+1;  // OBSERVACION : averiguar su funcion y traducir
        Irri = Irrigation[i];  // OBSERVACION : verificar que los datos de clima esten cargado la informacion adecuada
        ETo = PET[i];
        Tmax = MaxTemp[i];
        Tmin = MinTemp[i];
        tt = TT[i];
        Tav = (double)(Tmax+Tmin)/2;
        Tac = tt;
        W = (Tav>=Tb&&Tav<To?1-pow((double)(Tav-To)/(To-Tb),2):(Tav>=To&&Tav<=Th?-((double)(Tav-Th)/(Th-To)):0));
        Tl = 1.25*Tav;
        Stemp = (double)(2)/3.1416*(Tav-Tl)*exp((double)(-((double)(k)/(BD*c))*pow(3.1416,2)*1.0E+10)/pow(Dl,2))*sin((double)(3.1416*D)/Dl)+Tav+(double)(Tl-Tav)/Dl*D;
        TF = (Stemp<5?0:(Stemp>35?1:(double)(Stemp-5)/30));
        min = std::min(WFD,TF);
        min1 = std::min(min,phn);
        RHMIN = NHUM*DMINR*TF*MF*DMOD;
        flow109 = RHMIN;
        flow105 = RHMIN;
        flow102 = RHMIN*10;
        flow103 = flow102;
        MFTF = MF*TF;
        G1CA = CNRF*MFTF*0.8;
        CA = G1CA*FPOOLCA;
        flow6 = CA;
        G1CE = CNRF*MFTF*0.05;
        CE = G1CE*FPOOLCE;
        flow1 = CE;
        G1LI = CNRF*MFTF*0.0095;
        LI = G1LI*FPOOLLI;
        flow2 = LI;
        GRCOM = CA+CE+LI;
        grcom = GRCOM;
        flow108 = GRCOM;
        TFF = (double)(Stemp)/40+0.2;
        TFU = (TFF<0?0:TFF);
        UHYDR = AKU*std::min(MFU,TFU)*NUREA*0.01;
        flow1_0 = UHYDR;
        flow2_0 = flow1_0;
        NH4u = flow1_0;
        var13 = (double)(AKU*std::min(MFU,TFU)*NUREAi)/100;
        Tmin_0 = Tmin;
        CCRF = (Tmin_0<Tcr?(Tmin_0>Trg?(double)(Trg-Tmin_0)/(Trg-Tcr):0):1);
        Reb = (CCRF<REB?CCRF:REB);
        CCL = (Tmin_0<Tld?1:(Tmin_0<Tcr?1-(double)(Tld-Tmin_0)/(Tld-Tcr):0));
        Rain = Rainfall[i];
        PAR = Radiation[i]*0.5;
        month = (day<=31?1:(day>31&&day<=59?2:(day>59&&day<=90?3:(day>90&&day<=120?4:(day>120&&151?5:(day>151&&day<=181?6:(day>181&&day<=212?7:(day>212&&day<=243?8:(day>243&&day<=273?9:(day>273&&day<=304?10:(day>304&&day<=334?11:12)))))))))));
        PDay++;
        DAE = (PDay>=EDay?PDay-EDay:0);
        Te = (DAE<=0?0:(DAE>0&&Tav<Tb?0:(Tav>=Tb&&Tav<=Th?(Tav-Tb)*W:0)));
        CC = (DAE<=0?0:(canopy1>0?canopy1:pow(10,-4)));
        Eo = ym*ETo*exp(-0.7*4*CC);
        To_0 = (CC==0?0.0001:(double)(1.1*ETo*(1-exp(-0.7*4*CC)))/(1-exp(-0.7*4*ym)));
        T = (s>CL?To_0:(s<WP?0:(double)(To_0*(WP-s))/(WP-CL)));
        S = (Rain+Irri+CS-Eo-T<=0.9*WP?0.9*WP:(Rain+Irri+CS-Eo-T>=FC?FC:Rain+Irri+CS-Eo-T));
        Ws = (1-(double)(T)/To_0-0.8<0?0:1-(double)(T)/To_0-0.8);
        RUEw = ((double)(RUEs*(0.8-Ws))/0.8<0?0:(double)(RUEs*(0.8-Ws))/0.8);
        dW = (double)(RUE*CC*PAR)/100;
        CC_0 = CC;
        CCf = (CC_0+ay2-ay1>0?CC_0+ay2-ay1:0);
        dTDM_0 = (double)(CCf*PAR*RUEs_0)/100;
        CCn = CC*Ns;
        dTDM_1 = (double)(CCn*PAR*RUE_0)/100;
        
        delayCCf = CCf;
        fay1 = (CCL>0?delayCCf*CCL:0);
        delayCC = CC;
        dCC = CC_0-delayCC;
        fay2 = (dCC>0?dCC*REB:(double)(dCC*1)/REB);

        if(i==0)
        {
          CWs = Ws;
          FON = FONi;
        }

        REST = (var1>0?GRCOM*(0.02-(double)(FON)/var1):0);
        RNACp = std::min(REST,TOTN);
        RNAC = (RNACp<0?0:RNACp);
        rnac = RNAC;
        GRNOMCE = (FOM>=5?(double)(CE*FON)/FOM:0);
        flow3 = GRNOMCE;
        GRNOMLI = (FOM>=5?(double)(LI*FON)/FOM:0);
        flow4 = GRNOMLI;
        GRNOMCA = (FOM>=5?(double)(CA*FON)/FOM:0);
        GRNOM = GRNOMCA+GRNOMCE+GRNOMLI;
        flow110 = GRNOM*0.2;
        flow101 = (double)(GRNOM*0.2)/0.04;
        grnom = GRNOM;
        flow107 = GRNOM;
        NNOM = 0.8*GRNOM+RHMIN-RNAC;
        NH4o = NNOM;
        var19 = NH4o+NH4u+NH4am;
        SNH4 = var19;
        SANC = 1-exp(-0.01363*SNH4);
        ELNC = std::min(min,SANC);
        RP2 = exp(2.302*ELNC);
        RP22 = (RP2<0.05?0.05:(RP2>1?1:RP2));
        A = std::min(RP22,min1);
        bb = (double)(A*40*NH4ppm)/(NH4ppm+90);
        RNTRF = (bb>0.8?0.8:bb);
        dNO3 = RNTRF;
        flow2_1 = RNTRF;
        flow205 = RNTRF;
        flow4_0 = var19;
        flow102_0 = NNOM;
        flow7 = GRNOMCA;
        CCw = (CWs>75?0:(double)(75-CWs)/75*CC);
        dTDM = (double)(RUEw*CCw*PAR)/100;

    /*    SALIDAS    */
    tdm[isim][i]=TDM;
    tdmw[isim][i]=TDMw;
    tdmn[isim][i]=TDMn;
    tdmf[isim][i]=TDMf;


    dty[isim][i]=DTY;
    dtyw[isim][i]=DTYw;
    dtyn[isim][i]=DTYn;
    dtyf[isim][i]=DTYf;


    fty[isim][i]=FTY;
    ftyw[isim][i]=FTYw;
    ftyn[isim][i]=FTYn;
    ftyf[isim][i]=FTYf;

    cc[isim][i]=CC;
    ccw[isim][i]=CCw;
    ccn[isim][i]=CCn;
    ccf[isim][i]=CCf;

    /* fin de modelo matematico */

        NO3POOL = NO3POOL+dNO3;
        NHUM = NHUM+flow110-flow109;
        RHMINacum = RHMINacum+flow105;
        HUM = HUM+flow101-flow102;
        Hum_decomp__acum = Hum_decomp__acum+flow103;
        FOM = FOM-grcom;
        FON = FON+rnac-grnom;
        FPOOLCE = FPOOLCE-flow1;
        FPOOLLI = FPOOLLI-flow2;
        NCE_acum = NCE_acum+flow3;
        NLI_acum = NLI_acum+flow4;
        FPOOLCA = FPOOLCA-flow6;
        acumGRNOM = acumGRNOM+flow107;
        NCA_acum = NCA_acum+flow7;
        acumGRCOM = acumGRCOM+flow108;
        NUREA = NUREA-flow1_0;
        comp2 = comp2+flow2_0;
        cd108 = cd108+flow205;
        N_lib_acum = N_lib_acum+flow102_0;
        NH4POOL = NH4POOL+flow4_0-flow2_1;
        //Thermal_timepointer->Tac = Thermal_timepointer->Tac+stage_incr(&(Thermal_timepointer->anon_19), 1, Thermal_timepointer->Te);
        //Thermal_timepointer->Tac = Weatherpointer->tt;
        CS = CS+S-s;
        CWs = CWs+Ws;
        TDMw = TDMw+dTDM;
        TDM = TDM+dW;
        TDMf = TDMf+dTDM_0;
        c1 = c1+fay1-ay1;
        c2 = c2+fay2-ay2;
        C3 = C3+CCf-fccf;
        REB = REB+Reb-reba;
        TDMn = TDMn+dTDM_1;
  } // end for i
      switch (idModel)  // 1: Potential Growth , 2:Drought , 3:Nitrogen Stress , 4:Frost
      {
        case 1 : ult_fty[isim]=fty[isim][time->duration-1];
        break;
        case 2 : ult_fty[isim]=ftyw[isim][time->duration-1];
        break;
        case 3 : ult_fty[isim]=ftyn[isim][time->duration-1];
        break;
        case 4 : ult_fty[isim]=ftyf[isim][time->duration-1];
      }
} // end for isim
}
//------------------------------------------------------------------------------
int Simulation::Just_simulate()
{
for(int isim=0;isim<time->repetitions;isim++)
{ // begin for isim
  AME_model* test=new AME_model();
  int valor = do_setstep(1,1);
  for(int i=0;i<365;i++)
  {
    test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.MinTemp[i]   = 0;
    test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.MaxTemp[i]   = 0;
    test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.Rainfall[i]  = 0;
    test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.Radiation[i] = 0;
    test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.PET[i] = 0;
    test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.Irrigation[i] = 0;
//    test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.SoilTemp[i] = 0;
  }
  int reg=-1;
  for(int i=0;i<climate->RecNum;i++)
  {
    if(climate->Day[i]==time->DayStart && climate->Month[i]==time->MonthStart && climate->Year[i]==time->YearStart)
    {
      reg=i;
      break;
    }
  }
  if(reg==-1)
  {
    return 2; // La fecha ingresada no existe
  }
  int newItem=-1;
//
  int numdias=time->duration;
  double* datTmin=new double[numdias];
  double* datTmax=new double[numdias];

  for(int i=reg;i<climate->RecNum;i++)
  {
      newItem++;
      if(newItem<365)
      {
        if(newItem<time->duration)
        {
          datTmin[newItem]=climate->MinTemp[i];
          datTmax[newItem]=climate->MaxTemp[i];
        }
      test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.MinTemp[newItem]   = climate->MinTemp[i];
      test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.MaxTemp[newItem]   = climate->MaxTemp[i];
      test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.Rainfall[newItem]  = climate->Precipit[i];
      test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.Radiation[newItem] = climate->Radiation[i];
      test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.PET[newItem] = climate->ET[i];
      test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.Irrigation[newItem] = climate->Irri[i];
//      Obs[newItem]=climate->Obs[i];
//      ObsCC[newItem]=climate->ObsCC[i];
//      test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.SoilTemp[newItem] = climate->SoilTemp[i];
      }
  }
//
//  climate->setTmin(datTmin,cont+1);
//  climate->setTmax(datTmax,cont+1);
//
  CalcularTT(datTmin,datTmax);

  delete []datTmin;
  delete []datTmax;

  for(int i=0;i<numdias;i++)
  {
      test->Sol_integral_2012_Tor_9394_9_NewEq2013.Weather.TT[i]   = climate->TT[i];
  }


//
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Time.EDay=crop->plant->EDay;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Randomize.v=crop->plant->v;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Canopy_cover.ym=crop->plant->fcl;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Canopy_cover.N=crop->plant->N;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Canopy_cover.te=crop->plant->R0;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Canopy_cover.tm=crop->plant->F0;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Total_dry_matter_production.RUE=crop->plant->LUE;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Tuber_production.s_0=crop->tuber->A;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Tuber_production.DMcont=crop->tuber->DMCont;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Tuber_production.r=crop->tuber->M;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Tuber_production.t=crop->tuber->b;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Frost_limited_production.Tcr=crop->tuber->Tcr;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Frost_limited_production.Tld=crop->tuber->Tld;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Frost_limited_production.Trg=crop->tuber->Trg;

  test->Sol_integral_2012_Tor_9394_9_NewEq2013.N_dynamics.MIN_FOMA.Type_of_OM_added.Type=nitrogen->SelectedOM;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.N_dynamics.FERTILIZERS.Fert=nitrogen->SelectedFert;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.N_dynamics.FERTILIZERS.amount=nitrogen->AmountFert;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.N_dynamics.MIN_FOMA.FOMi=nitrogen->FOMi;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Time.Planting_Date.dd=1;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Time.Planting_Date.mm=1;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Soil_parameters.ISM=soil->Moisture;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Soil_parameters.OM=soil->OM;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Soil_parameters.Soil_depth=soil->SoilDepth;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Soil_parameters.Soil_texture=soil->SelectedSoil;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Soil_parameters.pH=soil->Ph;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Soil_parameters.Soil_temp_est.Dl=soil->MaxDepth;
  test->Sol_integral_2012_Tor_9394_9_NewEq2013.Thermal_time.Thermal_conditions=climate->ThermalCond;


  ame_rand_ref=&aleatorio;

  for(int i=0;i<time->duration;i++)
  { // begin for i
    int phasecont=do_setstep(i,-1);
    test->advancemodel(i,phasecont);
    if(i==0)
    {
      test->int_evalmodel(0,-2);
    }
    else
    {
      //test->int_evalmodel(i-1,1);
      test->int_evalmodel(i,1);

    }

    /*    SALIDAS    */
    tdm[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Total_dry_matter_production.TDM;
    tdmw[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Water_limited_production.Total_dry_matter_production_W.TDMw;
    tdmn[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Nitrogen_limited_production.Total_dry_matter_production_N.TDMn;
    tdmf[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Frost_limited_production.Total_dry_matter_prod_F.TDMf;


    dty[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Tuber_production.DTY;
    dtyw[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Water_limited_production.Tuber_production_W.DTYw;
    dtyn[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Nitrogen_limited_production.Tuber_production_N.DTYn;
    dtyf[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Frost_limited_production.Tuber_production_F.DTYf;


    fty[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Tuber_production.FTY;
    ftyw[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Water_limited_production.Tuber_production_W.FTYw;
    ftyn[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Nitrogen_limited_production.Tuber_production_N.FTYn;
    ftyf[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Frost_limited_production.Tuber_production_F.FTYf;

    cc[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Potential_production.Canopy_cover.CC;
    ccw[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Water_limited_production.Canopy_Cover_W.CCw;
    ccn[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Nitrogen_limited_production.Canopy_cover_N.CCn;
    ccf[isim][i]=test->Sol_integral_2012_Tor_9394_9_NewEq2013.Frost_limited_production.CCf;

    test->updatemodel(0, 1);
  } // end for i

  delete test;

      switch (idModel)  // 1: Potential Growth , 2:Drought , 3:Nitrogen Stress , 4:Frost
      {
        case 1 : ult_fty[isim]=fty[isim][time->duration-1];
        break;
        case 2 : ult_fty[isim]=ftyw[isim][time->duration-1];
        break;
        case 3 : ult_fty[isim]=ftyn[isim][time->duration-1];
        break;
        case 4 : ult_fty[isim]=ftyf[isim][time->duration-1];
      }

} // end for isim
}
//------------------------------------------------------------------------------
int Simulation::CalculatesAfterSimulation()
{
// se promedia los resultados
  for(int i=0;i<365;i++)
  {
    Xtdm[i]=0.0;
    Xtdmw[i]=0.0;
    Xtdmn[i]=0.0;
    Xtdmf[i]=0.0;

    Xdty[i]=0.0;
    Xdtyw[i]=0.0;
    Xdtyn[i]=0.0;
    Xdtyf[i]=0.0;

    Xfty[i]=0.0;
    Xftyw[i]=0.0;
    Xftyn[i]=0.0;
    Xftyf[i]=0.0;

    Xcc[i]=0.0;
    Xccw[i]=0.0;
    Xccn[i]=0.0;
    Xccf[i]=0.0;
  }
  for(int i=0;i<time->duration;i++)
  {
    for(int isim=0;isim<time->repetitions;isim++)
    {
      Xtdm[i]=Xtdm[i]+tdm[isim][i];
      Xtdmw[i]=Xtdmw[i]+tdmw[isim][i];
      Xtdmn[i]=Xtdmn[i]+tdmn[isim][i];
      Xtdmf[i]=Xtdmf[i]+tdmf[isim][i];

      Xdty[i]=Xdty[i]+dty[isim][i];
      Xdtyw[i]=Xdtyw[i]+dtyw[isim][i];
      Xdtyn[i]=Xdtyn[i]+dtyn[isim][i];
      Xdtyf[i]=Xdtyf[i]+dtyf[isim][i];

      Xfty[i]=Xfty[i]+fty[isim][i];
      Xftyw[i]=Xftyw[i]+ftyw[isim][i];
      Xftyn[i]=Xftyn[i]+ftyn[isim][i];
      Xftyf[i]=Xftyf[i]+ftyf[isim][i];

      Xcc[i]=Xcc[i]+cc[isim][i];
      Xccw[i]=Xccw[i]+ccw[isim][i];
      Xccn[i]=Xccn[i]+ccn[isim][i];
      Xccf[i]=Xccf[i]+ccf[isim][i];
    }
  }

  for(int i=0;i<time->duration;i++)
  {
  Xtdm[i]=Xtdm[i]/time->repetitions;
  Xtdmw[i]=Xtdmw[i]/time->repetitions;
  Xtdmn[i]=Xtdmn[i]/time->repetitions;
  Xtdmf[i]=Xtdmf[i]/time->repetitions;

  Xdty[i]=Xdty[i]/time->repetitions;
  Xdtyw[i]=Xdtyw[i]/time->repetitions;
  Xdtyn[i]=Xdtyn[i]/time->repetitions;
  Xdtyf[i]=Xdtyf[i]/time->repetitions;

  Xfty[i]=Xfty[i]/time->repetitions;
  Xftyw[i]=Xftyw[i]/time->repetitions;
  Xftyn[i]=Xftyn[i]/time->repetitions;
  Xftyf[i]=Xftyf[i]/time->repetitions;

  Xcc[i]=Xcc[i]/time->repetitions;
  Xccw[i]=Xccw[i]/time->repetitions;
  Xccn[i]=Xccn[i]/time->repetitions;
  Xccf[i]=Xccf[i]/time->repetitions;
  }
//
// calculo de los limites de confianza solo para modelo 1 : Potential Growth

//  double* LC1=new double[time->duration];
//  double* LC2=new double[time->duration];

  if(idModel==1) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
  {
    for(int iday=0;iday<time->duration;iday++)
    {
      double* diffEstX=new double[time->repetitions];
      double* diffEstXPow2=new double[time->repetitions];
      double sumatoria=0.0;
      for(int irep=0;irep<time->repetitions;irep++)
      {
        diffEstX[irep]=fty[irep][iday]-Xfty[iday];
        diffEstXPow2[irep]=pow(diffEstX[irep],2);
        sumatoria=sumatoria+diffEstXPow2[irep];
      }
      double varianza=sumatoria/double(time->repetitions);
      double devstd=sqrt(varianza);
      delete[] diffEstX;
      delete[] diffEstXPow2;

      LC1[iday]=Xfty[iday]-(devstd/sqrt(time->repetitions));
      LC2[iday]=Xfty[iday]+(devstd/sqrt(time->repetitions));
    }
  }
//
  if(idModel==1) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
  {
    ExpFreshYield=Xfty[time->duration-1];
  }
  if(idModel==2) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
  {
    ExpFreshYield=Xftyw[time->duration-1];
  }
  if(idModel==3) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
  {
    ExpFreshYield=Xftyn[time->duration-1];
  }
  if(idModel==4) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
  {
    ExpFreshYield=Xftyf[time->duration-1];
  }
  if(idModel==5) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
  {
    ExpFreshYield=Xfty[time->duration-1];
  }
// Hallar el valor maximo y minimo de fresh yield en todas las repeticiones
  MinFreshYield=1000;
  MaxFreshYield=0;
  for(int i=0;i<time->duration;i++)
  {
   for(int isim=0;isim<time->repetitions;isim++)
   {
    if(idModel==1) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
    {
      if(fty[isim][i]<MinFreshYield)
      {
        MinFreshYield=fty[isim][i];
      }
      if(fty[isim][i]>MaxFreshYield)
      {
        MaxFreshYield=fty[isim][i];
      }
    }
    if(idModel==2) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
    {
      if(ftyw[isim][i]<MinFreshYield)
      {
        MinFreshYield=ftyw[isim][i];
      }
      if(ftyw[isim][i]>MaxFreshYield)
      {
        MaxFreshYield=ftyw[isim][i];
      }
    }
    if(idModel==3) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
    {
      if(ftyn[isim][i]<MinFreshYield)
      {
        MinFreshYield=ftyn[isim][i];
      }
      if(ftyn[isim][i]>MaxFreshYield)
      {
        MaxFreshYield=ftyn[isim][i];
      }
    }
    if(idModel==4) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
    {
      if(ftyf[isim][i]<MinFreshYield)
      {
        MinFreshYield=ftyf[isim][i];
      }
      if(ftyf[isim][i]>MaxFreshYield)
      {
        MaxFreshYield=ftyf[isim][i];
      }
    }
    if(idModel==5) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
    {
      if(fty[isim][i]<MinFreshYield)
      {
        MinFreshYield=fty[isim][i];
      }
      if(fty[isim][i]>MaxFreshYield)
      {
        MaxFreshYield=fty[isim][i];
      }
    }
   }
  }
}
//------------------------------------------------------------------------------
int Simulation::SaveOutputs()
{
//  Se guarda los resultados en los archivos
// Se abre los archivos de salida
  FILE *stream1=0;
  FILE *stream2=0;
  FILE *stream3=0;
  FILE *stream4=0;
  FILE *stream5=0;
  FILE *stream6=0;
  FILE *streamBoxPlotfty=0;

  stream1=fopen(report->Archivo1,"w");
  rewind(stream1);
  stream2=fopen(report->Archivo2,"w");
  rewind(stream2);
  stream3=fopen(report->Archivo3,"w");
  rewind(stream3);
  stream4=fopen(report->Archivo4,"w");
  rewind(stream4);
  stream5=fopen(report->Archivo5,"w");
  rewind(stream5);
  stream6=fopen(report->Archivo6,"w");
  rewind(stream6);
  streamBoxPlotfty=fopen(report->rBoxPlotfty,"a");
  rewind(streamBoxPlotfty);

  double DMCont = crop->tuber->DMCont;
  fprintf(stream1,"%f\n",float(DMCont));

  for(int i=0;i<time->duration;i++)
  {

    if(idModel==1) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
    {
      fprintf(stream1,"%f %f\n",float(Xtdm[i]),float(Xdty[i]));
      fprintf(stream2,"%f %f %f\n",float(Xfty[i]),float(LC1[i]),float(LC2[i]));
    }
    if(idModel==2) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
    {
      fprintf(stream1,"%f %f\n",float(Xtdmw[i]),float(Xdtyw[i]));
      fprintf(stream2,"%f\n",float(Xftyw[i]));
    }
    if(idModel==3) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
    {
      fprintf(stream1,"%f %f\n",float(Xtdmn[i]),float(Xdtyn[i]));
      fprintf(stream2,"%f\n",float(Xftyn[i]));
    }
    if(idModel==4) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
    {
      fprintf(stream1,"%f %f\n",float(Xtdmf[i]),float(Xdtyf[i]));
      fprintf(stream2,"%f\n",float(Xftyf[i]));
    }
    if(idModel==5) // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
    {
      fprintf(stream1,"%f %f\n",float(Xtdm[i]),float(Xdty[i]));
      fprintf(stream2,"%f\n",float(Xfty[i]));
    }
    fprintf(stream3,"%f %f %f %f\n",float(Xcc[i]),float(Xccw[i]),float(Xccn[i]),float(Xccf[i]));
    fprintf(stream4,"%f %f %f %f\n",float(Xdty[i]),float(Xdtyw[i]),float(Xdtyn[i]),float(Xdtyf[i]));
    fprintf(stream5,"%f %f %f %f\n",float(Xfty[i]),float(Xftyw[i]),float(Xftyn[i]),float(Xftyf[i]));
    fprintf(stream6,"%f %f %f %f\n",float(Xtdm[i]),float(Xtdmw[i]),float(Xtdmn[i]),float(Xtdmf[i]));
  }
//  delete[] LC1;
//  delete[] LC2;
//
  // ordenar vector antes de guardar en archivo
  std::vector<double> myvector (ult_fty, ult_fty+time->repetitions);
  sort (myvector.begin(), myvector.end(), myobject);
  // vector rendimiento potencial
  std::vector<double> myvectorPot (ult_fty2, ult_fty2+time->repetitions);
  sort (myvectorPot.begin(), myvectorPot.end(), myobject);
  //
  fprintf(streamBoxPlotfty,"%i\n",time->repetitions);
  for(int irep=0;irep<time->repetitions;irep++)
  {
//    fprintf(streamBoxPlotfty,"%f\n",float(ult_fty[irep]));
    fprintf(streamBoxPlotfty,"%f %f\n",float(myvector[irep]),float(myvectorPot[irep]));
  }
//
  fclose(stream1);
  fclose(stream2);
  fclose(stream3);
  fclose(stream4);
  fclose(stream5);
  fclose(stream6);
  fclose(streamBoxPlotfty);
  return 0;
}
// --------------------------------------------------------------------------------------------------------
void Simulation::Estadisticos()
{
// selecciono los valores observados y los estimados
// Fresh tuber yield
  int contObs=0;
  for(int i=0;i<time->duration;i++)
  {
    if(Obs[i]!=0.0) contObs++;
  }
  double* valObs=new double[contObs];
  double* valEst=new double[contObs];

  int idObs=0;
  double fty;
  for(int i=0;i<time->duration;i++)
  {
    if(Obs[i]!=0.0)
    {
      valObs[idObs]=Obs[i];
      switch (idModel)  // 1: Potential Growth , 2:Drought , 3:Nitrogen Stress , 4:Frost
      {
        case 1 : fty=Xfty[i];
        break;
        case 2 : fty=Xftyw[i];
        break;
        case 3 : fty=Xftyn[i];
        break;
        case 4 : fty=Xftyf[i];
      }
      valEst[idObs]=fty;
      idObs++;
    }
  }
// Canopy cover
  int contObsCC=0;
  for(int i=0;i<time->duration;i++)
  {
    if(ObsCC[i]!=0.0) contObsCC++;
  }
  double* valObsCC=new double[contObsCC];
  double* valEstCC=new double[contObsCC];

  int idObsCC=0;
  double cc;
  for(int i=0;i<time->duration;i++)
  {
    if(ObsCC[i]!=0.0)
    {
      valObsCC[idObsCC]=ObsCC[i];
      switch (idModel)  // 1: Potential Growth , 2:Drought , 3:Nitrogen Stress , 4:Frost
      {
        case 1 : cc=Xcc[i];
        break;
        case 2 : cc=Xccw[i];
        break;
        case 3 : cc=Xccn[i];
        break;
        case 4 : cc=Xccf[i];
      }
      valEstCC[idObsCC]=cc;
      idObsCC++;
    }
  }
// Calculo de los estadisticos
//Fresh tuber yield
  double sumObs=0.0;
  double sumEst=0.0;
  double diff=0.0;
  double sumDiff=0.0;
  double diffAbs=0.0;
  double sumDiffAbs=0.0;
  double sumDiffPow2=0.0;
  for(int i=0;i<contObs;i++)
  {
    sumObs=sumObs+valObs[i];
    sumEst=sumEst+valEst[i];
    diff=valObs[i]-valEst[i];
    sumDiff=sumDiff+diff;
    diffAbs=fabs(diff);
    sumDiffAbs=sumDiffAbs+diffAbs;
    sumDiffPow2=sumDiffPow2+(pow(diff,2));
  }
  avgObs=sumObs/double(contObs);
  avgEst=sumEst/double(contObs);
  BIAS=sumDiff/double(contObs);
  MAE=sumDiffAbs/double(contObs);
  MSE=sumDiffPow2/double(contObs);
  RMSE=sqrt(MSE);
  RRMSE=RMSE/avgObs;
  double diffObsX=0.0;
  double diffObsXPow2=0.0;
  double sum_diffObsXPow2=0.0;
  double diffEstX=0.0;
  double diffEstXPow2=0.0;
  double sum_diffEstXPow2=0.0;
  double sum_diff_obs_est=0.0;
  for(int i=0;i<contObs;i++)
  {
    diffObsX=valObs[i]-avgObs;
    diffObsXPow2=pow(diffObsX,2);
    sum_diffObsXPow2=sum_diffObsXPow2+diffObsXPow2;

    diffEstX=valEst[i]-avgEst;
    diffEstXPow2=pow(diffEstX,2);
    sum_diffEstXPow2=sum_diffEstXPow2+diffEstXPow2;

    sum_diff_obs_est+=(diffObsX*diffEstX);
  }
  EF=1-(sumDiffPow2/sum_diffObsXPow2);
  varObs=sum_diffObsXPow2/double(contObs);  // varianza poblacional de las observaciones
  varEst=sum_diffEstXPow2/double(contObs);  // varianza poblacional de las estimaciones
  covObsEst=sum_diff_obs_est/double(contObs); // covarianza
  double diffavg=avgEst-avgObs;
  rC=2.0*covObsEst/(varEst+varObs+pow(diffavg,2));

//Canopy cover
  double sumObsCC=0.0;
  double sumEstCC=0.0;
  double diffCC=0.0;
  double sumDiffCC=0.0;
  double diffAbsCC=0.0;
  double sumDiffAbsCC=0.0;
  double sumDiffPow2CC=0.0;
  for(int i=0;i<contObsCC;i++)
  {
    sumObsCC=sumObsCC+valObsCC[i];
    sumEstCC=sumEstCC+valEstCC[i];
    diffCC=valObsCC[i]-valEstCC[i];
    sumDiffCC=sumDiffCC+diffCC;
    diffAbsCC=fabs(diffCC);
    sumDiffAbsCC=sumDiffAbsCC+diffAbsCC;
    sumDiffPow2CC=sumDiffPow2CC+(pow(diffCC,2));
  }
  avgObsCC=sumObsCC/double(contObsCC);
  avgEstCC=sumEstCC/double(contObsCC);
  BIASCC=sumDiffCC/double(contObsCC);
  MAECC=sumDiffAbsCC/double(contObsCC);
  MSECC=sumDiffPow2CC/double(contObsCC);
  RMSECC=sqrt(MSECC);
  RRMSECC=RMSECC/avgObsCC;
  double diffObsXCC=0.0;
  double diffObsXPow2CC=0.0;
  double sum_diffObsXPow2CC=0.0;
  double diffEstXCC=0.0;
  double diffEstXPow2CC=0.0;
  double sum_diffEstXPow2CC=0.0;
  double sum_diff_obs_estCC=0.0;
  for(int i=0;i<contObsCC;i++)
  {
    diffObsXCC=valObsCC[i]-avgObsCC;
    diffObsXPow2CC=pow(diffObsXCC,2);
    sum_diffObsXPow2CC=sum_diffObsXPow2CC+diffObsXPow2CC;

    diffEstXCC=valEstCC[i]-avgEstCC;
    diffEstXPow2CC=pow(diffEstXCC,2);
    sum_diffEstXPow2CC=sum_diffEstXPow2CC+diffEstXPow2CC;

    sum_diff_obs_estCC+=(diffObsXCC*diffEstXCC);
  }
  EFCC=1-(sumDiffPow2CC/sum_diffObsXPow2CC);
  varObsCC=sum_diffObsXPow2CC/double(contObsCC);  // varianza poblacional de las observaciones
  varEstCC=sum_diffEstXPow2CC/double(contObsCC);  // varianza poblacional de las estimaciones
  covObsEstCC=sum_diff_obs_estCC/double(contObsCC); // covarianza
  double diffavgCC=avgEstCC-avgObsCC;
  rCCC=2.0*covObsEstCC/(varEstCC+varObsCC+pow(diffavgCC,2));



  delete[] valObs;
  delete[] valEst;
  delete[] valObsCC;
  delete[] valEstCC;
}
// --------------------------------------------------------------------------------------------------------
int Simulation::Month(int day)
{
  int month=0;
  if(day<=31)           {month= 1;}
  if(day>31&&day<=59)   {month= 2;}
  if(day>59&&day<=90)   {month= 3;}
  if(day>90&&day<=120)  {month= 4;}
  if(day>120&&day<=151) {month= 5;}
  if(day>151&&day<=181) {month= 6;}
  if(day>181&&day<=212) {month= 7;}
  if(day>212&&day<=243) {month= 8;}
  if(day>243&&day<=273) {month= 9;}
  if(day>273&&day<=304) {month=10;}
  if(day>304&&day<=334) {month=11;}
  if(day>334)           {month=12;}
  return month;
}
// --------------------------------------------------------------------------------------------------------
double Simulation::Random()
{
  int valor=0.0;
  double ran=0.0;
  double Z0=0.0,Z1=0.0,Z2=0.0;
  begin:
  randomize();
  valor=random(50001);
  ran=double(valor)/50000.00;
  Z0=2*ran-1;
  if(Z0==1.0){goto begin;}
  if(Z0==-1.0){goto begin;}
  Z2=(1+Z0)/(1-Z0);
  Z1=log10(Z2)/1.82;
  return Z1;
}
// --------------------------------------------------------------------------------------------------------
void Simulation::CleanVariables()
{
  NumberScenario=0;
  strcpy (obsFileName, "");
}
// --------------------------------------------------------------------------------------------------------
int Simulation::DeterminePosition(char* archivo,char* campo)
{
  fstream FicheroGrafo;
  FicheroGrafo.open(archivo, ios::in);
  char p[100];
  int tam=strlen(campo);
  char valor[100]="";
  int i,j,z;
  FicheroGrafo.getline(p,100);
  int contPal=0;
  int OrdenCampo=0;
  bool encontro=false;
  bool finalizo=false;
  for (i=0;i<100;i++)
  {
     if(p[i] == '\0'){finalizo=true;}
     if (p[i] != ' ' && p[i] != '\0')
     {
       contPal++;
       valor[contPal-1]=p[i];
     }
     else
     {
       if(contPal>0)
       {
          OrdenCampo++;
          encontro=false;
          if(tam==contPal)
          {
            for(j=0;j<tam;j++)
            {
              if(valor[j]!=campo[j])
              {
                encontro=false;
                break;
              }
              encontro=true;
            }
          }
          for(z=0;z<contPal;z++){valor[z]=' ';}
          contPal=0;
       }
     }
     if(encontro){break;}
     if(finalizo && !encontro){OrdenCampo=0;break;}
  }
  FicheroGrafo.close();
  return OrdenCampo;
}
// --------------------------------------------------------------------------------------------------------
int Simulation::GetColumnData(char* FileName,char* FieldName,double* vect)
{
  int pos=DeterminePosition(FileName,FieldName);
  FILE *pFile=0;
  pFile = fopen (FileName,"r");
  if (pFile==0)
  {
     fclose(pFile);
     return -1; // problema al abrir el archivo
  }
  fclose(pFile);
  ifstream in(FileName);
  string linea;
  vector<string> v;
  string buffer;
  char* pEnd=0;
  int i,j=0,ContCol=0;
  getline(in,linea,'\n');
  for(i=1;!in.eof();i++)
  {
      getline(in,linea,'\n');
      stringstream aStream;
      aStream << linea;
      ContCol=0;
      while(!aStream.eof())
      {
         ContCol++;
         j++;
         buffer="";
         aStream >> buffer;
         v.push_back(buffer);
         if(ContCol==pos)
         {
           vect[i-1]=strtod(v[j-1].c_str(),&pEnd);
         }
      }
  }
  in.close();
  return 0;
}
// --------------------------------------------------------------------------------------------------------
void Simulation::Clone(Simulation* other)
{
 other->NumberScenario=NumberScenario;
 other->idModel=idModel;
for(int isim=0;isim<100;isim++)
{
  for(int i=0;i<365;i++)
  {
    other->tdm[isim][i]=tdm[isim][i];
    other->tdmw[isim][i]=tdmw[isim][i];
    other->tdmn[isim][i]=tdmn[isim][i];
    other->tdmf[isim][i]=tdmf[isim][i];

    other->dty[isim][i]=dty[isim][i];
    other->dtyw[isim][i]=dtyw[isim][i];
    other->dtyn[isim][i]=dtyn[isim][i];
    other->dtyf[isim][i]=dtyf[isim][i];

    other->fty[isim][i]=fty[isim][i];
    other->ftyw[isim][i]=ftyw[isim][i];
    other->ftyn[isim][i]=ftyn[isim][i];
    other->ftyf[isim][i]=ftyf[isim][i];

    other->cc[isim][i]=cc[isim][i];
    other->ccw[isim][i]=ccw[isim][i];
    other->ccn[isim][i]=ccn[isim][i];
    other->ccf[isim][i]=ccf[isim][i];
  }
}
for(int i=0;i<365;i++)
{
    other->Xtdm[i]=Xtdm[i];
    other->Xtdmw[i]=Xtdmw[i];
    other->Xtdmn[i]=Xtdmn[i];
    other->Xtdmf[i]=Xtdmf[i];

    other->Xdty[i]=Xdty[i];
    other->Xdtyw[i]=Xdtyw[i];
    other->Xdtyn[i]=Xdtyn[i];
    other->Xdtyf[i]=Xdtyf[i];

    other->Xfty[i]=Xfty[i];
    other->Xftyw[i]=Xftyw[i];
    other->Xftyn[i]=Xftyn[i];
    other->Xftyf[i]=Xftyf[i];

    other->Xcc[i]=Xcc[i];
    other->Xccw[i]=Xccw[i];
    other->Xccn[i]=Xccn[i];
    other->Xccf[i]=Xccf[i];
}

}
// --------------------------------------------------------------------------------------------------------
void Simulation::CalcularTT(double* tempMin,double* tempMax)
{
// --------------------------------------------------------------------------
//
//                             THERMAL TIME
//
// --------------------------------------------------------------------------
    int diassim=time->duration;
    int EmergencyDays=crop->plant->EDay;
    int ndays=diassim-EmergencyDays;
    double* tmin=new double[ndays];
    double* tmax=new double[ndays];
    for(int i=0;i<ndays;i++)
    {
      double borrar1=tempMin[i+EmergencyDays];
      double borrar2=tempMax[i+EmergencyDays];

      tmin[i]=tempMin[i+EmergencyDays];
      tmax[i]=tempMax[i+EmergencyDays];
    }

    double parameters1,parameters2,parameters3,parameters4;
    parameters1=0.0;
    parameters2=12.0;
    parameters3=24.0;
    parameters4=35.0;
    double b1 = 1.0/(parameters2 - parameters1);
    double a1 = -1.0 * b1 * parameters1;
    double b2 = 1.0/(parameters3 - parameters4);
    double a2 = -1.0 * b2 * parameters4;
    double minimo=GetMedian(tmin,ndays);
    double base = 0.0;
    if (minimo > 10.0) base = 2.0;
//    TT <- NULL
//    peso <- NULL
//    day <- NULL
    double Y0 = (tmin[0] + tmax[0])/2.0;
    double k = 1.0;
    if (Y0 < parameters2) {
        k = a1 + b1 * Y0 ;
    }
    if (Y0 > parameters3) {
        k = a2 + b2 * Y0;
    }
    if (Y0 < parameters1 || Y0 > parameters4) {
        k = 0;
    }
    double* peso=new double[ndays];
    double* TT=new double[ndays];
    int* day=new int[ndays];
    peso[0]= k;
    TT[0]  = peso[0] * (Y0 - base);
    day[0] = EmergencyDays;
    for(int i=1;i<ndays;i++)
    {
        Y0 = (tmin[i] + tmax[i])/2.0;
        k = 1.0;
        if (Y0 < parameters2) {
            k = a1 + b1 * Y0;
        }
        if (Y0 > parameters3) {
            k = a2 + b2 * Y0;
        }
        if (Y0 < parameters1 || Y0 > parameters4) {
            k = 0.0;
        }
        peso[i] = k;
        TT[i] = TT[i - 1] + peso[i] * (Y0 - base);
        day[i] = day[i - 1] + 1.0;
    }

  double* TTtemp=new double[diassim];
  int contTT=-1;
  for(int i=0;i<diassim;i++)
  {
    if(i<EmergencyDays)
    {
     TTtemp[i]=0.00001;
    }
    else
    {
      contTT++;
      TTtemp[i]=TT[contTT];
    }
  }
  climate->setTT(TTtemp,diassim);
  delete[] TTtemp;
    delete []peso;
    delete []day;
    delete []TT;
    delete []tmin;
    delete []tmax;
}
// --------------------------------------------------------------------------------------------------------
double Simulation::GetMedian(double* daArray, int iSize) {
    // Allocate an array of the same size and sort it.
    double* dpSorted = new double[iSize];
    for (int i = 0; i < iSize; ++i) {
        dpSorted[i] = daArray[i];
    }
    for (int i = iSize - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (dpSorted[j] > dpSorted[j+1]) {
                double dTemp = dpSorted[j];
                dpSorted[j] = dpSorted[j+1];
                dpSorted[j+1] = dTemp;
            }
        }
    }
    // Middle or average of middle values in the sorted array.
    double dMedian = 0.0;
    if ((iSize % 2) == 0) {
        dMedian = (dpSorted[iSize/2] + dpSorted[(iSize/2) - 1])/2.0;
    } else {
        dMedian = dpSorted[iSize/2];
    }
    delete [] dpSorted;
    return dMedian;
}
//---------------------------------------------------------------------------
void Simulation::LoadObservedInformation()
{
AnsiString nombre = AnsiString(obsFileName);
int posicion=nombre.Pos(".");
int longitud=nombre.Length();
int caract=longitud-posicion;
AnsiString ext=nombre.SubString(posicion+1,caract);
if(ext=="prn")
{
  RecNum=CountRegisters(obsFileName);
  GetColumnData(obsFileName , TitObsFY , Obs  );
  GetColumnData(obsFileName , TitObsCC , ObsCC  );
}
if(ext=="csv")
{
  RecNum=CountRegistersFromCSVFile(obsFileName);
  GetColumnDataFromCSVFile(obsFileName , TitObsFY , Obs  );
  GetColumnDataFromCSVFile(obsFileName , TitObsCC , ObsCC  );
}
}
//------------------------------------------------------------------------------
int Simulation::CountRegistersFromCSVFile(char* FileName)
{
  int cont=0;
  std::ifstream  data(FileName);
  int num;
  std::string line;
  std::getline(data,line); // la primera linea no debe contabilizarse ya que es cabecera
  int numelem=0;
  while(std::getline(data,line))
  {
    cont++;
  }
  data.close();
  return cont;
}
//------------------------------------------------------------------------------
int Simulation::CountRegisters(char* FileName)
{
  ifstream in(FileName);
  string linea;
  vector<string> v;
  string buffer;
  int i,j=0;
  getline(in,linea,'\n');
  string dato;
  bool esdigito;
  int cont=0;
  for(i=1;!in.eof();i++)
  {
      getline(in,linea,'\n');
      stringstream aStream;
      aStream << linea;
      while(!aStream.eof())
      {
         j++;
         buffer="";
         aStream >> buffer;
         v.push_back(buffer);
         dato=v[j-1].c_str();
         esdigito=false;
         esdigito=isdigit(dato[0]);
         if(esdigito)
         {
           cont++;
           break;
         }
      }
  }
  in.close();
  return cont;
}
//------------------------------------------------------------------------------
int Simulation::GetColumnDataFromCSVFile(char* FileName,char* FieldName,double* vect)
{
  int pos=DeterminePositionFromCSVFile(FileName,FieldName);
  int cont;
  std::ifstream  data(FileName);
  int num;
  std::string line;
  std::getline(data,line); // la primera linea no debe contabilizarse ya que es cabecera
  int numelem=0;
  while(std::getline(data,line))
  {
    std::stringstream  lineStream(line);
    std::string        cell;
    numelem++;
    int cont=0;
    while(std::getline(lineStream,cell,','))
    {
      cont++;
      // Aqui obtenemos una celda
      num=strlen(cell.c_str());
      char* dato = new char[ num + 1 ];
      strcpy(dato,cell.c_str());
      if(cont==pos)
      {
        vect[numelem-1]=atof(dato);
      }
    }
  }
  data.close();
  return numelem;
}
//------------------------------------------------------------------------------
int Simulation::DeterminePositionFromCSVFile(char* archivo,char* campo)
{
std::ifstream  data(archivo);
int cont=0;
int num;
std::string line;
std::getline(data,line);
std::stringstream  lineStream(line);
std::string        cell;
int tam=strlen(campo);
int OrdenCampo=0;
  bool encontro=false;

while(std::getline(lineStream,cell,','))
{
  cont++;
  // Aqui obtenemos una celda
  num=strlen(cell.c_str());
  char* dato = new char[ num + 1 ];
  strcpy(dato,cell.c_str());
  for(int j=0;j<tam;j++)
  {
    if(cell[j]!=campo[j])
    {
      encontro=false;
      break;
    }
    encontro=true;
  }
  OrdenCampo++;
  if(encontro) break;
}
if(!encontro) OrdenCampo=0;
data.close();
return OrdenCampo;
}
//------------------------------------------------------------------------------
void Simulation::CleanVectorObserved()
{
  for(int i=0;i<365;i++)
  {
    Obs[i]=0.0;
    ObsCC[i]=0.0;
  }
}
//------------------------------------------------------------------------------
int Simulation::simulate()
{
Just_simulate3();
CalculatesAfterSimulation();
return 0;
}
//------------------------------------------------------------------------------
int Simulation::Just_simulate3()
{

randomize();
for(int isim=0;isim<time->repetitions;isim++)
{ // begin for isim
double MinTemp[365];
double MaxTemp[365];
double Rainfall[365];
double Radiation[365];
double PET[365];
double Irrigation[365];
double TT[365];
double sunshine[365];
// locate the record with start date
  int reg=-1;
  for(int i=0;i<climate->RecNum;i++)
  {
    if(climate->Day[i]==time->DayStart && climate->Month[i]==time->MonthStart && climate->Year[i]==time->YearStart)
    {
      reg=i; // get record
      break;
    }
  }
  if(reg==-1)
  {
    return 2; // start date does not exist
  }
//
  int newItem=-1;
//
  int numdias=time->duration;
  double* datTmin=new double[numdias];
  double* datTmax=new double[numdias];
  for(int i=reg;i<climate->RecNum;i++)
  {
      newItem++;
      if(newItem<365)
      {
        if(newItem<time->duration)
        {
          datTmin[newItem]=climate->MinTemp[i];
          datTmax[newItem]=climate->MaxTemp[i];
        }
        MinTemp[newItem]= climate->MinTemp[i];
        MaxTemp[newItem]= climate->MaxTemp[i];
        Rainfall[newItem]= climate->Precipit[i];
        Radiation[newItem]= climate->Radiation[i];
        PET[newItem]= climate->ET[i];
        Irrigation[newItem]= climate->Irri[i];
        sunshine[newItem]= climate->Sunshine[i];
      }
  }
  CalcularTT(datTmin,datTmax);

  delete []datTmin;
  delete []datTmax;

  for(int i=0;i<numdias;i++)
  {
      TT[i]   = climate->TT[i];
  }

//  ASIGNACION DE INPUTS

  int EDay=crop->plant->EDay;
  double v=crop->plant->v;
  double wmax=crop->plant->fcl;
  double N=crop->plant->N;
  double te=crop->plant->R0;
  double tm=crop->plant->F0;
  double RUE=crop->plant->LUE;
  double Tu_0=crop->tuber->A;
  double DMcont=crop->tuber->DMCont;
  double A_0=crop->tuber->M;
  double b=crop->tuber->b;
  double Tcr=crop->tuber->Tcr;
  double Tld=crop->tuber->Tld;
  double Trg=crop->tuber->Trg;
  double RUE_0=crop->tuber->A;

  int Type=nitrogen->SelectedOM;
  int Fert=nitrogen->SelectedFert;
  double amount=nitrogen->AmountFert;
  double FOMi=nitrogen->FOMi;
  int dd=1;
  int mm=1;
  double ISM=soil->Moisture;
  double OM=soil->OM;
  double Soil_depth=soil->SoilDepth;
  int Soil_texture=soil->SelectedSoil;
  double pH=soil->Ph;
  double Dl=soil->MaxDepth;
  
//  int Thermal_conditions=climate->ThermalCond;

//  declaracion de variables  (Posibles constantes)
double DMINR;  // humic frax decay rate
double DMOD;  // (0-1) factor decrease to rate of mineralix special cases (volcanic soil: less than 1), virgin soils (more than 1)
double _C;  //  % C org matt added Asumiendo como en la ecuacion que CN es 60
double FOCi;
double UREA;
double NUREAi;
double NH4_fert;
double NH4am;
double NO3fert;
double NO3am;
int PDate;
double OC;
double phn;
double AK;
double AKU;
double Area;
double D;
double Soil_Vol;
double RUEs;
double RUEs_0;
double GC0;
double GC250;
double hydric1;
double hydric2;
double hydric3;
double hydric4;
double hydric5;
double hydric6;
double hydric7;

double k;
double c;
double cl;
double CL;
double FC;
double WP;
double fc;
double wp;
double BD;
double Po;
double SWeight;
double OMw;
double NHUMi;
double CHUMi;

double OM_CN1;
double OM_CN2;

double CN;

double _N;
// declaracion de variables

double HUM;
double NHUM;
double CS;
double NO3POOL;
double NUREA;
double FOM;
double FPOOLCE;
double FPOOLLI;
double FPOOLCA;
double RHMINacum;
double Hum_decomp__acum;
double NCE_acum;
double NLI_acum;
double acumGRNOM;
double NCA_acum;
double acumGRCOM;
double comp2;
double cd108;
double N_lib_acum;
double NH4POOL;
double Tac;
double rnd;
double rdm;
double TDMw;
double TDM;
double TDMf;
double c1;
double c2;
double C3;
double REB;
double TDMn;

double reba;
double fccf;
double ay2;
double ay1;
double Npc;
double Npot;
double verificar_densidad;
double canopy;
double t50;
double d;
double canopy1;
double DTY1;
double DTY2;
double Part;
double DTYw;
double FTYw;
double DTY;
double FTY;
double DTYf;
double FTYf;
double DTYn;
double FTYn;
double NH4ppm;
double var1;
double FONi;
double NO3ppm;
double Nac;
double NacNpot;
double Ns;
double TOTN;
double CNR;
double CNRF;
double s;
double WFD;
double MF;
double SWF;
double MFU;
int day;
double Irri;
double ETo;
double Tmax;
double Tmin;
double tt;
double Tav;
double W;
double Tl;
double Stemp;
double TF;
double min;
double min1;
double RHMIN;
double flow109;
double flow105;
double flow102;
double flow103;
double MFTF;
double G1CA;
double CA;
double flow6;
double G1CE;
double CE;
double flow1;
double G1LI;
double LI;
double flow2;
double GRCOM;
double grcom;
double flow108;
double TFF;
double TFU;
double UHYDR;
double flow1_0;
double flow2_0;
double NH4u;
double var13;
double Tmin_0;
double CCRF;
double Reb;
double CCL;
double Rain;
double PAR;
int month;
int PDay;
int DAE;
double Tb;
double Tbasal_completar_mediana;
int Tmin10;
int fTo;
double iTo;
double Tu;
double Te;
double CC;
double Eo;
double To;
double T;
double S;
double Ws;
double RUEw;
double dW;
double CC_0;
double CCf;
double dTDM_0;
double CCn;
double dTDM_1;

double delayCCf;
double fay1;
double delayCC;
double dCC;
double fay2;

double CWs;
double FON;

double REST;
double RNACp;
double RNAC;
double rnac;
double GRNOMCE;
double flow3;
double GRNOMLI;
double flow4;
double GRNOMCA;
double GRNOM;
double flow110;
double flow101;
double grnom;
double flow107;
double NNOM;
double NH4o;
double var19;
double SNH4;
double SANC;
double ELNC;
double RP2;
double RP22;
double A;
double bb;
double RNTRF;
double dNO3;
double flow2_1;
double flow205;
double flow4_0;
double flow102_0;
double flow7;
double CCw;
double dTDM;
// Photoperiod and temperature effect on TIO
double Tb_0;
double To_0;
double Tu_1;
double a;
double w;
double Pc;
double Tu_cTII;
double cTII;
double Part_cTII;
double HI_cTII;
double Tindex;
double Pindex;
double TII;
double tt_fixed;
bool bsearch_tt;

// asignaciones realizadas antes de incio de la simulacion
// -2>=phase
DMINR = 8.3*pow(10,-5);
DMOD = 1;
_C = 60;
FOCi = FOMi*_C/100.0;
UREA = (Fert==1?amount:0);
NUREAi = UREA;
NH4_fert = (Fert==2?0.225:(Fert==3?0.15:0));
NH4am = NH4_fert*amount;
NO3fert = (Fert==2?0.775:0);
NO3am = NO3fert*amount;
Tbasal_completar_mediana = 2;
fTo = 24;
Tb = 0;
iTo = 12;
Tu = 35;
PDate = (mm==1?dd:(mm==2?dd+31:(mm==3?dd+59:(mm==4?dd+90:(mm==5?dd+120:(mm==6?dd+151:(mm==7?dd+181:(mm==8?dd+212:(mm==9?dd+243:(mm==10?dd+273:(mm==11?dd+304:dd+334)))))))))));
OC = 0.58*OM;
phn = pH*0.05;
AK = -1.12+1.31*OC+0.203*pH-0.155*OC*pH;
AKU = (AK<0.25?0.25:AK);
Area = 10000;
D = Soil_depth*100;
Soil_Vol = Area*Soil_depth;
RUEs_0 = RUEs;
verificar_densidad = 4.17;
GC0 = 0.6;
GC250 = 1;
Tb_0 = 4;
To_0 = 15;
Tu_1 = 28;
a = (double)(log(2))/log((double)(Tu_1-Tb_0)/(To_0-Tb_0));
w = 0.2;
Pc = 18;
//  Tu_cTII = 0.9;
tt_fixed=0.0;
bsearch_tt=true;

switch (Soil_texture)
{
    case 1:
      hydric1=1.24;
      hydric2=54;
      hydric3=50;
      hydric4=32;
      hydric5=15;
      hydric6=10.9;
      hydric7=3845.3;
      break;
    case 2:
      hydric1=1.30;
      hydric2=52;
      hydric3=44;
      hydric4=23;
      hydric5=120;
      hydric6=6.4;
      hydric7=3862.5;
      break;
    case 3:
      hydric1=1.36;
      hydric2=55;
      hydric3=54;
      hydric4=39;
      hydric5=2;
      hydric6=11;
      hydric7=4567.7;
      break;
    case 4:
      hydric1=1.37;
      hydric2=43;
      hydric3=33;
      hydric4=9;
      hydric5=50;
      hydric6=1.4;
      hydric7=3404.6;
      break;
    case 5:
      hydric1=1.37;
      hydric2=46;
      hydric3=33;
      hydric4=13;
      hydric5=150;
      hydric6=1.4;
      hydric7=3404.6;
      break;
    case 6:
      hydric1=1.40;
      hydric2=50;
      hydric3=39;
      hydric4=23;
      hydric5=100;
      hydric6=7;
      hydric7=3863.0;
      break;
    case 7:
      hydric1=1.42;
      hydric2=36;
      hydric3=13;
      hydric4=6;
      hydric5=1500;
      hydric6=1.8;
      hydric7=2390.6;
      break;
    case 8:
      hydric1=1.44;
      hydric2=46;
      hydric3=31;
      hydric4=15;
      hydric5=250;
      hydric6=2.8;
      hydric7=3533.1;
      break;
    case 9:
      hydric1=1.44;
      hydric2=38;
      hydric3=16;
      hydric4=8;
      hydric5=800;
      hydric6=1.8;
      hydric7=2627.0;
      break;
    case 10:
      hydric1=1.46;
      hydric2=41;
      hydric3=22;
      hydric4=10;
      hydric5=500;
      hydric6=1.7;
      hydric7=3052.8;
      break;
    case 11:
      hydric1=1.48;
      hydric2=50;
      hydric3=39;
      hydric4=27;
      hydric5=75;
      hydric6=10.6;
      hydric7=4172.3;
      break;
    default:
      hydric1=1.51;
      hydric2=47;
      hydric3=32;
      hydric4=20;
      hydric5=125;
      hydric6=5.7;
      hydric7=3847.3;
}
k = hydric5;
c = hydric6;
cl = hydric3-0.5*(hydric3-hydric4);
CL = (double)(Soil_Vol*cl)/1000;
FC = (double)(Soil_Vol*hydric3)/1000;
WP = (double)(Soil_Vol*hydric4)/1000;
fc = hydric3;
wp = hydric4;
BD = hydric1*1000;
Po = (double)(100*(2.65-(double)(BD)/1000))/2.65;
SWeight = (double)(Soil_Vol*BD)/1000;
OMw = (double)(OM)/100*SWeight;
NHUMi = (double)(OMw*1000)/10;
CHUMi = OMw*1000;
switch (Type)
{
    case 1:
      OM_CN1=10;
      OM_CN2=1;
      break;
    case 2:
      OM_CN1=18;
      OM_CN2=1;
      break;
    case 3:
      OM_CN1=19;
      OM_CN2=1;
      break;
    case 4:
      OM_CN1=20;
      OM_CN2=1;
      break;
    case 5:
      OM_CN1=60;
      OM_CN2=1;
      break;
    case 6:
      OM_CN1=80;
      OM_CN2=1;
      break;
    case 7:
      OM_CN1=90;
      OM_CN2=1;
      break;
    case 8:
      OM_CN1=134;
      OM_CN2=1;
      break;
    default:
      OM_CN1=170;
      OM_CN2=1;
}
CN = OM_CN1;
_N = (double)(_C)/CN;
// FIN de -2>=phase

//  0 >= phase

	HUM = CHUMi;
	NHUM = NHUMi;
	CS = ISM;
	NO3POOL = NO3am;
	NUREA = NUREAi;
	FOM = FOMi;
	FPOOLCE = FOMi*0.7;
	FPOOLLI = FOMi*0.1;
	FPOOLCA = FOMi*0.2;
	RHMINacum = 0;
	Hum_decomp__acum = 0;
	NCE_acum = 0;
	NLI_acum = 0;
	acumGRNOM = 0;
	NCA_acum = 0;
	acumGRCOM = 0;
	comp2 = 0;
	cd108 = 0;
	N_lib_acum = 0;
	NH4POOL = 0;
	Tac = 1.0E-05;
	rnd=random(5001);
	rnd=rnd/5000;
	rdm = (double)(log((double)(1+rnd)/(1-rnd)))/1.82; // log: es logaritmo natural
	TDMw = 0;
	TDM = 1.0E-37;
	TDMf = 0;
	c1 = 0;
	c2 = 0;
	C3 = 0.00368;
	REB = 1;
	TDMn = 0;
	cTII = 0;

//  FIN de 0 >= phase

//  INICIO DE LAS ITERACIONES
day=PDate-1;
PDay=-1;
bool error=false;
t50 = bisection(te, te + 1000,wmax,te,tm,&error);
d=t50-te;
  for(int i=0;i<time->duration;i++)
  { // begin for i
        day++;
        if(day==366) day=1;
    /* modelo matematico  */
// 1>=phase
	reba = REB;
	fccf = C3;
	ay2 = c2;
	ay1 = c1;
	Npc = 1.35+4.05*exp(-0.26*TDM);
	Npot = (double)(Npc*TDM)/100;
	canopy = wmax*exp(-((double)(tm)/(Tac*verificar_densidad)))*(1+(double)(te-Tac)/(te-tm))*pow((double)(Tac)/te,(double)(te)/(te-tm));
	canopy1 = rdm*v*canopy+canopy;
	Part = A_0*exp(-(exp((double)(-(Tac-Tu_0))/b)));
	DTYw = TDMw*Part;
	FTYw = (double)(DTYw)/DMcont;
	DTY1 = TDM*Part;
	DTYf = TDMf*Part;
	FTYf = (double)(DTYf)/DMcont;
	DTYn = TDMn*Part;
	FTYn = (double)(DTYn)/DMcont;

        if(cTII>20.0 && bsearch_tt)
        {
          tt_fixed=tt;
          bsearch_tt=false;
        }
        else
        {
          tt_fixed=0;
        }
        if(bsearch_tt)
        {
          Tu_cTII=1.0;
        }
        else
        {
          Tu_cTII=(tt_fixed+b)/Tu_0;
        }
//        Tu_cTII=
	Part_cTII = A_0*exp(-(exp((double)(-(Tac-Tu_0*Tu_cTII))/b)));
	HI_cTII = (cTII<=20?0:Part_cTII);
	DTY2 = TDM*HI_cTII;
	DTY = (Tu_cTII<=1?DTY1:DTY2);
	FTY = (double)(DTY)/DMcont;
	NH4ppm = (double)(NH4POOL)/SWeight*1000;
	var1 = (FOM<5?0:FOM);
	FONi = (double)(FOM*_N)/100;
	NO3ppm = (double)(NO3POOL)/SWeight*1000;
	Nac = (double)(NO3POOL)/1000;
	NacNpot = (double)(Nac)/Npot;
	Ns = (NacNpot>1?1:(GC250-GC0)*NacNpot+GC0);
	TOTN = (NO3POOL>0?NO3POOL:0);
	CNR = (double)(FOCi)/(TOTN+FONi);
	CNRF = exp((double)(-0.963*(CNR-25))/25);
	s = CS;
	WFD = 1-(double)(s-FC)/(Po-FC);
	MF = (s>FC?(double)(s-FC)/(Po-FC):(s<=FC&&s>WP?1-0.5*((double)(s-WP)/(FC-WP)):0));
	SWF = MF+0.2;
	MFU = (SWF>1?1:(SWF<0?0:SWF));
	//day = fmod(glob_element(ts, 1)+PDate-1,365)+1;  // OBSERVACION : averiguar su funcion y traducir
	Irri = Irrigation[i];  // OBSERVACION : verificar que los datos de clima esten cargado la informacion adecuada
	ETo = PET[i];
	Tmax = MaxTemp[i];
	Tmin = MinTemp[i];
	Tmin10 = (Tmin<10.0?0.0:1.0);
	tt = TT[i];
	Tav = (double)(Tmax+Tmin)/2;
	Tac = tt;
	W = (Tav>=Tb&&Tav<=iTo?Tav*((double)(1)/(iTo-Tb)):(Tav>iTo&&Tav<fTo?1:(Tav>=fTo&&Tav<=Tu?(double)(Tav*1)/(fTo-Tu)-(double)(1)/(fTo-Tu)*35:0)));
	Tl = 1.25*Tav;
	Stemp = (double)(2)/3.1416*(Tav-Tl)*exp((double)(-((double)(k)/(BD*c))*pow(3.1416,2)*1.0E+10)/pow(Dl,2))*sin((double)(3.1416*D)/Dl)+Tav+(double)(Tl-Tav)/Dl*D;
	TF = (Stemp<5?0:(Stemp>35?1:(double)(Stemp-5)/30));
	min = std::min(WFD,TF);
	min1 = std::min(min,phn);
	RHMIN = NHUM*DMINR*TF*MF*DMOD;
	flow109 = RHMIN;
	flow105 = RHMIN;
	flow102 = RHMIN*10;
	flow103 = flow102;
	MFTF = MF*TF;
	G1CA = CNRF*MFTF*0.8;
	CA = G1CA*FPOOLCA;
	flow6 = CA;
	G1CE = CNRF*MFTF*0.05;
	CE = G1CE*FPOOLCE;
	flow1 = CE;
	G1LI = CNRF*MFTF*0.0095;
	LI = G1LI*FPOOLLI;
	flow2 = LI;
	GRCOM = CA+CE+LI;
	grcom = GRCOM;
	flow108 = GRCOM;
	TFF = (double)(Stemp)/40+0.2;
	TFU = (TFF<0?0:TFF);
	UHYDR = AKU*std::min(MFU,TFU)*NUREA*0.01;
	flow1_0 = UHYDR;
	flow2_0 = flow1_0;
	NH4u = flow1_0;
	var13 = (double)(AKU*std::min(MFU,TFU)*NUREAi)/100;
	Tindex = (Tav<Tb_0?0:(Tav>Tu_1?0:(double)(2*pow(Tav-Tb_0,a)*pow(To_0-Tb_0,a)-pow(Tav-Tb_0,2*a))/pow(To_0-Tb_0,2*a)));
	Tmin_0 = Tmin;
	CCRF = (Tmin_0<Tcr?(Tmin_0>Trg?(double)(Trg-Tmin_0)/(Trg-Tcr):0):1);
	Reb = (CCRF<REB?CCRF:REB);
	CCL = (Tmin_0<Tld?1:(Tmin_0<Tcr?1-(double)(Tld-Tmin_0)/(Tld-Tcr):0));
	Rain = Rainfall[i];
	PAR = Radiation[i]*0.5;
	N = sunshine[i];
	Pindex = (N>Pc?exp(-(w*(N-Pc))):1);
	TII = Tindex*Pindex;
	month = (day<=31?1:(day>31&&day<=59?2:(day>59&&day<=90?3:(day>90&&day<=120?4:(day>120&&day<=151?5:(day>151&&day<=181?6:(day>181&&day<=212?7:(day>212&&day<=243?8:(day>243&&day<=273?9:(day>273&&day<=304?10:(day>304&&day<=334?11:12)))))))))));
	PDay++;
	DAE = (PDay>=EDay?PDay-EDay:0);
	Te = (DAE<=0?0:(DAE>0&&Tav<Tb?0:(Tav>=Tb&&Tav<=Tu?(Tav-Tbasal_completar_mediana)*W:0)));
	CC = (DAE<=0?0:(canopy1>0?canopy1:pow(10,-6)));
	Eo = wmax*ETo*exp(-0.7*4*CC);
	To = (CC==0?0.0001:(double)(1.1*ETo*(1-exp(-0.7*4*CC)))/(1-exp(-0.7*4*wmax)));
	T = (s>CL?To:(s<WP?0:(double)(To*(WP-s))/(WP-CL)));
	S = (Rain+Irri+CS-Eo-T<=0.9*WP?0.9*WP:(Rain+Irri+CS-Eo-T>=FC?FC:Rain+Irri+CS-Eo-T));
	Ws = (1-(double)(T)/To-0.8<0?0:1-(double)(T)/To-0.8);
        if(tt<t50-0*d)
        {
           RUEs = RUE;
        }
        else
        {
           RUEs=RUE*(1-(tt-t50+0*d)/(2*d));
        }

	RUEw = ((double)(RUEs*(0.8-Ws))/0.8<0?0:(double)(RUEs*(0.8-Ws))/0.8);
	dW = (double)(RUE*CC*PAR)/100;
	CC_0 = CC;
	CCf = (CC_0+ay2-ay1>0?CC_0+ay2-ay1:0);
	dTDM_0 = (double)(CCf*PAR*RUEs_0)/100;
	CCn = CC*Ns;
	dTDM_1 = (double)(CCn*PAR*RUE_0)/100;
	
	delayCCf = CCf;
	fay1 = (CCL>0?delayCCf*CCL:0);
	delayCC = CC;
	dCC = CC_0-delayCC;
	fay2 = (dCC>0?dCC*REB:(double)(dCC*1)/REB);

// FIN de 1>=phase

// 0>=phase
        if(i==0)
        {
          CWs = Ws;
          FON = FONi;
        }
// FIN de 0>=phase

// 1>=phase
        REST = (var1>0?GRCOM*(0.02-(double)(FON)/var1):0);
        RNACp = std::min(REST,TOTN);
        RNAC = (RNACp<0?0:RNACp);
        rnac = RNAC;
        GRNOMCE = (FOM>=5?(double)(CE*FON)/FOM:0);
        flow3 = GRNOMCE;
        GRNOMLI = (FOM>=5?(double)(LI*FON)/FOM:0);
        flow4 = GRNOMLI;
        GRNOMCA = (FOM>=5?(double)(CA*FON)/FOM:0);
        GRNOM = GRNOMCA+GRNOMCE+GRNOMLI;
        flow110 = GRNOM*0.2;
        flow101 = (double)(GRNOM*0.2)/0.04;
        grnom = GRNOM;
        flow107 = GRNOM;
        NNOM = 0.8*GRNOM+RHMIN-RNAC;
        NH4o = NNOM;
        var19 = NH4o+NH4u+NH4am;
        SNH4 = var19;
        SANC = 1-exp(-0.01363*SNH4);
        ELNC = std::min(min,SANC);
        RP2 = exp(2.302*ELNC);
        RP22 = (RP2<0.05?0.05:(RP2>1?1:RP2));
        A = std::min(RP22,min1);
        bb = (double)(A*40*NH4ppm)/(NH4ppm+90);
        RNTRF = (bb>0.8?0.8:bb);
        dNO3 = RNTRF;
        flow2_1 = RNTRF;
        flow205 = RNTRF;
        flow4_0 = var19;
        flow102_0 = NNOM;
        flow7 = GRNOMCA;
        CCw = (CWs>75?0:(double)(75-CWs)/75*CC);
        dTDM = (double)(RUEw*CCw*PAR)/100;

// FIN de 1>=phase

    /*    SALIDAS    */
    tdm[isim][i]=TDM;
    tdmw[isim][i]=TDMw;
    tdmn[isim][i]=TDMn;
    tdmf[isim][i]=TDMf;

    dty[isim][i]=DTY;
    dtyw[isim][i]=DTYw;
    dtyn[isim][i]=DTYn;
    dtyf[isim][i]=DTYf;

    fty[isim][i]=FTY;
    ftyw[isim][i]=FTYw;
    ftyn[isim][i]=FTYn;
    ftyf[isim][i]=FTYf;

    cc[isim][i]=CC;
    ccw[isim][i]=CCw;
    ccn[isim][i]=CCn;
    ccf[isim][i]=CCf;

    /* fin de modelo matematico */
//  updatemodel(0, 1)    1>=phase
        NO3POOL = NO3POOL+dNO3;
        NHUM = NHUM+flow110-flow109;
        RHMINacum = RHMINacum+flow105;
        HUM = HUM+flow101-flow102;
        Hum_decomp__acum = Hum_decomp__acum+flow103;
        FOM = FOM-grcom;
        FON = FON+rnac-grnom;
        FPOOLCE = FPOOLCE-flow1;
        FPOOLLI = FPOOLLI-flow2;
        NCE_acum = NCE_acum+flow3;
        NLI_acum = NLI_acum+flow4;
        FPOOLCA = FPOOLCA-flow6;
        acumGRNOM = acumGRNOM+flow107;
        NCA_acum = NCA_acum+flow7;
        acumGRCOM = acumGRCOM+flow108;
        NUREA = NUREA-flow1_0;
        comp2 = comp2+flow2_0;
        cd108 = cd108+flow205;
        N_lib_acum = N_lib_acum+flow102_0;
        NH4POOL = NH4POOL+flow4_0-flow2_1;
        //Thermal_timepointer->Tac = Thermal_timepointer->Tac+stage_incr(&(Thermal_timepointer->anon_19), 1, Thermal_timepointer->Te);
        //Thermal_timepointer->Tac = Weatherpointer->tt;
        CS = CS+S-s;
        CWs = CWs+Ws;
        TDMw = TDMw+dTDM;
        TDM = TDM+dW;
        TDMf = TDMf+dTDM_0;
        c1 = c1+fay1-ay1;
        c2 = c2+fay2-ay2;
        C3 = C3+CCf-fccf;
        REB = REB+Reb-reba;
        TDMn = TDMn+dTDM_1;
        cTII = cTII+TII;
//  FIN de updatemodel(0, 1)    1>=phase
  } // end for i
      switch (idModel)  // 1: Potential Growth , 2:Drought , 3:Nitrogen Stress , 4:Frost
      {
        case 1 : ult_fty[isim]=fty[isim][time->duration-1];
                 break;
        case 2 : ult_fty[isim]=ftyw[isim][time->duration-1];
                 ult_fty2[isim]=fty[isim][time->duration-1];
                 break;
        case 3 : ult_fty[isim]=ftyn[isim][time->duration-1];
                 break;
        case 4 : ult_fty[isim]=ftyf[isim][time->duration-1];
      }

} // end for isim
}
//------------------------------------------------------------------------------
double Simulation::Fx50(double x,double Wmax, double te,double tm,bool* error)
{
    if(te==0.0) *error=true;
    if(te-tm==0.0) *error=true;
    if((x/te)==0 && (te/(te - tm))<=0.0) *error=true;
    if(*error) return 0.0;

    return 0.5 - Wmax * (1 + (te - x)/(te - tm)) * pow((x/te),(te/(te - tm)));
}
//---------------------------------------------------------------------------
double Simulation::bisection(double a, double b,double Wmax,double te, double tm,bool* error)
{
    double x = b;
    double d = (a + b)/2.0;
    double valor1;
    double valor2;
    while (fabs(x-d)/fabs(x) > 0.000000000001)
    {
        if (Fx50(x,Wmax,te,tm,error) == 0) break;
        valor1=Fx50(x,Wmax,te,tm,error);
        if(*error) break;
        valor2=Fx50(a,Wmax,te,tm,error);
        if(*error) break;
        if (valor1 * valor2 < 0)
            b = x;
        else {
            a = x;
        }
        d = x;
        x = (a + b)/2.0;
    }
    return x;
}
#endif

