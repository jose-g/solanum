//---------------------------------------------------------------------------
#ifndef UClimateH
#define UClimateH
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
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TfrmClimate : public TForm
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
        TEdit *Edit7;
        TEdit *Edit8;
        TEdit *edMinTemp;
        TEdit *edMaxTemp;
        TEdit *edPrecip;
        TEdit *edRad;
        TSpeedButton *cmdMinTemp;
        TSpeedButton *cmdMaxTemp;
        TSpeedButton *cmdPrecip;
        TSpeedButton *cmdRadiation;
        TOpenDialog *odClimate;
        TEdit *Edit1;
        TEdit *edET;
        TSpeedButton *cmdET0;
        TEdit *Edit4;
        TEdit *edIrri;
        TSpeedButton *cmdIrrigation;
        TEdit *Edit10;
        TEdit *edSoilTemp;
        TSpeedButton *cmdSoil;
        TEdit *Edit3;
        TEdit *edDay;
        TSpeedButton *cmdDay;
        TEdit *Edit11;
        TEdit *edMonth;
        TSpeedButton *cmdMonth;
        TEdit *Edit13;
        TEdit *edYear;
        TSpeedButton *cmdYear;
        void __fastcall cmdApplyClick(TObject *Sender);
        void __fastcall cmdCancelClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall cmdOpenClimateClick(TObject *Sender);
        void __fastcall cmdMinTempClick(TObject *Sender);
        void __fastcall cmdMaxTempClick(TObject *Sender);
        void __fastcall cmdPrecipClick(TObject *Sender);
        void __fastcall cmdRadiationClick(TObject *Sender);
        void __fastcall cmdET0Click(TObject *Sender);
        void __fastcall cmdIrrigationClick(TObject *Sender);
        void __fastcall cmdSoilClick(TObject *Sender);
        void __fastcall cmdDayClick(TObject *Sender);
        void __fastcall cmdMonthClick(TObject *Sender);
        void __fastcall cmdYearClick(TObject *Sender);
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
        double round(double);
        int RClkCol, RClkRow;
        bool Mensajes();
public:		// User declarations
        __fastcall TfrmClimate(TComponent* Owner);
        __fastcall TfrmClimate(TComponent* Owner,ClimateFile*);
        void EnterInformation(ClimateFile*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmClimate *frmClimate;
//---------------------------------------------------------------------------
#endif

