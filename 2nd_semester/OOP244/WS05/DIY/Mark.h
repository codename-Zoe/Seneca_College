#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_

namespace sdds {
	class Mark {
		int m_value;
		void setInvalid();
		void setDefault();
	public:
		Mark();
		Mark(int);
		operator int() const;
		Mark& operator+=(const int);
		Mark& operator=(const int);
		operator double() const;
		operator char() const;
	};
		int operator+=(int&, Mark&);
}

#endif