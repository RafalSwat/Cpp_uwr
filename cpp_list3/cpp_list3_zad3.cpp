#include <iostream>

void allocate(int **&tab, int n);
void free(int **tab, int n);

void allocate(int **&tab, int n) //zmienną jest wskaznik na wskaznik adresu
{
	tab = new int*[n];
	for (int i = 0; i < n; i++)
	{
		tab[i] = new int[n];
	}
}
void free(int **tab, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] tab[i];
	}
	delete[] tab;
}

int main()
{
	int** tab = nullptr;
	int n;
	std::cout << "podaj n, n > 0, n <= 10: ";
	std::cin >> n;
	if (!(n > 0 && n <= 10))
		return -1;
	allocate(&tab, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			std::cout << "t[" << i << "][" << j << "] = " << tab[i][j] << " ";
		std::cout << "\n";
	}
	free(tab, n);
}
