#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds
{
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }

   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }

   void closeFile() {
      if (fptr) fclose(fptr);
   }

   bool read(char* m_name) {
       bool result;
        if (fscanf(fptr, "%[^\n]\n", m_name) == 1){
        result = true;
        }
        else {
        result = false;
        }
        return result;
   }

   bool read(int& m_empNo) {
       bool result;
        if (fscanf(fptr, "%d,", &m_empNo) == 1){
            result = true;
        }
        else {
            result = false;
        }
        return result;
   }

   bool read(double& m_salary) {
       bool result;
       if (fscanf(fptr, "%lf,", &m_salary) == 1) {
           result = true;
       }
       else {
           result = false;
       }
       return result;
   }
}