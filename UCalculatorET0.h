//---------------------------------------------------------------------------

#ifndef UCalculatorET0H
#define UCalculatorET0H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "ManageDataPotato.h"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TfrmCalculatorET0 : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *cmdCancel;
        TBitBtn *cmdApply;
        void __fastcall cmdCancelClick(TObject *Sender);
        void __fastcall cmdApplyClick(TObject *Sender);
private:	// User declarations
        ManageDataPotato *cond;
        bool Validate();
        TEdit* FindDataError(int*);
        void ShowMessageError(int);
        void SaveData();
public:		// User declarations
        __fastcall TfrmCalculatorET0(TComponent* Owner);
        void EnterInformation(ManageDataPotato*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCalculatorET0 *frmCalculatorET0;
//---------------------------------------------------------------------------
#endif
