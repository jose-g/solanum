//---------------------------------------------------------------------------

#ifndef UCampoH
#define UCampoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TfrmCampo : public TForm
{
__published:	// IDE-managed Components
        TListBox *ListBox1;
        TEdit *Edit1;
        TBitBtn *cmdCancel;
        TBitBtn *cmdApply;
        void __fastcall Edit1DragOver(TObject *Sender, TObject *Source,
          int X, int Y, TDragState State, bool &Accept);
        void __fastcall Edit1DragDrop(TObject *Sender, TObject *Source,
          int X, int Y);
        void __fastcall ListBox1Click(TObject *Sender);
private:	// User declarations
//        CampoType cond;
public:		// User declarations
        __fastcall TfrmCampo(TComponent* Owner);
        void EnterInformation(char*[],int,AnsiString);
        AnsiString ReturnInformation();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCampo *frmCampo;
//---------------------------------------------------------------------------
#endif
