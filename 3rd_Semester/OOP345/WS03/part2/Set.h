//========================================
// Set module
// Set.h
// Name: Nozomi Tsuchiya
// ID: 154666192
// Date: 2021/06/10
// I have done all the coding by myself and only copied the code 
// that my professor provided to complete my workshops and assignments.
//========================================

#ifndef SET_H
#define SET_H
#include <iostream>

namespace sdds
{
	template <unsigned int N, typename T>
	class Set
	{
		T collection[N];
		unsigned int num_element;
	public:
		Set() : collection{}, num_element{}{};

		size_t size() const {
			return num_element;
		}

		const T& get(size_t idx) const {
			return collection[idx];
		}

		void operator+=(const T& item) {
			if (num_element < N) {
				collection[num_element] = item;
				num_element++;
			}
		}
	};
}
#endif