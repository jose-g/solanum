//---------------------------------------------------------------------------
#ifndef UMainNSH
#define UMainNSH
//---------------------------------------------------------------------------
#include "ManageDataPotato.h"
#include "UMenu.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <jpeg.hpp>
#include "Solanum.h"
//---------------------------------------------------------------------------
class TfrmMainNS : public TForm
{
__published:	// IDE-managed Components
        TBevel *Bevel1;
        TPanel *Panel1;
        TSpeedButton *sbNew;
        TSpeedButton *sbOpen;
        TSpeedButton *sbSave;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton8;
        TSaveDialog *sdCond;
        TOpenDialog *odCond;
        TStatusBar *StatusBar1;
        TImage *Image1;
        TButton *Button1;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton9;
        TMainMenu *MainMenu1;
        TMenuItem *Scenario1;
        TMenuItem *New1;
        TMenuItem *N1;
        TMenuItem *Open1;
        TMenuItem *Save1;
        TMenuItem *Conditions1;
        TMenuItem *climate1;
        TMenuItem *CropParameter1;
        TMenuItem *NitrogenDynamics1;
        TMenuItem *SoilParameter1;
        TMenuItem *Demonstration1;
        TMenuItem *Getdemo1;
        TMenuItem *Simulation1;
        TMenuItem *Simulate1;
        TMenuItem *Report1;
        TMenuItem *Textreport1;
        TMenuItem *Drymatterproduction2;
        TMenuItem *Drymatterproductionresume1;
        TMenuItem *Graphreport1;
        TMenuItem *Drymatterproduction1;
        TMenuItem *Freshtuberyield1;
        TMenuItem *ComparisonCanopycover1;
        TMenuItem *ComparisonDrytuberyield1;
        TMenuItem *N2;
        TMenuItem *Clearall1;
        TMenuItem *Tools1;
        TMenuItem *CalculatorSoilTemperature1;
        TMenuItem *CalculatorETo1;
        TMenuItem *Help1;
        TMenuItem *Content1;
        TMenuItem *Gettingstarted1;
        TMenuItem *N3;
        TMenuItem *Aboutmodel1;
        TMenuItem *Exit1;
        TMenuItem *Calculatorofparameters1;
        void __fastcall SpeedButton9Click(TObject *Sender);
        void __fastcall climate1Click(TObject *Sender);
        void __fastcall Getdemo1Click(TObject *Sender);
        void __fastcall New1Click(TObject *Sender);
        void __fastcall Save1Click(TObject *Sender);
        void __fastcall Open1Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Simulate1Click(TObject *Sender);
        void __fastcall CropParameter1Click(TObject *Sender);
        void __fastcall Drymatterproduction1Click(TObject *Sender);
        void __fastcall Clearall1Click(TObject *Sender);
        void __fastcall Drymatterproduction2Click(TObject *Sender);
        void __fastcall Drymatterproductionresume1Click(TObject *Sender);
        void __fastcall SpeedButton6Click(TObject *Sender);
        void __fastcall Aboutmodel1Click(TObject *Sender);
        void __fastcall SpeedButton8Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall CalculatorSoilTemperature1Click(TObject *Sender);
        void __fastcall CalculatorETo1Click(TObject *Sender);
        void __fastcall SpeedButton7Click(TObject *Sender);
        void __fastcall Freshtuberyield1Click(TObject *Sender);
        void __fastcall ComparisonCanopycover1Click(TObject *Sender);
        void __fastcall ComparisonDrytuberyield1Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall Calculatorofparameters1Click(TObject *Sender);
private:	// User declarations
        ManageDataPotato *cond;
        AnsiString ArchivoDato;
        void ModificarStatusBar(AnsiString);
        void SelectReports();
        AnsiString archivo1,archivo2,archivo3,archivo4,archivo5,archivo6,DMProd,DMProdResume;
        AnsiString WorkDir;
        TfrmMenu* menu;
        Solanum* prjSolanum;
        DBCultivo* dbcultivo;
public:		// User declarations
        __fastcall TfrmMainNS(TComponent* Owner);
        __fastcall TfrmMainNS(TfrmMenu*,Solanum*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMainNS *frmMainNS;
//---------------------------------------------------------------------------
#endif


