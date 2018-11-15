/**********************************************************
// OOP345 Workshop 5: Lambda Expressions
// File: Grades.cpp
// Version: 1
// Date October/10/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP345 SEF
// Description:
***********************************************************/
#include "Grades.h"

namespace sict {

	Grades::Grades(char* fileName) {
		try {
			std::ifstream ifs(fileName);
			if (!ifs)
				throw "Error: Failed to open the file.";

			if (ifs.is_open()) {
				std::string _str;
				int _counter = 0;

				while (getline(ifs, _str))
					_counter++;

				ifs.clear();

				ifs.seekg(0);

				counter = _counter;

				studentNumber = new std::string[counter];
				studentGrade = new double[counter];
				for (int i = 0; i < counter; i++) {
					ifs >> studentNumber[i];
					ifs >> studentGrade[i];
				}
				ifs.close();
			}
		}
		catch (std::ifstream::failure message) {
			std::cerr << "Error: Failed to open the file.";
		}
	}

	Grades::~Grades() {
		delete[] studentNumber;
		delete[] studentGrade;
	}
}

