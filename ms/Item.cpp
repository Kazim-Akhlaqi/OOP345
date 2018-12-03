/**********************************************************
// OOP345 Final Project: ms3
// File: Item.cpp
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
#include "Item.h"
#include <iomanip>

// the maximum characters to be displayed for a field (all Item objects share the same WF)

unsigned int Item::m_widthField = 0;

// custom constructor receives a reference to an unmodifiable std::string. 
// This string contains a single record(one line) that has been retrieved
// from the input file specified by the user.
Item::Item(const std::string& record) {
	size_t m_count = 0u;
	size_t m_pos = 0u;
	bool m_more = true;
	Utilities utilities;
	while (m_more && m_count < 4) {
		if (m_count == 0) {
			m_name = utilities.extractToken(record, m_pos, m_more);
		}
		else if (m_count == 1) {
			m_serialNumber = (unsigned)std::stoi(utilities.extractToken(record, m_pos, m_more));
		}
		else if (m_count == 2) {
			m_quantity = (unsigned int)std::stoi(utilities.extractToken(record, m_pos, m_more));
			if (utilities.getFieldWidth() > m_widthField) {
				m_widthField = utilities.getFieldWidth();
			}
		}
		else m_description = utilities.extractToken(record, m_pos, m_more);
		m_count++;
	}
}

// returns the name of the current Item object
const std::string& Item::getName() const {
	return m_name;
}

// returns the next serial number to be used on
// the assembly line and increments m_serialNumber
const unsigned int Item::getSerialNumber() {
	return m_serialNumber++;
}

// returns the remaining quantity of the current Item object
const unsigned int Item::getQuantity() {
	return m_quantity;
}

// substracts 1 from the available quantity; should not go below 0.
void Item::updateQuantity() {
	if (m_quantity > 0)
		m_quantity--;
}

// inserts the content of the current object into first parameter.
// if full is false display just the name and SN, else display the 
// name, SN, quanitity and description of an Item
void Item::display(std::ostream& os, bool full) const {

	if (full) {
		os << std::setw(m_widthField) << std::left << m_name;
		os << " [" << std::setw(6) << std::right << std::setfill('0') << m_serialNumber << std::setfill(' ') << std::left;
		os << "] Quantity: " << std::setw(m_widthField) << std::left << m_quantity;
		os << " Description: " << m_description << std::endl;
	}
	else {
		os << std::setw(m_widthField) << std::left << m_name;
		os << " [" << std::right << std::setw(6) << std::setfill('0') << m_serialNumber << std::setfill(' ') << std::left << "]" << std::endl;
	}

}