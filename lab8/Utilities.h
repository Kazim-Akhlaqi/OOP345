/**********************************************************
// OOP345 Workshop 8: Smart Pointers
// File: Utilities.h
// Version: 1
// Date October/16/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP345 SEF
// Description: Code is provide by school.
***********************************************************/

#ifndef W8_UTILITIES_H
#define W8_UTILITIES_H
#include "List.h"
#include "Element.h"

namespace w8 {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif