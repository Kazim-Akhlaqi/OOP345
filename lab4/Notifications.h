/**********************************************************
// OOP345 Workshop 3: Containers
// File: Notification.h
// Version: 1
// Date October/4/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP345 SEF
// Description:
***********************************************************/
#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <iostream>
#include "Message.h"
#include <vector>

namespace w4 {

	class Notifications {

	private:

		std::vector<Message> _msg;

	public:

		// default constructor - empty
		Notifications() : _msg{} {}

		// copy constructor
		Notifications(const Notifications& src) { *this = src; }

		// copy assignment operator
		Notifications& operator=(const Notifications&);

		// move constructor
		Notifications(Notifications&&);

		// move assignment operator
		Notifications& operator=(Notifications&&);

		// destructor
		~Notifications() {}

		// adds msg to the set
		void operator+=(const Message& msg);

		// inserts the Message objects to the os output stream
		void display(std::ostream& os) const;
	};

}
#endif // !NOTIFICATION_H
