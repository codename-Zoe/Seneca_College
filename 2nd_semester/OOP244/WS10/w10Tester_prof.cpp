// Workshop 10:
// Version: 1.0
// Date: 2021-04-04
// Author: Fardad Soleimanloo
// Description:
// This file tests the lab section of your workshop for submission
/////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "HtmlText.h"
#include "Text.h"
using namespace std;
using namespace sdds;
void show(Text T)  {
   cout << "*" << T << "*" << endl;
}
void saveHtml(HtmlText H) {
   ofstream("dcwr.html")<<H;
}
void displayFile(const char* filename) {
   cout << "File: " << filename << endl;
   cout << "==================================================" << endl;
   ifstream fin(filename);
   char ch = 0;
   while (fin.get(ch)) {
      cout << ch;
   }
   cout << endl << "==================================================" << endl;
}
int main() {
   Text T("test.txt");
   Text Y("dcwr.txt");
   Text Z;
   Y = T;
   Z = Y;
   show(Y);
   HtmlText H1("dcwr.txt", "Derived Classes and Resources");
   HtmlText H2("dcwr.txt");
   HtmlText H3;
   H2 = H1;
   H3 = H2;
   saveHtml(H3);
   displayFile("dcwr.html");
   return 0;
}