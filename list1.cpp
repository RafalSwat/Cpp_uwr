#include <iostream>
#include <cmath>
#include <climits>
#include <cstdio>
#include <Windows.h>

//ex1. przy 17! bledne wyniki, przekroczony zakres int
void factorial(int n)
{
	int result = 1;
	for (int i = 0; i <= n; i++) 
	{
		if (i < 2) 
		{
			result = i;
			std::cout << i << "!= " << result << std::endl;
		}
		else 
		{
			result *= i;
			std::cout << i << "!= " << result << std::endl;
		}
	}
}
//ex2. przekroczenie zakresu
void sum_product()
{
	int a, b;
	std::cout << "give the first number: "; std::cin >> a; std::cout << std::endl;
	std::cout << "give the second number : "; std::cin >> b; std::cout << std::endl;
	std::cout << "sum = " << a + b << std::endl;
	std::cout << "product = " << a * b << std::endl;
}
//ex.3 przy int wywala program, przy float mamy inf
void quotient_0()
{
	int a; float b;
	std::cout << "give the first number: "; std::cin >> a; std::cout << std::endl;
	std::cout << "give the second number : "; std::cin >> b; std::cout << std::endl;
	//std::cout << "quotient by 0 of " << a << " = " << a / 0 << std::endl;
	std::cout << "quotient by 0 of " << b << " = " << b / 0 << std::endl;
}
//ex.4 
void sum_double()
{
	double a, b;
	std::cout << "give the first number: "; std::cin >> a; std::cout << std::endl;
	std::cout << "give the second number : "; std::cin >> b; std::cout << std::endl;
	
	if (a + b == a)
	{
		std::cout << "a = " << a << ", " << "b: " << b << std::endl;
		std::cout << "sum = " << a + b << std::endl;
	}
	else 
	{
		std::cout << "not!" << std::endl;
		std::cout << "sum = " << a + b << std::endl;
	}
}
//ex.5 limits
void limits()
{
	std::cout << "min int: " << INT_MIN << std::endl;
	std::cout << "min abs int: " << std::abs(INT_MIN) << std::endl;
	std::cout << "min int minus 1: " << INT_MIN - 1 << std::endl;
}
//ex.6
void pi_calculus()
{
	double result_1 = 0;
	double result_2 = 1;
	double result_3 = 0;

	for (int j = 1; j<1000000; j++)
	{
		result_1 += pow(-1, j + 1) / (2 * j - 1);
		result_2 *= 4 * pow(j, 2) / (4 * pow(j, 2) - 1);
		result_3 += 1 / (pow(2 * j - 1, 2));
	}
	result_1 *= 4;
	result_2 *= 2;
	result_3 *= 8;
	result_3 = sqrt(result_3);
	std::cout << "result 1: " << result_1 << std::endl;
	std::cout << "result 2: " << result_2 << std::endl;
	std::cout << "result 3: " << result_3 << std::endl;
}
//ex.7
void pi_rec()
{
	double t = 1 / sqrt(3);
	double pi;
	for (int i = 0; i < 30; i++)
	{
		pi = 6 * pow(2, i) * t;
		t = (sqrt(pow(t, 2) + 1) - 1) / t;
		std::cout << pi << std::endl;
	}
	t = 1 / sqrt(3);
	for (int i = 0; i < 30; i++)
	{
		pi = 6 * pow(2, i) * t;
		t = t / (sqrt(pow(t, 2) + 1) + 1);
		std::cout << pi << std::endl;
	}
}

int main()
{

	system("pause");
	return 0;
}
