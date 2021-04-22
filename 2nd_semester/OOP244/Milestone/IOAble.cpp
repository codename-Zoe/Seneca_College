#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "IOAble.h"
using namespace std;
namespace sdds
{
	ostream& IOAble::csvWrite(std::ostream& ostr) const {
		return ostr;
	}

	istream& IOAble::csvRead(std::istream& istr) {
		return istr;
	}

	ostream& IOAble::write(std::ostream& ostr) const {
		return ostr;
	}

	istream& IOAble::read(std::istream& istr) {
		return istr;
	}

	IOAble::~IOAble() {

	}

	ostream& operator<<(ostream& ostr, const IOAble& ioable) {
		return ioable.write(ostr);
	}

	istream& operator>>(istream& istr, IOAble& ioable) {
		return ioable.read(istr);
	}

}
