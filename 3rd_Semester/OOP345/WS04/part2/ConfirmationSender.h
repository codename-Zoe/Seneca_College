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
