//---------------------------------------------------------------------------

#ifndef UReportTXTH
#define UReportTXTH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TfrmReportTXT : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox2;
        TSpeedButton *SpeedButton4;
        TRichEdit *RichEdit2;
        TRichEdit *RichEdit1;
        TMemo *memReport;
        TSaveDialog *SaveDialog1;
        TGroupBox *GroupBox3;
        TSpeedButton *sbSave;
        TRichEdit *RichEdit3;
        TRichEdit *RichEdit4;
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall sbSaveClick(TObject *Sender);
private:	// User declarations
        char* filename;
public:		// User declarations
        __fastcall TfrmReportTXT(TComponent* Owner);
        void EnterInformation(char*,AnsiString);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmReportTXT *frmReportTXT;
//---------------------------------------------------------------------------
#endif
