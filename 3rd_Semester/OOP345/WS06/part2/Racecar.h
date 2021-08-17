#ifndef RACECAR_H
#define RACECAR_H
#include "Car.h"

namespace sdds
{
	class Racecar : public Car
	{
		double m_booster{ 0.0 };
	public:
		Racecar() {};
		Racecar(std::istream&);
		void display(std::ostream&) const;
		double topSpeed() const;
	};
}
#endif