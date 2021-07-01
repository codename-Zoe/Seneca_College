//========================================
// ConfirmationSender module
// ConfirmationSender.h
// Name: Nozomi Tsuchiya
// ID: 154666192
// Date: 2021/06/17
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
//========================================
#ifndef CONFIRMATIONSENDER_H
#define CONFIRMATIONSENDER_H
#include "Reservation.h"

namespace sdds
{
	class ConfirmationSender
	{
		const Reservation** ptr_reserve{};
		size_t count{};
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender&);    //copy constructor
		ConfirmationSender(ConfirmationSender&&)noexcept; //move constructor
		ConfirmationSender& operator=(const ConfirmationSender&);    //copy assignment
		ConfirmationSender& operator=(ConfirmationSender&&)noexcept; //move assignment
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		~ConfirmationSender();
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs);
	};

}
#endif