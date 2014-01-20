//---------------------------------------------------------------------------
#include <vcl.h>
#include <fstream>
#include "sstream.h"
#pragma hdrstop
#include "UGraph2AM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TeeComma"
#pragma link "TeeSeriesTextEd"
#pragma link "TeeURL"
#pragma link "TeeComma"
#pragma link "TeeSeriesTextEd"
#pragma link "TeeURL"
#pragma resource "*.dfm"
TfrmGraph2AM *frmGraph2AM;
//---------------------------------------------------------------------------
__fastcall TfrmGraph2AM::TfrmGraph2AM(TComponent* Owner)
        : TForm(Owner)
{
  filename=NULL;
  filename=new char[255];
}
//---------------------------------------------------------------------------
void TfrmGraph2AM::EnterInformation(char* _cond)
{
strcpy(filename,_cond);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGraph2AM::SpeedButton4Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGraph2AM::chbTotalDMClick(TObject *Sender)
{
  tch1->Series[0]->Marks->Visible=chbTotalDM->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmGraph2AM::FormShow(TObject *Sender)
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
  double gci_sim_s,gai_sim_s;
  AnsiString titulo;
  tch1->Series[0]->Clear();
//  tch1->Series[1]->Clear();
  double max=0.0;
  for(i=1;!in.eof();i++)
  {
    getline(in,line,'\n');
    fscanf(pFile,"%s\n",&data1);
    gci_sim_s=strtod(data1,NULL);
//    gai_sim_s=strtod(data2,NULL);
//    if(gai_sim_s>max){max=gai_sim_s;}
    titulo=AnsiString(i);
    tch1->Series[0]->AddXY(i,gci_sim_s,titulo,tch1->Series[0]->Color);
//    tch1->Series[1]->AddXY(i,gai_sim_s,titulo,tch1->Series[1]->Color);
  }
  in.close();
  fclose(pFile);
//  tch1->Axes->Left->Automatic=false;
//  tch1->Axes->Left->Maximum=max+(max*10/100);
  Edit1->Text=i-1;
//  Edit2->Text=FormatFloat("0.00",float(dwtot));
//  Edit3->Text=FormatFloat("0.00",float(dwtbf));
//  Edit4->Text=FormatFloat("0.00",float(dwtbf/DMCont));
}
//---------------------------------------------------------------------------

