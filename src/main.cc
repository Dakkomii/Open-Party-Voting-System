/**
	@file main.cc

	Implementation of the main method for the whole system

	@author King Yiu Suen (suenx008)
*/

#include <iostream>
#include <string>
#include <vector>
#include "votingsystem.h"

/// Main function of the voting system.
int main() {
    std::string welcome_message;
    std::string user_input;
    std::vector<std::string> filenames;
    
    // Indicate if all filenames are valid
    bool flag = false;

    // ASCII art generated at https://patorjk.com/software/taag
    // Ivrit font with default settings
    welcome_message += R"(
        +---------------------------------------------------------------------+
        | \ \   / /__ | |_(_)_ __   __ _  / ___| _   _ ___| |_ ___ _ __ ___   |
        |  \ \ / / _ \| __| | '_ \ / _` | \___ \| | | / __| __/ _ \ '_ ` _ \  |
        |   \ V / (_) | |_| | | | | (_| |  ___) | |_| \__ \ ||  __/ | | | | | |
        |    \_/ \___/ \__|_|_| |_|\__, | |____/ \__, |___/\__\___|_| |_| |_| |
        |                          |___/         |___/                        |
        +---------------------------------------------------------------------+
    )";
    welcome_message += "\n\n";
    std::cout << welcome_message;

    // Ask user to input ballot files
    // Repeat if one of the files is invalid
    VotingSystem* vs = new VotingSystem();
    while (!flag) {
        std::cout << "Enter ballot files here (space separated): ";
        std::getline(std::cin, user_input);
        filenames = vs->ParseFileNames(user_input);
        flag = true;
        for (auto filename : filenames) {
            if (!vs->ValidateFileName(filename)) {
                flag = false;
            }
        }
        std::cout << "\n";
    }

    vs->set_filenames(filenames);
    
    // Start counting votes and generating reports
    vs->StartAnElection();
    return 0;
}
