#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include "Patient.h"

namespace sdds
{
	class TriagePatient : public Patient
	{
		char* symptom;
	public:
		TriagePatient();
		virtual char type() const;
		virtual ostream& csvWrite(ostream&) const;
		virtual istream& csvRead(istream&);
		virtual ostream& write(ostream&) const;
		virtual istream& read(istream&);
		~TriagePatient();
	};
}
#endif


