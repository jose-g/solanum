//---------------------------------------------------------------------------

#ifndef UReportGraphMenuTwoSeriesH
#define UReportGraphMenuTwoSeriesH
//---------------------------------------------------------------------------
#include "clases\Report.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmReportGraphMenuTwoSeries : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox2;
        TSpeedButton *SpeedButton4;
        TRichEdit *RichEdit2;
        TRichEdit *RichEdit1;
        TGroupBox *GroupBox1;
        TRichEdit *RichEdit3;
        TRichEdit *RichEdit4;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button6;
        TButton *Button5;
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
private:	// User declarations
        Report *cond;
        int IDmodel;
public:		// User declarations
        __fastcall TfrmReportGraphMenuTwoSeries(TComponent* Owner);
        void EnterInformation(Report*,int);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmReportGraphMenuTwoSeries *frmReportGraphMenuTwoSeries;
//---------------------------------------------------------------------------
#endif
