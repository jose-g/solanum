//---------------------------------------------------------------------------

#ifndef UGraphBoxPlotH
#define UGraphBoxPlotH
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
class TfrmGraphBoxPlot : public TForm
{
__published:	// IDE-managed Components
        TTeeCommander *tc1;
        TChart *tch1;
        TLabel *Label8;
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
        char* filename;
        TBoxSeries* box[100];
public:		// User declarations
        __fastcall TfrmGraphBoxPlot(TComponent* Owner);
        void EnterInformation(char*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGraphBoxPlot *frmGraphBoxPlot;
//---------------------------------------------------------------------------
#endif
