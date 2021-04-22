#include <iostream>
#include "CalorieList.h"

using namespace std;
namespace sdds
{
	Food* food = nullptr;

	void CalorieList::setEmpty() {
		food = nullptr;
	}

	double CalorieList::totalCal()const {
		double totalCal = 0.0;
		for (int i = 0; i < noOfMeal; i++) {
			totalCal += food[i].getCalorie(); 
		}
		return totalCal;
	}

	bool CalorieList::isValid()const {
		bool result = true;
		int i;
		if (food != nullptr) {
			for (i = 0; i < noOfMeal && result == true; i++) {
				if (food[i].isValid()) {
					result = true;
				}
				else {
					result = false;
				}
			}
		}
		else {
			result = false;
		}
		return result;
	}

	void CalorieList::Title()const {
		cout << "+----------------------------------------------------+" << endl;
		if (isValid()) {
			cout << "|  Daily Calorie Consumption                         |" << endl;
		}
		else {
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}	

	void CalorieList::footer()const {
		cout << "+--------------------------------+------+------------+" << endl;
		if (isValid()) {
			if (0 < totalCal() && totalCal() < 10000) {
				cout << "|    Total Calories for today:     ";
				cout.width(4);
			}
			else if (totalCal() > 9999) {
				cout << "|    Total Calories for today:   ";
			}
				cout << totalCal() << " |            |" << endl;
		}
		else {
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}
		cout << "+----------------------------------------------------+" << endl;
	}

	void CalorieList::init(int size) {
		if (size <= 0) {
			setEmpty();
		}
		else {
			noOfMeal = size;
			mealsAdded = 0;
			food = new Food[noOfMeal];
			for (int i = 0; i < noOfMeal; i++) {
				food[i].setEmpty();
			}
		}
	}

	bool CalorieList::add(const char* item_name, int calories, int when) {
		if (mealsAdded < noOfMeal) {
			food[mealsAdded].set(item_name, calories, when);
			mealsAdded++;
			return true;
		}
		return false;
	}

	void CalorieList::display()const {
		int i = 0;
		Title();
		for (i = 0; i < noOfMeal; i++) {
			food[i].display();
		}
		footer();
	}

	void CalorieList::deallocate() {
		delete[] food;
		food = nullptr;
	}

}