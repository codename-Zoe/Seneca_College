#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "CovidPatient.h"

namespace sdds
{
	int nextCovidTicket = 1;

	CovidPatient::CovidPatient() : Patient(nextCovidTicket) {
		nextCovidTicket++;
	}

	char CovidPatient::type() const {
		return 'C';
	}

	istream& CovidPatient::csvRead(istream& is) {
		Patient::csvRead(is);
		nextCovidTicket = Patient::number() + 1;
		is.ignore(1000, '\n');
		return is;
	}

	ostream& CovidPatient::write(ostream& os)const {
		if (Patient::fileIO()) {
			Patient::csvWrite(os);
		}
		else {
			os << "COVID TEST" << endl;
			Patient::write(os);
			os << endl;
		}
		return os;
	}

	istream& CovidPatient::read(istream& is) {
		if (Patient::fileIO()) {
			csvRead(is);
		}
		else {
			Patient::read(is);
		}
		return is;
	}
}