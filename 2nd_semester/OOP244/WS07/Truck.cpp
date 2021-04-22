#include <iostream>
#include "MotorVehicle.h"
#include "Truck.h"

using namespace std;
namespace sdds
{
	Truck::Truck(const char plate[], int builtYear, double capacity, const char newAddress[]) : MotorVehicle(plate, builtYear) {
		maxCapacity = capacity;
		cargoWeight = 0;
		MotorVehicle::moveTo(newAddress);
	}

	bool Truck::addCargo(double cargo) {
		if (maxCapacity != cargoWeight) {
			if (maxCapacity >= (cargoWeight + cargo)) {
				cargoWeight += cargo;
				return true;
			}
			else {
				cargoWeight = maxCapacity;
				return true;
			}
		}
		else {
			return false;
		}
	}

	bool Truck::unloadCargo() {
		if (cargoWeight != 0) {
			cargoWeight = 0;
			return true;
		}
		else {
			return false;
		}
	}

	ostream& Truck::write(ostream& os) const {
		MotorVehicle::write(os);
		os << " | " << cargoWeight << "/" << maxCapacity;
		return os;
	}

	istream& Truck::read(istream& in) {
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> maxCapacity;
		cout << "Cargo: ";
		in >> cargoWeight;
		return in;
	}

	ostream& operator<<(ostream& ostr, const Truck& truck) {
		return truck.write(ostr);
	}

	istream& operator>>(istream& istr, Truck& truck) {
		return truck.read(istr);
	}

}