//---------------------------------------------------------------------------
#ifndef USelYearH
#define USelYearH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include "Simulation.h"
#include "Climate.h"
//---------------------------------------------------------------------------
class TfrmSelYear : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *cmdCancel;
        TBitBtn *cmdApply;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TListBox *lbAllYears;
        TListBox *lbPast;
        TListBox *lbFuture;
        TButton *buAddOneItemToPast;
        TButton *butDelAllItemsFromPast;
        TButton *butDelItemFromPast;
        TButton *butAddAllToPast;
        TButton *buAddOneItemToFuture;
        TButton *butAddAllToFuture;
        TButton *butDelItemFromFuture;
        TButton *butDelAllItemsFromFuture;
        void __fastcall cmdCancelClick(TObject *Sender);
        void __fastcall cmdApplyClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall buAddOneItemToPastClick(TObject *Sender);
        void __fastcall butAddAllToPastClick(TObject *Sender);
        void __fastcall butDelItemFromPastClick(TObject *Sender);
        void __fastcall butDelAllItemsFromPastClick(TObject *Sender);
        void __fastcall buAddOneItemToFutureClick(TObject *Sender);
        void __fastcall butAddAllToFutureClick(TObject *Sender);
        void __fastcall butDelItemFromFutureClick(TObject *Sender);
        void __fastcall butDelAllItemsFromFutureClick(TObject *Sender);
private:	// User declarations
        Simulation *sim;
        Climate *climate;
        void SaveData();
public:		// User declarations
        __fastcall TfrmSelYear(TComponent* Owner);
        void EnterInformation(Simulation*,Climate*);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSelYear *frmSelYear;
//---------------------------------------------------------------------------
#endif
