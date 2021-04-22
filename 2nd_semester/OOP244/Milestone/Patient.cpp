#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Patient.h"
#include "utils.h"

using namespace std;
namespace sdds
{
	Patient::Patient(int num, bool flag) : m_ticket(num) {
		p_name = nullptr;
		OHIPnumber = 0;
		IOflag = flag;
	}

	Patient::~Patient() {
		delete[] p_name;
		p_name = nullptr;
	}

	bool Patient::fileIO() const {
		return IOflag;
	}

	void Patient::fileIO(bool flag) {
		IOflag = flag;
	}

	bool operator==(const Patient& patient, const char ch) {
		if (ch == patient.type()) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator==(const Patient& p1, const Patient& p2) {
		if (p1.type() == p2.type()) {
			return true;
		}
		else {
			return false;
		}
	}

	void Patient::setArrivalTime() {
		m_ticket.resetTime();
	}

	Patient::operator Time() const {
		return Time(m_ticket);
	}

	int Patient::number() const {
		return m_ticket.number();
	}

	ostream& Patient::csvWrite(ostream& os)const {
		os << type() << "," << p_name << "," << OHIPnumber << ",";
		m_ticket.csvWrite(os);
		return os;
	}

	istream& Patient::csvRead(istream& is) {
		string str;
		getline(is, str, ',');
		delete[] p_name;
		p_name = nullptr;
		p_name = new char[strlen(str.c_str()) + 1];
		strcpy(p_name, str.c_str());
		is >> OHIPnumber;
		is.ignore(1000, ',');
		m_ticket.csvRead(is);
		return is;
	}

	ostream& Patient::write(ostream& os)const {
		m_ticket.write(os);
		os << endl;
		if (strlen(p_name) > 25) {
			for (int i = 0; i < 25; i++) {
				os << p_name[i];
			}
		}
		else {
			os << p_name;
		}
		os << ", OHIP: " << OHIPnumber;
		return os;
	}

	istream& Patient::read(istream& is) {
		string str;
		cout << "Name: ";
		getline(is, str, '\n');
		delete[] p_name;
		p_name = nullptr;
		p_name = new char[strlen(str.c_str()) + 1];
		strcpy(p_name, str.c_str());
		OHIPnumber = getInt(100000000, 999999999, "OHIP: ", "Invalid OHIP Number, ", true);
		return is;
	}
}