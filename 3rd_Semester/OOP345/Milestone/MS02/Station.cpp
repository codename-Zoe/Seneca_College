#include <iostream>
#include <iomanip>
#include <string>
#include "Station.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
	size_t Station::m_widthField = 0;
	size_t Station::id_generator = 0;

	Station::Station(const std::string& str) {
		Utilities util;
		size_t next_pos = 0;
		bool more = true;
		id_generator++;

		//set extracted value to each member variables
		m_id = id_generator;
		m_name = util.extractToken(str, next_pos, more);
		m_serial = stoi(util.extractToken(str, next_pos, more));
		num_items = stoi(util.extractToken(str, next_pos, more));
		util.getFieldWidth() > m_widthField ? m_widthField = util.getFieldWidth() : m_widthField;
		m_desc = util.extractToken(str, next_pos, more);
	}

	const std::string& Station::getItemName() const {
		return m_name;
	}

	size_t Station::getNextSerialNumber() {
		m_serial++;
		return m_serial - 1;
	}

	size_t Station::getQuantity() const {
		return num_items;
	}

	void Station::updateQuantity() {
		num_items < 0 ? num_items = 0 : num_items--;
	}

	void Station::display(std::ostream& os, bool full) const {
		if (!full) {
			os << "[" << right << setfill('0') << setw(3) << m_id << "] Item: " << setfill(' ') << left << setw(m_widthField) << m_name;
			os << " [" << right << setfill('0') << setw(6) << m_serial << "]" << endl;
		}
		else {
			os << "[" << right << setfill('0') << setw(3) << m_id << "] Item: " << setfill(' ') << left << setw(m_widthField) << m_name;
			os << " [" << right << setfill('0') << setw(6) << m_serial << "] Quantity: ";
			os << setfill(' ') << left << setw(m_widthField) << num_items << " Description: " << m_desc << endl;
		}
	}
}