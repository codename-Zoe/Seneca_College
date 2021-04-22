#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {
	struct Poprepo
	{
		char* postalCode;
		int population;
	};
	void sort();
	bool load(const char* filename);
	bool load(Poprepo& poprepo);
	void display(const Poprepo& poprepo);
	void display();
	void deallocateMemory();
}
#endif 