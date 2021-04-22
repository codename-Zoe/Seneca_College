#include "Time.h"
#include "utils.h"

using namespace std;
namespace sdds
{
	Time& Time::setToNow() {
		m_min = getTime();
		return *this;
	}

	Time::Time(unsigned int min) {
		m_min = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const {
		int hour = 0, min = 0;
		hour = m_min / 60;
		min = m_min % 60;
		if (hour < 10 && min < 10) {
			ostr << 0 << hour << ":" << 0 << min;
		}
		else if (hour < 10 && min >= 10) {
			ostr << 0 << hour << ":" << min;
		}
		else if (hour >= 10 && min < 10) {
			ostr << hour << ":" << 0 << min;
		}
		else {
			ostr << hour << ":" << min;
		}
		return ostr;
	}

	std::istream& Time::read(std::istream& istr) {
		int hour = 0, min = 0;
		char del = 'X';
		istr >> hour >> del >> min;
		if (hour < 0 || min < 0 || del != ':') {
			istr.setstate(ios::failbit);
		}
		else {
			m_min = hour * 60 + min;
		}
		return istr;
	}

	Time& Time::operator-= (const Time& D) {
		while (D.m_min > m_min) {
			m_min += 24 * 60;
		}
		m_min -= D.m_min;
		return *this;
	}

	Time Time::operator-(const Time& D)const {
		Time T;
		T.m_min = m_min;
		while (D.m_min > T.m_min) {
			T.m_min += 24 * 60;
		}
		T.m_min -= D.m_min;
		return T;
	}

	Time& Time::operator+=(const Time& D) {
		m_min = m_min + D.m_min;
		return*this;
	}

	Time Time::operator+(const Time& D)const {
		Time T;
		T.m_min = m_min + D.m_min;
		return T;
	}

	Time& Time::operator=(unsigned int val) {
		m_min = val;
		return*this;
	}

	Time& Time::operator*= (unsigned int val) {
		m_min = m_min * val;
		return *this;
	}

	Time Time::operator *(unsigned int val)const {
		Time T;
		T.m_min = m_min * val;
		return T;
	}

	Time& Time::operator /= (unsigned int val) {
		m_min = m_min / val;
		return *this;
	}

	Time Time::operator /(unsigned int val)const {
		Time T;
		T.m_min = m_min / val;
		return T;
	}

	Time::operator int()const {
		return (int)m_min;
	}

	Time::operator unsigned int()const {
		return (unsigned int)m_min;
	}

	std::ostream& operator<<(std::ostream& ostr, const Time& D) {
		return D.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Time& D) {
		return D.read(istr);
	}
}