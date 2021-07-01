// Workshop 4 - Containers
// 2020/01/28 - Cornel
// 2021/01/19 - Chris
// 2021/02/05 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include "Restaurant.h"
#include "Restaurant.h"
#include "ConfirmationSender.h"
#include "ConfirmationSender.h"
#include "Reservation.h"
#include "Reservation.h"


int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n";

	const sdds::Reservation** ppReservations = nullptr;
	size_t cnt = 0;

	// Process the file
	if (argc > 1) {
		std::ifstream file(argv[1]);
		if (!file)
		{
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			return 1;
		}

		std::string strReservation;
		// count how many records are in the file
		do
		{
			std::getline(file, strReservation);

			// if the previous operation failed, the "file" object is
			//   in error mode
			if (file)
			{
				// Check if this is a commented line.
				//   In the input file, commented lines start with '#'
				if (strReservation[0] != '#')
					++cnt;
			}
		} while (file);

		ppReservations = new const sdds::Reservation*[cnt];
		cnt = 0;

		// read again from the file, but this time load and store data
		file.clear();
		file.seekg(std::ios::beg);
		do
		{
			std::getline(file, strReservation);

			// if the previous operation failed, the "file" object is
			//   in error mode
			if (file)
			{
				// Check if this is a commented line.
				//   In the input file, commented lines start with '#'
				if (strReservation[0] != '#')
				{
					ppReservations[cnt] = new const sdds::Reservation(strReservation);
					++cnt;
				}
			}
		} while (file);
		file.close();
	}
	std::cout << "\nReservations\n--------------------------\n";
	for (auto i = 0u; i < cnt; ++i)
	{
		std::cout << *ppReservations[i];
	}
	std::cout << "--------------------------\n\n";

	{
		std::cout << "R: Testing Constructor\n";
		std::cout << "==========================\n";
		sdds::Restaurant res1(ppReservations, cnt);
		std::cout << res1;  // 1
		std::cout << "==========================\n\n";

		std::cout << "R: Testing Copy Constructor\n";
		std::cout << "==========================\n";
		sdds::Restaurant res2(res1);
		std::cout << res1;  // 2
		std::cout << res2;  // 3
		std::cout << "==========================\n\n";

		{
			std::cout << "R: Testing Copy Assign\n";
			std::cout << "==========================\n";
			res2 = res2;
			std::cout << res1;  // 4
			std::cout << res2;  // 5
			sdds::Restaurant res3(ppReservations + 3, 4);
			res2 = res3;
			std::cout << res2;  // 6
			std::cout << res3;  // 7
			std::cout << "==========================\n\n";
		}

		std::cout << "R: Testing Move Constructor\n";
		std::cout << "==========================\n";
		sdds::Restaurant res3(std::move(res2));
		std::cout << res2;  // 8
		std::cout << res3;  // 9
		std::cout << "==========================\n\n";

		std::cout << "R: Testing Move Assign\n";
		std::cout << "==========================\n";
		res3 = std::move(res3);
		std::cout << res2;  // 10
		std::cout << res3;  // 11
		res2 = std::move(res3);
		std::cout << res2;  // 12
		std::cout << res3;  // 13
		std::cout << "==========================\n\n";
	}


	// Confirmation Sender
	{
		std::cout << "CS: Testing Constructor\n";
		std::cout << "==========================\n";
		sdds::ConfirmationSender sender1;
		std::cout << sender1;
		std::cout << "==========================\n\n";

		std::cout << "CS: Testing Operators\n";
		std::cout << "==========================\n";
		sender1 += *ppReservations[5];
		sender1 += *ppReservations[16];
		sender1 += *ppReservations[16];
		sender1 += *ppReservations[8];
		sender1 += *ppReservations[10];
		sender1 += *ppReservations[9];
		std::cout << sender1;
		sender1 -= *ppReservations[8];
		sender1 -= *ppReservations[9];
		sender1 -= *ppReservations[7];
		std::cout << sender1;
		std::cout << "==========================\n\n";

		std::cout << "CS: Testing Copy Constructor\n";
		std::cout << "==========================\n";
		sdds::ConfirmationSender sender2(sender1);
		std::cout << sender1;
		std::cout << sender2;
		std::cout << "==========================\n\n";

		sender2 = sender2;

		std::cout << "CS: Testing Move Constructor\n";
		std::cout << "==========================\n";
		sdds::ConfirmationSender sender3(std::move(sender1));
		std::cout << sender1;
		std::cout << sender3;
		std::cout << "==========================\n\n";

		sender3 = std::move(sender3);
	}
	// cleanup
	for (auto i = 0u; i < cnt; ++i)
		delete ppReservations[i];
	delete[] ppReservations;

	return 0;
}