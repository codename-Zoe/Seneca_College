#include <iostream>
#include <cstring>
#include "Rectangle.h"

using namespace std;
namespace sdds
{
	Rectangle::Rectangle() : LblShape(){
		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle(const char* str, int width, int height) : LblShape(str) {
		int len = strlen(label());
		m_width = width;
		m_height = height;
		if (m_height < 3 || m_width < len + 2) {
			m_width = 0;
			m_height = 0;
		}
	}

	void Rectangle::getSpecs(istream& is) {
		LblShape::getSpecs(is);
		is >> m_width;
		is.ignore(1000, ',');
		is >> m_height;
		is.ignore(1000, '\n');
	}

	void Rectangle::draw(ostream& os) const{
		if (m_width != 0 && m_height != 0) {
			int i = 3;
			os << "+";
			os.fill('-');
			os.width(m_width - 2);
			os << "-";
			os << "+" << endl;
			os << "|";
			os.fill(' ');
			os.width(m_width - 2);
			os << left << label() << "|" << endl;
			while (i < m_height) {
				os << "|";
				os.width(m_width - 2);
				os << " ";
				os << "|" << endl;
				i++;
			}
			os << "+";
			os.fill('-');
			os.width(m_width - 2);
			os << "-";
			os << "+";
		}
	}
}