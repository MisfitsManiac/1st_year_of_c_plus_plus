#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

// Deklaracja funkcji - mówi, ¿e istnieje funkcja
void register_user(const std::string& filename);
bool login_user(const std::string& filename);
void change_password(const std::string& filename);

#endif // FUNCTIONS_H