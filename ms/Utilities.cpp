/**********************************************************
// OOP345 Final Project: ms3
// File: Utilities.cpp
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

#include "Utilities.h"

// separates the tokens from a given std::string.
// All Utilities objects share the same delimiter.
char Utilities::m_delimiter = ' ';

// constructor
Utilities::Utilities() {
	m_widthField = 1;
}

// sets the field width of the current object to the value of the parameter
void Utilities::setFieldWidth(size_t widthField) {
	m_widthField = widthField;
}

// returns the field width of the current object
size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

// extracts tokens from the first parameter 
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	std::string extractedToken = str.substr(next_pos);
	size_t pos = extractedToken.find(m_delimiter);
	if (pos != std::string::npos) {
		extractedToken = extractedToken.substr(0, pos);
		next_pos += pos + 1;
		if (extractedToken == "")
			throw "There is not any token between delimiters";
		more = true;
	}
	else {
		more = false;
	}
	if (extractedToken.length() > m_widthField)
		setFieldWidth(extractedToken.length());

	return extractedToken;
}

// sets the delimiter for this class to the character received
void Utilities::setDelimiter(const char delimiter) {
	m_delimiter = delimiter;
}

// returns the delimiter character of the current object

const char Utilities::getDelimiter() const {
	return m_delimiter;
}