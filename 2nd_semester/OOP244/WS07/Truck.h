#ifndef SDDS_TRUCK_H_
#define SDDS_TRUCK_H_
#include "MotorVehicle.h"

using namespace std;
namespace sdds
{
	class Truck : public MotorVehicle
	{
		double maxCapacity;
		double cargoWeight;
	public:
		Truck(const char plate[], int builtYear, double capacity, const char address[]);
		bool addCargo(double cargo);
		bool unloadCargo();
		ostream& write(ostream& os) const;
		istream& read(istream& in);
	};
	ostream& operator<<(ostream& ostr, const Truck& Truck);
	istream& operator>>(istream& istr, Truck& Truck);
}
#endif