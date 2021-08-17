#ifndef LINEMANAGER_H
#define LINEMANAGER_H
#include <vector>
#include "Workstation.h"

namespace sdds
{
	class LineManager
	{
		std::vector<Workstation*> activeLine{};
		size_t m_cntCustomerOrder{0};
		Workstation* m_firstStation{nullptr};
	public:
		LineManager() {};
		LineManager(const std::string& filename, const std::vector<Workstation*>& stations);
		void linkStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif // !LINEMANAGER_H