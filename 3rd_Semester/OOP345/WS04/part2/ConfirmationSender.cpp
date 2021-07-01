#include <iostream>
#include "ConfirmationSender.h"

using namespace std;
namespace sdds
{
	ConfirmationSender::ConfirmationSender() {}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src) { //copy constructor
		*this = src;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src)noexcept {      //move constructor
		*this = move(src);
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src) { //copy assignment
		if (this != &src) {
			count = src.count;
			delete[] ptr_reserve;
			ptr_reserve = nullptr;
			ptr_reserve = new const Reservation*[count];
			for (size_t i = 0; i < count; i++) {
				ptr_reserve[i] = src.ptr_reserve[i];
			}
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src)noexcept { //move assignment
		if (this != &src) {
			delete[] ptr_reserve;
			ptr_reserve = nullptr;
			ptr_reserve = src.ptr_reserve;
			count = src.count;
			src.ptr_reserve = nullptr;
			src.count = 0;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool exist = false;
		for (size_t i = 0; i < count && !exist; i++) {
			if (ptr_reserve[i] == &res) {
				exist = true;
			}
		}
		if (!exist) {
			const Reservation** temp = new const Reservation*[count + 1];
			for (size_t i = 0; i < count; i++) {
				temp[i] = ptr_reserve[i];
			}
			temp[count] = &res;
			count++;
			delete[] ptr_reserve;
			ptr_reserve = temp;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		bool exist = false;
		size_t index = 0;
		for (size_t i = 0; i < count && !exist; i++) {
			if (ptr_reserve[i] == &res) {
				count--;
				index = i;
				exist = true;
			}
		}
		if (exist) {
			const Reservation** temp = new const Reservation * [count];
			for (size_t i = 0; i < count; i++) {
				if (i < index) {
					temp[i] = ptr_reserve[i];
				}
				else {
					temp[i] = ptr_reserve[i + 1];
				}
			}
			delete[] ptr_reserve;
			ptr_reserve = nullptr;
			ptr_reserve = temp;
		}
		return *this;
	}

	ConfirmationSender::~ConfirmationSender() {
		delete[] ptr_reserve;
	}

	ostream& operator<<(std::ostream& os, const ConfirmationSender& cs) {
			os << "--------------------------" << endl;
			os << "Confirmations to Send" << endl;
			os << "--------------------------" << endl;
		if (cs.count == 0) {
			os << "There are no confirmations to send!" << endl;
			os << "--------------------------" << endl;
		}
		else {
			for (size_t i = 0; i < cs.count; i++) {
				os << *cs.ptr_reserve[i];
			}
			os << "--------------------------" << endl;
		}
		return os;
	}
}
