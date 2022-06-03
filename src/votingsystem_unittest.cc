/**
	@file votingsystem_unittest.cc

	Unit test for the VotingSystem class

	@author King Yiu Suen (suenx008@umn.edu)
*/

#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "votingsystem.h"

/// Test fixture for testing the VotingSystem class.
class VotingSystemTest: public ::testing::Test {
public:
	/// Allocation of resources for test fixture.
	void SetUp() {
		vs = new VotingSystem();
	}

	/// Deallocation of resources for test fixture.
	void TearDown() {
		delete vs;
	}

protected:
	/// A pointer to a VotingSystem instace.
	VotingSystem* vs;
};

/// Test the functionality of VotingSystem's ParseFileNames method.
TEST_F (VotingSystemTest, VotingSystemParseFileNames) {
	std::vector<std::string> filenames;
	filenames = vs->ParseFileNames("abc.csv");
	EXPECT_EQ(filenames[0], "abc.csv");

	filenames = vs->ParseFileNames("../testing/ir_testfile.csv ../testing/opl_testfile.csv");
	EXPECT_EQ(filenames[0], "../testing/ir_testfile.csv");
	EXPECT_EQ(filenames[1], "../testing/opl_testfile.csv");
}

/// Test the functionality of VotingSystem's ValidateFileName method.
TEST_F (VotingSystemTest, VotingSystemValidateFileName) {
	EXPECT_FALSE(vs->ValidateFileName("abc123.csv"));
	EXPECT_FALSE(vs->ValidateFileName("abc123"));
	EXPECT_FALSE(vs->ValidateFileName("abc.vsc"));
	EXPECT_FALSE(vs->ValidateFileName("csv.abc"));
	EXPECT_FALSE(vs->ValidateFileName("csv"));
	EXPECT_FALSE(vs->ValidateFileName(""));
	EXPECT_TRUE(vs->ValidateFileName("../testing/ir_testfile.csv"));
	EXPECT_TRUE(vs->ValidateFileName("../testing/opl_testfile.csv"));
}

