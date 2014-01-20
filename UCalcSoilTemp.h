//---------------------------------------------------------------------------
#ifndef UCalcSoilTempH
#define UCalcSoilTempH
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
//---------------------------------------------------------------------------
class TfrmCalcSoilTemp : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *cmdCancel;
        TBitBtn *cmdApply;
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
        TRichEdit *RichEdit36;
        TComboBox *cbSoilTexture;
        TRichEdit *RichEdit5;
        TEdit *edSoilDepth;
        TRichEdit *RichEdit6;
        TRichEdit *RichEdit8;
        TEdit *edMaxDepth;
        TRichEdit *RichEdit9;
        TButton *butGenSoilTemp;
        TLabel *Label1;
        TLabel *Label2;
        TSaveDialog *sdResult;
        TButton *butSaveET0;
        void __fastcall cmdApplyClick(TObject *Sender);
        void __fastcall cmdCancelClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall cmdMinTempClick(TObject *Sender);
        void __fastcall cmdMaxTempClick(TObject *Sender);
        void __fastcall butGenSoilTempClick(TObject *Sender);
        void __fastcall butSaveET0Click(TObject *Sender);
private:	// User declarations
        bool Validate();
        TEdit* FindDataError(int*);
        void ShowMessageError(int);
        void PutValuesOnForm();
        void SaveData();
        ManageDataPotato *cond;
        ManageDataPotato *condTemp;
        void CopyValuesToCondTemp();
        char* List[100];
        int num;
//        PotatoClimateType condSource;
public:		// User declarations
        __fastcall TfrmCalcSoilTemp(TComponent* Owner);
        void EnterInformation(ManageDataPotato*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCalcSoilTemp *frmCalcSoilTemp;
//---------------------------------------------------------------------------
#endif

