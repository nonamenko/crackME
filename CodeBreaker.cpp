#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

// Функція для затримки виконання програми
void sleep_ms(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}

// Функція для перевірки пароля
bool checkPassword(const string& input) {
    // Складний пароль (можна змінити для ускладнення)
    const string correctPassword = "SecurePass123";

    // Простий захист від прямого аналізу
    // Порівнюємо ASCII значення символів з певним зміщенням
    if (input.length() != correctPassword.length()) {
        return false;
    }

    for (size_t i = 0; i < input.length(); ++i) {
        if ((input[i] ^ 0xAA) != (correctPassword[i] ^ 0xAA)) {
            return false;
        }
    }

    return true;
}

int main() {
    cout << "Вітаємо у CodeBreaker!\n";
    cout << "Будь ласка, введіть пароль: ";

    string userInput;
    cin >> userInput;

    // Невелика затримка для ускладнення аналізу
    sleep_ms(500);

    if (checkPassword(userInput)) {
        cout << "Вітаємо! Ви розбили CodeBreaker.\n";
    } else {
        cout << "Пароль невірний. Спробуйте ще раз.\n";
    }

    return 0;
}