/// Test the functionality of VotingSystem's CsvToData method.
TEST_F (VotingSystemTest, VotingSystemCsvToData) {
	std::vector<std::vector<std::string>> ir_data = VotingSystem::CsvToData("../testing/ir_testfile.csv");

	EXPECT_EQ(ir_data[0][0], "IR");

	EXPECT_EQ(ir_data[1][0], "4");

	EXPECT_EQ(ir_data[2][0], "Rosen");
	EXPECT_EQ(ir_data[2][1], "D");
	EXPECT_EQ(ir_data[2][2], "Kleinberg");
	EXPECT_EQ(ir_data[2][3], "R");
	EXPECT_EQ(ir_data[2][4], "Chou");
	EXPECT_EQ(ir_data[2][5], "I");
	EXPECT_EQ(ir_data[2][6], "Royce");
	EXPECT_EQ(ir_data[2][7], "L");

	EXPECT_EQ(ir_data[3][0], "6");

	EXPECT_EQ(ir_data[4][0], "1");
	EXPECT_EQ(ir_data[4][1], "3");
	EXPECT_EQ(ir_data[4][2], "4");
	EXPECT_EQ(ir_data[4][3], "2");

	EXPECT_EQ(ir_data[5][0], "1");
	EXPECT_EQ(ir_data[5][1], "");
	EXPECT_EQ(ir_data[5][2], "2");
	EXPECT_EQ(ir_data[5][3], "");

	EXPECT_EQ(ir_data[6][0], "1");
	EXPECT_EQ(ir_data[6][1], "2");
	EXPECT_EQ(ir_data[6][2], "3");
	EXPECT_EQ(ir_data[6][3], "");

	EXPECT_EQ(ir_data[7][0], "3");
	EXPECT_EQ(ir_data[7][1], "2");
	EXPECT_EQ(ir_data[7][2], "1");
	EXPECT_EQ(ir_data[7][3], "4");

	EXPECT_EQ(ir_data[8][0], "");
	EXPECT_EQ(ir_data[8][1], "");
	EXPECT_EQ(ir_data[8][2], "1");
	EXPECT_EQ(ir_data[8][3], "2");

	EXPECT_EQ(ir_data[9][0], "");
	EXPECT_EQ(ir_data[9][1], "");
	EXPECT_EQ(ir_data[9][2], "");
	EXPECT_EQ(ir_data[9][3], "1");

	std::vector<std::vector<std::string>> opl_data = VotingSystem::CsvToData("../testing/opl_testfile.csv");

	EXPECT_EQ(opl_data[0][0], "OPL");

	EXPECT_EQ(opl_data[1][0], "6");

	EXPECT_EQ(opl_data[2][0], "Pike");
	EXPECT_EQ(opl_data[2][1], "D");
	EXPECT_EQ(opl_data[2][2], "Foster");
	EXPECT_EQ(opl_data[2][3], "D");
	EXPECT_EQ(opl_data[2][4], "Deutsch");
	EXPECT_EQ(opl_data[2][5], "R");
	EXPECT_EQ(opl_data[2][6], "Borg");
	EXPECT_EQ(opl_data[2][7], "R");
	EXPECT_EQ(opl_data[2][8], "Jones");
	EXPECT_EQ(opl_data[2][9], "R");
	EXPECT_EQ(opl_data[2][10], "Smith");
	EXPECT_EQ(opl_data[2][11], "I");

	EXPECT_EQ(opl_data[3][0], "3");

	EXPECT_EQ(opl_data[4][0], "9");

	EXPECT_EQ(opl_data[5][0], "1");
	EXPECT_EQ(opl_data[6][0], "1");
	EXPECT_EQ(opl_data[7][1], "1");
	EXPECT_EQ(opl_data[8][4], "1");
	EXPECT_EQ(opl_data[9][5], "1");
	EXPECT_EQ(opl_data[10][3], "1");
	EXPECT_EQ(opl_data[11][3], "1");
	EXPECT_EQ(opl_data[12][0], "1");
	EXPECT_EQ(opl_data[13][1], "1");

	std::vector<std::vector<std::string>> po_data = VotingSystem::CsvToData("../testing/po_testfile.csv");

	EXPECT_EQ(po_data[0][0], "PO");

	EXPECT_EQ(po_data[1][0], "6");

	EXPECT_EQ(po_data[2][0], "Pike");
	EXPECT_EQ(po_data[2][1], "D");
	EXPECT_EQ(po_data[2][2], "Foster");
	EXPECT_EQ(po_data[2][3], "D");
	EXPECT_EQ(po_data[2][4], "Deutsch");
	EXPECT_EQ(po_data[2][5], "R");
	EXPECT_EQ(po_data[2][6], "Borg");
	EXPECT_EQ(po_data[2][7], "R");
	EXPECT_EQ(po_data[2][8], "Jones");
	EXPECT_EQ(po_data[2][9], "R");
	EXPECT_EQ(po_data[2][10], "Smith");
	EXPECT_EQ(po_data[2][11], "I");

	EXPECT_EQ(po_data[3][0], "9");

	EXPECT_EQ(po_data[4][0], "1");
	EXPECT_EQ(po_data[5][0], "1");
	EXPECT_EQ(po_data[6][1], "1");
	EXPECT_EQ(po_data[7][4], "1");
	EXPECT_EQ(po_data[8][5], "1");
	EXPECT_EQ(po_data[9][3], "1");
	EXPECT_EQ(po_data[10][3], "1");
	EXPECT_EQ(po_data[11][0], "1");
	EXPECT_EQ(po_data[12][1], "1");
}

