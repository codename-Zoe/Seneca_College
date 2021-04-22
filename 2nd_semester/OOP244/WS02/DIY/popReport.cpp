#include "Population.h"

using namespace sdds;
int main() {
   if (load("PCpopulationsComplete.csv")) {
      display();
   }
   deallocateMemory();
   return 0;
}