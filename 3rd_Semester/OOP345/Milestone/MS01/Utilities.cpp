#include "Utilities.h"

using namespace std;
namespace sdds
{
	char Utilities::m_delimiter = ' ';

	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}

	string Utilities::extractToken(const string& str, size_t& next_pos, bool& more) {
		string str_found = "";
		size_t first_pos = next_pos;
		next_pos = str.find(m_delimiter, first_pos);

		// if the token is before \n (no more delimiter in the string)
		if (next_pos == string::npos) {
			str_found = str.substr(first_pos);
			more = false;
		}
		// if the token is between the delimiter
		else if(first_pos != next_pos) {
			str_found = str.substr(first_pos, next_pos - first_pos);
			more = true;
		}
		else {
			more = false;
			throw "No token";
		}
		// update m_widthField to the size of the token extracted
		if (m_widthField < str_found.length()) {
			m_widthField = str_found.length();
		}
		next_pos++;
		return str_found;
	}

	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter() {
		return m_delimiter;
	}
}