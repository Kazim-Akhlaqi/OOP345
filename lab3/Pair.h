/**********************************************************
// OOP345 Workshop 3: Templates
// File: Pair.h
// Version: 1
// Date Sept/28/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP345 SEF
// Description:
***********************************************************/

#ifndef PAIR_H
#define PAIR_H

template <typename A = char*, typename B = int>
class Pair {
	A _key;
	B _value;

public:
	// default constructor adopts a safe empty state
	Pair()
	{
	}

	// overloaded constructor that sets the key-value pair elements of the class
	Pair(const A& key, const B& value)
	{
		_key = key;
		_value = value;
	}

	// returns a read-only version of the stored key information
	const A& getKey() const
	{
		return _key;
	}

	// returns a read-only version of the stored value information
	const B& getValue() const
	{
		return _value;
	}
};
#endif