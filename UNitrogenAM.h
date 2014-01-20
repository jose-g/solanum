//---------------------------------------------------------------------------
#ifndef UNitrogenAMH
#define UNitrogenAMH
//---------------------------------------------------------------------------
#include "Nitrogen.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmNitrogenAM : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *cmdCancel;
        TBitBtn *cmdApply;
        TComboBox *cbOM;
        TRichEdit *RichEdit36;
        TRichEdit *RichEdit25;
        TEdit *edAmountFert;
        TRichEdit *RichEdit28;
        TRichEdit *RichEdit1;
        TComboBox *cbFert;
        TRichEdit *RichEdit2;
        TEdit *edFOMi;
        TRichEdit *RichEdit3;
        void __fastcall cmdCancelClick(TObject *Sender);
        void __fastcall cmdApplyClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
        Nitrogen *cond;
        bool Validate();
        TEdit* FindDataError(int*);
        void ShowMessageError(int);
        void SaveData();
        void PutValuesOnForm();
        int ItemSelected;
public:		// User declarations
        __fastcall TfrmNitrogenAM(TComponent* Owner);
        void EnterInformation(Nitrogen*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmNitrogenAM *frmNitrogenAM;
//---------------------------------------------------------------------------
#endif
