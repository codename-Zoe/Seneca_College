#include <iomanip>
#include <string>
#include "Book.h"

using namespace std;
namespace sdds
{
	Book::Book() {}

	const std::string& Book::title() const {
		return b_title;
	}
	
	const std::string& Book::country() const {
		return public_country;
	}

	const size_t& Book::year() const {
		return public_year;
	}

	double& Book::price() {
		return b_price;
	}

	Book::Book(const std::string& strBook) {
		string str = strBook;

		b_author = str.substr(0, str.find(","));
		str = str.erase(0, str.find(",") + 1);

		b_title = str.substr(0, str.find(","));
		str = str.erase(0, str.find(",") + 1);
		
		public_country = str.substr(0, str.find(","));
		str = str.erase(0, str.find(",") + 1);
		
		b_price = stod(str.substr(0, str.find(",")));
		str = str.erase(0, str.find(",") + 1);

		public_year = stoi(str.substr(0, str.find(",") + 1));
		str = str.erase(0, str.find(",") + 1);

		description = str.substr(0);

		// trimming //
		b_author.erase(0, b_author.find_first_not_of(' '));
		b_author.erase(b_author.find_last_not_of(' ') + 1);

		b_title.erase(0, b_title.find_first_not_of(' '));
		b_title.erase(b_title.find_last_not_of(' ') + 1);

		public_country.erase(0, public_country.find_first_not_of(' '));
		public_country.erase(public_country.find_last_not_of(' ') + 1);

		description.erase(0, description.find_first_not_of(' '));
		description.erase(description.find_last_not_of(' ') + 1);
	}

	std::ostream& operator<<(std::ostream& os, const Book& src) {
		os << setw(20) << src.b_author << " | ";
		os << setw(22) << src.title() << " | ";
		os << setw(5)  << src.country() << " | ";
		os << setw(4)  << src.year() << " | ";
		os << fixed << setw(6) << setprecision(2) << src.b_price << " | ";
		os << src.description << endl;
		return os;
	}
}
