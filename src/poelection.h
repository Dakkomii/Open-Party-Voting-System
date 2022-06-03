/**
	@file poelection.h

	Header file for the POElection class

	@author Brian Lu (luxx0463@umn.edu)
*/

#ifndef SRC_POELECTION_H_
#define SRC_POELECTION_H_

#include <string>
#include <vector>

#include "election.h"

/**
	@brief Class that represents an election using Popularity Only voting.

	POElection sets up an election and runs the Popularity Only voting
	algorithm in order to determine which candidate wins.
*/
class POElection : public Election {
public:
	/**
		@brief POElection's constructor.

		@param data The parsed data from the ballot file.

		@param output_dir The output directory for the audit file and media report.
		Defaults to the current directory.
	*/
	POElection(std::vector<std::vector<std::string>> data, std::string output_dir="");

	/**
		@brief POElection's destructor.
	*/
	~POElection();

	/**
		@brief (Not implemented) Run the election.
	*/
	void Run() override {};

private:
	/**
		@brief (Not implemented) Distribute all ballots to the corresponding candidates.
	*/
	void DistributeBallots() override {};

	/**
		@brief (Not implemented) Announce the results of the election.
	*/
	void AnnounceResults() override {};

	/**
		@brief Set up the logger for the election.

		@param output_dir The output directory where the audit file and media
		report will be created.
	*/
	void SetUpLogger(std::string output_dir) override;
};

#endif
