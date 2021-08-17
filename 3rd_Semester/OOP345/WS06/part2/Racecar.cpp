#include "Racecar.h"

using namespace std;
namespace sdds
{
	Racecar::Racecar(std::istream& in) : Car(in){
		string booster;
		getline(in, booster, '\n');

		booster.erase(0, booster.find_first_not_of(' '));
		booster.erase(booster.find_last_not_of(' ') + 1);

		m_booster = stod(booster);
	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const {
		return Car::topSpeed() * (1 + m_booster);
	}
}

