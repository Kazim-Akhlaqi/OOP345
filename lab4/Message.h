/**********************************************************
// OOP345 Workshop 3: Containers
// File: Message.h
// Version: 1
// Date October/4/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP345 SEF
// Description:
***********************************************************/
#ifndef MESSAGE_H
#define MESSAGE_H

#include <fstream>

namespace w4 {

	class Message {

	private:

		std::string _user;
		std::string _tweet;
		std::string _reply;

	public:

		//default constructor
		Message() : Message("", "", "") {}

		// three argument constructor
		Message(std::string user, std::string tweet, std::string reply) : _user{ user }, _tweet{ tweet }, _reply{ reply }{}

		// constructor retrieves a record from the in file object,
		// parses the record and stores its components in the Message object.
		// c is the character that delimits each record
		Message(std::ifstream& in, char c);

		// destructor
		~Message() {};

		// returns true if the object is in a safe empty state
		bool empty() const { return (_user.empty() && _tweet.empty() && _reply.empty());}

		// displays the Message objects within the container
		void display(std::ostream&) const;

	};

}
#endif // !MESSAGE_H
