#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include "Ticket.h"
#include "IOAble.h"

using namespace std;
namespace sdds
{
	class Patient : public IOAble
	{
		char* p_name;
		int OHIPnumber;
		Ticket m_ticket;
		bool IOflag;
	public:
		Patient(int num = 0, bool flag = false);
		~Patient();
		Patient(const Patient&) = delete;
		Patient& operator=(const Patient&) = delete;

		virtual char type() const = 0;
		bool fileIO() const;
		void fileIO(bool);
		void setArrivalTime();
		operator Time() const;
		int number() const;

		virtual ostream& csvWrite(ostream&)const;
		virtual istream& csvRead(istream&);
		virtual ostream& write(ostream&)const;
		virtual istream& read(istream&);
	};
	bool operator==(const Patient&, const char);
	bool operator==(const Patient&, const Patient&);
}
#endif