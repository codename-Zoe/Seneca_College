// Workshop 9:
// ReadWrite.cpp
// 2021-03-26
// Version: 1.0 
// Author: Fardad Soleimanloo
/////////////////////////////////////////////
#include <iostream>
#include "ReadWrite.h"
using namespace std;
namespace sdds {
   ostream& operator<<(ostream& os, const ReadWrite& c) {
      return c.display(os);
   }

   istream& operator >> (istream& is, ReadWrite& c) {
      return c.read(is);
   }
}