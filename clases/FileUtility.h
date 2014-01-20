#ifndef FileUtilityH
#define FileUtilityH
  class FileData
  {
    public:
      FileData();
      ~FileData();
      int GetFieldsName(char*[],char*);
      int GetFieldsNameFromCSVFile(char*[],char*);
      int GetNumberLinesFromCSVFile(char*);
  };
#endif
