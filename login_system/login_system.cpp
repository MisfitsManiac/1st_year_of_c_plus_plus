#include <iostream>
#include <string>

int main() {
	//std::string new_login, new_password;
	std::string login, password;
	std::string correct_login;
	std::string correct_password;
	int option;

	do {
		//MENU
		std::cout << "\n===== MENU =====" << std::endl;
		std::cout << "1. Login" << std::endl;
		std::cout << "2. Register" << std::endl;
		std::cout << "3. Change password" << std::endl;
		std::cout << "4. Exit" << std::endl;
		std::cout << "\nChoose option: " << std::endl;
		std::cin >> option;

		//Options
		switch (option) {
		case 1: {
			std::cout << "Welcome! Please log in.\n " << std::endl;
			std::cout << "|Login|: ";
			std::cin >> login;
			std::cout << "|Password|: ";
			std::cin >> password;

			if (login == correct_login && password == correct_password) {
				std::cout << "\nLogin succesfull!" << std::endl;
			}
			else {
				std::cout << "\nWrong login or password!" << std::endl;
			}
			break;
		}

		case 2: {
			std::cout << "Register new user.\n " << std::endl;
			std::cout << "|Login|: ";
			std::cin >> correct_login;
			std::cout << "|Password|: ";
			std::cin >> correct_password;
			break;
		}

		case 3: {
			std::string current_password, new_password, confirm_password;

			std::cout << "|Login|: ";
			std::cin >> login;

			if (login != correct_login) {
				std::cout << "Wrong login!" << std::endl;
				break;
			}

			std::cout << "|Current password|: ";
			std::cin >> password;

			if (password != correct_password) {
				std::cout << "Wrong password!" << std::endl;
				break;
			}

			std::cout << "|New password|: ";
			std::cin >> new_password;
			std::cout << "|Confirm new password|: ";
			std::cin >> confirm_password;

			if (new_password != confirm_password) {
				std::cout << "Passwords not match. Try again." << std::endl;
			}
			else if (new_password.empty()) {
				std::cout << "Password can't be empty! Try again." << std::endl;
			}
			else {
				correct_password = new_password;
				std::cout << "Password changed!" << std::endl;
			}
			break;
		}

		case 4:
			std::cout << "\nThank you for using our service!\n\nClosing application..." << std::endl;
			break;

		default:
			std::cout << "\nWrong option! Please try again." << std::endl;
		}
	} while (option != 4);

	return 0;
}