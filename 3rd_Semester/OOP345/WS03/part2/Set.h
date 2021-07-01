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
