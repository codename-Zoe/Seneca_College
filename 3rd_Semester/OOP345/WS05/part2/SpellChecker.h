//========================================
// SpellChecker module
// SpellChecker.h
// Name: Nozomi Tsuchiya
// ID: 154666192
// Date: 2021/06/25
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
//========================================
#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H
#include <string>

namespace sdds
{
	const int MAX = 6;
	class SpellChecker
	{
		std::string m_badWords[MAX]{};
		std::string m_goodWords[MAX]{};
		size_t num_misspelled[MAX]{};
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif