#include <iostream>
#include <set> // т.к. теперь нам важен порядок и возможность итерироваться по элементам
#include <vector>
#include <algorithm>

#define NUMBER_OF_BUTTONS 3

int main() {
    // Инициализация
    int buff;
    unsigned int N = 0;
    std::set<int> inputSet, modSet, resultSet;
    
    for (int i = 0; i < NUMBER_OF_BUTTONS; i++) {
        std::cin >> buff; //x, y, z
        inputSet.insert(buff);
    }

    std::cin >> buff; //N
    while (buff > 0) {
        modSet.insert(buff % 10);
        buff /= 10;
    }

    std::set_difference(modSet.begin(), modSet.end(), 
                        inputSet.begin(), inputSet.end(), std::inserter(resultSet, resultSet.begin()));

    std::cout << resultSet.size();

    return 0;
}