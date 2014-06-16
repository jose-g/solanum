//---------------------------------------------------------------------------
#include <vcl.h>
#include <fstream>
#include "sstream.h"
#pragma hdrstop
#include "UGraphBoxPlot_DS.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TeeComma"
#pragma link "TeeBoxPlot"
#pragma resource "*.dfm"
TfrmGraphBoxPlot_DS *frmGraphBoxPlot_DS;
//---------------------------------------------------------------------------
__fastcall TfrmGraphBoxPlot_DS::TfrmGraphBoxPlot_DS(TComponent* Owner)
        : TForm(Owner)
{
  filename=NULL;
  filename=new char[255];
}
//---------------------------------------------------------------------------
void TfrmGraphBoxPlot_DS::EnterInformation(char* _cond)
{
  strcpy(filename,_cond);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGraphBoxPlot_DS::FormShow(TObject *Sender)
{
  populateWLGraph();
  populatePGGraph();
}
//---------------------------------------------------------------------------
void TfrmGraphBoxPlot_DS::populateWLGraph()
{
  tc1->Panel=tch1;
  FILE * pFile;
  pFile = fopen (filename,"r");
  ifstream in(filename);
  int i;
  string line;
  char chnumrep[20];
  char data1[20];
  char data2[20];
  int numrep;
  double valor;
  int day;
  AnsiString titulo;
  double max=0.0;
  int contScenario=0;
  for(i=1;!in.eof();i++)
  {
    getline(in,line,'\n');
    fscanf(pFile,"%s\n",&chnumrep);
    numrep=atoi(chnumrep);
    strcpy(chnumrep,"");
    box[contScenario]=new TBoxSeries(tch1);
    box[contScenario]->Position=contScenario+1;
    box[contScenario]->Box->Color=0x0080FFFF;
    box[contScenario]->WhiskerPen->Color=clYellow;
    tch1->AddSeries(box[contScenario]);
    tch1->Series[contScenario]->Clear();

    for(int idato=0;idato<numrep;idato++)
    {
      getline(in,line,'\n');
      fscanf(pFile,"%s %s\n",&data1,&data2);
      valor=strtod(data1,NULL);
      tch1->Series[contScenario]->Add(valor,contScenario+1,clRed);
    }
    contScenario++;
  }
  in.close();
  fclose(pFile);
}
//---------------------------------------------------------------------------
void TfrmGraphBoxPlot_DS::populatePGGraph()
{
  tc2->Panel=tch2;
  FILE * pFile;
  pFile = fopen (filename,"r");
  ifstream in(filename);
  int i;
  string line;
  char chnumrep[20];
  char data1[20];
  char data2[20];
  int numrep;
  double valor;
  int day;
  AnsiString titulo;
  double max=0.0;
  int contScenario=0;
  for(i=1;!in.eof();i++)
  {
    getline(in,line,'\n');
    fscanf(pFile,"%s\n",&chnumrep);
    numrep=atoi(chnumrep);
    strcpy(chnumrep,"");
    box2[contScenario]=new TBoxSeries(tch2);
    box2[contScenario]->Position=contScenario+1;
    box2[contScenario]->Box->Color=0x0080FFFF;
    box2[contScenario]->WhiskerPen->Color=clYellow;
    tch2->AddSeries(box2[contScenario]);
    tch2->Series[contScenario]->Clear();

    for(int idato=0;idato<numrep;idato++)
    {
      getline(in,line,'\n');
      fscanf(pFile,"%s %s\n",&data1,&data2);
      valor=strtod(data2,NULL);
      tch2->Series[contScenario]->Add(valor,contScenario+1,clRed);
    }
    contScenario++;
  }
  in.close();
  fclose(pFile);
}
//---------------------------------------------------------------------------
