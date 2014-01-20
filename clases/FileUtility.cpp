#ifndef FileUtilityCPP
#define FileUtilityCPP
#include "FileUtility.h"
#include <fstream>
#include "vector.h"
#include "sstream.h"
//------------------------------------------------------------------------------
FileData::FileData()
{
}
//------------------------------------------------------------------------------
FileData::~FileData()
{
}
//------------------------------------------------------------------------------
int FileData::GetFieldsName(char *FieldsList[],char *FileName)
{
  ifstream in(FileName);
  string line;
  vector<string> v;
  string buffer;
  getline(in,line,'\n');
  stringstream aStream;
  aStream << line;
  const char* valor;
  int z=0;
  int num;
  while(!aStream.eof())
  {
    z++;
    aStream >> buffer;
    v.push_back(buffer);
    num=strlen(v[z-1].c_str());
    char* dato = new char[ num + 1 ];
    strcpy(dato, v[z-1].c_str());
    FieldsList[z-1]=dato;
  }
  in.close();
  return z;
}
//------------------------------------------------------------------------------
int FileData::GetFieldsNameFromCSVFile(char *FieldsList[],char *FileName)
{
std::ifstream  data(FileName);
int cont=0;
int num;
    std::string line;
//    while(std::getline(data,line))
//    {
std::getline(data,line);
        std::stringstream  lineStream(line);
        std::string        cell;
        while(std::getline(lineStream,cell,','))
        {
          cont++;
          // Aqui obtenemos una celda
          num=strlen(cell.c_str());
          char* dato = new char[ num + 1 ];
          strcpy(dato,cell.c_str());
          FieldsList[cont-1]=dato;
        }
//    }
data.close();
  return cont;
}
//------------------------------------------------------------------------------
int FileData::GetNumberLinesFromCSVFile(char *FileName)
{
std::ifstream data(FileName);
int cont=0;
std::string line;
//std::getline(data,line);
//std::stringstream  lineStream(line);
//std::string        cell;
while(std::getline(data,line))
{
  cont++;
}
data.close();
return cont;
}
//------------------------------------------------------------------------------
#endif
