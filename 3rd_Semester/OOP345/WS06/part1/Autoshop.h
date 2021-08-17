#ifndef AUTOSHOP_H
#define AUTOSHOP_H
#include <vector>
#include "Car.h"
#include "Vehicle.h"

namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out); // const;
		~Autoshop();
	};
}
#endif