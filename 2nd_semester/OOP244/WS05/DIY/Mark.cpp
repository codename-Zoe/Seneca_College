#include "Mark.h"

using namespace std;
namespace sdds
{
	void Mark::setInvalid() {
		m_value = -1;
	}

	void Mark::setDefault() {
		m_value = 0;
	}

	Mark::Mark() {
		setDefault();
	}

	Mark::Mark(int num) {
		if (0 <= num && num <= 100) {
			m_value = num;
		}
		else {
			setInvalid();
		}
	}		

	Mark::operator int() const{
		if (m_value == -1) {
			return 0;
		}
		return m_value;
	}

	Mark& Mark::operator+=(const int num) {
		if (m_value != -1) {
			m_value += num;
		}
		if (m_value > 100) {
			setInvalid();
		}
		return *this;
	}

	Mark& Mark::operator=(const int num) {
		if (0 <= num && num <= 100 && m_value != -1) {
			m_value = num;
		}
		else if (0 <= num && num <= 100 && m_value == -1) {
			setDefault();
			m_value = num;
		}
		else {
			setInvalid();
		}
		return *this;
	}

	Mark::operator double() const {
		int result;
		if (m_value == -1) {
			result = 0;
		}
		else if (0 <= m_value && m_value < 50) {
			result = 0;
		}
		else if (50 <= m_value && m_value < 60) {
			result = 1;
		}
		else if (60 <= m_value && m_value < 70) {
			result = 2;
		}
		else if (70 <= m_value && m_value < 80) {
			result = 3;
		}
		else if (80 <= m_value && m_value <= 100) {
			result = 4;
		}
		return result;
	}

	Mark::operator char() const {
		char result;
		if (m_value == -1) {
			result = 'X';
		}
		else if (0 <= m_value && m_value < 50) {
			result = 'F';
		}
		else if (50 <= m_value && m_value < 60) {
			result = 'D';
		}
		else if (60 <= m_value && m_value < 70) {
			result = 'C';
		}
		else if (70 <= m_value && m_value < 80) {
			result = 'B';
		}
		else if (80 <= m_value && m_value <= 100) {
			result = 'A';
		}
		return result;
	}

	int operator+=(int& num, Mark& mark) {
		num += mark.operator int();
		return num;
	}

}