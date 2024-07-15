#include <iostream>
#include <vector>
#include <limits>

#define INFINITY std::numeric_limits<double>::max()
//double INFINITY = std::numeric_limits<double>::max();

struct solution {
    int sol_case = -1;
    std::vector<double> sol_values;
};

solution solver(std::vector<int>& data) {
    // Инициализация
    double a = data[0], b = data[1], c = data[2], d = data[3], e = data[4], f = data[5];
    double x0 = INFINITY, y0 = INFINITY;

    // 5) Ответ любая пара
    if (a == 0 && b == 0 && c == 0 && d == 0) {
        if (e == 0 && f == 0)
            return {5, {}};
        else return {0, {}};
    }

    // 1) Беск. много решений вида y=kx+b
    if (b != 0 && b*c == a*d && b*f == e*d && a*f == e*c) {
        if (c != 0 && d != 0 && f != 0)
            return {1, {-a/b, e/b}};
    }

    // 2) Единственное решение
    if (a != 0 || c != 0) {
        if (b != 0 || d != 0) {
            x0 = (e*d - f*b) / (a*d - c*b);
            if (b != 0)
                y0 = (e-a*x0)/b;
            else
                y0 = (f-c*x0)/d;
            
            return {2, {x0, y0}};        
        }
    }

    // 3) Беск. много решений вида x = x0 && \forall y \in \mathbb{R}
    if (b == 0 && b == d) {
        x0 = e/a;
        if (f/c == x0)
            return {3, {x0}};
    }

    // 4) Беск. много решений вида \forall x \in \mathbb{R} && y = y0
    if (a == 0 && a == c) {
        y0 = e/b;
        if (f/d == y0)
            return {4, {y0}};
    }
    
    // 0) Нет решений (а также все остальные случаи)
    return {0, {}};
}

int main() {
    // Инициализация
    std::vector<int> data;
    for (int i = 0; i < 6; i++)
    {
        double buff = INFINITY;
        std::cin >> buff;
        data.push_back(buff);
    }

    // Тело
    auto result = solver(data);
    std::cout << result.sol_case;

    if (result.sol_values.size() > 0)
    for (auto el : result.sol_values) {
        if (el == -0) // поправка на "приколы"
            el = 0;
        std::cout << " " << el;    
    }  

    return 0;
}