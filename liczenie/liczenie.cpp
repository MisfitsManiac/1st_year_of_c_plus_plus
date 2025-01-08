#include <iostream>

int main() {
	int a, b;
	std::cout << "Podaj pierwsz¹ liczbê: ";
	std::cin >> a;
	std::cout << "Podaj drug¹ liczbê: ";
	std::cin >> b;
	std::cout << "Wynik to: ";

	int suma = a + b;
	std::cout << "Wynik to: " << suma << std::endl;

	return 0;
}