//---------------------------------------------------------------------------
#include <vcl.h>
#include <io.h>
#include <math.h>
#include<cmath>
#pragma hdrstop
struct myData
{
   double x;
   double y;
};

#include "UCalcParameter.h"
#include "UCampo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmCalcParameter *frmCalcParameter;
//---------------------------------------------------------------------------
__fastcall TfrmCalcParameter::TfrmCalcParameter(TComponent* Owner,ClimateFile *_cond)
        : TForm(Owner)
{
Initialize();
cond=_cond;
CopyValuesToCondTemp();
}
//---------------------------------------------------------------------------
__fastcall TfrmCalcParameter::TfrmCalcParameter(TComponent* Owner)
        : TForm(Owner)
{
Initialize();
cond=new ClimateFile(15000);
GetDemo();
}
//---------------------------------------------------------------------------
void TfrmCalcParameter::Initialize()
{
  condTemp=new ClimateFile(15000);
  sgClimate->Cells[0][1]="Day";
  sgClimate->Cells[1][0]="Minimun Temp";
  sgClimate->Cells[2][0]="Maximun Temp";
  sgClimate->Cells[3][0]="Radiation";
  sgClimate->Cells[1][1]="oC";
  sgClimate->Cells[2][1]="oC";
  sgClimate->Cells[3][1]="MJ/m2";
  sgClimate->RowHeights[0]=18;
  sgClimate->RowHeights[1]=18;
  sgClimate->ColWidths[0]=30;
  sgClimate->ColWidths[1]=80;
  sgClimate->ColWidths[2]=80;
  sgClimate->ColWidths[3]=50;
}
//---------------------------------------------------------------------------
void TfrmCalcParameter::EnterInformation(ClimateFile *_cond)
{
cond=_cond;
CopyValuesToCondTemp();
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParameter::FormShow(TObject *Sender)
{
  int cant=AnsiString(cond->FileName).Length();
  if (cant==0)
  {
  }
  else
  {
    int existe=access(cond->FileName, 0);
    if(existe==-1) // el archivo no existe
    {
      Application->MessageBox("The specified file does not exist!!!","¡Warning!",MB_OK);
      return;
    }
    else
    {
      FileData *util=new FileData();
      AnsiString nombre = AnsiString(condTemp->FileName);
      int posicion=nombre.Pos(".");
      int longitud=nombre.Length();
      int caract=longitud-posicion;
      AnsiString ext=nombre.SubString(posicion+1,caract);
      if(ext=="prn") num=util->GetFieldsName(List,condTemp->FileName);
      if(ext=="csv") num=util->GetFieldsNameFromCSVFile(List,condTemp->FileName);
      delete util;
    }
  }
  PutValuesOnForm();
}
//---------------------------------------------------------------------------
void TfrmCalcParameter::CopyValuesToCondTemp()
{
   strcpy(condTemp->FileName,cond->FileName);
   strcpy(condTemp->TitTMin,cond->TitTMin);
   strcpy(condTemp->TitTMax,cond->TitTMax);
   strcpy(condTemp->TitPrec,cond->TitPrec);
   strcpy(condTemp->TitRad,cond->TitRad);
   strcpy(condTemp->TitET,cond->TitET);
   strcpy(condTemp->TitIrri,cond->TitIrri);
   strcpy(condTemp->TitSoilTemp,cond->TitSoilTemp);
   strcpy(condTemp->TitDay,cond->TitDay);
   strcpy(condTemp->TitMonth,cond->TitMonth);
   strcpy(condTemp->TitYear,cond->TitYear);
   strcpy(condTemp->TitSunshine,cond->TitSunshine);
   condTemp->RecNum=cond->RecNum;
   for(int i=1;i<=condTemp->RecNum;i++)
   {
     condTemp->MinTemp[i-1]   = cond->MinTemp[i-1];
     condTemp->MaxTemp[i-1]   = cond->MaxTemp[i-1];
     condTemp->Precipit[i-1]   = cond->Precipit[i-1];
     condTemp->Radiation[i-1]   = cond->Radiation[i-1];
     condTemp->ET[i-1]   = cond->ET[i-1];
     condTemp->Irri[i-1]   = cond->Irri[i-1];
     condTemp->SoilTemp[i-1]   = cond->SoilTemp[i-1];
     condTemp->Sunshine[i-1]   = cond->Sunshine[i-1];
     condTemp->Day[i-1]   = cond->Day[i-1];
     condTemp->Month[i-1]   = cond->Month[i-1];
     condTemp->Year[i-1]   = cond->Year[i-1];
   }
}
//---------------------------------------------------------------------------
void TfrmCalcParameter::PutValuesOnForm()
{
   edPathFile->Text=condTemp->FileName;
   edMinTemp->Text=condTemp->TitTMin;
   edMaxTemp->Text=condTemp->TitTMax;
   edRad->Text=condTemp->TitRad;


   if(condTemp->RecNum==0)
   {
     sgClimate->RowCount=3;
   }
   else
   {
     sgClimate->RowCount=condTemp->RecNum+2;
   }
   for(int i=1;i<=condTemp->RecNum;i++)
   {
     sgClimate->RowHeights[i+1] = 18;
     sgClimate->Cells[0][i+1]   = i;
     sgClimate->Cells[1][i+1]   = condTemp->MinTemp[i-1];
     sgClimate->Cells[2][i+1]   = condTemp->MaxTemp[i-1];
     sgClimate->Cells[3][i+1]   = condTemp->Radiation[i-1];
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParameter::cmdCancelClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParameter::cmdApplyClick(TObject *Sender)
{
  bool exitoso=false;
  exitoso=Validate();
  if(exitoso)
  {
    SaveData();
    Close();
  }
}
//---------------------------------------------------------------------------
bool TfrmCalcParameter::Validate()
{
  TEdit *casilla=new TEdit(this);
  int cod=0; //0 : indica que no hay errores
  casilla = FindDataError(&cod);
  if(cod!=0)
  {
    ShowMessageError(cod);
    casilla->SetFocus();
    return false;
  }
  else
  {
    return true;
  }
}
//---------------------------------------------------------------------------
TEdit* TfrmCalcParameter::FindDataError(int* _cod)
{
//  int datoi;
//  try
//  {
//    datoi=edInput1->Text.ToInt();
//  }
//  catch(...)
//  {
//    *_cod=1; // 1: No es un valor entero
//    return edInput1;
//  }
//  double datod=0.0;
//  try
//  {
//    datod=edInput2->Text.ToDouble();
//  }
//  catch(...)
//  {
//    *_cod=2; // 2: No es un valor real
//    return edInput2;
//  }
//  try
//  {
//    datod=edInput3->Text.ToDouble();
//  }
//  catch(...)
//  {
//    *_cod=2; // 2: No es un valor real
//    return edInput3;
//  }
  return edPathFile;
}
//---------------------------------------------------------------------------
void TfrmCalcParameter::ShowMessageError(int _cod)
{
  if(_cod==1)
  {
    Application->MessageBox("The value should be an integer!", "Warning!", MB_OK);
  }
  if(_cod==2)
  {
    Application->MessageBox("The value should be a real!", "Warning!", MB_OK);
  }
}
//---------------------------------------------------------------------------
void TfrmCalcParameter::SaveData()
{
   strcpy( cond->FileName,condTemp->FileName);
   strcpy( cond->TitTMin,condTemp->TitTMin);
   strcpy( cond->TitTMax,condTemp->TitTMax);
   strcpy( cond->TitPrec,condTemp->TitPrec);
   strcpy( cond->TitRad,condTemp->TitRad);
   strcpy( cond->TitET,condTemp->TitET);
   strcpy( cond->TitIrri,condTemp->TitIrri);
   strcpy( cond->TitSoilTemp,condTemp->TitSoilTemp);
   strcpy( cond->TitDay,condTemp->TitDay);
   strcpy( cond->TitMonth,condTemp->TitMonth);
   strcpy( cond->TitYear,condTemp->TitYear);
   strcpy( cond->TitSunshine,condTemp->TitSunshine);

   cond->RecNum=condTemp->RecNum;
   for(int i=1;i<=condTemp->RecNum;i++)
   {
     cond->MinTemp[i-1]=condTemp->MinTemp[i-1];
     cond->MaxTemp[i-1]=condTemp->MaxTemp[i-1];
     cond->Precipit[i-1]=condTemp->Precipit[i-1];
     cond->Radiation[i-1]=condTemp->Radiation[i-1];
     cond->ET[i-1]=condTemp->ET[i-1];
     cond->Irri[i-1]=condTemp->Irri[i-1];
     cond->SoilTemp[i-1]=condTemp->SoilTemp[i-1];
     cond->Sunshine[i-1]=condTemp->Sunshine[i-1];
     cond->Day[i-1]=condTemp->Day[i-1];
     cond->Month[i-1]=condTemp->Month[i-1];
     cond->Year[i-1]=condTemp->Year[i-1];
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParameter::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  delete condTemp;
  delete cond; // tener cuidado al eliminar este objeto, si este formulario se inicializo con el primer constructor no se deberia borrar el objeto cond
  Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParameter::cmdOpenClimateClick(TObject *Sender)
{
  if(odClimate->Execute())
  {
     FileData *util=new FileData();
     int numTemp=0;
     if(odClimate->FilterIndex==1)
     {
       numTemp = util->GetFieldsNameFromCSVFile(ListTemp,odClimate->FileName.c_str());
     }
     if(odClimate->FilterIndex==2)
     {
       numTemp = util->GetFieldsName(ListTemp,odClimate->FileName.c_str());
     }
     delete util;
     // si se captura los titulos
     if(numTemp>0)
     {
   // verifico que las columnas day, month y year existan
   // levantamos los datos de dia, mes y año, el titulo de cada uno de ellos esta definido
   // por defecto en la clase
   char* fn = new char[ odClimate->FileName.Length() + 1 ];
   strcpy(fn, odClimate->FileName.c_str());
   int pos;
   int contErr=0;
   AnsiString errores="";
   if(odClimate->FilterIndex==1)
   {
     pos=condTemp->DeterminePositionFromCSVFile(fn,condTemp->TitDay);
   }
   if(odClimate->FilterIndex==2)
   {
     pos=condTemp->DeterminePosition(fn,condTemp->TitDay);
   }

   if(pos==0)
   {
     errores=errores+"'Day' ";
     contErr++;
   }
   if(odClimate->FilterIndex==1)
   {
     pos=condTemp->DeterminePositionFromCSVFile(fn,condTemp->TitMonth);
   }
   if(odClimate->FilterIndex==2)
   {
     pos=condTemp->DeterminePosition(fn,condTemp->TitMonth);
   }
   if(pos==0)
   {
     errores=errores+"'Month' ";
     contErr++;
   }

   if(odClimate->FilterIndex==1)
   {
     pos=condTemp->DeterminePositionFromCSVFile(fn,condTemp->TitYear);
   }
   if(odClimate->FilterIndex==2)
   {
     pos=condTemp->DeterminePosition(fn,condTemp->TitYear);
   }
   if(pos==0)
   {
     errores=errores+"'Year' ";
     contErr++;
   }
   if(contErr==1)
   {
     AnsiString mensaje="The file does not have information about "+errores+",it is necesary include the required information considering the title "+errores+"in the first line of the climate file";
     Application->MessageBox(mensaje.c_str(), "Warning!", MB_OK);
     return;
   }
   else
   {
     if(contErr>1)
     {
       AnsiString mensaje="The file does not have information about "+errores+",it is necesary include the required information considering the titles "+errores+"in the first line of the climate file";
       Application->MessageBox(mensaje.c_str(), "Warning!", MB_OK);
       return;
     }
   }
   // Si las columnas Day, Month, Year se encuentran presentes en el archivo de clima, entonces se continua con el proceso
   // volvemos a cargar los titulos de cada columna del archivo de clima
     FileData *util=new FileData();
     if(odClimate->FilterIndex==1)
     {
       num = util->GetFieldsNameFromCSVFile(List,odClimate->FileName.c_str());
     }
     if(odClimate->FilterIndex==2)
     {
       num = util->GetFieldsName(List,odClimate->FileName.c_str());
     }
     delete util;
     
   edPathFile -> Text = odClimate->FileName;
   strcpy(condTemp->FileName,odClimate->FileName.c_str());

   condTemp->CleanTitles();
   edMinTemp  -> Text = "";
   edMaxTemp  -> Text = "";
   edRad      -> Text = "";
   condTemp->CleanVectorClimate();
   if(odClimate->FilterIndex==1)
   {
     condTemp->RecNum=condTemp->CountRegistersFromCSVFile(condTemp->FileName);
     condTemp->GetColumnDataFromCSVFile(fn,condTemp->TitDay,condTemp->Day);
     condTemp->GetColumnDataFromCSVFile(fn,condTemp->TitMonth,condTemp->Month);
     condTemp->GetColumnDataFromCSVFile(fn,condTemp->TitYear,condTemp->Year);
   }
   if(odClimate->FilterIndex==2)
   {
     condTemp->RecNum=condTemp->CountRegisters(condTemp->FileName);
     condTemp->GetColumnData(fn,condTemp->TitDay,condTemp->Day);
     condTemp->GetColumnData(fn,condTemp->TitMonth,condTemp->Month);
     condTemp->GetColumnData(fn,condTemp->TitYear,condTemp->Year);
   }

   sgClimate->RowCount=condTemp->RecNum+2;
   for(int i=2;i<=sgClimate->RowCount;i++)
   {
     for(int j=1;j<=7;j++)
     {
       sgClimate->Cells[j][i]="";
     }
     sgClimate->Cells[0][i]=i-1;
   }
   
   delete fn;
     }
     else
     {
      Application->MessageBox("No information on the climate file!", "Warning!", MB_OK);
     }
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParameter::cmdMinTempClick(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Minimun temperature");
  if(frm->ShowModal()==mrOk)
  {
    edMinTemp->Text=frm->ReturnInformation();
    strcpy(condTemp->TitTMin, edMinTemp->Text.c_str());
    int numelem=condTemp->GetColumnData(condTemp->FileName,condTemp->TitTMin,condTemp->MinTemp);
    if(numelem==0) numelem=condTemp->GetColumnDataFromCSVFile(condTemp->FileName,condTemp->TitTMin,condTemp->MinTemp);
    sgClimate->RowCount=condTemp->RecNum+2;
    for(int i=1;i<=condTemp->RecNum;i++)
    {
     sgClimate->Cells[1][i+1]=condTemp->MinTemp[i-1];
    }
  }
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParameter::cmdMaxTempClick(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Maximun temperature");
  if(frm->ShowModal()==mrOk)
  {
    edMaxTemp->Text=frm->ReturnInformation();
    strcpy(condTemp->TitTMax, edMaxTemp->Text.c_str());
    int numelem=condTemp->GetColumnData(condTemp->FileName,condTemp->TitTMax,condTemp->MaxTemp);
    if(numelem==0)numelem=condTemp->GetColumnDataFromCSVFile(condTemp->FileName,condTemp->TitTMax,condTemp->MaxTemp);
    sgClimate->RowCount=condTemp->RecNum+2;
    for(int i=1;i<=condTemp->RecNum;i++)
    {
     sgClimate->Cells[2][i+1]=condTemp->MaxTemp[i-1];
    }
  }
  delete frm;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParameter::cmdRadClick(TObject *Sender)
{
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Radiation");
  if(frm->ShowModal()==mrOk)
  {
    edRad->Text=frm->ReturnInformation();
    strcpy(condTemp->TitRad, edRad->Text.c_str());
    int numelem=condTemp->GetColumnData(condTemp->FileName,condTemp->TitRad,condTemp->Radiation);
    if(numelem==0)numelem=condTemp->GetColumnDataFromCSVFile(condTemp->FileName,condTemp->TitRad,condTemp->Radiation);
    sgClimate->RowCount=condTemp->RecNum+2;
    for(int i=1;i<=condTemp->RecNum;i++)
    {
     sgClimate->Cells[3][i+1]=condTemp->Radiation[i-1];
    }
  }
  delete frm;
}
//---------------------------------------------------------------------------
void TfrmCalcParameter::GetDemo()
{
  AnsiString DirTrab=ExtractFileDir(Application->ExeName)+"\\";
  char* workdir;
  workdir=0;
  workdir = new char[255];
  strcpy(workdir,DirTrab.c_str());

  char clima[255];
  strcpy(clima,workdir);
  strncat(clima,"Toralapa93.csv",14);
  strcpy(condTemp->FileName,clima);

  strcpy(condTemp->TitTMin,"tmin");
  strcpy(condTemp->TitTMax,"tmax");
  strcpy(condTemp->TitPrec,"Rain");
  condTemp->LoadClimateInformation();
  PutValuesOnForm();
  DateTimePicker1->Date=StrToDate("10/22/1993");
  DateTimePicker2->Date=StrToDate("4/23/1994");
  edEmDay->Text=25;
  delete workdir;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParameter::butGetThermalTimeClick(TObject *Sender)
{
// --------------------------------------------------------------------------
//
//                             THERMAL TIME
//
// --------------------------------------------------------------------------

    int EmergencyDays=edEmDay->Text.ToInt();
    double parameters1,parameters2,parameters3,parameters4;
    parameters1=0.0;
    parameters2=12.0;
    parameters3=24.0;
    parameters4=35.0;
    double b1 = 1.0/(parameters2 - parameters1);
    double a1 = -1.0 * b1 * parameters1;
    double b2 = 1.0/(parameters3 - parameters4);
    double a2 = -1.0 * b2 * parameters4;
    int ndays=159;
    double* tempMin=new double[ndays];
    condTemp->GetColumnDataFromCSVFile("tempSelected.csv","tmin",tempMin);
    double* tempMax=new double[ndays];
    condTemp->GetColumnDataFromCSVFile("tempSelected.csv","tmax",tempMax);
    condTemp->setTmin(tempMin,ndays);
    condTemp->setTmax(tempMax,ndays);
    double minimo=GetMedian(condTemp->MinTemp,condTemp->RecNum);
    double base = 0.0;
    if (minimo > 10.0) base = 2.0;
//    TT <- NULL
//    peso <- NULL
//    day <- NULL
    double Y0 = (condTemp->tminSelected[0] + condTemp->tmaxSelected[0])/2.0;
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
        Y0 = (condTemp->tminSelected[i] + condTemp->tmaxSelected[i])/2.0;
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
    delete []peso;
    delete []tempMin;
    delete []tempMax;
// --------------------------------------------------------------------------
//
//                             THERMAL TIME
//
// --------------------------------------------------------------------------
    parameters1=0.0;
    parameters2=12.0;
    parameters3=24.0;
    parameters4=35.0;
    double Wmax = 0.8;
    double cover1p = 32.0;
    int GrowthZero = 160;
// Canopy
    double tm;
    double te=BetaFunction(TT,day,ndays,cover1p,GrowthZero,Wmax,&tm);
    double TIOnset=thermalDAP2(TT,day,tm,ndays);
    double A=0.75;
    double Tu=0.0;
    double b=GompertzFunction(TT,TIOnset,A,GrowthZero,&Tu,day,ndays); // generic
    delete []TT;
    delete []day;
}
//---------------------------------------------------------------------------
double TfrmCalcParameter::GompertzFunction(double* TT, double TIOnset, double A, double GrowthZero,double* Tu,int* day,int ndays)
{
  double L=thermalDAP1(TT,day,TIOnset,ndays);
  double te=thermalDAP1(TT,day,GrowthZero,ndays);
  double b = (te - L)/log(log(0.01/A)/log(0.99));
  *Tu = te + b * log(-log(0.99));
  return b;
}
//---------------------------------------------------------------------------
double TfrmCalcParameter::BetaFunction(double* TT, int* day,int ndays,double cover1p, int GrowthZero, double Wmax,double *tm)
{
  double t0=thermalDAP1(TT,day,cover1p,ndays);
  double te=thermalDAP1(TT,day,GrowthZero,ndays);
  *tm = bisection(0, te + 10,Wmax,te,t0);
  return te;
}
//---------------------------------------------------------------------------
double TfrmCalcParameter::bisection(double a, double b,double Wmax,double te, double t0)
{
    double x = b;
    double d = (a + b)/2.0;
    while (fabs(x-d)/fabs(x) > 0.000000000001)
    {
        double valor1=Fx1(x,Wmax,te,t0);
        double valor2=Fx1(a,Wmax,te,t0);
        if (valor1 == 0)
            break;
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
//---------------------------------------------------------------------------
double TfrmCalcParameter::Fx1(double x,double Wmax, double te,double t0)
{
    return 0.01 - Wmax * (1 + (te - t0)/(te - x)) * pow((t0/te),(te/(te - x)));
}
//---------------------------------------------------------------------------
double TfrmCalcParameter::thermalDAP1(double* TT,int* day,double dap,int ndays)  // con dato de entrada dap la salida es Time
{
  myData* data=new myData[ndays];
  for(int i=0;i<ndays;i++)
  {
    (data+i)->x=day[i];
    (data+i)->y=TT[i];
  }

  dap = round(dap);
  double Time;

  if(dap<day[0]) Time=0.0;
  if (dap > day[ndays-1])
  {
    leastSqrRegression(data,ndays);
    // aqui falta implementar esta funcion
    //  Time <- as.numeric(predict(model, data.frame(dap)))
  }
  if(dap>=day[0] && dap<=day[ndays-1])
  {
     for(int i=0;i<ndays;i++)
     {
       if(day[i]==dap)
       {
         Time=TT[i];
         break;
       }
     }
  }
  delete []data;
  return Time;
}
//---------------------------------------------------------------------------
double TfrmCalcParameter::thermalDAP2(double* TT,int* day,double Time,int ndays) // con Time
{
        double dap;
  myData* data=new myData[ndays];
  for(int i=0;i<ndays;i++)
  {
    (data+i)->x=day[i];
    (data+i)->y=TT[i];
  }

        if (Time < TT[0])
            dap = day[0];
        if (Time > TT[ndays-1]) {
            leastSqrRegression(data,ndays);
            // aqui falta implementar esta funcion
            //dap <- as.numeric(predict(model, data.frame(Time)))
        }
        if ((Time >= TT[0]) && (Time <= TT[ndays-1])) {
            int i = 0;
            while (TT[i] < Time) {
                i = i + 1;
            }
            if (i < ndays-1) {
                double medio = (TT[i] + TT[i - 1])/2.0;
                if (medio - TT[i - 1] > TT[i] - medio)
                  dap = day[i];
                else dap = day[i - 1];
            }
            else dap = day[i - 1];
        }
  delete []data;
  return dap;
}
//---------------------------------------------------------------------------
double TfrmCalcParameter::round(double number)
{
    return number < 0.0 ? ceil(number - 0.5) : floor(number + 0.5);
}
//---------------------------------------------------------------------------




/*
BetaFunction <- function (TT, cover1p, GrowthZero, Wmax)
{
    t0 <- as.numeric(thermalDAP(TT, dap = cover1p)[2])
    te <- as.numeric(thermalDAP(TT, dap = GrowthZero)[2])
    f <- function(t, Wmax, tm, te) Wmax * (1 + (te - t)/(te -
        tm)) * (t/te)^(te/(te - tm))
    Ft <- expression(Wmax * (1 + (te - t)/(te - tm)) * (t/te)^(te/(te -
        tm)))
    Fx1 <- function(x) 0.01 - Wmax * (1 + (te - t0)/(te - x)) *
        (t0/te)^(te/(te - x))
    tm <- bisection(Fx = Fx1, 0, te + 10)
    Fx50 <- function(x) 0.5 - Wmax * (1 + (te - x)/(te - tm)) *
        (x/te)^(te/(te - tm))
    T50 <- bisection(Fx = Fx50, te, te + 1000)
    f1 <- D(Ft, "t")
    out <- list(Wmax = Wmax, tm = tm, te = te, T50 = T50, f = Ft,
        f1 = f1)
    return(out)
}
*/

/*
thermalDAP <- function (TT, Time = NULL, dap = NULL)
{
            model <- lm(Time ~ dap, data = TT)
            print(data.frame(TT$Time))
            print(data.frame(TT$dap))
            print(model)
            print("hola3")
    if (is.null(Time) & !is.null(dap)) {
        dap <- round(dap, 0)
        if (dap < TT$dap[1])
            Time <- 0
        if (dap > TT$dap[nrow(TT)]) {
            model <- lm(Time ~ dap, data = TT)
            Time <- as.numeric(predict(model, data.frame(dap)))
        }
        if ((dap >= TT$dap[1]) & (dap <= TT$dap[nrow(TT)]))
            Time <- TT[TT$dap == dap, "Time"]
    }
    if (is.null(dap) & !is.null(Time)) {
        if (Time < TT$Time[1])
            dap <- TT$dap[1]
        if (Time > TT$Time[nrow(TT)]) {
            model <- lm(dap ~ Time, data = TT)
            dap <- as.numeric(predict(model, data.frame(Time)))
        }
        if ((Time >= TT$Time[1]) & (Time <= TT$Time[nrow(TT)])) {
            i <- 1
            while (TT$Time[i] < Time) {
                i <- i + 1
            }
            if (i < nrow(TT)) {
                medio <- (TT$Time[i] + TT$Time[i - 1])/2
                if (medio - TT$Time[i - 1] > TT$Time[i] - medio)
                  dap <- TT$dap[i]
                else dap <- TT$dap[i - 1]
            }
            else dap <- TT$dap[i - 1]
        }
    }
    return(list = c(dap = dap, Time = Time))
}
*/













void TfrmCalcParameter::leastSqrRegression(struct myData* xyCollection, int dataSize)
{
   if (xyCollection == NULL || dataSize == 0)
   {
//      printf("Empty data set!\n");
      return;
   }

   double SUMx = 0;     //sum of x values
   double SUMy = 0;     //sum of y values
   double SUMxy = 0;    //sum of x * y
   double SUMxx = 0;    //sum of x^2
   double SUMres = 0;   //sum of squared residue
   double res = 0;      //residue squared
//   double slope = 0;    //slope of regression line
//   double y_intercept = 0; //y intercept of regression line
   double SUM_Yres = 0; //sum of squared of the discrepancies
   double AVGy = 0;     //mean of y
   double AVGx = 0;     //mean of x
   double Yres = 0;     //squared of the discrepancies
   double Rsqr = 0;     //coefficient of determination

   //calculate various sums 
   for (int i = 0; i < dataSize; i++)
   {
      //sum of x
      SUMx = SUMx + (xyCollection + i)->x;
      //sum of y
      SUMy = SUMy + (xyCollection + i)->y;
      //sum of squared x*y
      SUMxy = SUMxy + (xyCollection + i)->x * (xyCollection + i)->y;
      //sum of squared x
      SUMxx = SUMxx + (xyCollection + i)->x * (xyCollection + i)->x;
   }

   //calculate the means of x and y
   AVGy = SUMy / dataSize;
   AVGx = SUMx / dataSize;

   //slope or a1
   slope = (dataSize * SUMxy - SUMx * SUMy) / (dataSize * SUMxx - SUMx*SUMx);

   //y itercept or a0
   y_intercept = AVGy - slope * AVGx;
   
//   printf("x mean(AVGx) = %0.5E\n", AVGx);
//   printf("y mean(AVGy) = %0.5E\n", AVGy);

//   printf ("\n");
//   printf ("The linear equation that best fits the given data:\n");
//   printf ("       y = %2.8lfx + %2.8f\n", slope, y_intercept);
//   printf ("------------------------------------------------------------\n");
//   printf ("   Original (x,y)   (y_i - y_avg)^2     (y_i - a_o - a_1*x_i)^2\n");
//   printf ("------------------------------------------------------------\n");

   //calculate squared residues, their sum etc.
   for (int i = 0; i < dataSize; i++) 
   {
      //current (y_i - a0 - a1 * x_i)^2
      Yres = pow(((xyCollection + i)->y - y_intercept - (slope * (xyCollection + i)->x)), 2);

      //sum of (y_i - a0 - a1 * x_i)^2
      SUM_Yres += Yres;

      //current residue squared (y_i - AVGy)^2
      res = pow((xyCollection + i)->y - AVGy, 2);

      //sum of squared residues
      SUMres += res;
      
//      printf ("   (%0.2f %0.2f)      %0.5E         %0.5E\n",(xyCollection + i)->x, (xyCollection + i)->y, res, Yres);
   }

   //calculate r^2 coefficient of determination
   Rsqr = (SUMres - SUM_Yres) / SUMres;

//   printf("--------------------------------------------------\n");
//   printf("Sum of (y_i - y_avg)^2 = %0.5E\t\n", SUMres);
//   printf("Sum of (y_i - a_o - a_1*x_i)^2 = %0.5E\t\n", SUM_Yres);
//   printf("Standard deviation(St) = %0.5E\n", sqrt(SUMres / (dataSize - 1)));
//   printf("Standard error of the estimate(Sr) = %0.5E\t\n", sqrt(SUM_Yres / (dataSize-2)));
//   printf("Coefficent of determination(r^2) = %0.5E\t\n", (SUMres - SUM_Yres)/SUMres);
//   printf("Correlation coefficient(r) = %0.5E\t\n", sqrt(Rsqr));

}
//---------------------------------------------------------------------------
double TfrmCalcParameter::GetMedian(double* daArray, int iSize) {
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
