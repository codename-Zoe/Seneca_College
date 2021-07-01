//========================================
// Movie module
// Movie.cpp
// Name: Nozomi Tsuchiya
// ID: 154666192
// Date: 2021/06/25
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
//========================================
#include <iomanip>
#include <string>
#include "Movie.h"

using namespace std;
namespace sdds
{
	Movie::Movie() {}

	const string& Movie::title() const {
		return m_title;
	}

	Movie::Movie(const string& strMovie) {
		string str = strMovie;
		m_title = str.substr(0, str.find(","));
		str = str.erase(0, str.find(",") + 1);
		m_year = stoi(str.substr(0, str.find(",")));
		str = str.erase(0, str.find(",") + 1);
		m_desc = str;

		m_title.erase(0, m_title.find_first_not_of(' '));
		m_title.erase(m_title.find_last_not_of(' ') + 1);

		m_desc.erase(0, m_desc.find_first_not_of(' '));
		m_desc.erase(m_desc.find_last_not_of(' ') + 1);
	}

	ostream& operator<<(ostream& os, const Movie& movie) {
		os << setw(40) << movie.m_title << " | " << setw(4) << movie.m_year;
		os << " | " << movie.m_desc << endl;
		return os;
	}
}