#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "PreTriage.h"
#include "CovidPatient.h"
#include "TriagePatient.h"

using namespace std;
namespace sdds
{
	PreTriage::PreTriage(const char* dataFilename) : m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), 
		                                             m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {
		m_averCovidWait = 15;
		m_averTriageWait = 5;
		m_dataFilename = new char[strlen(dataFilename) + 1];
		strcpy(m_dataFilename, dataFilename);
		load();
	}

	PreTriage::~PreTriage() {
		ofstream file;
		file.open(m_dataFilename);
		if (file.is_open()) {
			file << m_averCovidWait << "," << m_averTriageWait << endl;
			cout << "Saving Average Wait Times," << endl;
			cout << "   COVID Test: " << m_averCovidWait << endl;
			cout << "   Triage: " << m_averTriageWait << endl;
			cout << "Saving m_lineup..." << endl;
			for (int i = 0; i < m_lineupSize; i++) {
				m_lineup[i]->csvWrite(file) << endl;
				cout << i + 1 << "- ";
				m_lineup[i]->csvWrite(cout) << endl;
				delete m_lineup[i];
			}
			delete[] m_dataFilename;
			cout << "done!" << endl;
		}
	}

	const Time PreTriage::getWaitTime(const Patient& p)const {
		unsigned int count = 0;
		Time time;
		for (int i = 0; i < m_lineupSize; i++) {
			if (m_lineup[i]->type() == p.type()) {
				count++;
			}
		}
		time *= count;
		return time;
	}

	void PreTriage::setAverageWaitTime(const Patient& p) {
		Time time;
		unsigned int t_num = p.number();
		time.setToNow();
		if (p.type() == 'C') {
			m_averCovidWait = ((time - p.operator Time()) + (m_averCovidWait * (t_num - 1))) / t_num;
		}
		else if (p.type() == 'T') {
			m_averTriageWait = ((time - p.operator Time()) + (m_averTriageWait * (t_num - 1))) / t_num;
		}
	}

	void PreTriage::removePatientFromLineup(int index) {
		removeDynamicElement<Patient>(m_lineup, index, m_lineupSize);
	}

	int PreTriage::indexOfFirstInLine(char type) const {
		int index = -1;
		for (int i = 0; i < m_lineupSize && index == -1; i++) {
			if (m_lineup[i]->type() == type) {
				index = i;
			}
		}
		return index;
	}

	void PreTriage::load() {
		char ch = 'x';
		cout << "Loading data..." << endl;
		ifstream file(m_dataFilename);
		if (file) {
			file >> m_averCovidWait;
			file.ignore(1000, ',');
			file >> m_averTriageWait;
			file.ignore(1000, '\n');
			Patient* patient = nullptr;
			for (int i = 0; i < maxNoOfPatients && !file.eof(); i++) {
				ch = file.get();
				file.ignore(1000, ',');
				if (ch == 'C') {
					patient = new CovidPatient();
				}
				else if (ch == 'T') {
					patient = new TriagePatient();
				}

				if (patient != nullptr) {
					patient->fileIO(true);
					patient->csvRead(file);
					patient->fileIO(false);
					m_lineup[i] = patient;
					m_lineupSize++;
					patient = nullptr;
				}
			}
			if (!file.eof()) {
				cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
			}

			if (m_lineupSize == 0) {
				cout << "No data or bad data file!" << endl << endl;
			}
			else {
				cout << m_lineupSize << " Records imported..." << endl << endl; 
			}
		}
	}

	void PreTriage::reg() {
		int select;
		if (m_lineupSize >= maxNoOfPatients) {
			cout << "Line up full!" << endl;
			return;
		}
		m_pMenu >> select;
		if (select == 1) {
			m_lineup[m_lineupSize] = new CovidPatient();
		}
		else if (select == 2) {
			m_lineup[m_lineupSize] = new TriagePatient();
		}
		else if (select == 0) {
			return;
		}
		m_lineup[m_lineupSize]->setArrivalTime();
		cout << "Please enter patient information: " << endl;
		m_lineup[m_lineupSize]->fileIO(false);
		m_lineup[m_lineupSize]->read(cin);
		cout << endl << "******************************************" << endl;
		cout << *m_lineup[m_lineupSize];
		cout << "Estimated Wait Time: ";
		cout << getWaitTime(*m_lineup[m_lineupSize]) << endl;
		cout << "******************************************" << endl << endl;
		m_lineupSize++;
	}

	void PreTriage::admit() {
		int select, index;
		char type;
		m_pMenu >> select;
		if (select == 1) {
			type = 'C';
		}
		else if (select == 2) {
			type = 'T';
		}
		else if (select == 0) {
			return;
		}
		index = indexOfFirstInLine(type);
		if (index == -1) {
			return;
		}
		cout << endl << "******************************************" << endl;
		m_lineup[index]->fileIO(false);
		cout << "Calling for ";
		m_lineup[index]->write(cout);
		cout << "******************************************" << endl << endl;
		setAverageWaitTime(*m_lineup[index]);
		removePatientFromLineup(index);
	}

	void PreTriage::run(void) {
		int select;
		do {
			m_appMenu >> select;
			if (select == 0) {
				return;
			}
			else if (select == 1) {
				reg();
			}
			else if (select == 2) {
				admit();
			}
		} while (select != 0);
	}
}