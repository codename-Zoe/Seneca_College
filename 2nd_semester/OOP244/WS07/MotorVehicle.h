#ifndef SDDS_VEHICLE_H_
#define SDDS_VEHICLE_H_
const int maxPlateNum = 9;
const int addressSize = 64;

using namespace std;
namespace sdds
{
	class MotorVehicle
	{
		char plate[maxPlateNum];
		char address[addressSize];
		int year;
	public:
		MotorVehicle(const char plateNum[], int year);
		void moveTo(const char* address);
		ostream& write(ostream& os)const;
		istream& read(istream& in);
	};
	ostream& operator<<(ostream& ostr, const MotorVehicle& vehicle);
	istream& operator>>(istream& istr, MotorVehicle& vehicle);
}
#endif