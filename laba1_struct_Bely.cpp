#include <iostream>
#include <tuple>

// Функция для нахождения НОД и коэффициентов x, y
std::tuple<int, int, int> extended_gcd(int a, int b) {
    if (b == 0) {
        return std::make_tuple(a, 1, 0);
    }
    int gcd, x1, y1;
    std::tie(gcd, x1, y1) = extended_gcd(b, a % b);
    int x = y1;
    int y = x1 - (a / b) * y1;
    return std::make_tuple(gcd, x, y);
}

// Функция для нахождения обратного элемента
int mod_inverse(int a, int n) {
    int gcd, x, y;
    std::tie(gcd, x, y) = extended_gcd(a, n);
    if (gcd != 1) {
        return 0; // Обратного элемента не существует
    }
    else {
        return (x % n + n) % n; // Приведение x к положительному остатку
    }
}

int main() {
    int a, n;
    std::cout << "Введите a и n: ";
    std::cin >> a >> n;

    int result = mod_inverse(a, n);
    if (result == 0) {
        std::cout << "Обратного элемента не существует" << std::endl;
    }
    else {
        std::cout << "Обратный элемент: " << result << std::endl;
    }

    return 0;
}