// Final Project Tester
// file: fp1Tester.cpp
// Version: 0.9
// Date: 2021-03-26
// Author: Fardad 
// Description:
// This file tests the Final project 
// with no data file
/////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "PreTriage.h"
#include "utils.h"
using namespace sdds;
using namespace std;
int main() {
   sdds::debug = true;
   ofstream("data.csv").close();
   PreTriage P("data.csv");
   P.run();
   return 0;
}

