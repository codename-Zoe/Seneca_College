#ifndef STATION_H
#define STATION_H
#include <string>

namespace sdds
{
	class Station
	{
		size_t m_id{};
		std::string m_name{};
		std::string m_desc{};
		size_t m_serial{};
		size_t num_items{};
	  static size_t m_widthField;
		static size_t id_generator;
	public:
		Station() {};
		Station(const std::string&);
		const std::string& getItemName() const;
		std::size_t getNextSerialNumber();
		std::size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}
#endif // STATION_H