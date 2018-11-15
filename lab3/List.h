/**********************************************************
// OOP345 Workshop 3: Templates
// File: List.h
// Version: 1
// Date Sept/28/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP345 SEF
// Description:
***********************************************************/

#ifndef LIST_H
#define LIST_H

#include <iostream>

template <typename T, int N = 1>
class List {

	T _array[N];
	size_t count;
	T Null;

public:

	// the default constructor adopts a safe empty state
	List()
	{
		count = 0; // set count to 0
	}

	//  returns the number of entires in the array
	size_t size() const
	{
		return count;
	}

	// overloaded operator that returns the element at the requested from the array
	const T& operator[](int index) const
	{
		if (index >= 0 && index < count)
			return _array[index];
		else
			return Null;
	}

	// overloaded operator that adds an element to the array, if space is available
	void operator+=(const T& Element)
	{
		if (count > N) {
			std::cout << "Not enough Space in Array." << std::endl;
		}
		else {
			_array[count] = Element;
			count++;
		}
	}

};

#endif


