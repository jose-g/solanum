//---------------------------------------------------------------------------

#ifndef UGraph2PGH
#define UGraph2PGH
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
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TfrmGraph2PG : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox2;
        TSpeedButton *SpeedButton4;
        TRichEdit *RichEdit2;
        TRichEdit *RichEdit1;
        TTeeCommander *tc1;
        TChart *tch1;
        TLineSeries *Series1;
        TSeriesTextSource *SeriesTextSource1;
        TGroupBox *GroupBox1;
        TRichEdit *RichEdit7;
        TRichEdit *RichEdit6;
        TCheckBox *chbTotalDM;
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
        TLineSeries *Series2;
        TLineSeries *Series3;
        TGroupBox *GroupBox3;
        TSpeedButton *sbSave;
        TRichEdit *RichEdit3;
        TRichEdit *RichEdit4;
        TSaveDialog *sdSave;
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall chbTotalDMClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall sbSaveClick(TObject *Sender);
private:	// User declarations
        char* filename;
public:		// User declarations
        __fastcall TfrmGraph2PG(TComponent* Owner);
        void EnterInformation(char*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGraph2PG *frmGraph2PG;
//---------------------------------------------------------------------------
#endif
