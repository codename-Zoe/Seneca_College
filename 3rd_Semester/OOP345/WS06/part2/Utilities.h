#ifndef UTILITIES_H
#define UTILITIES_H
#include "Car.h"
#include "Vehicle.h"
#include "Racecar.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in);
}
#endif