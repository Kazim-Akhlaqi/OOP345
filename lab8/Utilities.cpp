/**********************************************************
// OOP345 Workshop 8: Smart Pointers
// File: Utilities.cpp
// Version: 1
// Date October/16/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP345 SEF
// Description: TODOs Sections are written by Student
***********************************************************/

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace w8
{
	List<Product> mergeRaw(const List<Description>& description, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		//////////////////////////////////
		for (size_t i = 0; i < description.size(); i++){
			for (size_t n = 0; n < price.size(); n++){
				if (description[i].code == price[n].code){
					Product* ptr = new Product(description[i].desc, price[n].price);
					ptr->validate();
					priceList += ptr;

					delete ptr;
					ptr = nullptr;
				}
			}
		}
		///////////////////////////////
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& description, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		/////////////////////////////////////
		for (size_t i = 0; i < description.size(); i++){
			for (size_t n = 0; n < price.size(); n++){
				if (description[i].code == price[n].code){
					std::unique_ptr<Product> ptr(new Product(description[i].desc, price[n].price));
					ptr->validate();
					priceList += ptr;
				}
			}
		}
		////////////////////////////////////
		return priceList;
	}
}