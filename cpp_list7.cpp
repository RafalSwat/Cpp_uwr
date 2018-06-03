#include <iostream>
#include <algorithm>// Brakuje prawidłowej nazwy pliku nagłówkowego
#include <vector>

struct Point
{
	int x, y;
	//-------przeładowanie operatorów do f. sort i count-------
	bool operator==(const Point &p) const
	{
		return (x == p.x && y == p.y);
	}
	bool operator<(const Point &p) const
	{
		return (x < p.x && y < p.y);
	}
	//----------------------------------------------------------
};
//---przeladowanie strumienia by pasowal do couta z zadania-----
std::ostream& operator<<(std::ostream & out, const Point & p)
{
	return out << "(" << p.x << ", " << p.y << ")";
}
//--------------------------------------------------------------
struct Rnd
{
	uint32_t _seed;
	int m;
	int a;
	int c;
	//------------lista inicjalizacyjna do los. rnd------------
	Rnd()
		: _seed(1), m(pow(2, 32)), a(1664525), c(1013904223) {}

	Rnd(int n)
		: _seed(n), m(pow(2, 32)), a(1664525), c(1013904223) {}

	//--------funktor -> serce generatora----------------------
	uint32_t operator ()()
	{
		_seed = (a * _seed + c) % m;
		return _seed;
	}
	//----------------------------------------------------------
};

class Generator
{
private:
	Rnd _rnd;
public:
	Generator(int n = 1)
		: _rnd(n) { }


	Point operator ()() // Przeciążony opertor funkcyjny
	{
		Point p;
		p.x = _rnd() & 0xfff;
		p.y = _rnd() & 0xfff;
		return p;
	}
};
//------f. jako argument sorta i counta-> moze niepotrzebne----
bool equal(Point & p1, Point & p2)
{
	return (p1 == p2);
}
bool how_sort(Point & p1, Point & p2)
{
	if (p1.x < p2.x) return true;
	else if (p1.x == p2.x && p1.y < p2.y) return true;
	else if (p1 == p2) return false;
}
//-------------------------------------------------------------
int main()
{
	const int N = 10000000;
	std::vector<Point> v(N);


	std::generate(v.begin(), v.end(), Generator(1));
	///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
	//std::set<uint_32> u;  //<--- jak nie ma?!
	///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	auto const first = v[0];
	for (auto i : { 0, 1, 2, 3, 4, 5, 10, 100, N - 1 })
	{
		std::cout << "Point[" << i << "] = " << v[i] << "\n";
		//std::cout << std::count(v.begin(), v.end(), v[i]) << "\n"; // co tu się odwala??
	}
	//--------------licz jeśli taki sam jak pierwszy-------------------
	std::cout << "elementy równe pierwszemu: ";
	std::cout << std::count(v.begin(), v.end(), v[0]) << "\n";
	//--------------to samo z cout_if (wykorzystana lambda)------------
	std::cout << "elementy równe pierwszemu: ";
	std::cout << std::count_if(v.begin(), v.end(), [first](Point const& p) -> bool {return (p == first); }) << "\n";
	//---------------sortowanie----------------------------------------
	std::sort(v.begin(), v.end(), how_sort);
	for (auto i : { 0, 1, 2, 3, 4, 5, 50, 99000, N - 1 })
	{
		std::cout << "Point[" << i << "] = " << v[i] << "\n";
	}
	//----sprawdzam rozmair wektora przed usuwaniem tych samych--------
	std::cout << "wielkosc wektora przed usuwaniem tych samych: ";
	std::cout << v.size() << "\n";
	//-----usuwanie tych samych (rozmiar ten sam...)-------------------
	std::vector<Point>::iterator it1;
	it1 = std::unique(v.begin(), v.end());
	//-----usuwanie nieokreślonych miejsc z wektora--------------------
	std::cout << "liczba unikatowych punktow: ";
	v.erase(it1, v.end());
	std::cout << v.size() << "\n";
	//-------zwalnianie miejsca pustych mijsc w "v"--------------------
	//v.resize(std::distance(v.begin(), it));
	//------------nowy rozmiar ----------------------------------------
	//std::cout << v.size() << "\n";
	//--inicjalizacja wskaźnika i przypisanie początkowej wartości-----
	//std::vector<Point>::iterator it2;
	//for (it2 = v.begin(); it2 == v.begin() + 10; ++it2)
	//{
	//	* it2 = u...
	//}


	system("pause");
}
/*for (auto i : v)
	{
	std::cout << i << std::endl;
	}*/
