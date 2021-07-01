#include <iostream>
#include <string>
#include <iomanip>
#include "Reservation.h"

using namespace std;
namespace sdds
{
	Reservation::Reservation() {}

	Reservation::Reservation(const string& res) {
		string str = res;
		res_id = str.substr(0, str.find(":"));
		str = str.erase(0, str.find(":") + 1);
		res_name = str.substr(0, str.find(","));
		str = str.erase(0, str.find(",") + 1);
		email = str.substr(0, str.find(","));
		str = str.erase(0, str.find(",") + 1);
		party_size = stoi(str.substr(0, str.find(",")));
		str = str.erase(0, str.find(",") + 1);
		day = stoi(str.substr(0, str.find(",") + 1));
		str = str.erase(0, str.find(",") + 1);
		hour = stoi(str.substr(0));

		// trimming //
		res_id.erase(0, res_id.find_first_not_of(' '));
		res_id.erase(res_id.find_last_not_of(' ') + 1);

		res_name.erase(0, res_name.find_first_not_of(' '));
		res_name.erase(res_name.find_last_not_of(' ') + 1);

		email.erase(0, email.find_first_not_of(' '));
		email.erase(email.find_last_not_of(' ') + 1);
	}

	ostream& operator<<(ostream& os, const Reservation& res) {
		string meal;
		if (res.hour >= 6 && res.hour <= 9) {
			meal = "Breakfast";
		}
		else if (res.hour >= 11 && res.hour <= 15) {
			meal = "Lunch";
		}
		else if (res.hour >= 17 && res.hour <= 21) {
			meal = "Dinner";
		}
		else {
			meal = "Drinks";
		}

		os << "Reservation " << right << setw(10) << res.res_id << ": " << setw(20) << res.res_name
			<< "  " << left << setw(20) << "<" + res.email + ">" << "    " << meal << " on day " << res.day
			<< " @ " << res.hour << ":00 for " << res.party_size;
		if (res.party_size > 1) {
			os << " people." << endl;
		}
		else {
			os << " person." << endl;
		}
		return os;
	}
}
