//---------------------------------------------------------------------------

#ifndef UReportTableMYA_PGH
#define UReportTableMYA_PGH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <Grids.hpp>
#include "Simulation.h"
//---------------------------------------------------------------------------
class TfrmReportTableMYA_PG : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox2;
        TSpeedButton *SpeedButton4;
        TRichEdit *RichEdit2;
        TRichEdit *RichEdit1;
        TSaveDialog *SaveDialog1;
        TGroupBox *GroupBox3;
        TSpeedButton *sbSave;
        TRichEdit *RichEdit3;
        TRichEdit *RichEdit4;
        TStringGrid *sgFTY;
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall sbSaveClick(TObject *Sender);
        void __fastcall sgFTYDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
private:	// User declarations
        Simulation *sim;
public:		// User declarations
        __fastcall TfrmReportTableMYA_PG(TComponent* Owner);
        void EnterInformation(Simulation*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmReportTableMYA_PG *frmReportTableMYA_PG;
//---------------------------------------------------------------------------
#endif
