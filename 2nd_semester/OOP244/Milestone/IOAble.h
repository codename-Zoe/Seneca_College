#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H

using namespace std;
namespace sdds
{
	class IOAble
	{
	public:
		virtual ostream& csvWrite(std::ostream& ostr) const = 0;
		virtual istream& csvRead(std::istream& istr) = 0;
		virtual ostream& write(std::ostream& ostr) const = 0;
		virtual istream& read(std::istream& istr) = 0;
		virtual ~IOAble() = 0;
	};
	ostream& operator<<(ostream& ostr, const IOAble&);
	istream& operator>>(istream& istr, IOAble&);
}
#endif