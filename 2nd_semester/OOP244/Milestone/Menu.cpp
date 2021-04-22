#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "utils.h"
using namespace std;
namespace sdds
{
	Menu::Menu(const char* MenuContent, int NoOfSelections) {
		m_text = new char[strlen(MenuContent) + 1];
		strcpy(m_text, MenuContent);
		m_noOfSel = NoOfSelections;
	}

	Menu::~Menu() {
		delete[] m_text;
	}

	void Menu::display()const {
		cout << m_text << endl;
		cout << "0- Exit" << endl;
	}

	int& Menu::operator>>(int& Selection) {
		int input;
		display();
		input = getInt(0, m_noOfSel, "> ", "Invalid option ");
		Selection = input;
		return Selection;
	}

	Menu::Menu(const Menu& menu) {
		if (menu.m_text != nullptr) {
			m_text = nullptr;
			m_text = new char[strlen(menu.m_text) + 1];
			strcpy(m_text, menu.m_text);
			m_noOfSel = menu.m_noOfSel;
		}
	}
}