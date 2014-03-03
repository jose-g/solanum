//---------------------------------------------------------------------------
#ifndef UCalcET0H
#define UCalcET0H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include "Climate.h"
#include "FileUtility.h"
//---------------------------------------------------------------------------
class TfrmCalcET0 : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *cmdCancel;
        TBitBtn *cmdApply;
        TEdit *Edit2;
        TEdit *edPathFile;
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
        TEdit *Edit3;
        TEdit *edSunshine;
        TSpeedButton *cmdSunshine;
        TRichEdit *RichEdit14;
        TEdit *edLatDegree;
        TRichEdit *RichEdit17;
        TRichEdit *RichEdit1;
        TEdit *edLatMinutes;
        TRichEdit *RichEdit2;
        TRichEdit *RichEdit3;
        TEdit *edLatSeconds;
        TRichEdit *RichEdit4;
        TRichEdit *RichEdit5;
        TComboBox *cbHemisphere;
        TRichEdit *RichEdit6;
        TEdit *edz;
        TRichEdit *RichEdit7;
        TRichEdit *RichEdit8;
        TEdit *edG;
        TRichEdit *RichEdit9;
        TRichEdit *RichEdit10;
        TEdit *edAlbedo;
        TRichEdit *RichEdit11;
        TRichEdit *RichEdit12;
        TComboBox *cbSelect_Wind_cat;
        TEdit *Edit9;
        TComboBox *cbThermalCond;
        TRichEdit *RichEdit13;
        TComboBox *cbSelect_AP;
        TButton *butGenerateET0;
        TLabel *Label1;
        TLabel *Label2;
        TCheckBox *chbSunshine;
        TButton *butSaveET0;
        TSaveDialog *sdResult;
        TGroupBox *gbCoeff;
        TCheckBox *chbCoeff;
        TEdit *Edit1;
        TEdit *Edit4;
        TEdit *edCoeffA;
        TEdit *edCoeffB;
        void __fastcall cmdApplyClick(TObject *Sender);
        void __fastcall cmdCancelClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall cmdMinTempClick(TObject *Sender);
        void __fastcall cmdMaxTempClick(TObject *Sender);
        void __fastcall cmdRadClick(TObject *Sender);
        void __fastcall cmdSunshineClick(TObject *Sender);
        void __fastcall butGenerateET0Click(TObject *Sender);
        void __fastcall chbSunshineClick(TObject *Sender);
        void __fastcall butSaveET0Click(TObject *Sender);
        void __fastcall chbCoeffClick(TObject *Sender);
private:	// User declarations
        bool Validate();
        TEdit* FindDataError(int*);
        void ShowMessageError(int);
        void PutValuesOnForm();
        void SaveData();
        ClimateFile *cond;
        ClimateFile *condTemp;
        char* List[100];
        int num;
        void CopyValuesToCondTemp();
//        PotatoClimateType condSource;
public:		// User declarations
        __fastcall TfrmCalcET0(TComponent* Owner);
        void EnterInformation(ClimateFile*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCalcET0 *frmCalcET0;
//---------------------------------------------------------------------------
#endif

