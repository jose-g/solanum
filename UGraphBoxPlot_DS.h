//---------------------------------------------------------------------------

#ifndef UGraphBoxPlot_DSH
#define UGraphBoxPlot_DSH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "TeeBoxPlot.hpp"
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include "TeeComma.hpp"
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmGraphBoxPlot_DS : public TForm
{
__published:	// IDE-managed Components
        TTeeCommander *tc1;
        TChart *tch1;
        TLabel *Label8;
        TTeeCommander *tc2;
        TChart *tch2;
        TLabel *Label1;
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
        char* filename;
        TBoxSeries* box[100];
        TBoxSeries* box2[100];
        void populateWLGraph();
        void populatePGGraph();
public:		// User declarations
        __fastcall TfrmGraphBoxPlot_DS(TComponent* Owner);
        void EnterInformation(char*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGraphBoxPlot_DS *frmGraphBoxPlot_DS;
//---------------------------------------------------------------------------
#endif
