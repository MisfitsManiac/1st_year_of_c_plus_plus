#include "functions.h"
#include <fstream>
#include <iostream>

// Registration
void register_user(const std::string& filename) {
    std::string new_login, new_password, confirm_new_password;

    std::cout << "Register new user.\n " << std::endl;
    std::cout << "|Login|: ";
    std::cin >> new_login;
    std::cout << "|Password|: ";
    std::cin >> new_password;
    std::cout << "|Confirm password|: ";
    std::cin >> confirm_new_password;

    if (new_password != confirm_new_password) {
        std::cout << "Passwords not match. Try again." << std::endl;
        return;
    }

    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << new_login << " " << new_password << std::endl;
        file.close();
        std::cout << "Registration complete!" << std::endl;
    }
    else {
        std::cout << "ERROR 001: can't open database file!" << std::endl;
    }
}

// Login
bool login_user(const std::string& filename) {
    std::string login, password, file_login, file_password;

    std::cout << "|Login|: ";
    std::cin >> login;
    std::cout << "|Password|: ";
    std::cin >> password;

    std::fstream file(filename);

    if (file.is_open()) {
        while (file >> file_login >> file_password) {
            if (file_login == login && file_password == password) {
                file.close();
                return true;
            }
        }
        file.close();
    } else {
        std::cout << "ERROR 001: can't open database file!" << std::endl;
    }

    return false; //user not found
}

// Change password
void change_password(const std::string& filename) {
    std::string login, old_password, new_password, confirm_new_password;
    std::string file_login, file_password;

    std::cout << "Change password.\n\n" << std::endl;
    std::cout << "|Login|: ";
    std::cin >> login;
    std::cout << "|Old password|: ";
    std::cin >> old_password;

    std::ifstream file_in(filename); //users.txt for data export
    std::ofstream file_out("temp.txt"); //temp.txt for data import (temporary)
    bool user_found = false; //flag - if user was found, default is false

    if (file_in.is_open() && file_out.is_open()) { //check if both of files are opened correctly
        while (file_in >> file_login >> file_password) { //collecting data
            if (file_login == login && file_password == old_password) { //comparison of data from file (users.txt) and cin in this function
                user_found = true; //if true means it found user in users.txt

                std::cout << "|New password|: ";
                std::cin >> new_password;
                std::cout << "|Confirm new password|: ";
                std::cin >> confirm_new_password;

                if (new_password != confirm_new_password) {
                    std::cout << "Passwords not match. Try again." << std::endl;
                    file_out << file_login << " " << file_password << std::endl; //sending old data to temp.txt
                }
                else {
                    file_out << file_login << " " << new_password << std::endl; //sending new data to temp.txt
                    std::cout << "Password changed successfully!" << std::endl;
                }

            } else {
                file_out << file_login << " " << file_password << std::endl; //wrong login or/and password - no changes
            }
        }
        file_in.close(); //closing file
        file_out.close(); //closing file

        if (user_found) { //check if user found and if old password is correct
            if (std::remove(filename.c_str()) != 0) { //to study from HERE
                std::perror("Error deleting original file");
            }

            if (std::rename("temp.txt", filename.c_str()) != 0) {
                std::perror("Error renaming file"); //untill HERE
            }
            else {
                std::cout << "Password changed successfully!" << std::endl; //password changed
            }
        }
        else { //user or wrong old password - delete temp.txt
            std::remove("temp.txt");
            std::cout << "User not found or wrong password!" << std::endl;
        }
    }
}
