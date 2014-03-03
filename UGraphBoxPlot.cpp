//---------------------------------------------------------------------------
#include <vcl.h>
#include <fstream>
#include "sstream.h"
#pragma hdrstop
#include "UGraphBoxPlot.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TeeComma"
#pragma link "TeeBoxPlot"
#pragma resource "*.dfm"
TfrmGraphBoxPlot *frmGraphBoxPlot;
//---------------------------------------------------------------------------
__fastcall TfrmGraphBoxPlot::TfrmGraphBoxPlot(TComponent* Owner)
        : TForm(Owner)
{
  filename=NULL;
  filename=new char[255];
}
//---------------------------------------------------------------------------
void TfrmGraphBoxPlot::EnterInformation(char* _cond)
{
  strcpy(filename,_cond);
}
//---------------------------------------------------------------------------
void __fastcall TfrmGraphBoxPlot::FormShow(TObject *Sender)
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
  double gci_sim_s,gai_sim_s;
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
