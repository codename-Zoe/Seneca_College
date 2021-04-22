#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char* m_name);
   bool read(int& m_empNo);
   bool read(double& m_salary);
}
#endif
