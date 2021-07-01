#include <iostream>
#include "Restaurant.h"

using namespace std;
namespace sdds
{
	Restaurant::Restaurant() {};

	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
		if (reservations != nullptr) {
			count = cnt;
			reserve = new Reservation[count];
			for (size_t i = 0; i < count; i++) {
				reserve[i] = *reservations[i];
			}
		}
	}

	size_t Restaurant::size() const {
		return count;
	}

	Restaurant::Restaurant(const Restaurant& src) { //copy
		*this = src;
	}

	Restaurant::Restaurant(Restaurant&& src) noexcept{ //move
		*this = move(src);
	}

	Restaurant& Restaurant::operator=(const Restaurant& src) { //copy
		if (this != &src) {
			count = src.count;
			delete[] reserve;
			reserve = nullptr;
			reserve = new Reservation[count];  //allocated on the heap
			for (size_t i = 0; i < count; i++) {
				reserve[i] = src.reserve[i];
			}
		}
		return *this;
	}

	Restaurant& Restaurant::operator=(Restaurant&& src) noexcept{ //move
		if (this != &src) {
			delete[] reserve;
			reserve = nullptr;
			reserve = src.reserve;
			count = src.count;
			src.reserve = nullptr;
			src.count = 0;
		}
		return *this;
	}

	Restaurant::~Restaurant() {
		delete[] reserve;
	}

	ostream& operator<<(std::ostream& os, const Restaurant& res) {
		static int call_cnt = 0;
		call_cnt++;
			os << "--------------------------" << endl;
			os << "Fancy Restaurant (" << call_cnt << ")" << endl;
			os << "--------------------------" << endl;
		if (res.reserve == nullptr) {
			os << "This restaurant is empty!" << endl;
			os << "--------------------------" << endl;
		}
		else {
			for (size_t i = 0; i < res.size(); i++) {
				os << res.reserve[i];
			}
			os << "--------------------------" << endl;
		}
		return os;
	}

}
