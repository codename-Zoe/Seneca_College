#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include "Patient.h"

namespace sdds
{
	class CovidPatient : public Patient
	{
	public:
		CovidPatient();
		virtual char type() const;
		virtual istream& csvRead(istream&);
		virtual ostream& write(ostream&) const;
		virtual istream& read(istream&);
	};
}
#endif
