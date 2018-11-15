/**********************************************************
// OOP345 Workshop 7: STL Algorithms
// File: DataTable.h
// Version: 1
// Date October/9/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP345 SEF
// Description:
***********************************************************/
#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H

#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <numeric>
#include <algorithm>

namespace w7 {

	template<class T>
	class DataTable {

	private:

		std::vector<T> x;
		std::vector<T> y;
		int width;
		int decimals;

	public:

		DataTable(std::ifstream& fs, int _width, int _decimals) {

			width = _width;
			decimals = _decimals;

			while (fs.good()) {
				std::string line;
				std::getline(fs, line);

				std::stringstream ss;

				if (!line.empty()) {
					ss.str(line);

					T _x, _y;
					ss >> _x >> _y;

					x.push_back(_x);
					y.push_back(_y);
				}
			}
		}

		// This query returns the mean value of the dependent coordinate
		T mean() const {
			T mean = 0.0;
			T sum = std::accumulate(y.begin(), y.end(), (T)0.0);
			T ySize = y.size(); 
			
			mean = sum / ySize;

			return mean;
		}

		//This query returns the standard deviation of the dependent coordinates
		T sigma() const {
			
			T _mean = mean();
			T sum = 0.0;
			T stdDeviation = 0.0;
			T ySize = y.size();

			for (size_t i = 0; i < ySize; ++i)
				sum += (y[i] - _mean) * (y[i] - _mean);

			stdDeviation = std::sqrt(sum / (ySize - 1));
			
			return stdDeviation;
		}

		// This query returns the median value of the dependent coordinate
		T median() const {

			std::vector<T> _y = y;
			T median = 0.0;
			T _ySize = _y.size();

			std::sort(_y.begin(), _y.end());
			median = _y[_ySize / 2];

			return median;
		}

		// This query sets the parameters to the slope and intercept for the data set
		void regression(T& slope, T& y_intercept) const
		{
			T xSize = x.size();
			T ySize = y.size();

			T xSum = std::accumulate(x.begin(), x.end(), 0.0) / xSize;
			T ySum = std::accumulate(y.begin(), y.end(), 0.0) / ySize;

			T numerator = 0.0;
			T denominator = 0.0;

			for (size_t i = 0; i < xSize; ++i) {
				numerator += (x[i] - xSum) * (y[i] - ySum);
				denominator += (x[i] - xSum) * (x[i] - xSum);
			}

			slope = numerator / denominator;

			y_intercept = ySum - (slope * xSum);
		}

		// This query displays the data pairs
		void display(std::ostream& os) const {

			os << std::setw(width) << "x" << std::setw(width) << "y" << std::endl;

			T xSize = x.size();

			for (size_t i = 0; i < xSize; i++) {
				os << std::setw(width) << std::fixed 
					<< std::setprecision(decimals) << x[i]
					<< std::setw(width) << std::fixed 
					<< std::setprecision(decimals) << y[i] 
					<< std::endl;
			}
		}

		// This query returns the number of points in the dataset 
		size_t getSize() const {
			T xSize = x.size();
			return xSize;
		}
	};

	// Insertion operator helper function
	template<class T>
	std::ostream& operator<<(std::ostream& os, const DataTable<T>& DataTable){
		DataTable.display(os);
		return os;
	}
}

#endif
