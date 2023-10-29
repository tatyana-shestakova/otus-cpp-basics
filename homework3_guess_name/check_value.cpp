#include "check_value.h"

#include <iostream>

int guess_result(int targetValue) {

	const int target_value = targetValue;
	int current_value = 0;
	int attemps = 0;

	std::cout << "Enter your guess:" << std::endl;

	do {
		std::cin >> current_value;

		if (current_value < target_value) {
			std::cout << "greater than " << current_value << std::endl;
			attemps++;
		}
		else if (current_value > target_value) {
			std::cout << "less than " << current_value << std::endl;
			attemps++;
		}
		else {
			std::cout << "you win! attempts = " << attemps << std::endl;
			break;
		}

	} while(true);

	return attemps;
}