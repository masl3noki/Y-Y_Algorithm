#include <iostream>
#include <utility>
#include <unordered_set>
#include <vector>

/**
 * @brief Хеширование для unordered_set и элемента pair
 * 
 * @note Здесь я не особо заморачивался
 */
struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

/**
 * @brief Проверка на вхождение значения в полулуч [0, finish)
 * 
 * @param finish конец интервала
 * @param target элемент для проверки
 * 
 * @return true, если target внутри полулуча, иначе false
 * 
 * @note На самом деле похожая функция есть в стандартной библиотеке (std::clamp), но там отрезок. И чем копаться в функции, проще было написать самому
 */
bool in_Interval (const int& finish, const int& target) {
    if (target < finish && target >= 0)
        return true;
    return false;
}

/**
 * @brief Решение задачи
 * 
 * @param n исходное количество черепах
 * @param turtles множество уникальных черепах и соотв. пар значений
 * 
 * @return количество черепах, говорящих правду
 */
int solution(const int& n, const std::unordered_set<std::pair<int, int>, pair_hash>& turtles) {
    int count = 0;
    for (const auto& el : turtles) {
        if (in_Interval(n, el.first) && in_Interval(n, el.second) && (el.first + el.second) == n-1)
            count++;
    }

    return count;
}

int main() {
    // Инициализация
    int n=-1;
    std::unordered_set<std::pair<int, int>, pair_hash> turtles;
    
    std::cin >> n;
    std::pair<int, int> buff;
    for (int i = 0; i < n; i++) {
        std::cin >> buff.first >> buff.second;
        turtles.insert(buff);    
    }

    std::cout << solution(n, turtles);

    return 0;
}