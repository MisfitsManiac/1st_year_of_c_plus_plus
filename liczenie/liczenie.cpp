#include <iostream>

int main() {
	int a, b;
	std::cout << "Podaj pierwsz� liczb�: ";
	std::cin >> a;
	std::cout << "Podaj drug� liczb�: ";
	std::cin >> b;
	std::cout << "Wynik to: ";

	int suma = a + b;
	std::cout << "Wynik to: " << suma << std::endl;

	return 0;
}