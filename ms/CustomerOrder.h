/**********************************************************
// OOP345 Final Project: ms3
// File: CustomerOrder.h
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

#ifndef MS3_CUSTOMER_ORDER_H
#define MS3_CUSTOMER_ORDER_H

#include "Item.h"

struct ItemInfo {
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};

// An object from CustomerOrder class manages a single order on the assembly line.
class CustomerOrder {

private:

	// name of the customer 
	std::string m_name;

	// name of the product being assembled
	std::string m_product;

	// a count of the number of items for the customer’s order
	unsigned int m_cntItem;

	// a dynamically allocated array of pointers.
	// Each element of the array is a dynamically
	// allocated object of type ItemInfo.
	// This is the resource that CustomerOrder class must manage.
	ItemInfo** m_lstItem = nullptr;

	// the maximum the maximum width of a field,
	// used for display purposes
	static size_t m_widthField;

public:
	//default constructor
	CustomerOrder();

	// custom constructor takes a reference to a string
	//containing a single record from the input file
	CustomerOrder(std::string& record);

	// CustomerOrder object should not allow copy operations
	// and should throw an exception if called 
	CustomerOrder(CustomerOrder& other);

	// CustomerOrder object should be deleted
	CustomerOrder& operator=(CustomerOrder&) = delete;

	// move assignment operator
	CustomerOrder(CustomerOrder&& other) noexcept;
	CustomerOrder& operator=(CustomerOrder&& other);

	// desctructor
	~CustomerOrder();

	// returns the ItemInfo::m_fillState of the item specified as a parameter.
	// If the item doesn’t exist in the order, return true.
	bool getItemFillState(std::string item) const;

	// returns true if all the items in the order have been filled; false otherwise
	bool getOrderFillState() const;

	// fills the item in the current order that corresponds to
	// the item passed into the function 
	void fillItem(Item& item, std::ostream& os);

	// displays the state of the current object in the format
	void display(std::ostream& os) const;
};

#endif