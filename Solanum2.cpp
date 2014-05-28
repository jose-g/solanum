//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("ULogo.cpp", frmLogo);
USEFORM("UMenu.cpp", frmMenu);
USEFORM("UMainPG_AMY.cpp", frmMainPG_AMY);
USEFORM("UMainNS.cpp", frmMainNS);
USEFORM("clases\UReportGraphMenuTwoSeries.cpp", frmReportGraphMenuTwoSeries);
USEFORM("UReportTXTMenu.cpp", frmReportTXTMenu);
USEFORM("UReportTableMYA_PG.cpp", frmReportTableMYA_PG);
USEFORM("USimulationTime.cpp", frmSimulationTime);
USEFORM("UAbout.cpp", frmAbout);
USEFORM("UCampo.cpp", frmCampo);
USEFORM("UCalcSoilTemp.cpp", frmCalcSoilTemp);
USEFORM("UCropParameterPG.cpp", frmCropParameterPG);
USEFORM("UGraph1PG.cpp", frmGraph1PG);
USEFORM("UGraph2PG.cpp", frmGraph2PG);
USEFORM("UGraph3PG.cpp", frmGraph3PG);
USEFORM("UGraph4PG.cpp", frmGraph4PG);
USEFORM("UGraph5PG.cpp", frmGraph5PG);
USEFORM("UGraph6PG.cpp", frmGraph6PG);
USEFORM("UReportGraphMenuAM.cpp", frmReportGraphMenuAM);
USEFORM("USoilDS.cpp", frmSoilDS);
USEFORM("UClimateDS.cpp", frmClimateDS);
USEFORM("UCropParameterNS.cpp", frmCropParameterNS);
USEFORM("UNitrogenAM.cpp", frmNitrogenAM);
USEFORM("UGraph6TwoSeries.cpp", frmGraph6TwoSeries);
USEFORM("UGraph1AM.cpp", frmGraph1AM);
USEFORM("UGraph2TwoSeries.cpp", frmGraph2TwoSeries);
USEFORM("UGraph3TwoSeries.cpp", frmGraph3TwoSeries);
USEFORM("UGraph4TwoSeries.cpp", frmGraph4TwoSeries);
USEFORM("UGraph5AM.cpp", frmGraph5AM);
USEFORM("UMainFS.cpp", frmMainFS);
USEFORM("UCropParameterAM.cpp", frmCropParameterAM);
USEFORM("UMainDS.cpp", frmMainDS);
USEFORM("UMainAM.cpp", frmMainAM);
USEFORM("USoilAM.cpp", frmSoilAM);
USEFORM("UGraph6AM.cpp", frmGraph6AM);
USEFORM("UGraph4AM.cpp", frmGraph4AM);
USEFORM("UGraph2AM.cpp", frmGraph2AM);
USEFORM("UGraph3AM.cpp", frmGraph3AM);
USEFORM("UReportGraphMenuPG.cpp", frmReportGraphMenuPG);
USEFORM("UCalcET0.cpp", frmCalcET0);
USEFORM("UClimatePG.cpp", frmClimatePG);
USEFORM("UClimateAM.cpp", frmClimateAM);
USEFORM("UClimate.cpp", frmClimate);
USEFORM("UCalcParam.cpp", frmCalcParam);
USEFORM("UEstadistico.cpp", frmEstadistico);
USEFORM("UImportCropParameter.cpp", frmImportCropParameter);
USEFORM("UGraphBoxPlotMYA.cpp", frmGraphBoxPlotMYA);
USEFORM("UGraphBoxPlot_DS.cpp", frmGraphBoxPlot_DS);
USEFORM("UMainPG.cpp", frmMainPG);
USEFORM("UReportTXT.cpp", frmReportTXT);
USEFORM("UGraphBoxPlot.cpp", frmGraphBoxPlot);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "Solanum";
                 Application->CreateForm(__classid(TfrmMenu), &frmMenu);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
