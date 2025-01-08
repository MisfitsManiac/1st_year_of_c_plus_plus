#include <iostream>

int main() {
	int option;
	do {
		//MENU
		std::cout << "====== MENU =====" << std::endl;
		std::cout << "1. Powitanie" << std::endl;
		std::cout << "2. Dodawanie dwoch liczb" << std::endl;
		std::cout << "3. Sprawdz, czy liczba jest parzysta" << std::endl;
		std::cout << "4. Zamknij" << std::endl;
		std::cout << "=================\n" << std::endl;
		std::cout << "Wybierz opcje: \n" << std::endl;
		std::cin >> option;

		//opcje
		switch (option) {
		case 1: {
			std::cout << "Witaj nieznajomy!\n" << std::endl;
			break;
		}
		case 2: {
			double a, b;
			std::cout << "Podaj pierwsza liczbe: " << std::endl;
			std::cin >> a;
			std::cout << "Podaj druga liczbe: " << std::endl;
			std::cin >> b;
			std::cout << "Wynik to: " << a + b << "\n" << std::endl;
			break;
		}
		case 3: {
			int a;
			std::cout << "Parzysta czy nieparzysta?\nPodaj liczbe: " << std::endl;
			std::cin >> a;
			if (a % 2 == 0) {
				std::cout << "Liczba jest parzysta.\n" << std::endl;
			}
			else {
				std::cout << "Liczba jest nieparzysta.\n" << std::endl;
			}
			break;
		}
		case 4:
			std::cout << "Do widzenia!\n" << std::endl;
			break;

		default:
			std::cout << "Podano nieprawidlowa opcje!\n" << std::endl;
		}
	} while (option != 4);

	return 0;
}