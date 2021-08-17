#include <iostream>
#include <iomanip>
#include <algorithm>
#include "CustomerOrder.h"

using namespace std;
namespace sdds
{
	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder(const std::string& str) {
		Utilities util;
		bool more = false;
		size_t next_pos = 0;
		m_name = util.extractToken(str, next_pos, more);
		m_product = util.extractToken(str, next_pos, more);
		string items = str.substr(next_pos, str.length() - next_pos);
		m_cntItem = count(items.begin(), items.end(), util.getDelimiter()) + 1;
		m_lstItem = new Item* [m_cntItem];
		for (size_t i = 0; i < m_cntItem && more; i++) {
			m_lstItem[i] = new Item(util.extractToken(str, next_pos, more));
		}
		m_widthField < util.getFieldWidth() ? m_widthField = util.getFieldWidth() : m_widthField;
	}

	// copy constructor
	CustomerOrder::CustomerOrder(const CustomerOrder& src) { 
		throw "Copy operations are not allowed!";
	}

	// move constructor
	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept { 
		*this = move(src);
	}

	// move assignment operator
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept { 
		if (this != &src) {
			for (size_t i = 0; i < m_cntItem; i++) {
				delete m_lstItem[i];
			}
			delete[] m_lstItem;
			m_name = src.m_name;
			m_product = src.m_product;
			m_cntItem = src.m_cntItem;
			m_lstItem = src.m_lstItem;
			src.m_name = "";
			src.m_product = "";
			src.m_cntItem = 0;
			src.m_lstItem = nullptr;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder() {
		for (size_t i = 0; i < m_cntItem; i++) {
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}

	// check if all the items in the order have been filled
	bool CustomerOrder::isFilled() const {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (!m_lstItem[i]->m_isFilled) {
				return false;
			}
		}
		return true;
	}

	// check if all items specified by itemName have been filled
	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		bool isFilled = true;
		for (size_t i = 0; i < m_cntItem && isFilled; i++) {
			if (m_lstItem[i]->m_itemName == itemName) {
				isFilled = m_lstItem[i]->m_isFilled;
			}
		}
		return isFilled;
	}

	// it fills all items in the current order that the Station specified in the first parameter
	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == station.getItemName()) {
				if (station.getQuantity() > 0) {
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					station.updateQuantity();
					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
				}
				else {
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
				}
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << endl;
		for (size_t i = 0; i < m_cntItem; i++) {
			os << '[' << right << setw(6) << setfill('0')<< m_lstItem[i]->m_serialNumber;
			os << "] " << left << setw(m_widthField) << setfill(' ') << m_lstItem[i]->m_itemName << " - ";
			m_lstItem[i]->m_isFilled ? os << "FILLED" << endl : os << "TO BE FILLED" << endl;
		}
	}

}