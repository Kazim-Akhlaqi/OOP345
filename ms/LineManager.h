/**********************************************************
// OOP345 Final Project: ms3
// File: LineManager.h
// Version: 1
// Date of completion: November/30/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP345 SEF
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
***********************************************************/
#ifndef MS3_LINE_MANAGER_H
#define MS3_LINE_MANAGER_H

#include <vector>
//#include <deque>
#include "Task.h"
#include "CustomerOrder.h"

// A object from LineManager class manages the entire assembly line
// and contains the following information:
class LineManager {

private:

	// A container containing all the references of the Task objects on the assembly line
	std::vector<Task*> AssemblyLine;

	// A queue of customer orders to be filled
	std::deque<CustomerOrder> ToBeFilled;

	// A queue of customer orders completed
	std::deque<CustomerOrder> Completed;

	// The number of CustomerOrder objects the assembly line started with
	unsigned int m_cntCustomerOrder;

	size_t m_startTask = 0u;
	size_t m_endTask = 0u;

public:

	// custom constructor with the following arguments
	// a reference to an unmodifiable std::string.
	// a reference to a std::vector<Task*>
	// a reference to a std::vector<CustomerOrder>
	LineManager(const std::string& fileName, std::vector<Task*>& tasks, std::vector<CustomerOrder>& customerOrders);

	// this function performs one cycle of operations on the assembly line 
	bool run(std::ostream&);

	// displays all the orders that were completed
	void displayCompleted(std::ostream&) const;

	// validates each task on the assembly line
	void validateTasks() const;
};

#endif


