#include <iostream>
#include "sol_zesp.h"

int main()
{
	const Complex ii(0, 1);
	Complex a[3];
	a[0] = Complex(1, 1);
	a[1] = a[0] + ii;
	a[2] = a[1];
	a[2] += ii;
	Complex d = a[1] * a[2];
	d *= a[0];
	std::cout << a[0];
	for (int i = 1; i < 3; i++)
		std::cout << " * " << a[i];
	std::cout << " = " << d << "\n";
	std::cout << "jednostka urojona = " << ii.GetReal() << " + "
		<< ii.GetImaginary() << "i\n";

	system("pause");
	return 0;
}
