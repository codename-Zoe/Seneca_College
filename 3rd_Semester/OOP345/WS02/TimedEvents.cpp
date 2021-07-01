#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstring>
#include "TimedEvents.h"

using namespace std;
namespace sdds
{
	TimedEvents::TimedEvents() {}

	void TimedEvents::startClock() {
		start = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock() {
		end = std::chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* e_name) { //set values to variables
		if(num_record < 10)
		{
			Event[num_record].event_name = e_name;
			Event[num_record].unit_time = "nanoseconds";	
			Event[num_record].duration = std::chrono::duration_cast<chrono::nanoseconds>(end - start);
			num_record++;
		}
	}

	ostream& operator<<(ostream& os, const TimedEvents& te) {
		os << "--------------------------" << endl;
		os << "Execution Times:" << endl;
		os << "--------------------------" << endl;
		for (int i = 0; i < te.num_record; i++) {
			os << setw(21) << left << te.Event[i].event_name << " "
				 << setw(13) << right << te.Event[i].duration.count()  << " " 
				 << te.Event[i].unit_time << endl;
		}
		os << "--------------------------" << endl;
		return os;
	}
}
