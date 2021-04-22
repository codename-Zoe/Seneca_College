#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_
#include "Shape.h"

using namespace std;
namespace sdds
{
	class LblShape : public Shape
	{
		char* m_label = nullptr;
	protected:
		const char* label() const;
	public:
		LblShape();
		LblShape(const char* str);
		~LblShape();
		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape&) = delete;
		void getSpecs(istream&);
	};
}

#endif