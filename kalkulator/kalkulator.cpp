#include <iostream>

int main() {
	double a, b, wynik;
	char type;

	std::cout << "Kalkulator v0.1.\n\nWybierz typ operacji (podajac odpowiadajacy znak (+, -, *, /):\n\n" << std::endl;
	std::cin >> type;
	std::cout << "Podaj pierwsza liczbe: ";
	std::cin >> a;
	std::cout << "Podaj druga liczbe: ";
	std::cin >> b;

	if (type == '+') {
		wynik = a + b;
		std::cout << "Wynik to: " << wynik << std::endl;
	}

	else if (type == '-') {
		wynik = a - b;
		std::cout << "Wynik to: " << wynik << std::endl;
	}

	else if (type == '*') {
		wynik = a * b;
		std::cout << "Wynik to: " << wynik << std::endl;
	}

	else if (type == '/') {
		if (b != 0) {
			wynik = a / b;
			std::cout << "Wynik to: " << wynik << std::endl;
		}
		else {
			std::cout << "Blad: Nie mozna dzielic przez zero!" << std::endl;
		}

	}
	else {
		std::cout << "Blad! Nieprawidlowy znak dzialania!" << std::endl;
	}

	return 0;
}