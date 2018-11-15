#ifndef W6_PRODUCT_H
#define W6_PRODUCT_H

/**********************************************************
// OOP345 Workshop 6: STL Containers
// File: Product.h
// Version: 1
// Date November/2/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP345 SEF
// Description:
***********************************************************/

#include <iostream>
#include <string>
#include "iProduct.h"

namespace w6 {

	class Product : public iProduct {

	private:

		std::string _prodNum;
		double _prodCost;

	public:

		Product() : _prodNum{}, _prodCost{}{}
		Product(std::string & prodNum, double prodCost) : _prodNum{ prodNum }, _prodCost{ prodCost }{}
		~Product() {};
		double getPrice() const { return _prodCost; };
		void display(std::ostream& os) const;
	};

}
#endif 