//---------------------------------------------------------------------------

#ifndef UReportTXTMenuH
#define UReportTXTMenuH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include "Report.h"
//---------------------------------------------------------------------------
class TfrmReportTXTMenu : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox2;
        TSpeedButton *SpeedButton4;
        TRichEdit *RichEdit2;
        TRichEdit *RichEdit1;
        TGroupBox *GroupBox1;
        TRichEdit *RichEdit3;
        TRichEdit *RichEdit4;
        TButton *Button1;
        TButton *Button2;
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
        Report *cond;
public:		// User declarations
        __fastcall TfrmReportTXTMenu(TComponent* Owner);
        void EnterInformation(Report*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmReportTXTMenu *frmReportTXTMenu;
//---------------------------------------------------------------------------
#endif
