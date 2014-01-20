//---------------------------------------------------------------------------
#ifndef USoilDSH
#define USoilDSH
//---------------------------------------------------------------------------
#include "Soil.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmSoilDS : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *cmdCancel;
        TBitBtn *cmdApply;
        TComboBox *cbSoilTexture;
        TRichEdit *RichEdit36;
        TRichEdit *RichEdit1;
        TEdit *edMoisture;
        TRichEdit *RichEdit2;
        TRichEdit *RichEdit5;
        TEdit *edSoilDepth;
        TRichEdit *RichEdit6;
        void __fastcall cmdCancelClick(TObject *Sender);
        void __fastcall cmdApplyClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
        Soil *cond;
        bool Validate();
        TEdit* FindDataError(int*);
        void ShowMessageError(int);
        void SaveData();
        void PutValuesOnForm();
        int ItemSelected;
public:		// User declarations
        __fastcall TfrmSoilDS(TComponent* Owner);
        void EnterInformation(Soil*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSoilDS *frmSoilDS;
//---------------------------------------------------------------------------
#endif
