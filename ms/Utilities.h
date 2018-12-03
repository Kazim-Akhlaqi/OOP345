/**********************************************************
// OOP345 Final Project: ms3
// File: Utilities.h
// Version: 1
// Date of completion: November/24/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP345 SEF
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
***********************************************************/

#ifndef MS3_UTILITIES_H
#define MS3_UTILITIES_H

#include <string>


// Utilities class is used for Parsing string data from input files
// The Utilities type provides the basic functionality required
// for all objects in the assembly line system.

class Utilities {

private:

	// specifying the length of the token extracted;
	// used for display purpose later; default value is 1.
	size_t m_widthField = 1;

	// separates the tokens from a given std::string.
	// All Utilities objects share the same delimiter.
	static char m_delimiter;

public:
	// constructor
	Utilities();

	// sets the field width of the current object to the value of the parameter
	void setFieldWidth(size_t widthField);

	// returns the field width of the current object
	size_t getFieldWidth() const;

	// extracts tokens from the first parameter 
	const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

	// sets the delimiter for this class to the character received
	static void setDelimiter(const char delimiter);

	// returns the delimiter character of the current object
	const char getDelimiter() const;
};

#endif