#include <iostream> 
#include <string.h>

void show(double tab[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << tab[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}
///-------------------zad6-------------------
int main()
{
	///---------zad1------------------
	// deklaracja wskaznika na zmienna typu int
	int number = 1;
	int *ptr1 = &number;
	// deklaracja wskaznika na wskaznik
	int **ptr2 = &ptr1; /// int *ptr3 = ptr1;
	// deklaracja tab double
	double tab1[10];
	// deklaracja tab wskazników typu long long int
	long long int *tab_ptr1[10];
	// wskaznik na tab typu double
	double *ptr4 = tab1;
	//delete ptr4;
	// wskaźnik na tablicę 10 wskaźników na zmienne typu char (deklaracja dynamicznej tab)
	char **ptr5 = new char*[10];
	//delete [] ptr5;
	///---------zad2------------------
	int tab2[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int* ptr6 = &tab2[5];
	//wartosc drugie el. tab
	std::cout << tab2[1] << std::endl;
	//wrt. 0`tego el. tab
	std::cout << *tab2 << std::endl;
	//wrt 6+`ego el. tab
	std::cout << *ptr6 << std::endl;
	//wrt 2`ego el tab
	std::cout << *(tab2 + 1) << std::endl;
	//wrt 6`el tab
	std::cout << *ptr6 << std::endl;
	//pierwsze na co wskazuje ptr czyli tab[5]
	std::cout << ptr6[0] << std::endl;
	//wrt tab[5 + 3], czyli 8
	std::cout << ptr6[3] << std::endl;
	//wskazuje na tab[5 + 3]
	std::cout << *(ptr6 + 3) << std::endl;
	//wskazuje na tab[5 - 1]
	std::cout << *(ptr6 - 1) << std::endl;
	//wskazuje na tab[5 - 1]
	std::cout << ptr6[-1] << std::endl;
	//wart pierwszego el. tab
	std::cout << *&tab2[0] << std::endl;
	//wart (5-0) = 0
	std::cout << &tab2[5] - &tab2[0] << std::endl;
	//wrt 0`ego el. tab - wrt 0`ego el. tab (0 - 0) = 0
	std::cout << &tab2[0] - tab2 << std::endl;
	//!? rownowazne z (ptr6 + 1)
	std::cout << 1[ptr6] << std::endl;
	//!? rownowazne z 1[ptr6]
	std::cout << *(1 + ptr6) << std::endl;
	// wrt 5`ego el tab - wrt 0`ego el tab (5-0) = 5
	std::cout << ptr6 - tab2 << std::endl;
	//wrt 0`ego el tab - wrt 5`ego el tab (5-0) = -5
	std::cout << tab2 - ptr6 << std::endl;
	///-----------------------------
	//delete [] ptr6;
	//rzutowanie na wskaznik typu char, nie nie wiem jak interpretowac wynik
	std::cout << "(char*)tab - (char*)p " << (char*)tab2 - (char*)ptr6 << std::endl;
	std::cout << "show me elements -> "  << (char*)tab2 << " - " << (char*)ptr6 << std::endl;
	// sizeof zwraca wielkosc zarezerwowana dla inta
	std::cout << "((char*)tab - (char*)p)/sizeof(int) =  " << ((char*)tab2 - (char*)ptr6) / sizeof(int) << std::endl; 
	// sizeof zwraca ilosc elementow wskaznika
	std::cout << "((char*)tab - (char*)p)/sizeof(p) =  " << ((char*)tab2 - (char*)ptr6) / sizeof(*ptr6) << std::endl; 
	//wywala blad, void* -> sztuczka w C, temu typowi mozemy przypisac wart. wsk, dowolnego typu
	//std::cout << "(void*)tab - (void*)p = " << (void*)tab2 - (void*)ptr6 << std::endl;
	///---------zad3------------------
	//nie mam pojecia
	char (*tab3) [10];
	//tablica statyczna 2D
	int tab4[10][10] = {};
	//nie wiem ptr7 -> 0xcccccccc (wskaznik do f. przyjmuje double i zwraca double?)
	double(*ptr7)(double x);
	//nie wiem ptr8 -> 0xcccccccc (wskaznik do f ktora jest rzutowana na double i zwraca double)
	double(*ptr8)(double);
	// qsort(wsk na 0 - el. tab rzutowane na void, rozmiar tablicy, rozmiar pojedynczego el. w tab u nas int, w jaki sposob)
	void qsort(void* base, size_t num, size_t size, int(*compar)(const void*, const void*));
	// to samo, wydaje mi sie ze tab 2D
	void qsort(void*, size_t, size_t, int(*compar)(const void*, const void*));
	///---------zad4------------------
	//służy do kopiowania tekstu przekazywanego w drugim argumencie do obszaru wskazywanego przez pierwszy argument. 
	//Kopiowanie kontynuowane jest tak długo, aż zostanie skopiowany bajt zerowy.
	//KOD PISANY W C, A NIE W C++!!!
	/*void kopiuj(char ∗ dokad, const char ∗ skad) /// problem -> czy i ile miejsca jest w zm. dokad
	{
		while (∗dokad++ = ∗skad++)
			continue;
	}
	char tab5[200];
	kopiuj(tab5, ”Ala ma kota”);
	std::cout << ”tekst ’” << tab5 << ”’ ma dlugosc ” << strlen(tab5) << std::endl;*/
	///---------zad5-------------------
	std::cout << "a) " << sizeof("Ala") << std::endl;
	std::cout << "b) " << sizeof("\"Ala\"") << std::endl;
	std::cout << "c) " << sizeof("\n\n\n") << std::endl;
	std::cout << "d) " << sizeof("Ala ma kota") << std::endl;
	std::cout << "e) " << sizeof("Pięć") << std::endl;
	std::cout << "f) " << sizeof(L"Ala") << std::endl;
	std::cout << "g) " << sizeof(u"gwóźdź") << std::endl;
	std::cout << "h) " << sizeof(u8"Ala") << std::endl;
	std::cout << "i) " << sizeof(u8"Alą") << std::endl;
	std::cout << "j) " << sizeof(U"Ala") << std::endl;
	std::cout << "k) " << sizeof(U"Alą") << std::endl;
	std::cout << "l) " << sizeof("A") << std::endl;
	std::cout << "m) " << sizeof("Ą") << std::endl;
	std::cout << "n) " << sizeof("€") << std::endl;
	std::cout << "o) " << sizeof("�") << std::endl;
	
	system("pause");
	return 0;
}
