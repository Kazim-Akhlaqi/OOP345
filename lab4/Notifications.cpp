/**********************************************************
// OOP345 Workshop 3: Containers
// File: Notification.cpp
// Version: 1
// Date October/4/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP345 SEF
// Description:
***********************************************************/
#include <iostream>
#include "Message.h"
#include "Notifications.h"

namespace w4 {

	// copy assignment operator
	Notifications& Notifications::operator=(const Notifications& src) {
		if (this != &src)
			this->_msg = src._msg;

		return *this;
	}

	// move constructor
	Notifications::Notifications(Notifications && src) { *this = std::move(src); }

	// move assignment operator
	Notifications & Notifications::operator=(Notifications && src) {
		if (this != &src) {
			this->_msg = src._msg;
			(src._msg).clear();
		}
		return *this;
	}

	// adds msg to the set
	void Notifications::operator+=(const Message& msg) { _msg.push_back(msg); }

	// inserts the Message objects to the os output stream
	void Notifications::display(std::ostream& os) const {
		for (Message msg : _msg) msg.display(os);
	}

}
