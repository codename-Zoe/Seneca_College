#include <iostream>
#include <cstring>
#include <string>
#include "Item.h"

using namespace std;
namespace sdds
{
	void Item::setName(const char* name) {
		strncpy(m_itemName, name, 20);
	}

	void Item::setEmpty() {
		m_price = 0.0;
		m_itemName[0] = '\0';
	}

	void Item::set(const char* name, double price, bool taxed) {
		if (price < 0 || name == NULL) {
			setEmpty();
		}
		else {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}

	double Item::price()const {
		return m_price;
	}

	double Item::tax()const {
		double total = 0;
		if (!m_taxed) {
			total = 0.0;
		}
		else {
			total = m_price * 0.13;
		}
		return total;
	}

	bool Item::isValid()const {
		if (m_itemName[0] != '\0' || m_price > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void Item::display()const {
		string result;
		if (isValid()) {
			if (m_taxed) {
				result = "Yes";
			}
			else {
				result = "No ";
			}
			cout << "| ";
			cout.setf(ios::left);
			cout.fill('.');
			cout.width(20);
			cout << m_itemName;
			cout << " | ";
			cout.unsetf(ios::left);
			cout.width(7);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.fill(' ');
			cout << m_price << " | " << result;
			cout << " |" << endl;
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}

}

