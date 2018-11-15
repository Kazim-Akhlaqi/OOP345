/**********************************************************
// OOP345 Workshop 6: STL Containers
// File: ProdUtil.cpp
// Version: 1
// Date November/2/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP345 SEF
// Description:
***********************************************************/

#include "iProduct.h"
#include "ProdUtil.h"
#include "TaxableProduct.h"
#include <sstream>
#include <iomanip>


namespace w6 {

	std::ostream& operator<<(std::ostream& os, const iProduct& product) {
		product.display(os);
		os << std::endl;
		return os;
	}

	iProduct* readProduct(std::ifstream& is) {

		iProduct* _ptr = nullptr;
		std::string buffer;
		std::string prodNum;
		char taxCode = {};
		double prodCost = {};
		

		if (is.good())
		{
			if (std::getline(is, buffer, '\n')) {

				std::stringstream iss(buffer);

				if (buffer.length() == 11) {

					iss >> prodNum >> prodCost;

					_ptr = new Product(prodNum, prodCost);

				}

				if (buffer.length() == 13) {

					iss >> prodNum >> prodCost >> taxCode;

					if (taxCode == 'H' || taxCode == 'P') {

						_ptr = new TaxableProduct(prodNum, prodCost, taxCode);

					}
					else {

						std::string err = "Unrecognizable Tax Code!";
						taxCode = 0;
						throw err;

					}
				}
			}
		}

		return _ptr;
	}

}
