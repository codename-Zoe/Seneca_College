//========================================
// Pair module
// Pair.h
// Name: Nozomi Tsuchiya
// ID: 154666192
// Date: 2021/06/10
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
//========================================

#ifndef PAIR_H
#define PAIR_H
#include <iostream>

namespace sdds
{
	template<typename V, typename K>
	class Pair
	{
		V m_val;
		K m_key;
	public:
		Pair() {
			m_val = {};
			m_key = {};
		}

		Pair(const K& key, const V& value) {
			m_key = key;
			m_val = value;
		}

		const V& value() const {
			return m_val;
		}

		const K& key() const {
			return m_key;
		}

		void display(std::ostream& os) const {
			os << m_key << " : " << m_val << std::endl;
		}

		friend std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
			pair.display(os);
			return os;
		}

	};
}
#endif