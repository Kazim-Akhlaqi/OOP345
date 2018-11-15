/**********************************************************
// OOP345 Workshop 6: STL Containers
// File: TaxableProduct.cpp
// Version: 1
// Date November/2/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP345 SEF
// Description:
***********************************************************/
#include "TaxableProduct.h"
#include <iomanip>

namespace w6 {

	double TaxableProduct::getPrice() const {

		double taxRate = 0.0;

		if (_taxCode == 'H') taxRate = Product::getPrice() * 1.13;
		if (_taxCode == 'P') taxRate = Product::getPrice() * 1.08;

		return taxRate;
	}

	void TaxableProduct::display(std::ostream &os) const {

		Product::display(os);
		os << std::setw(4);

		if (_taxCode == 'H')
			std::cout << "HST";
		else
			std::cout << "PST";
	}
}