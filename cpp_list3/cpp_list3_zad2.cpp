#include <iostream>
#include <string>
#include <cstdlib>
#include <string>
double get_double(const char* s);
void error(const char* s);

void error(const char* s)
{
	std::cerr << s << "\nProgram aborted\n";
	exit(-1);
}
double get_double(const char* s)
{
	std::string::size_type ptr;     // Wskaźnik ustawiany na pozycję pierwszego znaku w stringu po liczbie
	if (isdigit(*s))
	{
		return std::stod(s, &ptr);
	}
	else
	{
		error(s);
	}
} 

int main(int argc, const char* argv[])
{
	if (argc != 4)
		error("Expecting 3 arguments");
	double a = get_double(argv[1]);
	double b = get_double(argv[3]);
	double c;
	switch (argv[2][0])
	{
	case '+': c = a + b; break;
	case '-': c = a - b; break;
	case '*': c = a * b; break;
	case '/': c = a / b; break;
	default: error("unexpected token");
	};
	std::cout << "= " << c << "\n";
}
