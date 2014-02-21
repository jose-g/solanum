//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UImportCropParameter.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmImportCropParameter *frmImportCropParameter;
//---------------------------------------------------------------------------
__fastcall TfrmImportCropParameter::TfrmImportCropParameter(int clave_)
        : TForm(Owner)
{
  clave=clave_;
  dbcultivoTemp=new DBCultivo();
  hizo=false;
  if(clave==2) // export crop parameters
  {
    butOpen->Visible=false;
    butImport->Caption="Export ...";
    this->Caption="Export ...";
    chkbSelect->Visible=true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmImportCropParameter::butImportClick(TObject *Sender)
{
  if(clave==1)
  {

    if(dbcultivoTemp->numreg>0)
    {
      int cont=0;
      int selec=0;
      for(int i=0;i<dbcultivoTemp->numreg;i++)
      {
        if(chkLB->Checked[i])
        {
          selec++;
          int indice=dbcultivo->numreg;
          strcpy(dbcultivo->Item[indice].cropname,dbcultivoTemp->Item[i].cropname);
          dbcultivo->Item[indice].plant->fcl=dbcultivoTemp->Item[i].plant->fcl;
          dbcultivo->Item[indice].plant->F0=dbcultivoTemp->Item[i].plant->F0;
          dbcultivo->Item[indice].plant->R0=dbcultivoTemp->Item[i].plant->R0;
          dbcultivo->Item[indice].tuber->M=dbcultivoTemp->Item[i].tuber->M;
          dbcultivo->Item[indice].tuber->A=dbcultivoTemp->Item[i].tuber->A;
          dbcultivo->Item[indice].tuber->b=dbcultivoTemp->Item[i].tuber->b;
          dbcultivo->Item[indice].tuber->DMCont=dbcultivoTemp->Item[i].tuber->DMCont;
          dbcultivo->Item[indice].plant->LUE=dbcultivoTemp->Item[i].plant->LUE;
          dbcultivo->Item[indice].tuber->Tcr=dbcultivoTemp->Item[i].tuber->Tcr;
          dbcultivo->Item[indice].tuber->Tld=dbcultivoTemp->Item[i].tuber->Tld;
          dbcultivo->Item[indice].tuber->Trg=dbcultivoTemp->Item[i].tuber->Trg;
          dbcultivo->Item[indice].plant->EDay=dbcultivoTemp->Item[i].plant->EDay;
          dbcultivo->Item[indice].tuber->w=dbcultivoTemp->Item[i].tuber->w;
          dbcultivo->Item[indice].tuber->Pc=dbcultivoTemp->Item[i].tuber->Pc;
          dbcultivo->numreg++;
        }
      }
      if(selec==0)
      {
        Application->MessageBox("You should select one crop at least !!!", "Warning!", MB_OK);
      }
      else
      {
        hizo=true;
        Close();
      }
    }
    else
    {
      Application->MessageBox("First, you should open a crop database !!!", "Warning!", MB_OK);
    }
  }
  if(clave==2)
  {
    if(dbcultivo->numreg<=0)
    {
      Application->MessageBox("There is no crop parameters in the database to export !!!", "Warning!", MB_OK);
      Close();
    }
    else
    {
      int selec=0;
      for(int i=0;i<dbcultivo->numreg;i++)
      {
        if(chkLB->Checked[i])
        {
          selec++;
        }
      }
      if(selec==0)
      {
        Application->MessageBox("You should select one crop at least !!!", "Warning!", MB_OK);
      }
      else
      { // si todo esta correcto se guarda los cultivos seleccionados
        AnsiString NomArchivo;
        bool exito=false;
        if(sdResult->Execute())
        {
           NomArchivo=sdResult->FileName;
           int indice=-1;
           dbcultivoTemp->numreg=0;
           for(int i=0;i<dbcultivo->numreg;i++)
           {
             if(chkLB->Checked[i])
             {
                indice++;
                strcpy(dbcultivoTemp->Item[indice].cropname,dbcultivo->Item[i].cropname);
                dbcultivoTemp->Item[indice].plant->fcl=dbcultivo->Item[i].plant->fcl;
                dbcultivoTemp->Item[indice].plant->F0=dbcultivo->Item[i].plant->F0;
                dbcultivoTemp->Item[indice].plant->R0=dbcultivo->Item[i].plant->R0;
                dbcultivoTemp->Item[indice].tuber->M=dbcultivo->Item[i].tuber->M;
                dbcultivoTemp->Item[indice].tuber->A=dbcultivo->Item[i].tuber->A;
                dbcultivoTemp->Item[indice].tuber->b=dbcultivo->Item[i].tuber->b;
                dbcultivoTemp->Item[indice].tuber->DMCont=dbcultivo->Item[i].tuber->DMCont;
                dbcultivoTemp->Item[indice].plant->LUE=dbcultivo->Item[i].plant->LUE;
                dbcultivoTemp->Item[indice].tuber->Tcr=dbcultivo->Item[i].tuber->Tcr;
                dbcultivoTemp->Item[indice].tuber->Tld=dbcultivo->Item[i].tuber->Tld;
                dbcultivoTemp->Item[indice].tuber->Trg=dbcultivo->Item[i].tuber->Trg;
                dbcultivoTemp->Item[indice].plant->EDay=dbcultivo->Item[i].plant->EDay;
                dbcultivoTemp->Item[indice].tuber->w=dbcultivo->Item[i].tuber->w;
                dbcultivoTemp->Item[indice].tuber->Pc=dbcultivo->Item[i].tuber->Pc;
                dbcultivoTemp->numreg++;
             }
           }
           hizo=dbcultivoTemp->saveAllParameters(NomArchivo.c_str());
           Close();
        }
      }
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmImportCropParameter::FormClose(TObject *Sender,
      TCloseAction &Action)
{
delete dbcultivoTemp;
}
//---------------------------------------------------------------------------
void __fastcall TfrmImportCropParameter::butOpenClick(TObject *Sender)
{
  AnsiString NomArchivo;
  bool exito=false;
  if(odAbrir->Execute())
  {
    NomArchivo=odAbrir->FileName;
    exito=dbcultivoTemp->LoadCrops(NomArchivo.c_str());
    for(int i=0;i<dbcultivoTemp->numreg;i++)
    {
      chkLB->Items->Add(dbcultivoTemp->Item[i].cropname);
    }
  }
}
//---------------------------------------------------------------------------
void TfrmImportCropParameter::EnterInformation(DBCultivo* _dbcultivo)
{
dbcultivo=_dbcultivo;
}
//---------------------------------------------------------------------------
void __fastcall TfrmImportCropParameter::FormShow(TObject *Sender)
{
  if(clave==2)  // export crop parameters
  {
    if(dbcultivo->numreg<=0)
    {
      Application->MessageBox("There is no crop parameters in the database to export !!!", "Warning!", MB_OK);
    }
    else
    {
      for(int i=0;i<dbcultivo->numreg;i++)
      {
        chkLB->Items->Add(dbcultivo->Item[i].cropname);
      }
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TfrmImportCropParameter::chkbSelectClick(TObject *Sender)
{
  for(int i=0;i<chkLB->Count;i++)
  {
    chkLB->Checked[i]=chkbSelect->Checked;
  }
}
//---------------------------------------------------------------------------
