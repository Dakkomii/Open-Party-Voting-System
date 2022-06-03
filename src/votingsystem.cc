/**
	@file votingsystem.cc

	Implementation of the methods for the VotingSystem class

	@author King Yiu Suen (suenx008@umn.edu)
*/

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <boost/tokenizer.hpp>
#include "votingsystem.h"
#include "irelection.h"
#include "oplelection.h"
#include "poelection.h"

std::vector<std::string> VotingSystem::ParseFileNames(std::string user_input) {
	std::vector<std::string> filenames;

	// Separate the input string by space
	typedef boost::tokenizer<boost::char_separator<char>> Tokenizer;
	boost::char_separator<char> sep(" ", "", boost::keep_empty_tokens);
	Tokenizer tok(user_input, sep);

	// Put the filenames in a vector
	for (Tokenizer::iterator beg = tok.begin(); beg != tok.end(); beg++) {
		std::string filename = *beg;
		filenames.push_back(filename);
	}

	return filenames;
}

bool VotingSystem::ValidateFileName(std::string filename) {
	// Check if the filename is an empty string
	if (filename.length() == 0) {
		std::cout << "Filename cannot be empty!\n";
		return false;
	}

	// Check if the file extension is csv
	if (filename.length() < 4 || filename.substr(filename.length() - 4) != ".csv") {
		std::cout << filename << " is not in csv format!\n";
		return false;
	}

	// Check if the file exists
	if (!std::ifstream(filename)) {
		std::cout << filename << " does not exist!\n";
		return false;
	}

	return true;
}

void VotingSystem::StartAnElection() {
	std::vector<std::vector<std::string>> data = AggregateData(filenames);
	Election* election;

	// Read the election type
	if (data[0][0] == "IR") {
		election = new IRElection(data);
	} else if (data[0][0] == "OPL") {
		election = new OPLElection(data);
	} else if (data[0][0] == "PO") {
		election = new POElection(data);
	}
	election->Run();
	return;
}

std::vector<std::vector<std::string>> VotingSystem::CsvToData(std::string filename) {
	std::vector<std::vector<std::string>> data;
	std::fstream csv(filename, std::ios::in);
	std::string csvline;

	while (getline(csv, csvline)) {
		std::vector<std::string> line;

		typedef boost::tokenizer<boost::char_separator<char>> Tokenizer;
		boost::char_separator<char> sep(", ", "", boost::keep_empty_tokens);
		Tokenizer tok(csvline, sep);

		for (Tokenizer::iterator beg = tok.begin(); beg != tok.end(); beg++) {
			std::string entry = *beg;
			entry.erase(remove(entry.begin(), entry.end(), '['), entry.end());
			entry.erase(remove(entry.begin(), entry.end(), ']'), entry.end());
			entry.erase(remove(entry.begin(), entry.end(), '('), entry.end());
			entry.erase(remove(entry.begin(), entry.end(), ')'), entry.end());
			line.push_back(entry);
		}

		data.push_back(line);
	}
	return data;
}

std::vector<std::vector<std::string>> VotingSystem::AggregateData(std::vector<std::string> filenames) {
	std::vector<std::vector<std::string>> aggregated_data;

	// Store the number of lines to skip
	int offset = 0;
	
	// Store the total number of ballots
	int total_ballots = 0;
	
	for (std::size_t i = 0; i < filenames.size(); i++) {
		std::vector<std::vector<std::string>> data = CsvToData(filenames[i]);
		
		aggregated_data.insert(aggregated_data.end(), data.begin() + offset, data.end());
		
		if (i == 0) {
			if (data[0][0] == "OPL") {
				offset = 5;
			} else {
				offset = 4;

			}
		}
		
		// Accumuate the number of ballots
		if (data[0][0] == "OPL") {
			total_ballots += std::stoi(data[4][0]);
		} else {
			total_ballots += std::stoi(data[3][0]);
		}
	}

	if (aggregated_data[0][0] == "OPL") {
		aggregated_data[4][0] = std::to_string(total_ballots);
	} else {
		aggregated_data[3][0] = std::to_string(total_ballots);
	}

	return aggregated_data;
}

