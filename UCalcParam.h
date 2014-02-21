//---------------------------------------------------------------------------
#ifndef UCalcParamH
#define UCalcParamH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>

#include "ManageDataPotato.h"
#include "FileUtility.h"
#include <Menus.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
#include "TeeComma.hpp"
//---------------------------------------------------------------------------
class TfrmCalcParam : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *cmdCancel;
        TEdit *Edit2;
        TEdit *edPathFile;
        TStringGrid *sgClimate;
        TEdit *Edit5;
        TEdit *Edit6;
        TEdit *edMinTemp;
        TEdit *edMaxTemp;
        TSpeedButton *cmdMinTemp;
        TSpeedButton *cmdMaxTemp;
        TOpenDialog *odClimate;
        TButton *butProcess;
        TLabel *Label1;
        TLabel *Label2;
        TSaveDialog *sdResult;
        TButton *butSaveTT;
        TEdit *Edit9;
        TEdit *Edit12;
        TDateTimePicker *dtpHarvestDate;
        TDateTimePicker *dtpPlantingDate;
        TStringGrid *sgClimateSel;
        TButton *butSelectData;
        TPopupMenu *GridMenu;
        TMenuItem *SetPlantingDate;
        TMenuItem *SetHarvestDate;
        TChart *tchCanopy;
        TChart *tchf1f2;
        TGroupBox *GroupBox1;
        TEdit *Edit3;
        TEdit *edEmDay;
        TRichEdit *RichEdit19;
        TRichEdit *RichEdit8;
        TEdit *edMaxgc;
        TEdit *Edit8;
        TRichEdit *RichEdit9;
        TEdit *edGrowthZero;
        TEdit *edcover1p;
        TRichEdit *RichEdit10;
        TEdit *edA;
        TRichEdit *RichEdit16;
        TEdit *edtu;
        TRichEdit *RichEdit24;
        TRichEdit *RichEdit11;
        TEdit *edb;
        TRichEdit *RichEdit3;
        TEdit *edte;
        TEdit *Edit15;
        TRichEdit *RichEdit2;
        TEdit *edtm;
        TEdit *Edit1;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLineSeries *Series3;
        TLineSeries *Series1;
        TLineSeries *Series2;
        TLineSeries *Series4;
        TGroupBox *GroupBox2;
        TEdit *Edit7;
        TEdit *Edit10;
        TEdit *Edit13;
        TEdit *Edit14;
        TRichEdit *RichEdit1;
        TRichEdit *RichEdit4;
        TButton *butSavePar;
        TButton *butAddParDB;
        TEdit *edNameCrop;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TButton *butDoSimulation;
        TRichEdit *RichEdit7;
        TLabel *Label13;
        TEdit *edRUE;
        TRichEdit *RichEdit6;
        TLabel *Label14;
        TEdit *edDMC;
        TEdit *Edit17;
        TChart *tch1;
        TLineSeries *LineSeries1;
        TTrackBar *tb_tu;
        TTeeCommander *tc1;
        TTrackBar *tb_b;
        TTrackBar *tb_te;
        TTrackBar *tb_tm;
        TRichEdit *RichEdit12;
        TEdit *edGrowthZero2;
        TRichEdit *RichEdit13;
        TLabel *Label15;
        TEdit *Edit4;
        TEdit *Edit11;
        TRichEdit *RichEdit5;
        TEdit *Edit16;
        TEdit *edtuberinit;
        TCheckBox *chkbtuberinit;
        TRichEdit *RichEdit14;
        TRichEdit *RichEdit25;
        TEdit *edPhotoSen;
        TRichEdit *RichEdit26;
        TRichEdit *RichEdit27;
        TEdit *edPhotoCrit;
        TRichEdit *RichEdit28;
        void __fastcall cmdCancelClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall cmdMinTempClick(TObject *Sender);
        void __fastcall cmdMaxTempClick(TObject *Sender);
        void __fastcall butProcessClick(TObject *Sender);
        void __fastcall butSaveTTClick(TObject *Sender);
        void __fastcall sgClimateMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall SetPlantingDateClick(TObject *Sender);
        void __fastcall SetHarvestDateClick(TObject *Sender);
        void __fastcall butSelectDataClick(TObject *Sender);
        void __fastcall butSaveParClick(TObject *Sender);
        void __fastcall butAddParDBClick(TObject *Sender);
        void __fastcall butDoSimulationClick(TObject *Sender);
        void __fastcall tb_tuChange(TObject *Sender);
        void __fastcall tb_bChange(TObject *Sender);
        void __fastcall tb_teChange(TObject *Sender);
        void __fastcall tb_tmChange(TObject *Sender);
        void __fastcall tb_tuEnter(TObject *Sender);
        void __fastcall tb_bEnter(TObject *Sender);
        void __fastcall tb_teEnter(TObject *Sender);
        void __fastcall tb_tmEnter(TObject *Sender);
        void __fastcall edtuKeyPress(TObject *Sender, char &Key);
        void __fastcall edbKeyPress(TObject *Sender, char &Key);
        void __fastcall edteKeyPress(TObject *Sender, char &Key);
        void __fastcall edtmKeyPress(TObject *Sender, char &Key);
        void __fastcall chkbtuberinitClick(TObject *Sender);
private:	// User declarations
        bool Validate();
        TEdit* FindDataError(int*);
        void ShowMessageError(int);
        void PutValuesOnForm();
        void SaveData();
        ManageDataPotato *cond;
        ManageDataPotato *condTemp;
        void backup_values();
        char* List[100];
        int num;
        bool Mensajes();
        int RClkCol, RClkRow;
        void InicializarsgClimateSel();
        void InicializarsgClimate();
        double round(double);
        double GetMedian(double*,int);
        double BetaFunction(double*,int*,int,double,int,double,double*,bool*);
        double thermalDAP1(double*,int*,double,int,bool*);
        double thermalDAP2(double*,int*,double,int,bool*);
        void leastSqrRegression(struct myData*,int,bool*);
        double slope;    //slope of regression line
        double y_intercept; //y intercept of regression line
        double Fx1(double,double,double,double,bool*);
        double bisection(double,double,double,double,double,bool*);
        double GompertzFunction(double*,double,double,double,double*,int*,int,bool*);
        void GraficoCanopyCover(double,double,double,double,double,double,bool*);
        void Graficof1f2(double,double,double,double,double,double,bool*);
        int pdDay,pdMonth,pdYear;
        int hdDay,hdMonth,hdYear;
        void restoreValues();
        void simular();
        void GuardarDatos();
        DBCultivo* dbcultivo;
        int dato_tu;
        int dato_b;
        int dato_te;
        int dato_tm;
        bool hacer;
        double val_mayor;
        double val_minimo;

   double back_fcl;
   double back_F0;
   double back_R0;
   double back_M;
   double back_A;
   double back_b;
   double back_DMCont;
   double back_LUE;
   double back_w;
   double back_Pc;
   int back_EDay;

   int back_YearStart;
   int back_MonthStart;
   int back_DayStart;
   int back_duration;
   int back_repetitions;

public:		// User declarations
        __fastcall TfrmCalcParam(TComponent* Owner);
        void EnterInformation(ManageDataPotato*,DBCultivo*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCalcParam *frmCalcParam;
//---------------------------------------------------------------------------
#endif

