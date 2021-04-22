// Workshop 9:
// Student.cpp
// 2021-03-26
// Version: 1.0 
// Author: Fardad Soleimanloo
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

using namespace std;
#include "Student.h"
namespace sdds {
   Student::Student() {
      set(0, "", 0.0);
   }
   Student::Student(int stno, const char* name, double gpa) {
      set(stno, name, gpa);
   }
   void Student::set(int stno, const char* name, double gpa) {
      m_stno = stno;
      strcpy(m_name, name);
      m_gpa = gpa;
   }
   ostream& Student::display(ostream& os)const {
      return os << m_stno << " " << m_name << " GPA: " << fixed << setprecision(1) << m_gpa;
   }
   istream& Student::read(istream& is) {
      is >> m_stno;
      is.getline(m_name, 40, '\n');
      return is;
   }
   bool Student::operator==(double gpa)const {
      return m_gpa > (gpa - 0.001) && m_gpa < (gpa + 0.001);
   }
}