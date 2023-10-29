#include "print_table_score.h"

#include <iostream>
#include <fstream>
#include <string>

int print_table(std::string filename) {
    // Read the high score file and print all results
	
    std::ifstream in_file{filename};
    if (!in_file.is_open()) {
        std::cout << "Failed to open file for read: " << filename << "!" << std::endl;
        return -1;
    }

    std::cout << "High scores table:" << std::endl;

    std::string username;
    int high_score = 0;
    while (true) {
        // Read the username first
        in_file >> username;
        // Read the high score next
        in_file >> high_score;
        // Ignore the end of line symbol
        in_file.ignore();

        if (in_file.fail()) {
            break;
        }

        // Print the information to the screen
        std::cout << username << '\t' << high_score << std::endl;
    }
	return 0;
}