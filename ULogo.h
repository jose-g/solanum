//---------------------------------------------------------------------------
#ifndef ULogoH
#define ULogoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
#include "UMainPG.h"
#include "UMenu.h"
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmLogo : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TButton *cmdContinue;
        TImage *Image1;
        TGroupBox *GroupBox3;
        TImage *Image2;
        TImage *Image3;
        TLabel *Label4;
        void __fastcall cmdContinueClick(TObject *Sender);
private:	// User declarations
        void CrearFormulariofrmMainPG();
        void CrearFormulariofrmMenu();
        TfrmMenu *frmMenu;
        TfrmMainPG *frmMainPG;
public:		// User declarations
        __fastcall TfrmLogo(TComponent* Owner);
        void TerminarAplicacion();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmLogo *frmLogo;
//---------------------------------------------------------------------------
#endif