/// Test the functionality of VotingSystem's AggregateData method.
TEST_F (VotingSystemTest, VotingSystemAggregateData) {
	std::vector<std::string> ir_filenames{"../testing/ir_testfile_part1.csv", "../testing/ir_testfile_part2.csv"};
	std::vector<std::vector<std::string>> ir_data = VotingSystem::AggregateData(ir_filenames);

	EXPECT_EQ(ir_data[0][0], "IR");

	EXPECT_EQ(ir_data[1][0], "4");

	EXPECT_EQ(ir_data[2][0], "Rosen");
	EXPECT_EQ(ir_data[2][1], "D");
	EXPECT_EQ(ir_data[2][2], "Kleinberg");
	EXPECT_EQ(ir_data[2][3], "R");
	EXPECT_EQ(ir_data[2][4], "Chou");
	EXPECT_EQ(ir_data[2][5], "I");
	EXPECT_EQ(ir_data[2][6], "Royce");
	EXPECT_EQ(ir_data[2][7], "L");

	EXPECT_EQ(ir_data[3][0], "6");

	EXPECT_EQ(ir_data[4][0], "1");
	EXPECT_EQ(ir_data[4][1], "3");
	EXPECT_EQ(ir_data[4][2], "4");
	EXPECT_EQ(ir_data[4][3], "2");

	EXPECT_EQ(ir_data[5][0], "1");
	EXPECT_EQ(ir_data[5][1], "");
	EXPECT_EQ(ir_data[5][2], "2");
	EXPECT_EQ(ir_data[5][3], "");

	EXPECT_EQ(ir_data[6][0], "1");
	EXPECT_EQ(ir_data[6][1], "2");
	EXPECT_EQ(ir_data[6][2], "3");
	EXPECT_EQ(ir_data[6][3], "");

	EXPECT_EQ(ir_data[7][0], "3");
	EXPECT_EQ(ir_data[7][1], "2");
	EXPECT_EQ(ir_data[7][2], "1");
	EXPECT_EQ(ir_data[7][3], "4");

	EXPECT_EQ(ir_data[8][0], "");
	EXPECT_EQ(ir_data[8][1], "");
	EXPECT_EQ(ir_data[8][2], "1");
	EXPECT_EQ(ir_data[8][3], "2");

	EXPECT_EQ(ir_data[9][0], "");
	EXPECT_EQ(ir_data[9][1], "");
	EXPECT_EQ(ir_data[9][2], "");
	EXPECT_EQ(ir_data[9][3], "1");

	std::vector<std::string> opl_filenames{"../testing/opl_testfile_part1.csv", "../testing/opl_testfile_part2.csv", "../testing/opl_testfile_part3.csv"};
	std::vector<std::vector<std::string>> opl_data = VotingSystem::AggregateData(opl_filenames);

	EXPECT_EQ(opl_data[0][0], "OPL");

	EXPECT_EQ(opl_data[1][0], "6");

	EXPECT_EQ(opl_data[2][0], "Pike");
	EXPECT_EQ(opl_data[2][1], "D");
	EXPECT_EQ(opl_data[2][2], "Foster");
	EXPECT_EQ(opl_data[2][3], "D");
	EXPECT_EQ(opl_data[2][4], "Deutsch");
	EXPECT_EQ(opl_data[2][5], "R");
	EXPECT_EQ(opl_data[2][6], "Borg");
	EXPECT_EQ(opl_data[2][7], "R");
	EXPECT_EQ(opl_data[2][8], "Jones");
	EXPECT_EQ(opl_data[2][9], "R");
	EXPECT_EQ(opl_data[2][10], "Smith");
	EXPECT_EQ(opl_data[2][11], "I");

	EXPECT_EQ(opl_data[3][0], "3");

	EXPECT_EQ(opl_data[4][0], "9");

	EXPECT_EQ(opl_data[5][0], "1");
	EXPECT_EQ(opl_data[6][0], "1");
	EXPECT_EQ(opl_data[7][1], "1");
	EXPECT_EQ(opl_data[8][4], "1");
	EXPECT_EQ(opl_data[9][5], "1");
	EXPECT_EQ(opl_data[10][3], "1");
	EXPECT_EQ(opl_data[11][3], "1");
	EXPECT_EQ(opl_data[12][0], "1");
	EXPECT_EQ(opl_data[13][1], "1");
	
	std::vector<std::string> po_filenames{"../testing/po_testfile.csv"};
	std::vector<std::vector<std::string>> po_data = VotingSystem::AggregateData(po_filenames);

	EXPECT_EQ(po_data[0][0], "PO");

	EXPECT_EQ(po_data[1][0], "6");

	EXPECT_EQ(po_data[2][0], "Pike");
	EXPECT_EQ(po_data[2][1], "D");
	EXPECT_EQ(po_data[2][2], "Foster");
	EXPECT_EQ(po_data[2][3], "D");
	EXPECT_EQ(po_data[2][4], "Deutsch");
	EXPECT_EQ(po_data[2][5], "R");
	EXPECT_EQ(po_data[2][6], "Borg");
	EXPECT_EQ(po_data[2][7], "R");
	EXPECT_EQ(po_data[2][8], "Jones");
	EXPECT_EQ(po_data[2][9], "R");
	EXPECT_EQ(po_data[2][10], "Smith");
	EXPECT_EQ(po_data[2][11], "I");

	EXPECT_EQ(po_data[3][0], "9");

	EXPECT_EQ(po_data[4][0], "1");
	EXPECT_EQ(po_data[5][0], "1");
	EXPECT_EQ(po_data[6][1], "1");
	EXPECT_EQ(po_data[7][4], "1");
	EXPECT_EQ(po_data[8][5], "1");
	EXPECT_EQ(po_data[9][3], "1");
	EXPECT_EQ(po_data[10][3], "1");
	EXPECT_EQ(po_data[11][0], "1");
	EXPECT_EQ(po_data[12][1], "1");
}

