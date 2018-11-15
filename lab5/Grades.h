/**********************************************************
// OOP345 Workshop 5: Lambda Expressions
// File: Grades.h
// Version: 1
// Date October/10/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP345 SEF
// Description:
***********************************************************/
#ifndef GRADES_H
#define GRADES_H
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

namespace sict {

	class Grades {
	private:
		std::string* studentNumber;
		double* studentGrade;
		int counter;
	public:

		Grades() :studentNumber(nullptr), studentGrade(nullptr), counter(0) {}
		Grades(char* fileName);
		~Grades();

		// prohibit copy, move, copy assignment, and movd assigment
		Grades(const Grades& gradesObj) = delete;
		Grades(Grades&& gradesObj) = delete;
		Grades& operator=(const Grades& gradesObj) = delete;
		Grades&& operator=(Grades&& gradesObj) = delete;

		template<typename F>
		void displayGrades(std::ostream& os, F expr) const {
			os.setf(std::ios::fixed);
			os.precision(2);
			for (int i = 0; i < counter; i++) {
				os << std::right << std::setw(10) 
				   << studentNumber[i] << " ";
				os << std::setw(5) << std::fixed << std::setprecision(2) 
				   << studentGrade[i] << " ";
				os << std::setw(4) << std::left 
				   << expr(studentGrade[i])
				   << std::endl;
			}
		}
	};
}

#endif

