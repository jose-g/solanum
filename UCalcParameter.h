//---------------------------------------------------------------------------
#ifndef UCalcParameterH
#define UCalcParameterH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>

#include "clases\Climate.h"
#include "clases\FileUtility.h"
//---------------------------------------------------------------------------
class TfrmCalcParameter : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *cmdCancel;
        TBitBtn *cmdApply;
        TEdit *Edit2;
        TEdit *edPathFile;
        TSpeedButton *cmdOpenClimate;
        TStringGrid *sgClimate;
        TEdit *Edit5;
        TEdit *Edit6;
        TEdit *Edit8;
        TEdit *edMinTemp;
        TEdit *edMaxTemp;
        TEdit *edRad;
        TSpeedButton *cmdMinTemp;
        TSpeedButton *cmdMaxTemp;
        TSpeedButton *cmdRad;
        TOpenDialog *odClimate;
        TDateTimePicker *DateTimePicker1;
        TEdit *Edit4;
        TEdit *Edit1;
        TDateTimePicker *DateTimePicker2;
        TEdit *Edit3;
        TButton *butGetThermalTime;
        TEdit *edEmDay;
        TRichEdit *RichEdit19;
        void __fastcall cmdApplyClick(TObject *Sender);
        void __fastcall cmdCancelClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall cmdOpenClimateClick(TObject *Sender);
        void __fastcall cmdMinTempClick(TObject *Sender);
        void __fastcall cmdMaxTempClick(TObject *Sender);
        void __fastcall cmdRadClick(TObject *Sender);
        void __fastcall butGetThermalTimeClick(TObject *Sender);
private:	// User declarations
        bool Validate();
        TEdit* FindDataError(int*);
        void ShowMessageError(int);
        void PutValuesOnForm();
        void SaveData();
        ClimateFile *cond;
        ClimateFile *condTemp;
        char* List[100];
        char* ListTemp[100];
        int num;
        void CopyValuesToCondTemp();
        void Initialize();
        void GetDemo();
        double GetMedian(double*,int);
        double BetaFunction(double*,int*,int,double,int,double,double*);
        double thermalDAP1(double*,int*,double,int);
        double thermalDAP2(double*,int*,double,int);
        double round(double);
        void leastSqrRegression(struct myData*,int);
        double slope;    //slope of regression line
        double y_intercept; //y intercept of regression line
        double Fx1(double,double,double,double);
        double bisection(double,double,double,double,double);
        double GompertzFunction(double*,double,double,double,double*,int*,int);
public:		// User declarations
        __fastcall TfrmCalcParameter(TComponent* Owner);
        __fastcall TfrmCalcParameter(TComponent* Owner,ClimateFile*);
        void EnterInformation(ClimateFile*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCalcParameter *frmCalcParameter;
//---------------------------------------------------------------------------
#endif

