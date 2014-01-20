//---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream>
#include "sstream.h"
#pragma hdrstop

#include "UGraph5AM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TeeComma"
#pragma link "TeeSeriesTextEd"
#pragma link "TeeURL"
#pragma link "TeeComma"
#pragma link "TeeSeriesTextEd"
#pragma link "TeeURL"
#pragma resource "*.dfm"
TfrmGraph5AM *frmGraph5AM;
//---------------------------------------------------------------------------
__fastcall TfrmGraph5AM::TfrmGraph5AM(TComponent* Owner)
        : TForm(Owner)
{
  filename=NULL;
  filename=new char[255];
}
//---------------------------------------------------------------------------
void TfrmGraph5AM::EnterInformation(char* _cond)
{
strcpy(filename,_cond);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGraph5AM::SpeedButton4Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGraph5AM::chbCCClick(TObject *Sender)
{
  tch1->Series[0]->Marks->Visible=chbCC->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmGraph5AM::chbCCwClick(TObject *Sender)
{
  tch1->Series[1]->Marks->Visible=chbCCw->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmGraph5AM::FormShow(TObject *Sender)
{
  tc1->Panel=tch1;
  FILE * pFile;
  pFile = fopen (filename,"r");
  ifstream in(filename);
  int i;
  string line;
  char data1[20];
  char data2[20];
  char data3[20];
  char data4[20];
  int day;
  double cc,ccw,ccn,ccf;
  AnsiString titulo;
  tch1->Series[0]->Clear();
  tch1->Series[1]->Clear();
  tch1->Series[2]->Clear();
  tch1->Series[3]->Clear();
  double max=0.0;
  for(i=1;!in.eof();i++)
  {
    getline(in,line,'\n');
    fscanf(pFile,"%s %s %s %s\n",&data1,&data2,&data3,&data4);
    cc=strtod(data1,NULL);
    ccw=strtod(data2,NULL);
    ccn=strtod(data3,NULL);
    ccf=strtod(data4,NULL);
    if(cc>max){max=cc;}
    if(ccw>max){max=ccw;}
    if(ccn>max){max=ccn;}
    if(ccf>max){max=ccf;}
    titulo=AnsiString(i);
    tch1->Series[0]->AddXY(i,cc,titulo,tch1->Series[0]->Color);
    tch1->Series[1]->AddXY(i,ccw,titulo,tch1->Series[1]->Color);
    tch1->Series[2]->AddXY(i,ccn,titulo,tch1->Series[2]->Color);
    tch1->Series[3]->AddXY(i,ccf,titulo,tch1->Series[3]->Color);
  }
  in.close();
  fclose(pFile);
  tch1->Axes->Left->Automatic=false;
  tch1->Axes->Left->Maximum=max+(max*10/100);
  Edit1->Text=i-1;
//  Edit2->Text=FormatFloat("0.00",float(dwtot));
//  Edit3->Text=FormatFloat("0.00",float(dwtbf));
//  Edit4->Text=FormatFloat("0.00",float(dwtbf/DMCont));
}
//---------------------------------------------------------------------------

void __fastcall TfrmGraph5AM::chbCCnClick(TObject *Sender)
{
  tch1->Series[2]->Marks->Visible=chbCCn->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmGraph5AM::chbCCfClick(TObject *Sender)
{
  tch1->Series[3]->Marks->Visible=chbCCf->Checked;
}
//---------------------------------------------------------------------------


void __fastcall TfrmGraph5AM::sbSaveClick(TObject *Sender)
{
  AnsiString NomArchivo;
  sdSave->FileName="";
  if(sdSave->Execute())
  {
    NomArchivo=sdSave->FileName;
    if(sdSave->FilterIndex==1)
    {
      FILE * pFile;
      pFile = fopen (filename,"r");
      ifstream in(filename);
      char data1[20];
      char data2[20];
      char data3[20];
      char data4[20];
      string line;
      FILE * pFileOutput=NULL;
      pFileOutput = fopen (NomArchivo.c_str(),"w");
      fprintf(pFileOutput,"%s %s %s %s %s\n","Day","   Fresh tuber yield potential","   Fresh tuber yield by water","   Fresh tuber yield by nitrogen","   Fresh tuber yield by frost");
      for(int i=0;!in.eof();i++)
      {
        getline(in,line,'\n');
        int valor=fscanf(pFile,"%s %s %s %s\n",&data1,&data2,&data3,&data4);
        if(valor==-1) break;
        fprintf(pFileOutput,"%s %i %s %s %s %s %s %s %s %s\n","",i,"           ",data1,"                     ",data2,"                      ",data3,"                     ",data4);
      }
      in.close();
      fclose(pFile);
      fclose(pFileOutput);
    }
    if(sdSave->FilterIndex==2)
    {
      FILE * pFile;
      pFile = fopen (filename,"r");
      ifstream in(filename);
      char data1[20];
      char data2[20];
      char data3[20];
      char data4[20];
      string line;
      FILE * pFileOutput=NULL;
      pFileOutput = fopen (NomArchivo.c_str(),"w");
      fprintf(pFileOutput,"%s %s %s %s %s\n","Day,","Fresh tuber yield potential,","Fresh tuber yield by water,","Fresh tuber yield by nitrogen,","Fresh tuber yield by frost");
      for(int i=0;!in.eof();i++)
      {
        getline(in,line,'\n');
        int valor=fscanf(pFile,"%s %s %s %s\n",&data1,&data2,&data3,&data4);
        if(valor==-1) break;
        fprintf(pFileOutput,"%i %s %s %s %s %s %s %s %s\n",i,",",data1,",",data2,",",data3,",",data4);
      }
      in.close();
      fclose(pFile);
      fclose(pFileOutput);
    }
  }
        
}
//---------------------------------------------------------------------------

void __fastcall TfrmGraph5AM::sdSaveSelectionChange(TObject *Sender)
{
if(sdSave->FilterIndex==1) sdSave->DefaultExt="txt";
if(sdSave->FilterIndex==2) sdSave->DefaultExt="csv";
        
}
//---------------------------------------------------------------------------

