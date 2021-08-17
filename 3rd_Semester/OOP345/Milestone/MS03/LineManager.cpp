#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "LineManager.h"

using namespace std;
namespace sdds
{
	LineManager::LineManager(const std::string& filename, const std::vector<Workstation*>& stations) {
		Utilities util;
		ifstream file(filename);
		if (!file) {
			throw "Incorrect file name!";
		}
		else {
			string str = "";
			string currentStr = "";
			string nextStr = "";
			bool more;
			size_t next_pos = 0;
			Workstation* currentStation = nullptr;
			Workstation* nextStation = nullptr; 
			Workstation* firstStation = nullptr;
			while (getline(file, str))	{
				currentStr = util.extractToken(str, next_pos, more);
				currentStation = *find_if(stations.begin(), stations.end(), [&](Workstation* station) {
					return station->getItemName() == currentStr;
					});
				activeLine.push_back(currentStation);
				if (more) {
					nextStr = util.extractToken(str, next_pos, more);
					nextStation = *find_if(stations.begin(), stations.end(), [&](Workstation* station) {
						return station->getItemName() == nextStr;
						});
					currentStation->setNextStation(nextStation);
				}
			}
			for_each(stations.begin(), stations.end(), [&](Workstation* station) {
				firstStation = *find_if(stations.begin(), stations.end(), [&](Workstation* station) {
					return station->getNextStation() == firstStation;
					});
				});
			m_firstStation = firstStation;
		}
		file.close();
		m_cntCustomerOrder = pending.size();
	}

	void LineManager::linkStations() {
		Workstation* station = m_firstStation;
		vector<Workstation*> reordered;
		while (station != nullptr){
			reordered.push_back(station);
			station = station->getNextStation();
		} 
		activeLine = reordered;
	}

	bool LineManager::run(std::ostream& os) {
		bool flag;
		static size_t count = 1;
		os << "Line Manager Iteration: " << count++ << endl;
		if (!pending.empty()) {
			*m_firstStation += move(pending.front());
			pending.pop_front();
		}
		for_each(activeLine.begin(), activeLine.end(), [&](Workstation* station) {station->fill(os); });
		for_each(activeLine.begin(), activeLine.end(), [&](Workstation* station) {station->attemptToMoveOrder(); });
		m_cntCustomerOrder == completed.size() + incomplete.size() ? flag = true : flag = false;
		return flag;
	}

	void LineManager::display(std::ostream& os) const {
		for_each(activeLine.begin(), activeLine.end(), [&](Workstation* station) {station->display(os); });
	}
}