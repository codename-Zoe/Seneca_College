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
