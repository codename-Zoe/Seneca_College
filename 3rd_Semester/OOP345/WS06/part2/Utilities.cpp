#include <sstream>
#include "Utilities.h"

using namespace std;
namespace sdds
{
	Vehicle* createInstance(std::istream& in) {
		Vehicle* temp = nullptr;

		std::string line;
		getline(in, line);

		line.erase(0, line.find_first_not_of(' '));
		line.erase(line.find_last_not_of(' ') + 1);
		std::stringstream ss(line);

		if (line != "") {
			if (toupper(line[0]) == 'C') {
				temp = new Car(ss);
			}
			else if (toupper(line[0]) == 'R') {
				temp = new Racecar(ss);
			}
			else {
				std::string error;
				getline(ss, error, ',');
				throw "Unrecognized record type: [" + error + "]";
			}
		}
		return temp;
	}
}