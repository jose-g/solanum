//---------------------------------------------------------------------------

#ifndef UGraphBoxPlotMYA_YearlyH
#define UGraphBoxPlotMYA_YearlyH
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
class TfrmGraphBoxPlotMYA_Yearly : public TForm
{
__published:	// IDE-managed Components
        TTeeCommander *tc1;
        TChart *tch1;
        TLabel *Label8;
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
        TBoxSeries* box[100];
        Simulation* sim;
public:		// User declarations
        __fastcall TfrmGraphBoxPlotMYA_Yearly(TComponent* Owner);
        void EnterInformation(Simulation*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGraphBoxPlotMYA_Yearly *frmGraphBoxPlotMYA_Yearly;
//---------------------------------------------------------------------------
#endif
