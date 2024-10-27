#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

int main() {
    
	const int max_value = 100;
	int current_value = 0;
	bool not_win = true;
	std::srand(std::time(nullptr));
	const int random_value = std::rand() % 100;

	const std::string high_scores_filename = "high_score.txt";

    
    std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;
	
	//int attempts = 1;
	int attempts_count = 0;
	
	std::cout << "Enter your guess:" << std::endl;


	do {
	    
		std::cin >> current_value;

		if (current_value < random_value && max_value) {
			std::cout << "less than " << current_value << std::endl;
			++attempts_count;
		}
		else if (current_value > random_value && max_value) {
			std::cout << "greater than " << current_value << std::endl;
			++attempts_count;
		}
		else {
			std::cout << "you win! attempts = " << attempts_count << "\n" << std::endl;


			std::ofstream out_file(high_scores_filename, std::ios_base::app);

			if (!out_file.is_open()) {
			std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
			return -1;
			}

			
			// Append new results to the table:
			out_file << user_name << ' ';
			out_file << attempts_count;
			out_file << std::endl;

			std::ifstream in_file(high_scores_filename);
			if (!in_file.is_open()) {
			std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
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
				break;
		}

	} while(not_win);

	

	return 0;
}