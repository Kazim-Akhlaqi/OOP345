/**********************************************************
// OOP345 Workshop 6: STL Containers
// File: TaxableProduct.h
// Version: 1
// Date November/2/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP345 SEF
// Description:
***********************************************************/

#ifndef W6_TAXABLE_PRODUCT_H
#define W6_TAXABLE_PRODUCT_H

#include "Product.h"
#include <string>

namespace w6 {

	class TaxableProduct : public Product {

	private:

		char _taxCode;

	public:

		TaxableProduct() {};
		TaxableProduct(std::string prodNum, double prodCost, char taxCode) : Product(prodNum, prodCost), _taxCode(taxCode) {}
		~TaxableProduct() {};
		double getPrice() const;
		void display(std::ostream&) const;
	};

}
#endif 