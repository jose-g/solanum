//---------------------------------------------------------------------------
#include <vcl.h>
#include <fstream.h>
#include <cassert>
#include <windows.h>
#pragma hdrstop
#include "UReportTableMYA_PG.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmReportTableMYA_PG *frmReportTableMYA_PG;
//---------------------------------------------------------------------------
__fastcall TfrmReportTableMYA_PG::TfrmReportTableMYA_PG(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportTableMYA_PG::SpeedButton4Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportTableMYA_PG::FormClose(TObject *Sender, TCloseAction &Action)
{
Action=caFree;
}
//---------------------------------------------------------------------------
void TfrmReportTableMYA_PG::EnterInformation(Simulation* _sim)
{
  sim=_sim;
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportTableMYA_PG::FormShow(TObject *Sender)
{
   sgFTY->ColWidths[0]=30;
//  poblar la tabla con los resultados
   int totYear=sim->totYearToSimulate;
   int numrep;
   sgFTY->ColCount=totYear+1; // se agrega uno por la fixed column el cual corresponde a la numeracion
   sgFTY->RowCount=sim->time->repFuture+1;
   int count=0;
   for(int i=0;i<totYear;i++)
   {
     count++;
     sgFTY->Cells[i+1][0]=sim->listYear[i];
     if(count>sim->totPastYear) {numrep=sim->time->repFuture+1;}
     else{numrep=sim->time->repetitions+1;}

     for(int idata=0;idata<numrep-1;idata++)
     {
       sgFTY->Cells[i+1][idata+1]=FormatFloat("##.00",sim->ult_fty_by_year[idata][i]);
     }
   }
   numrep=sim->time->repFuture+1;
   for(int i=0;i<numrep;i++)
   {
     sgFTY->Cells[0][i+1]=i+1;
   }
}
//---------------------------------------------------------------------------
void __fastcall TfrmReportTableMYA_PG::sbSaveClick(TObject *Sender)
{

if(SaveDialog1->Execute())
{
  AnsiString destino=SaveDialog1->FileName;
  AnsiString linea;
  int totYear=sim->totYearToSimulate;
  int numrep=sim->time->repFuture;

  FILE *sout=0;
  sout=fopen(destino.c_str(),"w");
  rewind(sout);
  linea="";
  for(int i=0;i<totYear;i++)
  {
    if(i==totYear-1)
    {
      linea=linea+sim->listYear[i];
    }
    else
    {
      linea=linea+sim->listYear[i]+",";
    }
  }
  fprintf(sout,"%s\n",linea.c_str());
  int cont;
  for(int idata=0;idata<numrep;idata++)
  {
    linea="";
    cont=0;
    for(int i=0;i<totYear;i++)
    {
      cont++;
      if(i==totYear-1)
      {
        if(idata>=sim->time->repetitions && cont<=sim->totPastYear)
        {
            linea=linea+" ";
        }
        else
        {
            linea=linea+sim->ult_fty_by_year[idata][i];
        }
      }
      else
      {
        if(idata>=sim->time->repetitions && cont<=sim->totPastYear)
        {
            linea=linea+" "+",";
        }
        else
        {
            linea=linea+sim->ult_fty_by_year[idata][i]+",";
        }
      }
    }
    fprintf(sout,"%s\n",linea.c_str());
  }
  fclose(sout);
}
}
//---------------------------------------------------------------------------

void __fastcall TfrmReportTableMYA_PG::sgFTYDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
      TStringGrid* StringGrid =
      static_cast<TStringGrid*>(Sender);
      assert(StringGrid != NULL);
      StringGrid->Canvas->FillRect(Rect);

      AnsiString text(
      StringGrid->Cells[ACol][ARow]);
      RECT RText = static_cast<RECT>(Rect);
      InflateRect(&RText, -3, -3);

      DrawText(StringGrid->Canvas->Handle,
      text.c_str(), text.Length(), &RText,
      DT_CENTER | DT_SINGLELINE |
      DT_VCENTER
      );
}
//---------------------------------------------------------------------------

