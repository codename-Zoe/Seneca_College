#include "Employee.h"

using namespace sdds;
int main() {
    if (load()) {
        display();
    }
    deallocateMemory();
    return 0;
}