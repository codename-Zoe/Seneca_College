//========================================
// SpellChecker module
// SpellChecker.cpp
// Name: Nozomi Tsuchiya
// ID: 154666192
// Date: 2021/06/25
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
//========================================
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"

using namespace std;
namespace sdds
{
	SpellChecker::SpellChecker(const char* filename) {
    int i = 0;
    string line;
    ifstream file(filename);
    if (!file){
      throw "Bad file name!";
      }
    else{
      while (file && i < MAX) {
        getline(file, m_badWords[i], ' ');
        m_badWords[i].erase(0, m_badWords[i].find_first_not_of(' '));
        m_badWords[i].erase(m_badWords[i].find_last_not_of(' ') + 1);
        getline(file, m_goodWords[i], '\n');
        m_goodWords[i].erase(0, m_goodWords[i].find_first_not_of(' '));
        m_goodWords[i].erase(m_goodWords[i].find_last_not_of(' ') + 1);
        i++;
      }
      //file.close();
    }
	}

	void SpellChecker::operator()(std::string& text) {
    for (size_t i = 0; i < MAX; i++) {
      while (text.find(m_badWords[i]) != string::npos) {
        text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]);
        num_misspelled[i]++;
      }
    }
	}

	void SpellChecker::showStatistics(std::ostream& out) const {
    out << "Spellchecker Statistics" << std::endl;
    for (size_t i = 0; i < MAX; i++) {
      out << setw(15) << right << m_badWords[i] << ": " << num_misspelled[i] << " replacements" << endl;
    }   
	}
}