#include <iostream>
#include <cmath>

/**
 * @brief Решение задачи
 * 
 * @param N, K, M входные данные задачи
 * @return int сколько частей можно расплавить
 */
int smeltery(const int& N, const int& K, const int& M ) {
    int totalParts = 0;
    int remainingMetal = N;

    // Бесконечный цикл переплавки металла, если масса предыдущего объекта < следующего
    if (N < K || K < M)
        return 0;
    
    while (remainingMetal >= K) {
        int blanks = remainingMetal / K;
        int partsPerBlank = K / M;
        int newParts = blanks * partsPerBlank;
        totalParts += newParts;

        // Вычисление остатка
        double usedMetal = blanks * K;
        double wastedMetal = blanks * (K - partsPerBlank * M);
        remainingMetal = remainingMetal - usedMetal + wastedMetal;
    }

    return totalParts;
}

int main() {
    // Инициализация
    int N = 0, K = 0, M = 0;
    std::cin >> N >> K >> M;

    // Тело
    std::cout << smeltery(N, K, M);

    return 0;
}