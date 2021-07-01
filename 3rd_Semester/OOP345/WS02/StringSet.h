#ifndef STRINGSET_H
#define STRINGSET_H
#include <iostream>

namespace sdds
{
	class StringSet
	{
		std::string* element{};
		size_t num_str{};
	public:
		StringSet();
		StringSet(const char*);
		StringSet(const StringSet&);
		StringSet(StringSet&&) noexcept;
		StringSet& operator=(const StringSet&);
		StringSet& operator=(StringSet&&) noexcept;
		~StringSet();
		size_t size();
		std::string operator[](size_t) const;
	};

}
#endif
