#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle
	{
		std::string m_maker{};
		std::string m_condition{};
		double m_topSpeed{};
	public:
		Car() {};
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream&) const;
	};
}
#endif