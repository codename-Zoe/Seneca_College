#ifndef SETSUMMABLE_H
#define SETSUMMABLE_H
#include <iostream>
#include "Set.h"

namespace sdds
{
	template<unsigned int N, typename T>
	class SetSummable : public Set<N, T>
	{
	public:
		T accumulate(const std::string& filter) const {
			T accumlator(filter);
			for (size_t i = 0; i < this->size(); i++) {
				if (accumlator.isCompatibleWith(this->get(i))) {
					accumlator += this->get(i);
				}
			}
			return accumlator;
		}
	};
}
#endif
