//---------------------------------------------------------------------------

#ifndef UMenuBorrarH
#define UMenuBorrarH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>

//---------------------------------------------------------------------------
class TfrmMenu : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TRadioButton *rbPG;
        TRadioButton *rbDS;
        TRadioButton *rbNS;
        TRadioButton *rbFS;
        TRadioButton *rbAM;
        TBitBtn *cmdExit;
        TBitBtn *cmdApply;
        TSpeedButton *sbPG;
        TSpeedButton *sbDS;
        TSpeedButton *sbNS;
        TSpeedButton *sbFS;
        TSpeedButton *sbOther;
        TGroupBox *GroupBox2;
        TImage *Image1;
        TLabel *Label1;
        void __fastcall cmdExitClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall cmdApplyClick(TObject *Sender);
        void __fastcall sbPGClick(TObject *Sender);
        void __fastcall sbDSClick(TObject *Sender);
        void __fastcall sbNSClick(TObject *Sender);
        void __fastcall sbOtherClick(TObject *Sender);
private:	// User declarations
        int accion;
        bool cargo;
public:		// User declarations
        __fastcall TfrmMenu(TComponent* Owner);
        void CerrarTodo();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMenu *frmMenu;
//---------------------------------------------------------------------------
#endif
