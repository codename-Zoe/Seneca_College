#ifndef SET_H
#define SET_H
#include <iostream>

namespace sdds
{
	template <int N, class T>
  class Set
	{
		T collection[N];
		int num_element = 0;
	public:
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
