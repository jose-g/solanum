//---------------------------------------------------------------------------

#ifndef UGraphCIinP_MYAH
#define UGraphCIinP_MYAH
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
#include "Simulation.h"
//---------------------------------------------------------------------------
class TfrmGraphCIinP_MYA : public TForm
{
__published:	// IDE-managed Components
        TTeeCommander *tc1;
        TChart *tch1;
        TPointSeries *Series1;
        TLineSeries *Series2;
        TLineSeries *Series3;
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
        TBoxSeries* box[2];
        Simulation *sim;
        int kind;
public:		// User declarations
        __fastcall TfrmGraphCIinP_MYA(TComponent* Owner);
        void EnterInformation(Simulation*,AnsiString,int);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGraphCIinP_MYA *frmGraphCIinP_MYA;
//---------------------------------------------------------------------------
#endif
