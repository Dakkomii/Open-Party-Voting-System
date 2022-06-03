/**
	@file poelection.cc

	Implementation of the methods for the POElection class

	@author Brian Lu (luxx0463@umn.edu)
*/

#include <string>
#include <vector>
#include <iostream>
#include "poelection.h"

POElection::POElection(std::vector<std::vector<std::string>> data, std::string output_dir) {
	// Number of candidates and ballots
	total_candidates = std::stoi(data[1][0]);
	total_ballots = std::stoi(data[3][0]);

	// Initialize winners vector to false
	winners = std::vector<bool>(total_candidates, false);

	// Convert candidate strings to Candidate instances
	for (int i=0; i<total_candidates; i++) {
		candidates.push_back(new Candidate(data[2][2*i], data[2][2*i+1]));
	}

	// Set up the election logger
	SetUpLogger(output_dir);

	// Convert ballot strings to Ballot instances
	for (int i=0; i<total_ballots; i++) {
			ballots.push_back(new Ballot(data[i+4], i));
	}
}

POElection::~POElection() {
	for (auto c : candidates) delete c;
	for (auto b : ballots) delete b;
	delete logger;
}

void POElection::SetUpLogger(std::string output_dir) {
	// audit_header holds the header for the audit file
	std::string audit_header;
	audit_header += "\n========== Voting System Audit Results ==========\n\n";
	audit_header += "Election Type: PO\n";
	audit_header += "Number of Candidates: " + std::to_string(total_candidates) + "\n";
	audit_header += "Candidates: ";
	for (int i=0; i < total_candidates; i++) {
		audit_header += candidates[i]->get_name() + " (" + candidates[i]->get_party();
		if (i == total_candidates-1) {
			audit_header += ")\n";
		} else {
			audit_header += "), ";
		}
	}
	audit_header += "Number of Ballots: " + std::to_string(total_ballots) + "\n\n";

	// logger writes to the audit file as the election runs
	logger = new ElectionLogger(output_dir);
	// Write header to audit file
	logger->WriteToAuditFile(audit_header);
}
