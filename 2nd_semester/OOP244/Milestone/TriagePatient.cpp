#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Ticket.h"
#include "utils.h"
#include "TriagePatient.h"

namespace sdds
{
	int nextTriageTicket = 1;

	TriagePatient::TriagePatient() : Patient(nextTriageTicket) {
		symptom = nullptr;
		nextTriageTicket++;
	}

	char TriagePatient::type() const {
		return 'T';
	}

	ostream& TriagePatient::csvWrite(ostream& os) const {
		Patient::csvWrite(os);
		os << ',' << symptom;
		return os;
	}

	istream& TriagePatient::csvRead(istream& is) {
		string str;
		delete[] symptom;
		symptom = nullptr;
		Patient::csvRead(is);
		is.ignore(1000, ',');
		getline(is, str, '\n');
		symptom = new char[strlen(str.c_str()) + 1];
		strcpy(symptom, str.c_str());
		nextTriageTicket = Patient::number() + 1;
		return is;
	}

	ostream& TriagePatient::write(ostream& os) const {
		if (Patient::fileIO()) {
			csvWrite(os);
		}
		else {
			os << "TRIAGE" << endl;
			Patient::write(os);
			os << endl;
			os << "Symptoms: " << symptom << endl;
		}
		return os;
	}

	istream& TriagePatient::read(istream& is) {
		if (Patient::fileIO()) {
			csvRead(is);
		}
		else {
			delete[] symptom;
			symptom = nullptr;
			Patient::read(is);
			symptom = getcstr("Symptoms: ", is, '\n');
		}
		return is;
	}

	TriagePatient::~TriagePatient() {
		delete[] symptom;
	}
}