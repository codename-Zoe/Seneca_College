#ifndef TIMEEVENTS_H
#define TIMEEVENTS_H
#include <iostream>
#include <chrono>

constexpr int MAX_RECORD{ 10 };

namespace sdds
{
	class TimedEvents
	{
		int num_record{};
		std::chrono::steady_clock::time_point start{};
		std::chrono::steady_clock::time_point end{};
		struct 
		{
			std::string event_name;
			std::string unit_time;
			std::chrono::steady_clock::duration duration;
		} Event[MAX_RECORD];
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char*);
		friend std::ostream& operator<<(std::ostream&, const TimedEvents&);
	};
}
#endif
