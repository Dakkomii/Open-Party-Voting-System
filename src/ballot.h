/**
	@file ballot.h

	Header file for the Ballot class

	@author Brian Lu (luxx0463@umn.edu)
*/

#ifndef SRC_BALLOT_H
#define SRC_BALLOT_H

#include <string>
#include <vector>

/**
	@brief Class that represents a ballot.

	A ballot has an ID number and an order of preferred candidates.
*/
class Ballot {
public:
	/**
		@brief Ballot's constructor.

		@param bstr A vector of strings that represents the order of preferred candidates.

		@param bid The ID number to be assigned to the ballot.
	*/
	Ballot(std::vector<std::string> bstr, int bid=-1);

	/**
		@brief Return the ballot's current preferred candidate.
		Return `-1` if there are no more preferred candidates.
	*/
	int GetChoice();

	/**
		@brief Increment the rank of the ballot, choosing its next preferred candidate.
	*/
	void IncrementRank() { rank++; }

	/**
		@brief Set the ballot to be invalid.
	*/
	void SetInvalid() { valid = false; }

	/**
		@brief Return the ID number of the ballot.
	*/
	int get_id() { return id; }

	/**
		@brief Return total number of choices specified on the ballot.
	*/
	int get_total_choices() { return total_choices; }

	/**
		@brief Return the validity of the ballot.
	*/
	bool get_valid() { return valid; }

private:
	/// The ID number of the ballot.
	int id;

	/// The total number of choices specified on the ballot.
	int total_choices;

	/// A vector of integers that represents the order of preferred candidates.
	std::vector<int> choices;

	/// The index indicating the ballot's current preferred candidate.
	int rank{0};

	/// The validity of the ballot; ballot must be removed from the election if invalid.
	bool valid{true};
};

#endif
