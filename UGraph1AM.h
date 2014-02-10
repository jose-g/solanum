//---------------------------------------------------------------------------

#ifndef UGraph1AMH
#define UGraph1AMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include "TeeComma.hpp"
#include "TeeSeriesTextEd.hpp"
#include "TeeURL.hpp"
//---------------------------------------------------------------------------
class TfrmGraph1AM : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox2;
        TSpeedButton *SpeedButton4;
        TRichEdit *RichEdit2;
        TRichEdit *RichEdit1;
        TTeeCommander *tc1;
        TChart *tch1;
        TLineSeries *Series1;
        TLineSeries *Series2;
        TSeriesTextSource *SeriesTextSource1;
        TGroupBox *GroupBox1;
        TRichEdit *RichEdit7;
        TRichEdit *RichEdit6;
        TCheckBox *chbTotalDM;
        TCheckBox *chbTuberDM;
        TLabel *Label1;
        TEdit *Edit1;
        TLabel *Label2;
        TEdit *Edit2;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *Edit3;
        TLabel *Label3;
        TLabel *Label6;
        TEdit *Edit4;
        TLabel *Label7;
        TLabel *Label8;
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall chbTotalDMClick(TObject *Sender);
        void __fastcall chbTuberDMClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
        char* filename;
public:		// User declarations
        __fastcall TfrmGraph1AM(TComponent* Owner);
        void EnterInformation(char*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGraph1AM *frmGraph1AM;
//---------------------------------------------------------------------------
#endif
