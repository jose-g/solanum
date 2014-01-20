//---------------------------------------------------------------------------
#ifndef UMainPGBorrarH
#define UMainPGBorrarH
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

//---------------------------------------------------------------------------
class TfrmMainPG : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Scenario1;
        TMenuItem *Conditions1;
        TMenuItem *Demonstration1;
        TMenuItem *Simulation1;
        TMenuItem *Report1;
        TMenuItem *Help1;
        TMenuItem *Exit1;
        TMenuItem *New1;
        TMenuItem *Open1;
        TMenuItem *N1;
        TMenuItem *Save1;
        TMenuItem *climate1;
        TMenuItem *CropParameter1;
        TMenuItem *Getdemo1;
        TMenuItem *Simulate1;
        TMenuItem *Textreport1;
        TMenuItem *Graphreport1;
        TMenuItem *N2;
        TMenuItem *Clearall1;
        TMenuItem *Content1;
        TMenuItem *Gettingstarted1;
        TMenuItem *N3;
        TMenuItem *Aboutmodel1;
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
        TMenuItem *Drymatterproduction1;
        TImage *Image1;
        TMenuItem *Drymatterproduction2;
        TMenuItem *Drymatterproductionresume1;
        TButton *Button1;
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
private:	// User declarations
        AnsiString ArchivoDato;
        ManageDataPotato* cond;
        void ModificarStatusBar(AnsiString);
        void SelectReports();
        AnsiString archivo1,archivo2,archivo3,archivo4,archivo5,archivo6,DMProd,DMProdResume;
        AnsiString WorkDir;
        TfrmMenu* menu;
public:		// User declarations
        __fastcall TfrmMainPG(TComponent* Owner);
        __fastcall TfrmMainPG(TfrmMenu*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMainPG *frmMainPG;
//---------------------------------------------------------------------------
#endif


