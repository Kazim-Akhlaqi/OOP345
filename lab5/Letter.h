/**********************************************************
// OOP345 Workshop 5: Lambda Expressions
// File: Letter.h
// Version: 1
// Date October/10/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP345 SEF
// Description:
***********************************************************/
#ifndef LETTER_H
#define LETTER_H

#include <string>

namespace sict {

	enum class Letter { APlus, A, BPlus, B, CPlus, C, DPlus, D, F };

	std::string letterGrade(const Letter letter) {
		switch (letter) {
		case Letter::APlus:
			return "A+";
			break;
		case Letter::A:
			return "A";
			break;
		case Letter::BPlus:
			return "B+";
			break;
		case Letter::B:
			return "B";
			break;
		case Letter::CPlus:
			return "C+";
			break;
		case Letter::C:
			return "C";
			break;
		case Letter::DPlus:
			return "D+";
			break;
		case Letter::D:
			return "D";
			break;
		case Letter::F:
			return "F";
			break;
		}
		return 0;
	}
}
#endif



