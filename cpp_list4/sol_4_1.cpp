#include <iostream>
#include <vector>
#include "sol_4_1.h"

void show(std::vector<double>& result)
{
	for (std::vector<double>::iterator it = result.begin(); it != result.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
}
double &operator*(std::vector<double>& v, std::vector<double>& w)
{
	if (v.size() != w.size()) 
	{	// Vectors must be the same size in order to add them!
		throw std::runtime_error("Can't add two vectors of different sizes!");
	}
	double product = 0;
	for (std::vector<double>::iterator it = v.begin(); it != v.end(); it++)
	{
		product += (v[*it] * w[*it]);
	}
	return product;
}
std::vector<double> fill_vector(std::vector<double>& vector)
{
	size_t size;
	double extender;
	std::cout << "how many elements in vector?: ";
	std::cin >> size;
	std::cout << std::endl;
	
	std::cout << "fill up vector: " << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> extender;
		vector.push_back(extender);
	}
	return vector;
}
