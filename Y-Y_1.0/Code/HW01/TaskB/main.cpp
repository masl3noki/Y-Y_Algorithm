#include <iostream>
#include <cmath>

/**
 * @brief Решение задачи
 * 
 * @param a, b, c входные данные задачи
 * @return bool true, если выполняется условие треугольника, иначе false
 */
bool isTriangle (int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0)
        // Если какая-то из сторон треугольника равна 0, то это означает, что хотя бы 2 точки совпадают, а значит все 3 точки лежат на одной прямой ==> не треугольник. Также длина не может быть отрицательной
        return false;

    // Условие на существование треугольника (сумма длин двух сторон > 3ей стороны)
    return ((a + b > c) && (b + c > a) && (c + a > b));
}

int main() {
    // Инициализация
    int a = 0;
    int b = 0;
    int c = 0;

    std::cin >> a >> b >> c;

    // Тело
    if (isTriangle(a, b, c))
        std::cout << "YES";
    else std::cout << "NO";

    return 0;
}