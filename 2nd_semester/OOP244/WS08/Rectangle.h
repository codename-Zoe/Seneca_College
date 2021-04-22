#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_
#include "LblShape.h"

namespace sdds
{
	class Rectangle : public LblShape
	{
		int m_width;
		int m_height;
	public:
		Rectangle();
		Rectangle(const char* str, int width, int height);
		void getSpecs(istream&);
		void draw(ostream&) const;
	};
}

#endif