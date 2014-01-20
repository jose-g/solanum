//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UCampo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmCampo *frmCampo;
//---------------------------------------------------------------------------
__fastcall TfrmCampo::TfrmCampo(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfrmCampo::EnterInformation(char *FieldsList[],int num,AnsiString titulo)
{
  Caption=titulo;
  int i;
  for(i=0;i<num;i++)
  {
   ListBox1->Items->Add(FieldsList[i]);
  }
}
//---------------------------------------------------------------------------
AnsiString TfrmCampo::ReturnInformation()
{
  return Edit1->Text;
}
//---------------------------------------------------------------------------

void __fastcall TfrmCampo::Edit1DragOver(TObject *Sender, TObject *Source,
      int X, int Y, TDragState State, bool &Accept)
{
Accept = Source->ClassNameIs("TListBox");
}
//---------------------------------------------------------------------------
void __fastcall TfrmCampo::Edit1DragDrop(TObject *Sender, TObject *Source,
      int X, int Y)
{
  if (Sender->ClassNameIs("TEdit") && Source->ClassNameIs("TListBox"))
  {
    TEdit *DestEdit = (TEdit *)Sender;
    int sel;
    sel=((TListBox *)Source)->ItemIndex;
    DestEdit->Text = ((TListBox *)Source)->Items->Strings[sel];
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmCampo::ListBox1Click(TObject *Sender)
{
int sel;
sel=ListBox1->ItemIndex;
Edit1->Text = ListBox1->Items->Strings[sel];
}
//---------------------------------------------------------------------------









