#include <iostream>
#include <cstring>
#include <string>
#include "Food.h"

using namespace std;
namespace sdds
{
	void Food::setName(const char* name) {
		strncpy(foodName, name, 30);
	}

	void Food::setEmpty() {
		calorie = 0;
		foodName[0] = '\0';
	}

	void Food::set(const char* name, int cal, int time) {
		if (name == NULL || (cal < 0 && cal > 3000) || time < 1) {
			setEmpty();
		}
		else {
			setName(name);
			calorie = cal;
			consumption = time;
		}
	}

	int Food::getCalorie()const {
		return calorie;
	}

	bool Food::isValid()const {
		if (foodName[0] != '\0' && (calorie > 0 && calorie <= 3000) && (consumption > 0 && consumption <=4)) {
			return true;
		}
		else {
			return false;
		}
	}

	void Food::display()const {
		string result;
		if (isValid()) {
			switch (consumption) {
			case 1:
				result = "Breakfast";
				break;
			case 2:
				result = "Lunch";
				break;
			case 3:
				result = "Dinner";
				break;
			case 4:
				result = "Snack";
				break;
			}
			cout << "| ";
			cout.setf(ios::left);
			cout.fill('.');
			cout.width(30);
			cout << foodName;
			cout << " | ";
			cout.unsetf(ios::left);
			cout.fill(' ');
			cout.width(4);
			cout << calorie << " | ";
			cout.setf(ios::left);
			cout.fill(' ');
			cout.width(10);
			cout << result << " |" << endl;
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}

}
