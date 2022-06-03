/**
	@file poelection_unittest.cc

	Unit test for the POEleciton class

	@author Brian Lu (luxx0463@umn.edu)
*/

#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "poelection.h"
#include "votingsystem.h"

/// Test fixture for testing the POElection class.
class POElectionTest : public ::testing::Test {
public:
	/// Allocation of resources for test fixture.
	void SetUp() {
		std::vector<std::vector<std::string>> data = VotingSystem::CsvToData("../testing/po_testfile.csv");
		std::vector<std::vector<std::string>> data_zerovote = VotingSystem::CsvToData("../testing/po_testfile_zerovote.csv");
		std::vector<std::vector<std::string>> data_zerocand = VotingSystem::CsvToData("../testing/po_testfile_zerocand.csv");

		elections.push_back(new POElection(data, "../testing/"));
		elections.push_back(new POElection(data_zerovote, "../testing/"));
		elections.push_back(new POElection(data_zerocand, "../testing/"));
	}

	/// Deallocation of resources for test fixture.
	void TearDown() {
		for (auto e : elections) delete e;
	}

	/// A vector of pointers to POElection instances.
	std::vector<POElection*> elections;
};

/// Test the functionality of POElection's constructor.
TEST_F(POElectionTest, POElectionConstructor) {
	EXPECT_EQ(elections[0]->get_total_candidates(), 6);
	EXPECT_EQ(elections[0]->get_total_ballots(), 9);

	EXPECT_EQ(elections[1]->get_total_candidates(), 6);
	EXPECT_EQ(elections[1]->get_total_ballots(), 0);

	EXPECT_EQ(elections[2]->get_total_candidates(), 0);
	EXPECT_EQ(elections[2]->get_total_ballots(), 0);
}
