#include "random_value\random_value.h"
#include "check_value.h"
#include "print_table_score.h"

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) {

	const std::string high_scores_filename = "high_scores.txt";

	int max_value = 100;

	// Application option
	std::string max = "-max";
	std::string level = "-level";
	std::string table = "-table";


	// Check only 2 arguments
	if(argc > 3) {
		std::cout << "Please, set only one option: level or maximun value" << std::endl;

		return -1;
	};

	// Set maximum value
	if(argc > 2 && argv[1] == max) {
		std::cout << argv[2] << std::endl;
		max_value = std::stoi(argv[2]);
	};

	// Set levels
	if(argc > 2 && argv[1] == level) {
		switch (std::stoi(argv[2]))
		{
			case 1:
				max_value = 10;
				break;
			case 2:
				max_value = 50;
				break;
			case 3:
				max_value = 100;
				break;
			
			default:
				std::cout << "Choose only current levels: 1, 2, 3" << std::endl;
				return -1;
		}
	}

	if(argc > 1 && argv[1] == table) {
		print_table(high_scores_filename);
		return 0;
	}

	// Ask about name
	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;

	// Set new random value
	int random_value = set_random_value(max_value);

	int attemps = guess_result(random_value);

	if(attemps) {
		// We should open the output file in the append mode - we don't want
		// to erase previous results.
		std::ofstream out_file{high_scores_filename, std::ios_base::app};
		if (!out_file.is_open()) {
			std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
			return -1;
		}


		// Append new results to the table:
		out_file << user_name << ' ';
		out_file << attemps;
		out_file << std::endl;

		print_table(high_scores_filename);
	}
	
	return 0;
}