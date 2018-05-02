#include <iostream>
#include <cmath>
#include "sol_zesp.h"


Complex::Complex(double r, double i) : real(r), imaginary(i) {}
Complex::Complex() : real(0), imaginary(0) {}
Complex::Complex(const Complex &other)
{
	real = other.real;
	imaginary = other.imaginary;
}

std::ostream &operator<<(std::ostream &out, const Complex &other)
{
	out << other.real << ", " << other.imaginary;
	return out;
}
const Complex &Complex::operator=(const Complex &other)
{
	return Complex(this->real = other.real, this->imaginary = other.imaginary);
}
Complex Complex::operator+(const Complex &other)
{
	return Complex(this->real + other.real, this->imaginary + other.imaginary);
}
Complex Complex::operator+(const double &other)
{
	return Complex(this->real + other, this->imaginary);
}
Complex Complex::operator-(const Complex &other)
{
	return Complex(this->real - other.real, this->imaginary - other.imaginary);
}
Complex Complex::operator-(const double &other)
{
	return Complex(this->real - other, this->imaginary);
}
Complex Complex::operator+=(const Complex &other)
{
	this->real = this->real + other.real;
	this->imaginary = this->imaginary + other.imaginary;
	return *this;
}
Complex Complex::operator-=(const Complex &other)
{
	this->real = this->real - other.real;
	this->imaginary = this->imaginary - other.imaginary;
	return *this;
}
Complex Complex::operator*(const Complex &other)
{
	return Complex(this->real * other.real, this->imaginary * other.imaginary);
}
Complex Complex::operator*(const double &other)
{
	return Complex(this->real * other, this->imaginary);
}
Complex Complex::operator*=(const Complex &other)
{
	this->real = this->real * other.real;
	this->imaginary = this->imaginary * other.imaginary;
	return *this;
}

double Complex::GetReal() const { return this->real; }
double Complex::GetImaginary() const { return this->imaginary; }
