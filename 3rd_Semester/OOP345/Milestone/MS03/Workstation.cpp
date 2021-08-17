#include <iostream>
#include <vector>
#include "Workstation.h"

using namespace std;
namespace sdds
{
	std::deque<CustomerOrder> pending{};
	std::deque<CustomerOrder> completed{};
	std::deque<CustomerOrder> incomplete{};

	Workstation::Workstation(const std::string& str) : Station(str){}

	void Workstation::fill(std::ostream& os) {
		if (!m_orders.empty()) {
			m_orders.begin()->fillItem(*this, os);
		}
	}

	bool Workstation::attemptToMoveOrder() {
		bool isMoved = false;
		if (!m_orders.empty()) {
			if (m_orders.front().isItemFilled(getItemName())) {
				if (!m_pNextStation) {
					if (m_orders.front().isFilled()) {
						completed.push_back(move(m_orders.front()));
					}
					else {
						incomplete.push_back(move(m_orders.front()));
					}
					m_orders.pop_front();
				}
				else {
					*m_pNextStation += move(m_orders.front());
					m_orders.pop_front();
				}
				isMoved = true;
			}
			else if (getQuantity() == 0) {
				if (!m_pNextStation) {
					incomplete.push_back(move(m_orders.front()));
					m_orders.pop_front();
				}
				else {
					*m_pNextStation += move(m_orders.front());
					m_orders.pop_front();
				}
				isMoved = true;
			}
		}
		return isMoved;
	}

	void Workstation::setNextStation(Workstation* station = nullptr) {
		m_pNextStation = station;
	}

	Workstation* Workstation::getNextStation() const {
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const {
		os << getItemName() << " --> ";
		m_pNextStation == nullptr ? os << "End of Line" << endl : os << m_pNextStation->getItemName() << endl;
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
		m_orders.push_back(move(newOrder));
		return *this;
	}
}