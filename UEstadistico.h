//---------------------------------------------------------------------------

#ifndef UEstadisticoH
#define UEstadisticoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "ManageDataPotato.h"
#include <Buttons.hpp>
#include <Grids.hpp>
#include "clases\FileUtility.h"
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TfrmEstadistico : public TForm
{
__published:	// IDE-managed Components
        TEdit *Edit2;
        TEdit *edPathFile;
        TSpeedButton *cmdOpenObserved;
        TEdit *Edit3;
        TEdit *Edit11;
        TEdit *edOCC;
        TSpeedButton *cmdOCC;
        TSpeedButton *cmdOFY;
        TEdit *edOFY;
        TStringGrid *sgFY;
        TStringGrid *sgCC;
        TButton *butShowStatistics;
        TLabel *Label1;
        TLabel *Label2;
        TOpenDialog *odObserved;
        TBitBtn *cmdCancel;
        TBitBtn *cmdApply;
        void __fastcall butShowStatisticsClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall cmdOpenObservedClick(TObject *Sender);
        void __fastcall cmdOFYClick(TObject *Sender);
        void __fastcall cmdOCCClick(TObject *Sender);
        void __fastcall cmdApplyClick(TObject *Sender);
        void __fastcall cmdCancelClick(TObject *Sender);
private:	// User declarations
        ManageDataPotato *cond;
        Simulation *condTemp;
        void Initialize();
        int num;
        char* List[100];
        char* ListTemp[100];
        void PutValuesOnForm();
        void CopyValuesToCondTemp();
        bool Validate();
        TEdit* FindDataError(int*);
        void ShowMessageError(int);
        void SaveData();
public:		// User declarations
        __fastcall TfrmEstadistico(TComponent* Owner);
        void EnterInformation(ManageDataPotato*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmEstadistico *frmEstadistico;
//---------------------------------------------------------------------------
#endif
