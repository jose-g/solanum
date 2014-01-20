//---------------------------------------------------------------------------
#ifndef USimulationTimeH
#define USimulationTimeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "ManageDataPotato.h"
//---------------------------------------------------------------------------
class TfrmSimulationTime : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TImage *Image1;
        TLabel *Label1;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *edTime;
        TComboBox *cbMonth;
        TBitBtn *cmdCancel;
        TBitBtn *cmdSimulate;
        TEdit *Edit3;
        TEdit *edDay;
        TEdit *Edit4;
        TEdit *edLocation;
        TEdit *Edit5;
        TComboBox *cbYear;
        TEdit *Edit6;
        TComboBox *cbThermal;
        TEdit *edNumSim;
        TEdit *Edit8;
        void __fastcall cmdSimulateClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
        bool Validate();
        TEdit* FindDataError(int*);
        void ShowMessageError(int);
        void PutValuesOnForm();
        void SaveData();
        ManageDataPotato *cond;
public:		// User declarations
        __fastcall TfrmSimulationTime(TComponent* Owner);
        void EnterInformation(ManageDataPotato*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSimulationTime *frmSimulationTime;
//---------------------------------------------------------------------------
#endif
