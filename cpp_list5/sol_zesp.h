#include <iostream>

class Complex
{
private:
	double real;
	double imaginary;

public:
	Complex(double r, double i);
	Complex();
	Complex(const Complex &other);

	friend std::ostream &operator<<(std::ostream &out, const Complex &other);
	const Complex &operator=(const Complex &other);
	Complex operator+(const Complex &other);
	Complex operator+(const double &other);
	Complex operator-(const Complex &other);
	Complex operator-(const double &other);
	Complex operator+=(const Complex &other);
	Complex operator-=(const Complex &other);
	Complex operator*(const Complex &other);
	Complex operator*(const double &other);
	Complex operator*=(const Complex &other);

	double GetReal() const ;
	double GetImaginary() const ;
};
