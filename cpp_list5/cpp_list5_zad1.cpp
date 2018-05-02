#include <iostream>

class Samochod
{
public:
	//Samochod(const int &n)
	Samochod(int const &n)
		:kola(n), sruby(4 * n)
	{
		std::cout << "Samochod z " << kola << " kolami i "
			<< sruby << " srubami\n";
	}
	Samochod() : kola(4), sruby(16) 
	{
		std::cout << "Samochod z " << kola << " kolami i "
			<< sruby << " srubami\n";
	};
	
private:
	int sruby;
	int kola;
};

int main()
{
	Samochod s4(4);
	Samochod s12(12);
	Samochod s17;

	system("pause");
	return 0;
}
