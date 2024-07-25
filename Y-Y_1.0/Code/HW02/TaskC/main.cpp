#include <iostream>
#include <vector>

/**
 * @brief Решение задачи
 * 
 * @param N, seq, x параметры задачи
 * @return int, который ближе всего к x по модулю. Это число принадлежит последовательности
 */
int solution(int& N, std::vector<int>& seq, int& x) {
    if (seq.size() < 2)
        return seq[0]; // Что делать с пустой последовательностью не сказано, поэтому нам пиздец

    int diff = std::abs(x - seq[0]);
    int x_closest = seq[0];
    for (int i = 1; i < N; i++) {
        if (std::abs(x - seq[i]) < diff) {
            diff = std::abs(x - seq[i]);
            x_closest = seq[i];
        }
    }
    
    return x_closest;
}

int main() {
    // Инициализация
    int N;
    int x = -1001;
    std::vector<int> seq;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int buff;
        std::cin >> buff;
        seq.push_back(buff);
    }
    std::cin >> x;

    // Тело
    std::cout << solution(N, seq, x);

    return 0;
}