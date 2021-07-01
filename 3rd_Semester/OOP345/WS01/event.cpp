#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "event.h"
using namespace std;
unsigned int g_sysClock;
namespace sdds
{
	Event::Event() {}

	Event::Event(const Event& src) {
		*this = src;
	}

	Event::~Event() {
			delete[] desc;
	}

	Event& Event::operator=(const Event& src) {
		if (this != &src) {
			if (src.desc != nullptr) {
				if (desc != nullptr) {
					delete[] desc;
					desc = nullptr; 
				}
				delete[] desc;
				desc = new char[strlen(src.desc) + 1];
				strcpy(desc, src.desc);
				time = src.time;
			}
			else {
				desc = nullptr;
				time = 0;
			}
		}
		return *this;
	}

	void Event::display() {
		static int counter = 1;
		int hh = time / 3600;
		int mm = time % 3600 / 60;
		int ss = time % 3600 % 60;
		if (desc == nullptr) {
			cout << setw(2) << setfill(' ') << counter << ". | No Event |" << endl;
		}
		else {
			cout << setw(2) << setfill(' ') << counter << ". " << setw(2) << setfill('0') << hh << ":"
				<< setw(2) << setfill('0') << mm << ":" << setw(2) << setfill('0') << ss << " => " << desc << endl;
		}
		counter++;
	}

	void Event::set(const char* arr) {
		if (arr != nullptr && arr[0] != '\0') {
			if (desc != nullptr) {
				delete[] desc;
				desc = nullptr;
			}
			desc = new char[strlen(arr) + 1];
			strcpy(desc, arr);
			time = g_sysClock;
		}
		else {
			delete[] desc;
			desc = nullptr;
			time = 0;
		}
	}
}