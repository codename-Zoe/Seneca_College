#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>  
#include <iomanip>
#include "Canister.h"

using namespace std;
namespace sdds {

	const double PI = 3.14159265;

	void Canister::setToDefault() {
		m_contentName = nullptr;
		m_height = 13.0;
		m_diameter = 10.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	bool Canister::isEmpty()const {
		if (m_contentVolume < 0.00001) {
			return true;
		}
		else {
			return false;
		}
	}

	bool Canister::hasSameContent(const Canister& C)const {
		if (strcmp(m_contentName, C.m_contentName) == 0 && m_contentName != nullptr && C.m_contentName != nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	void Canister::setName(const char* Cstr) {
		if (Cstr != nullptr && m_usable) {
			clear();
			m_contentName = new char[strlen(Cstr) + 1];
			strcpy(m_contentName, Cstr);
		}
	}

	Canister::Canister() {
		setToDefault();
	}

	Canister::Canister(const char* contentName) {
		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double height, double diameter, const char* contentName) {
		setToDefault();
		if (height >= 10.0 && height <= 40.0 && diameter >= 10.0 && diameter <= 30.0) {
			m_height = height;
			m_diameter = diameter;
			m_contentVolume = 0.0;
			setName(contentName);
		}
		else {
			m_usable = false;
		}
	}

	Canister::~Canister() {
		delete[] m_contentName;
		m_contentName = nullptr;
	}

	void Canister::clear() {
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	double Canister::capacity()const {
		return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
	}

	double Canister::volume()const {
		return m_contentVolume;
	}

	Canister& Canister::setContent(const char* contentName) {
		if (contentName == nullptr) {
			m_usable = false;
		}
		else if (isEmpty()){
			setName(contentName);
		}
		else if (strcmp(m_contentName, contentName) != 0) {
			m_usable = false;
		}
		return *this;
	}

	Canister& Canister::pour(double quantity) {
		if (m_usable && quantity > 0) {
			if (quantity + volume() <= capacity()) {
				m_contentVolume += quantity;
			}
			else {
				m_usable = false;
			}
		}
		return *this;
	}

	Canister& Canister::pour(Canister& C) {
		setContent(C.m_contentName);
		if (C.volume() > (capacity() - volume())) {
			C.m_contentVolume -= (capacity() - volume());
			m_contentVolume = capacity();
		}
		else {
			pour(C.m_contentVolume);
			C.m_contentVolume = 0.0;
		}
		return *this;
	}

	std::ostream& Canister::display()const {
		cout << setw(7) << setprecision(1) << fixed << capacity() << "cc (";
		cout << m_height << "x" << m_diameter << ") Canister";
		if (!m_usable) {
			cout << " of Unusable content, discard!";
		}
		else if (m_contentName != nullptr) {
			cout << " of ";
			cout << setw(7) << setprecision(1) << fixed << m_contentVolume << "cc   " << m_contentName;
		}
		return cout;
	}
   
}