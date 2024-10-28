// Title: Random Number Generator
// Author: Jonathan Burishkin
// C++

#include <iostream>
#include <random>
#include <limits>
#include <algorithm>

int main() {
	std::random_device rd;
	std::mt19937 gen(rd());
	int intFirst = 0, intLast = 0;
	int minInt = std::numeric_limits<int>::min();
	int maxInt = std::numeric_limits<int>::max();
	char control;

	std::cout << "\n---RANDOM INTEGER GENERATOR---" << std::endl;
	std::cout << "Min: " << minInt << "\nMax: " << maxInt << std::endl;

	while (true) {
		// Get first integer in the range.
		std::cout << "\nWhat is the first integer in the range? ";
		while (!(std::cin >> intFirst)) {
			std::cout << "Invalid Input, try again!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nWhat is the first integer in the range? ";
		}

		// Get second integer in the range.
		std::cout << "\nWhat is the last integer in the range? ";
		while (!(std::cin >> intLast)) {
			std::cout << "Invalid Input, try again!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nWhat is the first integer in the range? ";
		}

		// Ensure intFirst is less than or equal to intLast to avoid segmentation fault.
		if (intFirst > intLast) {
			std::swap(intFirst, intLast);
		}

		// Generate a random integer in the range.
		std::uniform_int_distribution<> distrib(intFirst, intLast);
		int random_int = distrib(gen);
		std::cout << "\nRandom integer: " << random_int << "\n" << std::endl;

		// Check if the user wants to quit.
		std::cout << "If you want to quit, press 'q'; if you want to continue press any other key.";
		std::cin >> control;
		if (control == 'q' || control == 'Q') {
			std::cout << "\nExiting program...\n";
			break;
		}

	}

    return 0;
}
