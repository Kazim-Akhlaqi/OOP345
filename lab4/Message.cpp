/**********************************************************
// OOP345 Workshop 3: Containers
// File: Message.cpp
// Version: 1
// Date October/4/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP345 SEF
// Description:
***********************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "Message.h"

namespace w4 {

	// constructor retrieves a record from the in file object,
	// parses the record and stores its components in the Message object.
	// c is the character that delimits each record
	Message::Message(std::ifstream& in, char c) {

		std::string str;
		std::getline(in, str, c);

		std::string user;
		std::string reply;
		std::string tweet;
		size_t userLocattion;

		user = str.substr(0, str.find(' '));
		userLocattion = str.find(user);
		str.erase(userLocattion, user.length() + 1);

		if (str.find('@') != static_cast<size_t>(-1)) {
			str.erase(0, 1);
			reply = str.substr(0, str.find(' '));
			str.erase(str.find(reply), str.find(' ') + 1);
		}
		else reply = "";

		tweet = str;
		if (!tweet.empty())
			*this = Message(user, tweet, reply);
	}

	// displays the Message objects within the container
	void Message::display(std::ostream& os) const {
		os << "Message" << std::endl;
		os << " User  : " << _user << std::endl;
		if (!_reply.empty()) {
			os << " Reply : " << _reply << std::endl;
		}
		os << " Tweet : " << _tweet << std::endl;
		os << std::endl;
	}

}
