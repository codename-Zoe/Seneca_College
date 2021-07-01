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
