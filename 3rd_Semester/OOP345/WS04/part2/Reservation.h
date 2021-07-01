#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>

namespace sdds
{
	class Reservation
	{
		std::string res_id{};
		std::string res_name{};
		std::string email{};
		int party_size{};
		int day{};
		int hour{};
	public:
		Reservation();
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
	};
}
#endif
