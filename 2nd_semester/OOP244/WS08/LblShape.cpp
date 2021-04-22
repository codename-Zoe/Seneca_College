#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include "LblShape.h"

using namespace std;
namespace sdds
{
	const char* LblShape::label() const{
		 return m_label;
	}

	LblShape::LblShape() {
		if (m_label == nullptr) {
			//do nothing
		}
		else {
			m_label = nullptr;
		}
	}

	LblShape::LblShape(const char* str) {
		m_label = new char[strlen(str) + 1];
		strcpy(m_label, str);
	}

	LblShape::~LblShape() {
		delete[] m_label;
	}

	void LblShape::getSpecs(istream& is) {
		string str;
		getline(is, str, ',');
		delete[] m_label;
		m_label = nullptr;
		m_label = new char[strlen(str.c_str()) + 1];
		strcpy(m_label, str.c_str());
	}
}
