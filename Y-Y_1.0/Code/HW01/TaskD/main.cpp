#include <iostream>
#include <cmath>
#include <string>

std::string solver(int& a, int&b, int&c) {
    // Если коэффициент перед x обнуляется, то либо x \in \varnothing, когда \sqrt{b} != c; либо x \in \mathbb{R} в другом случае
    if (a == 0) {
        if (std::sqrt(b) == c) {
            return "MANY SOLUTIONS";
        } else return "NO SOLUTION";
    }

    // Мы решаем в вещественных числах, значит при c<0 решения нет
    if (c < 0) {
        return "NO SOLUTION";
    }

    // Ищем решения только в целых числах, поэтому остаток от деления должен быть 0, чтобы решение прошло
    int x = (std::pow(c, 2) - b) / a;
    if (int(std::pow(c, 2) - b) % a != 0)
        return "NO SOLUTION";
    else return std::to_string(x);
}

int main() {
    // Инициализация
    int a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;

    // Тело
    std::cout << solver(a, b, c);

    return 0;
}