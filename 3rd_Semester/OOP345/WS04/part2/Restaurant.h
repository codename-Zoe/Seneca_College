//========================================
// Restaurant module
// Restaurant.h
// Name: Nozomi Tsuchiya
// ID: 154666192
// Date: 2021/06/17
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
//========================================
#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "Reservation.h"

namespace sdds
{
	class Restaurant
	{
		Reservation* reserve{};
		size_t count{};
	public:
		Restaurant();
		Restaurant(const Reservation* reservations[], std::size_t cnt);
		std::size_t size() const;
		Restaurant(const Restaurant&); //copy constructor
		Restaurant(Restaurant&&)noexcept;      //move constructor
		Restaurant& operator=(const Restaurant&); //copy assignment
		Restaurant& operator=(Restaurant&&)noexcept;      //move assignment
		~Restaurant();
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
	};
}
#endif