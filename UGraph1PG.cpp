//---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream>
#include "sstream.h"
#pragma hdrstop

#include "UGraph1PG.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TeeComma"
#pragma link "TeeSeriesTextEd"
#pragma link "TeeURL"
#pragma link "TeeComma"
#pragma link "TeeSeriesTextEd"
#pragma link "TeeURL"
#pragma resource "*.dfm"
TfrmGraph1PG *frmGraph1PG;
//---------------------------------------------------------------------------
__fastcall TfrmGraph1PG::TfrmGraph1PG(TComponent* Owner)
        : TForm(Owner)
{
  filename=NULL;
  filename=new char[255];
}
//---------------------------------------------------------------------------
void TfrmGraph1PG::EnterInformation(char* _cond)
{
strcpy(filename,_cond);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGraph1PG::SpeedButton4Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGraph1PG::chbTotalDMClick(TObject *Sender)
{
  tch1->Series[0]->Marks->Visible=chbTotalDM->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmGraph1PG::chbTuberDMClick(TObject *Sender)
{
  tch1->Series[1]->Marks->Visible=chbTuberDM->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmGraph1PG::FormShow(TObject *Sender)
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
  int day;
  double tdm_sim,wso_sim;
  AnsiString titulo;
  tch1->Series[0]->Clear();
  tch1->Series[1]->Clear();
  double max=0.0;
  fscanf(pFile,"%s\n",&data1);
  for(i=1;!in.eof();i++)
  {
    getline(in,line,'\n');
    fscanf(pFile,"%s %s\n",&data1,&data2);
    tdm_sim=strtod(data1,NULL);
    if(tdm_sim>max){max=tdm_sim;}
    wso_sim=strtod(data2,NULL);
    titulo=AnsiString(i);
    tch1->Series[0]->AddXY(i,tdm_sim,titulo,tch1->Series[0]->Color);
    tch1->Series[1]->AddXY(i,wso_sim,titulo,tch1->Series[1]->Color);
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
void __fastcall TfrmGraph1PG::sbSaveClick(TObject *Sender)
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
      fprintf(pFileOutput,"%s %s %s\n","Day","   Total dry matter","   Dry tuber yield");
      fscanf(pFile,"%s\n",&data1);
      for(int i=0;!in.eof();i++)
      {
        getline(in,line,'\n');
        int valor=fscanf(pFile,"%s %s\n",&data1,&data2);
        if(valor==-1) break;
        fprintf(pFileOutput,"%s %i %s %s            %s\n","",i,"       ",data1,data2);
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
      fprintf(pFileOutput,"%s %s %s\n","Day,","Total dry matter,","Dry tuber yield");
      fscanf(pFile,"%s\n",&data1);
      for(int i=0;!in.eof();i++)
      {
        getline(in,line,'\n');
        int valor=fscanf(pFile,"%s %s\n",&data1,&data2);
        if(valor==-1) break;
        fprintf(pFileOutput,"%i %s %s %s %s\n",i,",",data1,",",data2);
      }
      in.close();
      fclose(pFile);
      fclose(pFileOutput);
    }
  }
}
//---------------------------------------------------------------------------

