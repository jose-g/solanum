//---------------------------------------------------------------------------
#ifndef UCropParameterPGH
#define UCropParameterPGH
//---------------------------------------------------------------------------
#include "clases\Crop.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TfrmCropParameterPG : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *cmdCancel;
        TBitBtn *cmdApply;
        TGroupBox *GroupBox1;
        TRichEdit *RichEdit7;
        TEdit *Edit9;
        TEdit *Edit15;
        TEdit *Edit16;
        TEdit *Edit20;
        TEdit *edMaxgc;
        TEdit *edIniLig;
        TEdit *edIniGro;
        TEdit *edDurLeaf;
        TEdit *edThermal;
        TRichEdit *RichEdit2;
        TRichEdit *RichEdit3;
        TRichEdit *RichEdit4;
        TRichEdit *RichEdit5;
        TRichEdit *RichEdit6;
        TRichEdit *RichEdit8;
        TGroupBox *GroupBox2;
        TRichEdit *RichEdit9;
        TEdit *edMaxHI;
        TEdit *edAsyHI;
        TEdit *edSlopeHI;
        TEdit *edDMContent;
        TRichEdit *RichEdit10;
        TRichEdit *RichEdit11;
        TRichEdit *RichEdit12;
        TRichEdit *RichEdit15;
        TRichEdit *RichEdit16;
        TGroupBox *GroupBox3;
        TRichEdit *RichEdit14;
        TEdit *edAveLight;
        TRichEdit *RichEdit17;
        TRichEdit *RichEdit18;
        TEdit *edEmDay;
        TRichEdit *RichEdit19;
        TRichEdit *RichEdit24;
        TStringGrid *sgCrop;
        TButton *butAdd;
        TButton *butUpdate;
        TButton *butDelete;
        TButton *butExport;
        TRichEdit *RichEdit1;
        TEdit *edNameCrop;
        TSaveDialog *sdResult;
        TEdit *edTcr;
        TEdit *edTld;
        TEdit *edTrg;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TButton *butImport;
        TRichEdit *RichEdit13;
        TGroupBox *GroupBox4;
        TRichEdit *RichEdit20;
        TEdit *edPhotoSen;
        TRichEdit *RichEdit21;
        TRichEdit *RichEdit22;
        TEdit *edPhotoCrit;
        TRichEdit *RichEdit23;
        void __fastcall cmdCancelClick(TObject *Sender);
        void __fastcall cmdApplyClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall sgCropSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall butAddClick(TObject *Sender);
        void __fastcall butUpdateClick(TObject *Sender);
        void __fastcall butExportClick(TObject *Sender);
        void __fastcall butDeleteClick(TObject *Sender);
        void __fastcall butImportClick(TObject *Sender);
private:	// User declarations
        Crop *cond;
        bool Validate();
        TEdit* FindDataError(int*);
        void ShowMessageError(int);
        void SaveData();
        void PutValuesOnForm();
        int ItemSelected;
        DBCultivo* dbcultivo;
        void PoblarGrilla();
        void SaveInDB(int);
public:		// User declarations
        __fastcall TfrmCropParameterPG(TComponent* Owner);
        void EnterInformation(Crop*,DBCultivo*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCropParameterPG *frmCropParameterPG;
//---------------------------------------------------------------------------
#endif
