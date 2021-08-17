#include <sstream>
#include "Utilities.h"

using namespace std;
namespace sdds
{
	Vehicle* createInstance(std::istream& in) {
		Vehicle* temp = nullptr;
		string line;
		getline(in, line, '\n');
		line.erase(0, line.find_first_not_of(' '));
		stringstream ss(line);
		if (toupper(line[0]) == 'C') {
			temp = new Car(ss);
		}
		return temp;
	}
}