//---------------------------------------------------------------------------
#include <vcl.h>
#include <fstream>
#include "sstream.h"
#pragma hdrstop
#include "UGraph2PG.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TeeComma"
#pragma link "TeeSeriesTextEd"
#pragma link "TeeURL"
#pragma link "TeeComma"
#pragma link "TeeSeriesTextEd"
#pragma link "TeeURL"
#pragma resource "*.dfm"
TfrmGraph2PG *frmGraph2PG;
//---------------------------------------------------------------------------
__fastcall TfrmGraph2PG::TfrmGraph2PG(TComponent* Owner)
        : TForm(Owner)
{
  filename=NULL;
  filename=new char[255];
}
//---------------------------------------------------------------------------
void TfrmGraph2PG::EnterInformation(char* _cond)
{
strcpy(filename,_cond);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGraph2PG::SpeedButton4Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGraph2PG::chbTotalDMClick(TObject *Sender)
{
  tch1->Series[0]->Marks->Visible=chbTotalDM->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmGraph2PG::FormShow(TObject *Sender)
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
  double gci_sim_s,gai_sim_s;
  double lc1,lc2;
  AnsiString titulo;
  tch1->Series[0]->Clear();
  tch1->Series[1]->Clear();
  tch1->Series[2]->Clear();
  double max=0.0;
  for(i=1;!in.eof();i++)
  {
    getline(in,line,'\n');
    fscanf(pFile,"%s %s %s\n",&data1,&data2,&data3);
    gci_sim_s=strtod(data1,NULL);
    lc1=strtod(data2,NULL);
    lc2=strtod(data3,NULL);
//    gai_sim_s=strtod(data2,NULL);
//    if(gai_sim_s>max){max=gai_sim_s;}
    titulo=AnsiString(i);
    tch1->Series[0]->AddXY(i,gci_sim_s,titulo,tch1->Series[0]->Color);
    tch1->Series[1]->AddXY(i,lc1,titulo,tch1->Series[1]->Color);
    tch1->Series[2]->AddXY(i,lc2,titulo,tch1->Series[2]->Color);
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

void __fastcall TfrmGraph2PG::sbSaveClick(TObject *Sender)
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
      string line;
      FILE * pFileOutput=NULL;
      pFileOutput = fopen (NomArchivo.c_str(),"w");
      fprintf(pFileOutput,"%s %s %s %s\n","Day","   Fresh tuber yield","   LC1","        LC2");
      for(int i=0;!in.eof();i++)
      {
        getline(in,line,'\n');
        int valor=fscanf(pFile,"%s %s %s\n",&data1,&data2,&data3);
        if(valor==-1) break;
        fprintf(pFileOutput,"%s %i %s %s      %s   %s\n","",i,"        ",data1,data2,data3);
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
      fprintf(pFileOutput,"%s %s %s %s\n","Day,","Fresh tuber yield,","LC1,","LC2");
      for(int i=0;!in.eof();i++)
      {
        getline(in,line,'\n');
        int valor=fscanf(pFile,"%s %s %s\n",&data1,&data2,&data3);
        if(valor==-1) break;
        fprintf(pFileOutput,"%i %s %s %s %s %s %s\n",i,",",data1,",",data2,",",data3);
      }
      in.close();
      fclose(pFile);
      fclose(pFileOutput);
    }
  }
        
}
//---------------------------------------------------------------------------

