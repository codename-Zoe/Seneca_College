//========================================
// Book module
// Book.h
// Name: Nozomi Tsuchiya
// ID: 154666192
// Date: 2021/06/25
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
//========================================
#ifndef BOOK_H
#define BOOK_H
#include <string>

namespace sdds
{
	class Book
	{
		std::string b_author{};
		std::string b_title{};
		std::string public_country{};
		size_t public_year{};
		double b_price{};
		std::string description{};
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string&);
		friend std::ostream& operator<<(std::ostream& os, const Book&);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(description);
		}
	};	
}
#endif