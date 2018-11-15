// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include "Grades.h"
#include "Letter.h"
#include <cmath>

using namespace sict;

int main(int argc, char* argv[]) {

	std::cout << "Command Line: ";
	for (int i = 0; i < argc; i++)
		std::cout << argv[i] << ' ';
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	//TODO: Update the main functions as per the specifications here
	else {
		try {
			sict::Grades grades(argv[1]);
			auto letter = [](double gradeRange) {
				gradeRange = round(gradeRange);
				if ((gradeRange >= 90.0f) && (gradeRange <= 100))
					return letterGrade(Letter::APlus);
				else if ((gradeRange >= 80) && (gradeRange < 90))
					return letterGrade(Letter::A);
				else if ((gradeRange >= 75) && (gradeRange < 80))
					return letterGrade(Letter::BPlus);
				else if ((gradeRange >= 70) && (gradeRange < 75))
					return letterGrade(Letter::B);
				else if ((gradeRange >= 65) && (gradeRange < 70))
					return letterGrade(Letter::CPlus);
				else if ((gradeRange >= 60) && (gradeRange < 65))
					return letterGrade(Letter::C);
				else if ((gradeRange >= 55) && (gradeRange < 60))
					return letterGrade(Letter::DPlus);
				else if ((gradeRange >= 50) && (gradeRange < 55))
					return letterGrade(Letter::D);
				else return letterGrade(Letter::F);
			};
			grades.displayGrades(std::cout, letter);
		}
		catch (const char* err) {
			std::cerr << argv[0] << err << argv[1] << "\n";
			return 2;
		}
	}
	return 0;
}