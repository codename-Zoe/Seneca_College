#include <iostream>
#include <cstring>
#include "Bill.h"
using namespace std;
namespace sdds {
	Item* m_items = nullptr;

	void Bill::setEmpty() {
		m_title[0] = '\0';
		m_items = nullptr;
	}

	bool Bill::isValid()const {
		bool result = true;
		int i;
		if (m_title[0] != '\0' && m_items != nullptr) {
			for (i = 0; i < m_noOfItems && result == true; i++) {
				if (m_items[i].isValid()) {
					result = true;
				}
				else {
					result = false;
				}
			}
		}
		else {
			result = false;
		}
		return result;
	}

	double Bill::totalTax()const {  
		double totalTax = 0.0;
		for (int i = 0; i < m_noOfItems; i++) {
			totalTax += m_items[i].tax();
		}
		return totalTax;
	}

	double Bill::totalPrice()const {
		double total = 0.0;
		for (int i = 0; i < m_noOfItems; i++) {
			total += m_items[i].price();
		}
		return total;
	}

	void Bill::Title()const {
		cout << "+--------------------------------------+" << endl;
		if (isValid()) {
			cout << "| ";
			cout.setf(ios::left);
			cout.width(36);
			cout << m_title << " |" << endl;
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	void Bill::footer()const {
		cout << "+----------------------+---------+-----+" << endl;
		if (isValid()) {
			cout << "|                Total Tax: ";
			cout.width(10);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << totalTax() << " |" << endl;
			cout << "|              Total Price: ";
			cout.width(10);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << totalPrice() << " |" << endl;
			cout << "|          Total After Tax: ";
			cout.width(10);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << totalTax() + totalPrice() << " |" << endl;
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+--------------------------------------+" << endl;
	}

	void Bill::init(const char* title, int noOfItems) {
		if (title[0] == '\0'|| noOfItems <= 0) {
			setEmpty();
		}
		else {
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strncpy(m_title, title, 36);
			m_items = new Item[m_noOfItems];
			for (int i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}
	}

	bool Bill::add(const char* item_name, double price, bool taxed) {
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			return true;
		}
		return false;
	}

	void Bill::display()const {
		int i = 0;
		Title();
		for (i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}
		footer();
	}

	void Bill::deallocate() {
		delete[] m_items;
		m_items = nullptr;
	}

}