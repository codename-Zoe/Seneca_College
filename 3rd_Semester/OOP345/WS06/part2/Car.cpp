#include <iostream>
#include <iomanip>
#include <cctype>
#include "Car.h"

using namespace std;
namespace sdds
{
  Car::Car(std::istream& is) {
    string tag;
    string maker;
    string condition;
    string topSpeed;

    getline(is, tag, ',');
    getline(is, maker, ',');
    getline(is, condition, ',');
    getline(is, topSpeed, ',');

    // delete unnecessary spaces 
    tag.erase(0, tag.find_first_not_of(' '));
    tag.erase(tag.find_last_not_of(' ') + 1);

    maker.erase(0, maker.find_first_not_of(' '));
    maker.erase(maker.find_last_not_of(' ') + 1);
    m_maker = maker;

    condition.erase(0, condition.find_first_not_of(' '));
    condition.erase(condition.find_last_not_of(' ') + 1);

    topSpeed.erase(0, topSpeed.find_first_not_of(' '));
    topSpeed.erase(topSpeed.find_last_not_of(' ') + 1);

    if (condition == "" || condition[0] == ' ') {
      m_condition = "new";
    }
    else if (condition == "n") {
      m_condition = "new";
    }
    else if (condition == "u") {
      m_condition = "used";
    }
    else if (condition == "b") {
      m_condition = "broken";
    }
    else {
      string error = "Invalid record!";
      throw error;
    }

    if (isdigit(topSpeed[0])) {
      m_topSpeed = stod(topSpeed);
    }
    else {
      string error = "Invalid record!";
      throw error;
    }
	}

  std::string Car::condition() const {
    return m_condition;
  }

  double Car::topSpeed() const {
    return m_topSpeed;
  }

  void Car::display(std::ostream& out) const {
    out << "| " << right << setw(10) << m_maker << " | "  << left << setw(6) << condition()
      << " | " << fixed << setprecision(2) << setw(6) << topSpeed() << " |";
  }
}

