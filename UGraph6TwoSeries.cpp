//---------------------------------------------------------------------------
#include <vcl.h>
#include <fstream>
#include "sstream.h"
#pragma hdrstop
#include "UGraph6TwoSeries.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TeeComma"
#pragma link "TeeSeriesTextEd"
#pragma link "TeeURL"
#pragma link "TeeComma"
#pragma link "TeeSeriesTextEd"
#pragma link "TeeURL"
#pragma resource "*.dfm"
TfrmGraph6TwoSeries *frmGraph6TwoSeries;
//---------------------------------------------------------------------------
__fastcall TfrmGraph6TwoSeries::TfrmGraph6TwoSeries(TComponent* Owner)
        : TForm(Owner)
{
  filename=0;
  filename=new char[255];
}
//---------------------------------------------------------------------------
void TfrmGraph6TwoSeries::EnterInformation(char* _cond,int idModel,int idReport)
{
strcpy(filename,_cond);
IDmodel=idModel; // 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress
IDreport=idReport; // 1: Total Dry Matter Production, 2: Dry tuber yield , 3: Fresh tuber yield , 4: Canopy Cover
}
//---------------------------------------------------------------------------
void __fastcall TfrmGraph6TwoSeries::SpeedButton4Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGraph6TwoSeries::chbCCClick(TObject *Sender)
{
  tch1->Series[0]->Marks->Visible=chbCC->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmGraph6TwoSeries::chbCCwClick(TObject *Sender)
{
  tch1->Series[1]->Marks->Visible=chbCCw->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmGraph6TwoSeries::FormShow(TObject *Sender)
{
  tc1->Panel=tch1;
// configuro la grafica
  switch (IDreport) {
    case 1 : // Total dry matter production
            this->Caption="Graph : Total dry matter production";
            tch1->Title->Caption="TOTAL DRY MATTER PRODUCTION";
            tch1->LeftAxis->Title->Caption="t/ha";
            tch1->Series[0]->Title="Total dry matter prod (Potential)";
            tch1->Series[1]->Title="Total dry matter prod";
            chbCC->Caption="Total dry matter prod (Potential)";
            chbCCw->Caption="Total dry matter prod";
            break;
    case 2 : //  Dry tuber yield
            this->Caption="Graph : Dry tuber yield";
            tch1->Title->Caption="DRY TUBER YIELD";
            tch1->LeftAxis->Title->Caption="t/ha";
            tch1->Series[0]->Title="Dry tuber yield (Potential)";
            tch1->Series[1]->Title="Dry tuber yield";
            chbCC->Caption="Dry tuber yield (Potential)";
            chbCCw->Caption="Dry tuber yield";
            break;
    case 3 : //  Fresh tuber yield
            this->Caption="Graph : Fresh tuber yield";
            tch1->Title->Caption="FRESH TUBER YIELD";
            tch1->LeftAxis->Title->Caption="t/ha";
            tch1->Series[0]->Title="Fresh tuber yield (Potential)";
            tch1->Series[1]->Title="Fresh tuber yield";
            chbCC->Caption="Fresh tuber yield (Potential)";
            chbCCw->Caption="Fresh tuber yield";
            break;
    case 4 :  // Canopy cover
            this->Caption="Graph : Canopy cover";
            tch1->Title->Caption="CANOPY COVER";
            tch1->LeftAxis->Title->Caption="";
            tch1->Series[0]->Title="Canopy cover (Potential)";
            tch1->Series[1]->Title="Canopy cover";
            chbCC->Caption="Canopy cover (Potential)";
            chbCCw->Caption="Canopy cover";
            break;
  }
  switch (IDmodel) {
    case 2 :
            this->Caption=this->Caption+" (Drought stress)";
            tch1->Series[1]->Title=tch1->Series[1]->Title+" by drought stress";
            chbCCw->Caption=chbCCw->Caption + " by drought stress";
            break;
    case 3 :
            this->Caption=this->Caption+" (Nitrogen stress)";
            tch1->Series[1]->Title=tch1->Series[1]->Title+" by nitrogen stress";
            chbCCw->Caption=chbCCw->Caption + " by nitrogen stress";
            break;
    case 4 :
            this->Caption=this->Caption+" (Frost stress)";
            tch1->Series[1]->Title=tch1->Series[1]->Title+" by frost stress";
            chbCCw->Caption=chbCCw->Caption + " by frost stress";
            break;
  }

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
  double pot,stress;
  AnsiString titulo;
  tch1->Series[0]->Clear();
  tch1->Series[1]->Clear();
  double max=0.0;
  for(i=1;!in.eof();i++)
  {
    getline(in,line,'\n');
    fscanf(pFile,"%s %s %s %s\n",&data1,&data2,&data3,&data4);
    pot=strtod(data1,0);
    switch (IDmodel) {
      case 2 :  // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
            stress=strtod(data2,0);
            break;
      case 3 :  // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
            stress=strtod(data3,0);
            break;
      case 4 :  // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
            stress=strtod(data4,0);
            break;
    }
    if(pot>max){max=pot;}
    if(stress>max){max=stress;}
    titulo=AnsiString(i);
    tch1->Series[0]->AddXY(i,pot,titulo,tch1->Series[0]->Color);
    tch1->Series[1]->AddXY(i,stress,titulo,tch1->Series[1]->Color);
  }
  in.close();
  fclose(pFile);
  tch1->Axes->Left->Automatic=false;
  tch1->Axes->Left->Maximum=max+(max*10/100);
  Edit1->Text=i-1;
}
//---------------------------------------------------------------------------
void __fastcall TfrmGraph6TwoSeries::sbSaveClick(TObject *Sender)
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
      FILE * pFileOutput=0;
      pFileOutput = fopen (NomArchivo.c_str(),"w");
      if(IDmodel==2)  // Drought  stress
      {
        switch (IDreport) {
                case 1 :  // Total dry matter production
                        fprintf(pFileOutput,"%s %s %s\n","Day","   Total dry matter potential","   Total dry matter by water");
                        break;
                case 2 :  //  Dry tuber yield
                        fprintf(pFileOutput,"%s %s %s\n","Day","   Dry tuber yield potential","   Dry tuber yield by water");
                        break;
                case 3 :  //  Fresh tuber yield
                        fprintf(pFileOutput,"%s %s %s\n","Day","   Fresh tuber yield potential","   Fresh tuber yield by water");
                        break;
                case 4 :  // Canopy cover
                        fprintf(pFileOutput,"%s %s %s\n","Day","   Canopy cover potential","   Canopy cover by water");
                        break;
        }

      }
      if(IDmodel==3) // Nitrogen Stress
      {
        switch (IDreport) {
                case 1 :  // Total dry matter production
                        fprintf(pFileOutput,"%s %s %s\n","Day","   Total dry matter potential","   Total dry matter by nitrogen");
                        break;
                case 2 :  //  Dry tuber yield
                        fprintf(pFileOutput,"%s %s %s\n","Day","   Dry tuber yield potential","   Dry tuber yield by nitrogen");
                        break;
                case 3 :  //  Fresh tuber yield
                        fprintf(pFileOutput,"%s %s %s\n","Day","   Fresh tuber yield potential","   Fresh tuber yield by nitrogen");
                        break;
                case 4 :  // Canopy cover
                        fprintf(pFileOutput,"%s %s %s\n","Day","   Canopy cover potential","   Canopy cover by nitrogen");
                        break;
        }

      }
      if(IDmodel==3) // Frost Stress
      {
        switch (IDreport) {
                case 1 :  // Total dry matter production
                        fprintf(pFileOutput,"%s %s %s\n","Day","   Total dry matter potential","   Total dry matter by frost");
                        break;
                case 2 :  //  Dry tuber yield
                        fprintf(pFileOutput,"%s %s %s\n","Day","   Dry tuber yield potential","   Dry tuber yield by frost");
                        break;
                case 3 :  //  Fresh tuber yield
                        fprintf(pFileOutput,"%s %s %s\n","Day","   Fresh tuber yield potential","   Fresh tuber yield by frost");
                        break;
                case 4 :  // Canopy cover
                        fprintf(pFileOutput,"%s %s %s\n","Day","   Canopy cover potential","   Canopy cover by frost");
                        break;
        }

      }
      int cont=0;
      for(int i=0;!in.eof();i++)
      {
        cont++;
        getline(in,line,'\n');
        int valor=fscanf(pFile,"%s %s %s %s\n",&data1,&data2,&data3,&data4);
        if(valor==-1) break;
        switch (IDmodel) {
                case 2 :  // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
                        fprintf(pFileOutput,"%s %i %s %s %s %s\n","",i,"           ",data1,"                  ",data2);
                        break;
                case 3 :  // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
                        fprintf(pFileOutput,"%s %i %s %s %s %s\n","",i,"           ",data1,"                  ",data3);
                        break;
                case 4 :  // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
                        fprintf(pFileOutput,"%s %i %s %s %s %s\n","",i,"           ",data1,"                  ",data4);
                        break;
        }
      }
      cont=cont;
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
      FILE * pFileOutput=0;
      pFileOutput = fopen (NomArchivo.c_str(),"w");
      if(IDmodel==2)  // Drought  stress
      {
        switch (IDreport) {
                case 1 :  // Total dry matter production
                        fprintf(pFileOutput,"%s %s %s\n","Day,","Total dry matter potential,","Total dry matter by water");
                        break;
                case 2 :  //  Dry tuber yield
                        fprintf(pFileOutput,"%s %s %s\n","Day,","Dry tuber yield potential,","Dry tuber yield by water");
                        break;
                case 3 :  //  Fresh tuber yield
                        fprintf(pFileOutput,"%s %s %s\n","Day,","Fresh tuber yield potential,","Fresh tuber yield by water");
                        break;
                case 4 :  // Canopy cover
                        fprintf(pFileOutput,"%s %s %s\n","Day,","Canopy cover potential,","Canopy cover by water");
                        break;
        }

      }
      if(IDmodel==3) // Nitrogen Stress
      {
        switch (IDreport) {
                case 1 :  // Total dry matter production
                        fprintf(pFileOutput,"%s %s %s\n","Day,","Total dry matter potential,","Total dry matter by nitrogen");
                        break;
                case 2 :  //  Dry tuber yield
                        fprintf(pFileOutput,"%s %s %s\n","Day,","Dry tuber yield potential,","Dry tuber yield by nitrogen");
                        break;
                case 3 :  //  Fresh tuber yield
                        fprintf(pFileOutput,"%s %s %s\n","Day,","Fresh tuber yield potential,","Fresh tuber yield by nitrogen");
                        break;
                case 4 :  // Canopy cover
                        fprintf(pFileOutput,"%s %s %s\n","Day,","Canopy cover potential,","Canopy cover by nitrogen");
                        break;
        }

      }
      if(IDmodel==4) // Frost Stress
      {
        switch (IDreport) {
                case 1 :  // Total dry matter production
                        fprintf(pFileOutput,"%s %s %s\n","Day,","Total dry matter potential,","Total dry matter by frost");
                        break;
                case 2 :  //  Dry tuber yield
                        fprintf(pFileOutput,"%s %s %s\n","Day,","Dry tuber yield potential,","Dry tuber yield by frost");
                        break;
                case 3 :  //  Fresh tuber yield
                        fprintf(pFileOutput,"%s %s %s\n","Day,","Fresh tuber yield potential,","Fresh tuber yield by frost");
                        break;
                case 4 :  // Canopy cover
                        fprintf(pFileOutput,"%s %s %s\n","Day,","Canopy cover potential,","Canopy cover by frost");
                        break;
        }

      }
      for(int i=0;!in.eof();i++)
      {
        getline(in,line,'\n');
        int valor=fscanf(pFile,"%s %s %s %s\n",&data1,&data2,&data3,&data4);
        if(valor==-1) break;
        switch (IDmodel) {
                case 2 :  // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
                        fprintf(pFileOutput,"%i %s %s %s %s\n",i,",",data1,",",data2);
                        break;
                case 3 :  // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
                        fprintf(pFileOutput,"%i %s %s %s %s\n",i,",",data1,",",data3);
                        break;
                case 4 :  // 1: Potential Growth , 2:Drought stress , 3:Nitrogen Stress , 4:Frost Stress , 5:All models
                        fprintf(pFileOutput,"%i %s %s %s %s\n",i,",",data1,",",data4);
                        break;
        }
      }
      in.close();
      fclose(pFile);
      fclose(pFileOutput);
    }
  }

}
//---------------------------------------------------------------------------

void __fastcall TfrmGraph6TwoSeries::sdSaveSelectionChange(TObject *Sender)
{
if(sdSave->FilterIndex==1) sdSave->DefaultExt="txt";
if(sdSave->FilterIndex==2) sdSave->DefaultExt="csv";
}
//---------------------------------------------------------------------------

