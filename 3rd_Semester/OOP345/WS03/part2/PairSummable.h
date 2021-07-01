#ifndef PAIRSUMMABLE_H
#define PAIRSUMMABLE_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Pair.h"

namespace sdds
{
	template<typename V, typename K>
	class PairSummable : public Pair<V, K>
	{
		static V initial;
		static size_t width;
	public:
		PairSummable() {}

		PairSummable(const K& key, const V& value = initial) : Pair<V, K>(key, value) {
			if (width < key.size()) {
				width = key.size();
			}
		}

		bool isCompatibleWith(const PairSummable<V, K>& b) const {
			return this->key() == b.key();
		}

		PairSummable<V, K>& operator+=(const PairSummable<V, K>& obj) { 
			if (isCompatibleWith(obj)) {
				*this = PairSummable(this->key(), this->value() + obj.value());
			}
			return *this;
		}

		void display(std::ostream& os) const {
			os << std::left << std::setw(width);
			Pair<V, K>::display(os);
			os << std::right;
		}
	};

	template<typename V, typename K>
	size_t PairSummable<V, K>::width = 0;

	template<>
	int PairSummable<int, std::string>::initial = 0;

	template<>
	std::string PairSummable<std::string, std::string>::initial = "";

	template <> 
	PairSummable<std::string, std::string>&
	PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& obj) {
		if (isCompatibleWith(obj)) {
			if (this->value() != "") {
				std::string temp;
				temp = this->value() + ", " + obj.value();
				*this = PairSummable(this->key(), temp);
			}
			else {
				*this = PairSummable(this->key(), this->value() + obj.value());
			}
		}
		return *this;
	}

}
#endif
