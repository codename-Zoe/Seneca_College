// Workshop 3 - Templates
// 2019/01/23 - Chris Szalwinski
// 2019/09/20 - Cornel
// 2020/01/23 - Cornel
// 2021/01/14 - Chris

#include <fstream> 
#include <iostream>
#include <iomanip>
#include <string>
#include "Set.h"
#include "Pair.h"
#include "Set.h"
#include "Pair.h"


int main(int argc, char* argv[])
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	if (argc != 2) {
		std::cerr << "ERROR: Insufficient number of arguments.\n";
		return 2;
	}

	// Process the parameter
	// The values in this file will be interpreted as numbers
	//     Sumation means mathematical addition of numbers.
	{
		sdds::Set<10, sdds::Pair<int, std::string>> ticketSales;

		// get the data from the file
		{
			std::ifstream input(argv[1]);
			if (!input)
			{
				std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
				return 3;
			}
			do
			{
				char ticketType[64];
				int number;
				input >> ticketType >> number;
				if (input)
				{
					ticketSales += sdds::Pair<int, std::string> (ticketType, number);
				}
			} while (input);
			input.close();
		}

		std::cout << "Detail Ticket Sales\n"
		          << "--------------------------\n";
		for (size_t i = 0; i < ticketSales.size(); ++i)
			std::cout << ticketSales.get(i);
	}

	// done
	return 0;
}