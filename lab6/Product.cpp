/**********************************************************
// OOP345 Workshop 6: STL Containers
// File: Product.cpp
// Version: 1
// Date November/2/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP345 SEF
// Description:
***********************************************************/

#include "Product.h"
#include <iomanip>

namespace w6 {

	void Product::display(std::ostream & os) const {
		os << std::setw(16) << _prodNum << std::setw(16) << _prodCost;
	}

}