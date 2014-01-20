//---------------------------------------------------------------------------

#ifndef UImportCropParameterH
#define UImportCropParameterH
//---------------------------------------------------------------------------
#include "clases\Crop.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TfrmImportCropParameter : public TForm
{
__published:	// IDE-managed Components
        TCheckListBox *chkLB;
        TButton *butOpen;
        TButton *butImport;
        TOpenDialog *odAbrir;
        TSaveDialog *sdResult;
        TCheckBox *chkbSelect;
        void __fastcall butImportClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall butOpenClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall chkbSelectClick(TObject *Sender);
private:	// User declarations
        DBCultivo* dbcultivo;
        DBCultivo* dbcultivoTemp;
        int clave;
public:		// User declarations
        void EnterInformation(DBCultivo*);
        bool hizo;
        __fastcall TfrmImportCropParameter(int);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmImportCropParameter *frmImportCropParameter;
//---------------------------------------------------------------------------
#endif
