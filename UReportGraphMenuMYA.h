//---------------------------------------------------------------------------

#ifndef UReportGraphMenuMYAH
#define UReportGraphMenuMYAH
//---------------------------------------------------------------------------
#include "ManageDataPotato.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmReportGraphMenuMYA : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox2;
        TSpeedButton *SpeedButton4;
        TRichEdit *RichEdit2;
        TRichEdit *RichEdit1;
        TGroupBox *GroupBox1;
        TRichEdit *RichEdit3;
        TRichEdit *RichEdit4;
        TButton *Button6;
        TButton *Button5;
        TButton *Button1;
        TButton *Button2;
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
        ManageDataPotato *cond;
public:		// User declarations
        __fastcall TfrmReportGraphMenuMYA(TComponent* Owner);
        void EnterInformation(ManageDataPotato*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmReportGraphMenuMYA *frmReportGraphMenuMYA;
//---------------------------------------------------------------------------
#endif
