//---------------------------------------------------------------------------
#include <vcl.h>
#include <fstream>
#include "sstream.h"
#pragma hdrstop
#include "UDMProdPG.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TeeComma"
#pragma link "TeeSeriesTextEd"
#pragma link "TeeURL"
#pragma link "TeeComma"
#pragma link "TeeSeriesTextEd"
#pragma link "TeeURL"
#pragma resource "*.dfm"
TfrmDMProdPG *frmDMProdPG;
//---------------------------------------------------------------------------
__fastcall TfrmDMProdPG::TfrmDMProdPG(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfrmDMProdPG::EnterInformation(char* _cond)
{
filename=_cond;
}
//---------------------------------------------------------------------------
void __fastcall TfrmDMProdPG::SpeedButton4Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmDMProdPG::chbTotalDMClick(TObject *Sender)
{
  tch1->Series[0]->Marks->Visible=chbTotalDM->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmDMProdPG::chbTuberDMClick(TObject *Sender)
{
  tch1->Series[1]->Marks->Visible=chbTuberDM->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmDMProdPG::FormShow(TObject *Sender)
{
  tc1->Panel=tch1;
  FILE * pFile;
  pFile = fopen (filename,"r");
  ifstream in(filename);
  int i;
  string line;
  char data1[20];
  char data2[20];
  int day;
  double dwtot,dwtbf;
//  wchar_t * titulo = new wchar_t[2];
  AnsiString titulo;
  getline(in,line,'\n');
  fscanf(pFile,"%s\n",&data1);
  double DMCont=strtod(data1,NULL);
  tch1->Series[0]->Clear();
  tch1->Series[1]->Clear();
  for(i=1;!in.eof();i++)
  {
    getline(in,line,'\n');
    fscanf(pFile,"%s %s\n",&data1,&data2);
    dwtot=strtod(data1,NULL);
    dwtbf=strtod(data2,NULL);
    titulo=AnsiString(i);
    tch1->Series[0]->AddXY(i,dwtot,titulo,tch1->Series[0]->Color);
    tch1->Series[1]->AddXY(i,dwtbf,titulo,tch1->Series[1]->Color);
    //tch1->Series(0)->AddXY(i,dwtot,titulo,tch1->Series(0)->Color);
    //tch1->Series(1)->AddXY(i,dwtbf,titulo,tch1->Series(1)->Color);
  }
  in.close();
  fclose(pFile);
  Edit1->Text=i-1;
  Edit2->Text=FormatFloat("0.00",float(dwtot));
  Edit3->Text=FormatFloat("0.00",float(dwtbf));
  Edit4->Text=FormatFloat("0.00",float(dwtbf/DMCont));
}
//---------------------------------------------------------------------------

