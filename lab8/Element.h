/**********************************************************
// OOP345 Workshop 8: Smart Pointers
// File: Element.h
// Version: 1
// Date October/16/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP345 SEF
// Description: TODOs Sections are written by Student
***********************************************************/

#ifndef W8_ELEMENT_H
#define W8_ELEMENT_H

#include <iomanip>
#include <string>
#include <fstream>

extern const int FWC;
extern const int FWD;
extern const int FWP;

namespace w8 {

	struct Description {
		unsigned code;
		std::string desc;
		bool load(std::ifstream& f)
		{
			f >> code >> desc;
			return f.good();
		}

		void display(std::ostream& os) const
		{
			os << std::setw(FWC) << code
				<< std::setw(FWD) << desc
				<< std::endl;
		}
	};

	struct Price {
		unsigned code;
		double price;
		bool load(std::ifstream& f)
		{
			f >> code >> price;
			return f.good();
		}

		void display(std::ostream& os) const
		{
			os << std::setw(FWC) << code << std::setw(FWP)
				<< price << std::endl;
		}
	};

	struct Product {
		std::string desc;
		double price;
		int m_id;
		static size_t idGenerator;
		// this variable is used to print trace messages from
		//     constructors/destructor
		static bool Trace;
		Product()
		{
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    DC [" << m_id << "]" << std::endl;
		}
		Product(const std::string& str, double p)
		{
			this->desc = str;
			this->price = p;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "     C [" << m_id << "]" << std::endl;
		}
		Product(const Product& other)
		{
			this->desc = other.desc;
			this->price = other.price;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    CC [" << m_id
				<< "] from [" << other.m_id << "]"
				<< std::endl;
		}
		~Product()
		{
			if (Product::Trace)
				std::cout << "    ~D [" << m_id << "]" << std::endl;
		}

		// TODO: add the validate() function here
		struct ValidateException : public std::exception{
			std::string message;
			ValidateException(std::string message) : message(message) {}
			~ValidateException() throw() {}
			const char *what() const throw() { return message.c_str(); }
		};

		inline void validate(){
			std::string message = "*** Negative prices are invalid ***";
			if (this->price < 0) throw message;
		}
		////////////////////////////////////////
		
		void display(std::ostream& os) const
		{
			os << std::setw(FWD) << desc
				<< std::setw(FWP) << price
				<< std::endl;
		}
	};
}
#endif