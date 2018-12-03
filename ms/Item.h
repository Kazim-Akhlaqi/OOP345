/**********************************************************
// OOP345 Final Project: ms3
// File: Item.h
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
#ifndef MS3_ITEM_H
#define MS3_ITEM_H

#include <iostream>
#include <iomanip>


// An object from Item class manages a single item on the assembly line.

class Item {

private:

	// name of the Item 
	std::string m_name;

	// description of the item 
	std::string m_description;

	// the next serial number to be assigned on the assembly line 
	unsigned int m_serialNumber;

	// the number of current items left in stock
	unsigned int m_quantity;

	// the maximum characters to be displayed for a field (all Item objects share the same WF)
	static unsigned int m_widthField;

public:
	// custom constructor receives a reference to an unmodifiable std::string. 
	// This string contains a single record(one line) that has been retrieved
	// from the input file specified by the user.
	Item(const std::string& record);

	// returns the name of the current Item object
	const std::string& getName() const;

	// returns the next serial number to be used on
	// the assembly line and increments m_serialNumber
	const unsigned int getSerialNumber();

	// returns the remaining quantity of the current Item object
	const unsigned int getQuantity();

	// substracts 1 from the available quantity; should not go below 0.
	void updateQuantity();

	// inserts the content of the current object into first parameter.
	// if full is false display just the name and SN, else display the 
	// name, SN, quanitity and description of an Item
	void display(std::ostream& os, bool full) const;
};

#endif