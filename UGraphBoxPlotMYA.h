//---------------------------------------------------------------------------

#ifndef UGraphBoxPlotMYAH
#define UGraphBoxPlotMYAH
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
class TfrmGraphBoxPlotMYA : public TForm
{
__published:	// IDE-managed Components
        TTeeCommander *tc1;
        TChart *tch1;
        TLabel *Label8;
        TLabel *Label4;
        TLabel *Label5;
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
        TBoxSeries* box[3];
        Simulation *sim;
public:		// User declarations
        __fastcall TfrmGraphBoxPlotMYA(TComponent* Owner);
        void EnterInformation(Simulation*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGraphBoxPlotMYA *frmGraphBoxPlotMYA;
//---------------------------------------------------------------------------
#endif
