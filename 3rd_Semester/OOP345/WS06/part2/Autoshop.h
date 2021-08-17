#ifndef AUTOSHOP_H
#define AUTOSHOP_H
#include <vector>
#include <list>
#include "Car.h"
#include "Vehicle.h"

namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();

		// iterates over the vehicles stored in the m_vehicles 
		// and add vehicles to 
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			std::vector<Vehicle*>::iterator i;
			for (i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
				if (test(*i)) {
					vehicles.push_back(*i);
				}
			}
		}
	};
}
#endif