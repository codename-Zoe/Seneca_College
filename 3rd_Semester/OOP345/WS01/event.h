#pragma once

extern unsigned int g_sysClock;
namespace sdds
{
	class Event
	{
		char* desc{}; //event description
		int time{};   //number of seconds
	public:
		Event();
		Event(const Event&);
		~Event();
		Event& operator=(const Event&);
		void display();
		void set(const char* arr = nullptr);
	};
}