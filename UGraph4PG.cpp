//---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream>
#include "sstream.h"
#pragma hdrstop

#include "UGraph4PG.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TeeComma"
#pragma link "TeeSeriesTextEd"
#pragma link "TeeURL"
#pragma link "TeeComma"
#pragma link "TeeSeriesTextEd"
#pragma link "TeeURL"
#pragma resource "*.dfm"
TfrmGraph4PG *frmGraph4PG;
//---------------------------------------------------------------------------
__fastcall TfrmGraph4PG::TfrmGraph4PG(TComponent* Owner)
        : TForm(Owner)
{
  filename=NULL;
  filename=new char[255];
}
//---------------------------------------------------------------------------
void TfrmGraph4PG::EnterInformation(char* _cond)
{
strcpy(filename,_cond);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGraph4PG::SpeedButton4Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGraph4PG::chbCCClick(TObject *Sender)
{
  tch1->Series[0]->Marks->Visible=chbCC->Checked;
}
//---------------------------------------------------------------------------


void __fastcall TfrmGraph4PG::FormShow(TObject *Sender)
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
  double dty;
  AnsiString titulo;
  tch1->Series[0]->Clear();
  double max=0.0;
  for(i=1;!in.eof();i++)
  {
    getline(in,line,'\n');
    fscanf(pFile,"%s %s %s %s\n",&data1,&data2,&data3,&data4);
    dty=strtod(data1,NULL);
    if(dty>max){max=dty;}
    titulo=AnsiString(i);
    tch1->Series[0]->AddXY(i,dty,titulo,tch1->Series[0]->Color);
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



void __fastcall TfrmGraph4PG::sbSaveClick(TObject *Sender)
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
      fprintf(pFileOutput,"%s %s\n","Day","   Dry tuber yield potential");
      for(int i=0;!in.eof();i++)
      {
        getline(in,line,'\n');
        int valor=fscanf(pFile,"%s %s %s %s\n",&data1,&data2,&data3,&data4);
        if(valor==-1) break;
        fprintf(pFileOutput,"%s %i %s %s\n","",i,"         ",data1);
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
      fprintf(pFileOutput,"%s %s\n","Day,","Dry tuber yield potential,");
      for(int i=0;!in.eof();i++)
      {
        getline(in,line,'\n');
        int valor=fscanf(pFile,"%s %s %s %s\n",&data1,&data2,&data3,&data4);
        if(valor==-1) break;
        fprintf(pFileOutput,"%i %s %s\n",i,",",data1);
      }
      in.close();
      fclose(pFile);
      fclose(pFileOutput);
    }
  }

}
//---------------------------------------------------------------------------


void __fastcall TfrmGraph4PG::sdSaveSelectionChange(TObject *Sender)
{
if(sdSave->FilterIndex==1) sdSave->DefaultExt="txt";
if(sdSave->FilterIndex==2) sdSave->DefaultExt="csv";
}
//---------------------------------------------------------------------------

