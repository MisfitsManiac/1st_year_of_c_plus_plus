#include <iostream>

int main() {
	std::cout << "Wyœwietl liczby parzyste z zakresu od 1 do 20" << std::endl;
	for (int i = 1; i <= 20; i++) {
		if (i % 2 == 0) {
			std::cout << i << " ";
		}
	}
}