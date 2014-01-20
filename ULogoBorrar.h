//---------------------------------------------------------------------------
#ifndef ULogoBorrarH
#define ULogoBorrarH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
#include "UMainPGBorrar.h"
#include "UMenuBorrar.h"
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
        TLabel *Label4;
        TPanel *Panel1;
        TImage *Image2;
        TLabel *Label5;
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
