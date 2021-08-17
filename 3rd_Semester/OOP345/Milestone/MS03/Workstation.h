#ifndef WORKSTATION_H
#define WORKSTATION_H
#include <deque>
#include "CustomerOrder.h"

namespace sdds
{
	extern std::deque<CustomerOrder>pending;
	extern std::deque<CustomerOrder>completed;
	extern std::deque<CustomerOrder>incomplete;
	class Workstation : public Station
	{
		std::deque<CustomerOrder> m_orders{};
		Workstation* m_pNextStation{nullptr};
	public:
		Workstation() {};
		Workstation(const std::string&);
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
		Workstation(const Workstation&) = delete;
		Workstation& operator=(const Workstation&) = delete;
		Workstation(Workstation&&) = delete;
		Workstation& operator=(Workstation&&) = delete;
	};
}
#endif // !WORKSTATION_H