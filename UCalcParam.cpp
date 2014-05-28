//---------------------------------------------------------------------------
#include <vcl.h>
#include <io.h>
#pragma hdrstop
#include "UCalcParam.h"
#include "UCampo.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TeeComma"
#pragma resource "*.dfm"
TfrmCalcParam *frmCalcParam;
struct myData
{
   double x;
   double y;
};
// ---------------------------------------------------------------------------
//
//   FORMATEAR GRILLAS, ANCHO Y TITULO DE COLUMNAS
//
// ---------------------------------------------------------------------------
__fastcall TfrmCalcParam::TfrmCalcParam(TComponent* Owner)
        : TForm(Owner)
{
//   condTemp=new ManageDataPotato(0);
   InicializarsgClimate();
   InicializarsgClimateSel();
   tch1->Series[0]->Clear();
//   tch1->Series[1]->Clear();
//   tch1->Series[2]->Clear();
   dato_tu=0.0;
   dato_b=0.0;
   dato_te=0.0;
   dato_tm=0.0;
   hacer=false;
   tc1->Panel=tch1;
}
//---------------------------------------------------------------------------
void TfrmCalcParam::InicializarsgClimate()
{
   sgClimate->RowCount=3;
   sgClimate->Cells[0][1]="#";
   sgClimate->Cells[1][0]="Day";
   sgClimate->Cells[2][0]="Month";
   sgClimate->Cells[3][0]="Year";
   sgClimate->Cells[4][0]="Minimum Temp";
   sgClimate->Cells[5][0]="Maximum Temp";
   sgClimate->Cells[4][1]="oC";
   sgClimate->Cells[5][1]="oC";
   sgClimate->Cells[6][1]="oC";
   sgClimate->RowHeights[0]=18;
   sgClimate->RowHeights[1]=18;
   sgClimate->ColWidths[0]=30;
   sgClimate->ColWidths[1]=50;
   sgClimate->ColWidths[2]=50;
   sgClimate->ColWidths[3]=50;
   sgClimate->ColWidths[4]=80;
   sgClimate->ColWidths[5]=80;
}
//---------------------------------------------------------------------------
void TfrmCalcParam::InicializarsgClimateSel()
{
   sgClimateSel->Cells[0][1]="#";
   sgClimateSel->Cells[1][0]="Day";
   sgClimateSel->Cells[2][0]="Month";
   sgClimateSel->Cells[3][0]="Year";
   sgClimateSel->Cells[4][0]="Minimum Temp";
   sgClimateSel->Cells[5][0]="Maximum Temp";
   sgClimateSel->Cells[6][0]="TT";
   sgClimateSel->Cells[4][1]="oC";
   sgClimateSel->Cells[5][1]="oC";
   sgClimateSel->Cells[6][1]="oCd";
   sgClimateSel->RowHeights[0]=18;
   sgClimateSel->RowHeights[1]=18;
   sgClimateSel->ColWidths[0]=30;
   sgClimateSel->ColWidths[1]=50;
   sgClimateSel->ColWidths[2]=50;
   sgClimateSel->ColWidths[3]=50;
   sgClimateSel->ColWidths[4]=80;
   sgClimateSel->ColWidths[5]=80;
   sgClimateSel->ColWidths[6]=50;
   sgClimateSel->RowCount=3;
   for(int i=0;i<=6;i++)
   {
     sgClimateSel->Cells[i][2]="";
   }
}
// ---------------------------------------------------------------------------
//
//   RECIBO LAS CONDICIONES INICIALES Y LA BASE DE DATOS DE CULTIVO
//
// ---------------------------------------------------------------------------
void TfrmCalcParam::EnterInformation(ManageDataPotato *_cond,DBCultivo *_dbcultivo)
{
cond=_cond;
dbcultivo=_dbcultivo;
// HAGO UN BACKUP DE LOS DATOS QUE VOY A MODIFICAR EN ESTE FORMULARIO
backup_values();
}
//---------------------------------------------------------------------------
void TfrmCalcParam::backup_values()
{
/*
   condTemp->crop->plant->fcl=cond->crop->plant->fcl;
   condTemp->crop->plant->F0=cond->crop->plant->F0;
   condTemp->crop->plant->R0=cond->crop->plant->R0;
   condTemp->crop->tuber->M=cond->crop->tuber->M;
   condTemp->crop->tuber->A=cond->crop->tuber->A;
   condTemp->crop->tuber->b=cond->crop->tuber->b;
   condTemp->crop->tuber->DMCont=cond->crop->tuber->DMCont;
   condTemp->crop->plant->LUE=cond->crop->plant->LUE;
   condTemp->crop->plant->EDay=cond->crop->plant->EDay;

   condTemp->time->YearStart=cond->time->YearStart;
   condTemp->time->MonthStart=cond->time->MonthStart;
   condTemp->time->DayStart=cond->time->DayStart;
   condTemp->time->duration=cond->time->duration;
   condTemp->time->repetitions=cond->time->repetitions;
*/

   back_fcl=cond->crop->plant->fcl;
   back_F0=cond->crop->plant->F0;
   back_R0=cond->crop->plant->R0;
   back_M=cond->crop->tuber->M;
   back_A=cond->crop->tuber->A;
   back_b=cond->crop->tuber->b;
   back_DMCont=cond->crop->tuber->DMCont;
   back_LUE=cond->crop->plant->LUE;
   back_EDay=cond->crop->plant->EDay;
   back_w=cond->crop->tuber->w;
   back_Pc=cond->crop->tuber->Pc;

   back_YearStart=cond->time->YearStart;
   back_MonthStart=cond->time->MonthStart;
   back_DayStart=cond->time->DayStart;
   back_duration=cond->time->duration;
   back_repetitions=cond->time->repetitions;



}
// ---------------------------------------------------------------------------
//
//   MUESTRO LOS DATOS DE ENTRADA CON LOS CUALES SE REALIZARA EL PROCESO PRINCIPAL
//
// ---------------------------------------------------------------------------
void __fastcall TfrmCalcParam::FormShow(TObject *Sender)
{
  int cant=AnsiString(cond->climate->FileName).Length();
  if (cant==0)
  {
  }
  else
  {
    int existe=access(cond->climate->FileName, 0);
    if(existe==-1) // el archivo no existe
    {
      Application->MessageBox("The specified file does not exist!!!","¡Warning!",MB_OK);
      return;
    }
    else
    {
      FileData *util=new FileData();
      AnsiString nombre = AnsiString(cond->climate->FileName);
      int posicion=nombre.Pos(".");
      int longitud=nombre.Length();
      int caract=longitud-posicion;
      AnsiString ext=nombre.SubString(posicion+1,caract);
      if(ext=="prn") num=util->GetFieldsName(List,cond->climate->FileName);
      if(ext=="csv") num=util->GetFieldsNameFromCSVFile(List,cond->climate->FileName);
      delete util;
    }
  }
  PutValuesOnForm();
}
//---------------------------------------------------------------------------
void TfrmCalcParam::PutValuesOnForm()
{
   edPathFile->Text=cond->climate->FileName;
   edMinTemp->Text=cond->climate->TitTMin;
   edMaxTemp->Text=cond->climate->TitTMax;

   if(cond->climate->RecNum==0)
   {
     sgClimate->RowCount=3;
   }
   else
   {
     sgClimate->RowCount=cond->climate->RecNum+2;
   }
   for(int i=1;i<=cond->climate->RecNum;i++)
   {
     sgClimate->RowHeights[i+1] = 18;
     sgClimate->Cells[0][i+1]   = i;
     sgClimate->Cells[1][i+1]   = cond->climate->Day[i-1];
     sgClimate->Cells[2][i+1]   = cond->climate->Month[i-1];
     sgClimate->Cells[3][i+1]   = cond->climate->Year[i-1];
     sgClimate->Cells[4][i+1]   = cond->climate->MinTemp[i-1];
     sgClimate->Cells[5][i+1]   = cond->climate->MaxTemp[i-1];
   }
   edEmDay->Text=cond->crop->plant->EDay;
   edMaxgc->Text=cond->crop->plant->fcl;
   edA->Text=cond->crop->tuber->M;
   edRUE->Text=cond->crop->plant->LUE;
   edDMC->Text=cond->crop->tuber->DMCont;
   edPhotoSen->Text=cond->crop->tuber->w;
   edPhotoCrit->Text=cond->crop->tuber->Pc;

   AnsiString fecha=AnsiString(cond->time->MonthStart) + "/";
   fecha=fecha + AnsiString(cond->time->DayStart) + "/";
   fecha=fecha + AnsiString(cond->time->YearStart);
   dtpPlantingDate->Date=StrToDate(fecha.c_str());
   if(cond->time->duration<=0)
   {
     dtpHarvestDate->Date  = dtpPlantingDate->Date;
   }
   else
   {
     dtpHarvestDate->Date  = dtpPlantingDate->Date + cond->time->duration -1 ;
   }
}
//---------------------------------------------------------------------------
//
//  Usuario presiona el boton "Select data" para seleccionar los datos de clima
//
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParam::butSelectDataClick(TObject *Sender)
{
  InicializarsgClimateSel();

  AnsiString valor;

    AnsiString texto=dtpPlantingDate->Date.DateString();
    TDateTime DateValue = StrToDate(texto);

    ShortDateFormat = "d";
    valor = DateValue;
    pdDay=valor.ToInt();

    ShortDateFormat = "m";
    valor = DateValue;
    pdMonth=valor.ToInt();

    ShortDateFormat = "yyyy";
    valor = DateValue;
    pdYear=valor.ToInt();

    ShortDateFormat = "M/d/yyyy";

    texto=dtpHarvestDate->Date.DateString();
    DateValue = StrToDate(texto);

    ShortDateFormat = "d";
    valor = DateValue;
    hdDay=valor.ToInt();

    ShortDateFormat = "m";
    valor = DateValue;
    hdMonth=valor.ToInt();

    ShortDateFormat = "yyyy";
    valor = DateValue;
    hdYear=valor.ToInt();

    ShortDateFormat = "M/d/yyyy";

// diferencia de fechas
    TDateTime Start = dtpPlantingDate->Date;
    TDateTime End   = dtpHarvestDate->Date;
    TDateTime Diff  = End - Start;
    double d        = Diff.operator double();
    int numdias = round(d)+1;
    int reg_inicio,reg_final;

    double* datTmin=new double[numdias];
    double* datTmax=new double[numdias];

    for(int i=0;i<cond->climate->RecNum;i++)
    {
      if(cond->climate->Day[i]==pdDay && cond->climate->Month[i]==pdMonth && cond->climate->Year[i]==pdYear)
      {
        reg_inicio=i;
        break;
      }
    }
    int cont=-1;
    for(int i=reg_inicio;i<cond->climate->RecNum;i++)
    {
      cont++;
      datTmin[cont]=cond->climate->MinTemp[i];
      datTmax[cont]=cond->climate->MaxTemp[i];
      if(cond->climate->Day[i]==hdDay && cond->climate->Month[i]==hdMonth && cond->climate->Year[i]==hdYear)
      {
        reg_final=i;
        break;
      }
    }
    int numdatos=reg_final-reg_inicio+1;
    cond->climate->setTmin(datTmin,cont+1);
    cond->climate->setTmax(datTmax,cont+1);
    delete []datTmin;
    delete []datTmax;
// pueblo la grilla sgClimateSel
  sgClimateSel->RowCount=numdatos+2;
  int indice=reg_inicio-1;
  for(int i=0;i<cond->climate->numregSelected;i++)
  {
    indice++;
    sgClimateSel->Cells[0][i+2]=i+1;
    sgClimateSel->Cells[1][i+2]=cond->climate->Day[indice];
    sgClimateSel->Cells[2][i+2]=cond->climate->Month[indice];
    sgClimateSel->Cells[3][i+2]=cond->climate->Year[indice];
    sgClimateSel->Cells[4][i+2]=cond->climate->tminSelected[i];
    sgClimateSel->Cells[5][i+2]=cond->climate->tmaxSelected[i];
  }
}
//---------------------------------------------------------------------------
//
//  Usuario presiona el boton "PROCESS ..." para realizar proceso principal
//
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParam::butProcessClick(TObject *Sender)
{
// get user input
// validamos inputs
  double datod;
  if(chkbtuberinit->Checked)
  {
    try
    {
      datod=edtuberinit->Text.ToDouble();
    }
    catch(...)
    {
      Application->MessageBox("You should enter a right value in the tuber initiation box, check your data!!!","¡Warning!",MB_OK);
      edtuberinit->SelectAll();
      edtuberinit->SetFocus();
      return;
    }
  }
    int EmergencyDays=edEmDay->Text.ToInt();
    int ndays=cond->climate->numregSelected-EmergencyDays;
    double cover1p=edcover1p->Text.ToDouble();
    double GrowthZero=edGrowthZero->Text.ToDouble();
    double GrowthZero2=edGrowthZero2->Text.ToDouble();
    double Wmax=edMaxgc->Text.ToDouble();
    double A=edA->Text.ToDouble();

    double* tmin=new double[ndays];
    double* tmax=new double[ndays];
    for(int i=0;i<ndays;i++)
    {
      tmin[i]=cond->climate->tminSelected[i+EmergencyDays];
      tmax[i]=cond->climate->tmaxSelected[i+EmergencyDays];
    }

  butProcess->Enabled=false;
  bool error=false;

// --------------------------------------------------------------------------
//
//                             THERMAL TIME
//
// --------------------------------------------------------------------------
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
    delete []peso;
    delete []tmin;
    delete []tmax;
// --------------------------------------------------------------------------
//
//                             Beta and Gompertz function
//
// --------------------------------------------------------------------------
    parameters1=0.0;
    parameters2=12.0;
    parameters3=24.0;
    parameters4=35.0;
// Canopy
    double tm;
    double te=BetaFunction(TT,day,ndays,cover1p,GrowthZero,Wmax,&tm,&error);
    if(error)
    {
      butProcess->Enabled=true;
      Application->MessageBox("There were a error during the process, please check your data !!!", "Warning!", MB_OK);
      return;
    }
  double TIOnset=0;
  if(chkbtuberinit->Checked)
  {
    TIOnset=datod;
  }
  else
  {
    TIOnset=thermalDAP2(TT,day,tm,ndays,&error);
  }
    if(error)
    {
      butProcess->Enabled=true;
      Application->MessageBox("There were a error during the process, please check your data !!!", "Warning!", MB_OK);
      return;
    }
    double Tu=0.0;
    double b=GompertzFunction(TT,TIOnset,A,GrowthZero2,&Tu,day,ndays,&error); // generic
   if(error)
   {
     butProcess->Enabled=true;
     Application->MessageBox("There were a error during the process, please check your data !!!", "Warning!", MB_OK);
     return;
   }

// put output on form
  edtu->Text=FormatFloat("0.00",Tu);
  edb->Text=FormatFloat("0.00",b);
  edte->Text=FormatFloat("0.00",te);
  edtm->Text=FormatFloat("0.00",tm);
  int contTT=-1;
  double* ttdat=new double[cond->climate->numregSelected];
  for(int i=0;i<cond->climate->numregSelected;i++)
  {
    if(i<EmergencyDays)
    {
    sgClimateSel->Cells[6][i+2]=0.0;
    ttdat[i]=0.0;
    }
    else
    {
    contTT++;
    sgClimateSel->Cells[6][i+2]=FormatFloat("0.00",TT[contTT]);
    ttdat[i]=TT[contTT];
    }
  }
// guardar TT
    cond->climate->setTT(ttdat,cond->climate->numregSelected);
    delete []ttdat;
    delete []TT;
    delete []day;
// show in form
  dato_tu=int(round(Tu));
  edtu->Text=dato_tu;
  tb_tu->Position=0;

  dato_b=int(round(b));
  edb->Text=dato_b;
  tb_b->Position=0;

  dato_te=int(round(te));
  edte->Text=dato_te;
  tb_te->Position=0;

  dato_tm=int(round(tm));
  edtm->Text=dato_tm;
  tb_tm->Position=0;


// simulacion
// graficos
/*
  if(chkbtuberinit->Checked)
  {
    tm=edtuberinit->Text.ToDouble();
  }
*/

   GraficoCanopyCover(Wmax,te,tm,Tu,b,A,&error);
   if(error)
   {
     butProcess->Enabled=true;
     Application->MessageBox("There were a error during the process, please check your data !!!", "Warning!", MB_OK);
     return;
   }
   Graficof1f2(Wmax,te,tm,Tu,b,A,&error);
   if(error)
   {
     butProcess->Enabled=true;
     Application->MessageBox("There were a error during the process, please check your data !!!", "Warning!", MB_OK);
     return;
   }
  try
  {
    simular();
  }
  catch (Exception &exception)
  {
    butProcess->Enabled=true;
    Application->MessageBox("There were a error during the simulation process, please check your data !!!", "Warning!", MB_OK);
    return;
  }
  tch1->LeftAxis->AutomaticMaximum=false;
  tch1->LeftAxis->AutomaticMinimum=false;
  tch1->LeftAxis->Maximum=val_mayor+0.5;
  tch1->LeftAxis->Minimum=val_minimo-0.5;
  butProcess->Enabled=true;
}
//---------------------------------------------------------------------------
//
//                           SE REALIZAN LOS GRAFICOS
//
//---------------------------------------------------------------------------
void TfrmCalcParam::GraficoCanopyCover(double Wmax, double te, double tm,double Tu,double b, double A,bool* error)
{
  AnsiString titulo;
  double y;
  double gompertz;
  tchCanopy->Series[0]->Clear();
  tchCanopy->Series[1]->Clear();
  if(te==0.0) *error=true;
  if(te-tm==0.0) *error=true;
  if(*error) return;
  for(int t=1;t<2000;t++)
  {
    if((t/te)==0.0 && (te/(te-tm))<=0.0) *error=true;
    if(*error) return;
    y=  Wmax *   (1+(te-t)/(te-tm))   *    pow((t/te),(te/(te-tm)));
    if(b==0.0) *error=true;
    if(*error) return;
    gompertz=A * (exp(-exp(-(t - Tu)/b)));
    titulo=AnsiString(t);
    tchCanopy->Series[0]->AddXY(t,y,titulo,tchCanopy->Series[0]->Color);
    tchCanopy->Series[1]->AddXY(t,gompertz,titulo,tchCanopy->Series[1]->Color);
  }
}
//---------------------------------------------------------------------------
void TfrmCalcParam::Graficof1f2(double Wmax, double te, double tm,double Tu,double b, double A,bool* error)
{
  AnsiString titulo;
  double f1;
  double f2;
  tchf1f2->Series[0]->Clear();
  tchf1f2->Series[1]->Clear();

//  tc1->Panel=tchf1f2;
  if(te==0.0) *error=true;
  if(te-tm==0.0) *error=true;
  if(b==0.0) *error=true;
  if(*error) return;
  for(int t=1;t<2000;t++)
  {
    if((t/te)==0.0 && (((te/(te - tm))) - 1)<=0.0) *error=true;
    if((t/te)==0.0 && (te/(te - tm))<=0.0) *error=true;
    if(*error) break;
    f1=Wmax * (1 + (te - t)/(te - tm)) * (pow((t/te),((te/(te - tm))) - 1) * ((te/(te - tm)) * (1/te))) - Wmax * (1/(te - tm)) * pow((t/te),(te/(te - tm)));
    f2=A * (exp(-exp(-(t - Tu)/b)) * (exp(-(t - Tu)/b) * (1/b)) * (exp(-(t - Tu)/b) * (1/b)) - exp(-exp(-(t - Tu)/b)) * (exp(-(t - Tu)/b) * (1/b) * (1/b)));
    titulo=AnsiString(t);
    tchf1f2->Series[0]->AddXY(t,f1,titulo,tchf1f2->Series[0]->Color);
    tchf1f2->Series[1]->AddXY(t,f2,titulo,tchf1f2->Series[1]->Color);
  }
  return;
}
//---------------------------------------------------------------------------
//
//    FUNCIONES PARA EL CALCULO DE PARAMETROS
//
//---------------------------------------------------------------------------
double TfrmCalcParam::GompertzFunction(double* TT, double TIOnset, double A, double GrowthZero2,double* Tu,int* day,int ndays,bool* error)
{
  double L=thermalDAP1(TT,day,TIOnset,ndays,error);
  if(*error) return 0.0;

  double te=thermalDAP1(TT,day,GrowthZero2,ndays,error);
  if(*error) return 0.0;

  if(A<=0.0) *error=true;
  if((0.01/A)==1.0) *error=true;
  if((log(0.01/A)/log(0.99))==1.0) *error=true;
  if((log(0.01/A)/log(0.99))<=0) *error=true;
  if(*error) return 0.0;
  double b = (te - L)/log(log(0.01/A)/log(0.99));
  *Tu = te + b * log(-log(0.99));
  return b;
}
//---------------------------------------------------------------------------
double TfrmCalcParam::BetaFunction(double* TT, int* day,int ndays,double cover1p, int GrowthZero, double Wmax,double *tm, bool* error)
{
  double t0=thermalDAP1(TT,day,cover1p,ndays,error);
  if(*error) return 0.0;

  double te=thermalDAP1(TT,day,GrowthZero,ndays,error);
  if(*error) return 0.0;

  *tm = bisection(0, te + 10,Wmax,te,t0,error);
  if(*error) return 0.0;

  return te;
}
//---------------------------------------------------------------------------
double TfrmCalcParam::bisection(double a, double b,double Wmax,double te, double t0,bool* error)
{
    double x = b;
    double d = (a + b)/2.0;
    double valor1;
    double valor2;
    while (fabs(x-d)/fabs(x) > 0.000000000001)
    {
        valor1=Fx1(x,Wmax,te,t0,error);
        if(*error) break;
        valor2=Fx1(a,Wmax,te,t0,error);
        if(*error) break;
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
double TfrmCalcParam::Fx1(double x,double Wmax, double te,double t0,bool* error)
{
    if(te==0.0) *error=true;
    if(te-x==0.0) *error=true;
    if((t0/te)==0 && (te/(te - x))<=0.0) *error=true;
    if(*error) return 0.0;

    return 0.01 - Wmax * (1 + (te - t0)/(te - x)) * pow((t0/te),(te/(te - x)));
}
//---------------------------------------------------------------------------
double TfrmCalcParam::thermalDAP1(double* TT,int* day,double dap,int ndays,bool* error)  // con dato de entrada dap la salida es Time
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
    leastSqrRegression(data,ndays,error);
    if(*error) return 0.0;
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
double TfrmCalcParam::thermalDAP2(double* TT,int* day,double Time,int ndays,bool* error) // con Time
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
            leastSqrRegression(data,ndays,error);
            if(*error) return 0.0;
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
void TfrmCalcParam::leastSqrRegression(struct myData* xyCollection, int dataSize,bool* error)
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
   if(dataSize==0) *error=true;
   if(*error) return;
   AVGy = SUMy / dataSize;
   AVGx = SUMx / dataSize;

   //slope or a1
   if((dataSize * SUMxx - SUMx*SUMx)==0.0) *error=true;
   if(*error) return;
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
   if(SUMres==0) *error=true;
   if(*error) return;

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
double TfrmCalcParam::GetMedian(double* daArray, int iSize) {
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
//
//  El usuario puede lanzar una simulacion despues de cambiar sus
//  parametros manualmente
//
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParam::butDoSimulationClick(TObject *Sender)
{
  bool error=false;
  bool exitoso=false;
  exitoso=Validate();
  if(exitoso)
  {
double Wmax=edMaxgc->Text.ToDouble();
double A=edA->Text.ToDouble();
int te=edte->Text.ToInt();
int tm=edtm->Text.ToInt();
int Tu=edtu->Text.ToInt();
int b=edb->Text.ToInt();
simular();
GraficoCanopyCover(Wmax,te,tm,Tu,b,A,&error);
   if(error)
   {
     butProcess->Enabled=true;
     Application->MessageBox("There were a error during the process, please check your data !!!", "Warning!", MB_OK);
     return;
   }

Graficof1f2(Wmax,te,tm,Tu,b,A,&error);
   if(error)
   {
     butProcess->Enabled=true;
     Application->MessageBox("There were a error during the process, please check your data !!!", "Warning!", MB_OK);
     return;
   }

  }
}
//---------------------------------------------------------------------------
//
//                            PROCESO DE SIMULACION
//
//---------------------------------------------------------------------------
void TfrmCalcParam::simular()
{
   double result=0.0;
   cond->crop->plant->fcl=edMaxgc->Text.ToDouble();
   cond->crop->plant->F0=edtm->Text.ToDouble();
   cond->crop->plant->R0=edte->Text.ToDouble();
   cond->crop->tuber->M=edA->Text.ToDouble();
   cond->crop->tuber->A=edtu->Text.ToDouble();
   cond->crop->tuber->b=edb->Text.ToDouble();
   cond->crop->tuber->DMCont=edDMC->Text.ToDouble();
   cond->crop->plant->LUE=edRUE->Text.ToDouble();
   cond->crop->tuber->Tcr=-3;
   cond->crop->tuber->Tld=-5;
   cond->crop->tuber->Trg=-8;
   cond->crop->plant->EDay=edEmDay->Text.ToInt();
   cond->crop->tuber->w=edPhotoSen->Text.ToDouble();;
   cond->crop->tuber->Pc=edPhotoCrit->Text.ToDouble();;

  TDateTime pd = dtpPlantingDate->Date;
  TDateTime hd = dtpHarvestDate->Date;
  TDateTime Start = pd+cond->crop->plant->EDay;
  TDateTime Diff  = hd - pd + 1;

  cond->time->duration=round(Diff.operator double());
  cond->time->DayStart=pdDay;
  cond->time->MonthStart=pdMonth;
  cond->time->YearStart=pdYear;
  cond->time->repetitions=20;


  cond->DoSimulation();

// show in form
  tch1->Series[0]->Clear();
//  tch1->Series[1]->Clear();
//  tch1->Series[2]->Clear();
  AnsiString titulo;
  val_mayor=0.0;
  val_minimo=1000.0;
  for(int i=0;i<cond->simulation->time->duration;i++)
  {
    titulo=AnsiString(i);
    tch1->Series[0]->AddXY(i,cond->simulation->Xfty[i],titulo,tch1->Series[0]->Color);
//    tch1->Series[1]->AddXY(i,cond->simulation->LC1[i],titulo,tch1->Series[1]->Color);
//    tch1->Series[2]->AddXY(i,cond->simulation->LC2[i],titulo,tch1->Series[2]->Color);
    if(cond->simulation->LC2[i]>val_mayor) val_mayor=cond->simulation->LC2[i];
    if(cond->simulation->LC1[i]<val_minimo) val_minimo=cond->simulation->LC1[i];
  }
  Edit11->Text=FormatFloat("0.00",cond->simulation->ExpFreshYield);
  Edit13->Text=FormatFloat("0.00",cond->simulation->MinFreshYield);
  Edit14->Text=FormatFloat("0.00",cond->simulation->MaxFreshYield);

  if(val_mayor>tch1->LeftAxis->Maximum)
  {
    tch1->LeftAxis->Maximum=val_mayor+0.5;
  }
}
//---------------------------------------------------------------------------
//
//      El usuario puede guardar sus parametros en la BD
//
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParam::butAddParDBClick(TObject *Sender)
{
  bool exitoso=false;
  exitoso=Validate();
// chequear si se ha ingresado nombre al cultivo
  if(exitoso)
  {
  AnsiString nombre=edNameCrop->Text.Trim();
  int numcar=nombre.Length();
  if(numcar<=0)
  {
    exitoso=false;
    Application->MessageBox("Enter a name for the variety!", "Warning!", MB_OK);
    edNameCrop->SetFocus();
  }
  }
  if(exitoso)
  {
    GuardarDatos();
  strcpy(dbcultivo->Item[dbcultivo->numreg].cropname,edNameCrop->Text.c_str());
  dbcultivo->Item[dbcultivo->numreg].plant->fcl=cond->crop->plant->fcl;
  dbcultivo->Item[dbcultivo->numreg].plant->F0=cond->crop->plant->F0;
  dbcultivo->Item[dbcultivo->numreg].plant->R0=cond->crop->plant->R0;
  dbcultivo->Item[dbcultivo->numreg].tuber->M= cond->crop->tuber->M;
  dbcultivo->Item[dbcultivo->numreg].tuber->A= cond->crop->tuber->A;
  dbcultivo->Item[dbcultivo->numreg].tuber->b= cond->crop->tuber->b;
  dbcultivo->Item[dbcultivo->numreg].tuber->DMCont= cond->crop->tuber->DMCont;
  dbcultivo->Item[dbcultivo->numreg].plant->LUE=cond->crop->plant->LUE;
  dbcultivo->Item[dbcultivo->numreg].tuber->Tcr= cond->crop->tuber->Tcr;
  dbcultivo->Item[dbcultivo->numreg].tuber->Tld= cond->crop->tuber->Tld;
  dbcultivo->Item[dbcultivo->numreg].tuber->Trg= cond->crop->tuber->Trg;
  dbcultivo->Item[dbcultivo->numreg].plant->EDay=cond->crop->plant->EDay;
  dbcultivo->Item[dbcultivo->numreg].tuber->w= cond->crop->tuber->w;
  dbcultivo->Item[dbcultivo->numreg].tuber->Pc= cond->crop->tuber->Pc;
  dbcultivo->numreg++;
  dbcultivo->saveAllParameters(dbcultivo->DBName);
  Application->MessageBox("the parameters were added to the database !!!", "Successful!", MB_OK);
  }
}
//---------------------------------------------------------------------------
void TfrmCalcParam::GuardarDatos()
{
   cond->crop->plant->fcl=edMaxgc->Text.ToDouble();
   cond->crop->plant->F0=edtm->Text.ToDouble();
   cond->crop->plant->R0=edte->Text.ToDouble();
   cond->crop->tuber->M=edA->Text.ToDouble();
   cond->crop->tuber->A=edtu->Text.ToDouble();
   cond->crop->tuber->b=edb->Text.ToDouble();
   cond->crop->tuber->DMCont=edDMC->Text.ToDouble();
   cond->crop->plant->LUE=edRUE->Text.ToDouble();
   cond->crop->tuber->Tcr=-3;
   cond->crop->tuber->Tld=-5;
   cond->crop->tuber->Trg=-8;
   cond->crop->plant->EDay=edEmDay->Text.ToInt();
   cond->crop->tuber->w=edPhotoSen->Text.ToDouble();
   cond->crop->tuber->Pc=edPhotoCrit->Text.ToDouble();
}
//---------------------------------------------------------------------------
//
//      El usuario puede guardar sus inputs y parametros en archivo texto
//
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParam::butSaveParClick(TObject *Sender)
{
  bool exitoso=false;
  exitoso=Validate();
// chequear si se ha ingresado nombre al cultivo
  if(exitoso)
  {
  AnsiString nombre=edNameCrop->Text.Trim();
  int numcar=nombre.Length();
  if(numcar<=0)
  {
    exitoso=false;
    Application->MessageBox("Enter a name for the crop!", "Warning!", MB_OK);
    edNameCrop->SetFocus();

  }
  }
  if(exitoso)
  {
  GuardarDatos();
  AnsiString NomArchivo;
  bool exito=false;
  if(sdResult->Execute())
  {
    NomArchivo=sdResult->FileName;
    strcpy(cond->crop->cropname,edNameCrop->Text.c_str());
    exito=cond->crop->saveParameters(NomArchivo.c_str(),edcover1p->Text.ToInt(),edGrowthZero->Text.ToInt(),edGrowthZero2->Text.ToInt(),edPhotoSen->Text.ToDouble(),edPhotoCrit->Text.ToDouble());
    if(exito)
    {
      Application->MessageBox("Information about parameters was saved!", "Successful!", MB_OK);
    }
  }
  }
}
//---------------------------------------------------------------------------
//
//      El usuario puede guardar serie Thermal Time
//
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParam::butSaveTTClick(TObject *Sender)
{
  if(cond->climate->numtt>0)
  {
  AnsiString NomArchivo;
  bool exito=false;
  if(sdResult->Execute())
  {
    NomArchivo=sdResult->FileName;
    exito=cond->climate->saveTT(NomArchivo.c_str());
    if(exito)
    {
    Application->MessageBox("Information about Thermal time was saved!", "Successful!", MB_OK);
    }
  }
  }
  else
  {
    Application->MessageBox("There is not information about thermal time to save !", "Warning!", MB_OK);
  }
}
//---------------------------------------------------------------------------
//
// El usuario puede cerrar el formulario y hacer un restore a los datos de COND
//
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParam::cmdCancelClick(TObject *Sender)
{
//  delete condTemp;
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParam::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  restoreValues();
  Action=caFree;
}
//---------------------------------------------------------------------------
void TfrmCalcParam::restoreValues()
{
   cond->crop->plant->fcl=back_fcl;
   cond->crop->plant->F0=back_F0;
   cond->crop->plant->R0=back_R0;
   cond->crop->tuber->M=back_M;
   cond->crop->tuber->A=back_A;
   cond->crop->tuber->b=back_b;
   cond->crop->tuber->DMCont=back_DMCont;
   cond->crop->plant->LUE=back_LUE;
   cond->crop->plant->EDay=back_EDay;
   cond->crop->tuber->w=back_w;
   cond->crop->tuber->Pc=back_Pc;

   cond->time->YearStart=back_YearStart;
   cond->time->MonthStart=back_MonthStart;
   cond->time->DayStart=back_DayStart;
   cond->time->duration=back_duration;
   cond->time->repetitions=back_repetitions;
}
//---------------------------------------------------------------------------
//
// Otras funciones que ayudan a las funciones principales del formulario
//
//---------------------------------------------------------------------------
void TfrmCalcParam::ShowMessageError(int _cod)
{
  if(_cod==1)
  {
    Application->MessageBox("The value should be an integer, check your data!", "Warning!", MB_OK);
  }
  if(_cod==2)
  {
    Application->MessageBox("The value should be a real, check your data!", "Warning!", MB_OK);
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmCalcParam::cmdMinTempClick(TObject *Sender)
{
/*
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Minimun temperature");
  if(frm->ShowModal()==mrOk)
  {
    edMinTemp->Text=frm->ReturnInformation();
    strcpy(cond->climate->TitTMin, edMinTemp->Text.c_str());
    int numelem=cond->climate->GetColumnData(cond->climate->FileName,cond->climate->TitTMin,cond->climate->MinTemp);
    if(numelem==0) numelem=cond->climate->GetColumnDataFromCSVFile(cond->climate->FileName,cond->climate->TitTMin,cond->climate->MinTemp);
    sgClimate->RowCount=cond->climate->RecNum+2;
    for(int i=1;i<=cond->climate->RecNum;i++)
    {
     sgClimate->Cells[4][i+1]=cond->climate->MinTemp[i-1];
    }
  }
  delete frm;
*/
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParam::cmdMaxTempClick(TObject *Sender)
{
/*
  TfrmCampo *frm = new TfrmCampo(this);
  frm->EnterInformation(List,num,"Maximun temperature");
  if(frm->ShowModal()==mrOk)
  {
    edMaxTemp->Text=frm->ReturnInformation();
    strcpy(cond->climate->TitTMax, edMaxTemp->Text.c_str());
    int numelem=cond->climate->GetColumnData(cond->climate->FileName,cond->climate->TitTMax,cond->climate->MaxTemp);
    if(numelem==0)numelem=cond->climate->GetColumnDataFromCSVFile(cond->climate->FileName,cond->climate->TitTMax,cond->climate->MaxTemp);
    sgClimate->RowCount=cond->climate->RecNum+2;
    for(int i=1;i<=cond->climate->RecNum;i++)
    {
     sgClimate->Cells[5][i+1]=cond->climate->MaxTemp[i-1];
    }
  }
  delete frm;
*/
}
//---------------------------------------------------------------------------

void __fastcall TfrmCalcParam::sgClimateMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
TPoint RClkPoint;
if (Button != mbRight)
  return;
sgClimate->MouseToCell (X, Y, RClkCol, RClkRow);
//if ((RClkCol < 0) || (RClkRow < 0))
//{
//    return;
//}
if ((RClkCol < sgClimate->FixedCols) || (RClkRow < sgClimate->FixedRows))
{
  //  The user clicked on a fixed cell.
  //  Hide the convert items.
    SetPlantingDate->Visible = false;
    SetHarvestDate->Visible = false;
}
else
{
    SetPlantingDate->Visible = true;
    SetHarvestDate->Visible = true;
}
RClkPoint = sgClimate->ClientToScreen(Point (X, Y));
GridMenu->Popup (RClkPoint.x, RClkPoint.y);
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParam::SetPlantingDateClick(TObject *Sender)
{
if(!Mensajes()) return;
AnsiString fecha=sgClimate->Cells[2][RClkRow]+"/"+sgClimate->Cells[1][RClkRow]+"/"+sgClimate->Cells[3][RClkRow];
dtpPlantingDate->Date=StrToDate(fecha);
AnsiString mensaje="You have selected "+fecha+" like 'Planting date'";
Application->MessageBox(mensaje.c_str(), "Done!", MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParam::SetHarvestDateClick(TObject *Sender)
{
if(!Mensajes()) return;
AnsiString fecha=sgClimate->Cells[2][RClkRow]+"/"+sgClimate->Cells[1][RClkRow]+"/"+sgClimate->Cells[3][RClkRow];
dtpHarvestDate->Date=StrToDate(fecha);
AnsiString mensaje="You have selected "+fecha+" like 'Harvest date'";
Application->MessageBox(mensaje.c_str(), "Done!", MB_OK);
}
//---------------------------------------------------------------------------
bool TfrmCalcParam::Mensajes()
{
if(sgClimate->Cells[1][RClkRow]=="")
{
  AnsiString mensaje="There is no information in the column of Day, load the information !!!";
  Application->MessageBox(mensaje.c_str(), "Warning!", MB_OK);
  return false;
}
if(sgClimate->Cells[2][RClkRow]=="")
{
  AnsiString mensaje="There is no information in the column of Month, load the information !!!";
  Application->MessageBox(mensaje.c_str(), "Warning!", MB_OK);
  return false;
}
if(sgClimate->Cells[3][RClkRow]=="")
{
  AnsiString mensaje="There is no information in the column of Year, load the information !!!";
  Application->MessageBox(mensaje.c_str(), "Warning!", MB_OK);
  return false;
}
return true;
}
//---------------------------------------------------------------------------
double TfrmCalcParam::round(double number)
{
    return number < 0.0 ? ceil(number - 0.5) : floor(number + 0.5);
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParam::tb_tuChange(TObject *Sender)
{
  bool error=false;
  if(hacer)
  {
  bool exitoso=false;
  exitoso=Validate();
  if(exitoso)
  {
double Wmax=edMaxgc->Text.ToDouble();
double A=edA->Text.ToDouble();
int te=edte->Text.ToInt();
int tm=edtm->Text.ToInt();
int Tu=edtu->Text.ToInt();
int b=edb->Text.ToInt();
simular();
GraficoCanopyCover(Wmax,te,tm,Tu,b,A,&error);
   if(error)
   {
     butProcess->Enabled=true;
     Application->MessageBox("There were a error during the process, please check your data !!!", "Warning!", MB_OK);
     return;
   }

Graficof1f2(Wmax,te,tm,Tu,b,A,&error);
   if(error)
   {
     butProcess->Enabled=true;
     Application->MessageBox("There were a error during the process, please check your data !!!", "Warning!", MB_OK);
     return;
   }

edtu->Text=dato_tu+tb_tu->Position;
}
  else
  {
    hacer=false;
  }
}
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParam::tb_bChange(TObject *Sender)
{
  bool error=false;
  if(hacer)
  {
  bool exitoso=false;
  exitoso=Validate();
  if(exitoso)
  {
double Wmax=edMaxgc->Text.ToDouble();
double A=edA->Text.ToDouble();
int te=edte->Text.ToInt();
int tm=edtm->Text.ToInt();
int Tu=edtu->Text.ToInt();
int b=edb->Text.ToInt();
simular();
GraficoCanopyCover(Wmax,te,tm,Tu,b,A,&error);
   if(error)
   {
     butProcess->Enabled=true;
     Application->MessageBox("There were a error during the process, please check your data !!!", "Warning!", MB_OK);
     return;
   }

Graficof1f2(Wmax,te,tm,Tu,b,A,&error);
   if(error)
   {
     butProcess->Enabled=true;
     Application->MessageBox("There were a error during the process, please check your data !!!", "Warning!", MB_OK);
     return;
   }

edb->Text=dato_b+tb_b->Position;
}
  else
  {
    hacer=false;
  }
}
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParam::tb_teChange(TObject *Sender)
{
  bool error=false;
  if(hacer)
  {
  bool exitoso=false;
  exitoso=Validate();
  if(exitoso)
  {
double Wmax=edMaxgc->Text.ToDouble();
double A=edA->Text.ToDouble();
int te=edte->Text.ToInt();
int tm=edtm->Text.ToInt();
int Tu=edtu->Text.ToInt();
int b=edb->Text.ToInt();
simular();
GraficoCanopyCover(Wmax,te,tm,Tu,b,A,&error);
   if(error)
   {
     butProcess->Enabled=true;
     Application->MessageBox("There were a error during the process, please check your data !!!", "Warning!", MB_OK);
     return;
   }

Graficof1f2(Wmax,te,tm,Tu,b,A,&error);
   if(error)
   {
     butProcess->Enabled=true;
     Application->MessageBox("There were a error during the process, please check your data !!!", "Warning!", MB_OK);
     return;
   }

edte->Text=dato_te+tb_te->Position;
}
  else
  {
    hacer=false;
  }
}
}
//---------------------------------------------------------------------------

void __fastcall TfrmCalcParam::tb_tmChange(TObject *Sender)
{
  bool error=false;
  if(hacer)
  {
  bool exitoso=false;
  exitoso=Validate();
  if(exitoso)
  {
double Wmax=edMaxgc->Text.ToDouble();
double A=edA->Text.ToDouble();
int te=edte->Text.ToInt();
int tm=edtm->Text.ToInt();
int Tu=edtu->Text.ToInt();
int b=edb->Text.ToInt();
simular();
GraficoCanopyCover(Wmax,te,tm,Tu,b,A,&error);
   if(error)
   {
     butProcess->Enabled=true;
     Application->MessageBox("There were a error during the process, please check your data !!!", "Warning!", MB_OK);
     return;
   }

Graficof1f2(Wmax,te,tm,Tu,b,A,&error);
   if(error)
   {
     butProcess->Enabled=true;
     Application->MessageBox("There were a error during the process, please check your data !!!", "Warning!", MB_OK);
     return;
   }

edtm->Text=dato_tm+tb_tm->Position;
}
  else
  {
    hacer=false;
  }
}
}
//---------------------------------------------------------------------------
bool TfrmCalcParam::Validate()
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
//--------------------------------------------------------------------------
TEdit* TfrmCalcParam::FindDataError(int* _cod)
{
  double datod=0.0;
  int datoi=0;
  try
  {
    datoi=edEmDay->Text.ToInt();
  }
  catch(...)
  {
    *_cod=1; // 1: No es un valor entero
    return edEmDay;
  }
  try
  {
    datod=edMaxgc->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edMaxgc;
  }
  try
  {
    datod=edA->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edA;
  }
  try
  {
    datoi=edcover1p->Text.ToInt();
  }
  catch(...)
  {
    *_cod=1; // 1: No es un valor entero
    return edcover1p;
  }
  try
  {
    datoi=edGrowthZero->Text.ToInt();
  }
  catch(...)
  {
    *_cod=1; // 1: No es un valor entero
    return edGrowthZero;
  }
  try
  {
    datoi=edGrowthZero2->Text.ToInt();
  }
  catch(...)
  {
    *_cod=1; // 1: No es un valor entero
    return edGrowthZero2;
  }
  try
  {
    datod=edRUE->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edRUE;
  }
  try
  {
    datod=edDMC->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edDMC;
  }
  try
  {
    datoi=edtu->Text.ToInt();
  }
  catch(...)
  {
    *_cod=1; // 1: No es un valor entero
    return edtu;
  }
  try
  {
    datoi=edb->Text.ToInt();
  }
  catch(...)
  {
    *_cod=1; // 1: No es un valor entero
    return edb;
  }
  try
  {
    datoi=edte->Text.ToInt();
  }
  catch(...)
  {
    *_cod=1; // 1: No es un valor entero
    return edte;
  }
  try
  {
    datoi=edtm->Text.ToInt();
  }
  catch(...)
  {
    *_cod=1; // 1: No es un valor entero
    return edtm;
  }
  try
  {
    datod=edPhotoSen->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edPhotoSen;
  }
  try
  {
    datod=edPhotoCrit->Text.ToDouble();
  }
  catch(...)
  {
    *_cod=2; // 2: No es un valor real
    return edPhotoCrit;
  }

  return edEmDay;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParam::tb_tuEnter(TObject *Sender)
{
  hacer=true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmCalcParam::tb_bEnter(TObject *Sender)
{
  hacer=true;
        
}
//---------------------------------------------------------------------------

void __fastcall TfrmCalcParam::tb_teEnter(TObject *Sender)
{
  hacer=true;
        
}
//---------------------------------------------------------------------------

void __fastcall TfrmCalcParam::tb_tmEnter(TObject *Sender)
{
  hacer=true;
        
}
//---------------------------------------------------------------------------
void __fastcall TfrmCalcParam::edtuKeyPress(TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
{
 butDoSimulationClick(this);
}
}
//---------------------------------------------------------------------------


void __fastcall TfrmCalcParam::edbKeyPress(TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
{
 butDoSimulationClick(this);
}        
}
//---------------------------------------------------------------------------

void __fastcall TfrmCalcParam::edteKeyPress(TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
{
 butDoSimulationClick(this);
}        
}
//---------------------------------------------------------------------------

void __fastcall TfrmCalcParam::edtmKeyPress(TObject *Sender, char &Key)
{
if(Key==VK_RETURN)
{
 butDoSimulationClick(this);
}        
}
//---------------------------------------------------------------------------


void __fastcall TfrmCalcParam::chkbtuberinitClick(TObject *Sender)
{
edtuberinit->Enabled=chkbtuberinit->Checked;
}
//---------------------------------------------------------------------------

