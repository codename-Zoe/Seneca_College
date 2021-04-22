#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "MotorVehicle.h"

using namespace std;
namespace sdds
{
	MotorVehicle::MotorVehicle(const char plateNum[], int builtYear) {
		if (strlen(plateNum) < maxPlateNum) {
			strcpy(plate, plateNum);
		}
		year = builtYear;
		strcpy(address, "Factory");
	}

	void MotorVehicle::moveTo(const char* newAddress) {
		if (strcmp(address, newAddress) != 0) {
			cout << "|" << setw(8) << setfill(' ') << right << plate << "| |"
				 << setw(20) << setfill(' ') << address << " ---> "
				 << setw(20) << setfill(' ') << left << newAddress << "|" << endl;
			strcpy(address, newAddress);
		}
	}

	ostream& MotorVehicle::write(ostream& os)const {
		os << "| " << year << " | " << plate << " | " << address ;
		return os;
	}

	istream& MotorVehicle::read(istream& in) {
		cout << "Built year: ";
		in >> year;
		cout << "License plate: ";
		in >> plate;
		cout << "Current location: ";
		in >> address;
		return in;
	}

	ostream& operator<<(ostream& ostr, const MotorVehicle& vehicle) {
		vehicle.write(ostr);
		return ostr;
	}

	istream& operator>>(istream& istr, MotorVehicle& vehicle) {
		vehicle.read(istr);
		return istr;
	}

}