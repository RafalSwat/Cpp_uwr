#include <iostream>
#include <climits>
#include <cmath>

void my_swap(int *n, int *m);
void my_print(int *tab, int b);
void my_reverse(int *tab, const int N);
int my_sum(int *a, const int N);

void my_swap(int *n, int *m)
{
	int temp = *n;
	*n = *m;
	*m = temp;
}
void my_print(int *tab, const int n)
{
	for (int i = 0; i < n; i++)
		std::cout << tab[i] << ' ';
	std::cout << '\n';
}
void my_reverse(int *tab, const int N)
{	
	for (int i = 0; i < N; i++)
	{
		if (i < (N / 2.0))
		{
			my_swap(&tab[i], &tab[N - 1 - i]);
		}
	}
}
int my_sum(int *tab, const int N)
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += tab[i];
	}
	return sum;
}

int main()
{
	int n = 9, m = 10;
	std::cout << n << " " << m << "\n";
	my_swap(&n, &m);
	std::cout << n << " " << m << "\n";
	int tab[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	my_print(tab + 2, 7);
	my_reverse(tab + 1, 8);
	my_print(tab, 10);
	std::cout << my_sum(&tab[8], 2) << "\n"; // suma ostatnich dwóch

	system("pause");
	return 0;
}
