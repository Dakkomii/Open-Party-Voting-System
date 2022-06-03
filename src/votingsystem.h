/**
	@file votingsystem.h

	Header file for the VotingSystem class

	@author King Yiu Suen (suenx008@umn.edu)
*/

#ifndef SRC_VOTINGSYSTEM_H
#define SRC_VOTINGSYSTEM_H

#include <string>
#include <vector>
#include <fstream>

/**
 * @brief Class that validates and parses the ballot file.
 */
class VotingSystem {
public:
	/**
	 * @brief Parse the ballot filenames.
	 *
	 * @param user_input The input entered by the user.
	 */
	std::vector<std::string> ParseFileNames(std::string user_input);

	/**
	 * @brief Validate the ballot files.
	 *
	 * @param filename The filename entered by the user.
	 *
	 * @return A boolean value indicating whether the ballot file is valid.
	 */
	bool ValidateFileName(std::string filename);

	/**
	 * @brief Create an Election instance and run the corresponding algorithm.
	 */
	void StartAnElection();

	/**
	 * @brief Parse the CSV ballot file.
	 *
	 * @param filename The name of the ballot file to parse.
	 *
	 * @return The parsed data from the ballot file.
	 */
	static std::vector<std::vector<std::string>> CsvToData(std::string filename);

	/**
	 * @brief Aggregate data from multiple CSV ballot files.
	 *
	 * @param filenames A vector of ballot filenames.
	 *
	 * @return The aggregated data from the ballot files.
	 */
	static std::vector<std::vector<std::string>> AggregateData(std::vector<std::string> filenames);

	/**
	 * @brief Set the names of ballot files to be processed.
	 *
	 * @param f A vector of ballot filenames.
	 */
	void set_filenames(std::vector<std::string> f) { filenames = f; }

	/**
	 * @brief Get the names of ballot files to be processed.
	 *
	 * @return A vector of ballot filenames.
	 */
	std::vector<std::string> get_filenames() { return filenames; }


private:
	/// Names of the ballot file.
	std::vector<std::string> filenames;
};

#endif
