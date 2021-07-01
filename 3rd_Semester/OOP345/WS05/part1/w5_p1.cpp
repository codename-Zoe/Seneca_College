// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"

using namespace sdds;

enum AppErrors
{
	CannotOpenFile = 1, // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive anough parameters
};

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Book library[7];
	if (argc == 2) {
		int i = 0;
		std::string line;
		std::ifstream file(argv[1]);
		if (!file) {
			std::cout << "Cannot open file!" << std::endl;
			std::exit(AppErrors::CannotOpenFile);
		}
		else{
			while (std::getline(file, line)) {
				if (line[0] != '#') {
					library[i] = Book(line);
					i++;
				}
			}
		}
	}
	else
	{
		std::cerr << "ERROR: Incorrect number of arguments.\n";
		exit(AppErrors::BadArgumentCount);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	auto changePrice = [=](Book& book) {
		if (book.country() == "US") {
			book.price() *= usdToCadRate;
		}
		else if (book.country() == "UK" && book.year() >= 1990 && book.year() <= 1999) {
			book.price() *= gbpToCadRate;
		}
		return book;
	};

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";

	for (auto& book : library)
		std::cout << book;

	std::cout << "-----------------------------------------\n\n";

	for (auto& book : library)
		changePrice(book);

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";

	for (auto& book : library)
		std::cout << book;

	std::cout << "-----------------------------------------\n";

	return 0;
}
