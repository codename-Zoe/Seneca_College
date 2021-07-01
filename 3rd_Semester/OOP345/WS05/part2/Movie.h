//========================================
// Movie module
// Movie.h
// Name: Nozomi Tsuchiya
// ID: 154666192
// Date: 2021/06/25
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
//========================================
#ifndef MOVIE_H
#define MOVIE_H
#include <string>

namespace sdds
{
	class Movie
	{
		std::string m_title{};
		size_t m_year{};
		std::string m_desc{};
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_title);
			spellChecker(m_desc);
		}
		friend std::ostream& operator<<(std::ostream&, const Movie&);
	};
}
#endif