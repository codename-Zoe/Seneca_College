//========================================
// Reservation module
// Reservation.h
// Name: Nozomi Tsuchiya
// ID: 154666192
// Date: 2021/06/17
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
//========================================

#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>

namespace sdds
{
	class Reservation
	{
		std::string res_id;
		std::string res_name;
		std::string email;
		int party_size;
		int day;
		int hour;
	public:
	Reservation();
	Reservation(const std::string& res);
	friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
	};
}
#endif