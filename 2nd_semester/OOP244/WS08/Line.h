#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_
#include "LblShape.h"

namespace sdds
{
	class Line : public LblShape
	{
		int m_length;
	public:
		Line();
		Line(const char* str, int lineLen);
		void getSpecs(istream&);
		void draw(ostream&) const;
	};
}

#endif