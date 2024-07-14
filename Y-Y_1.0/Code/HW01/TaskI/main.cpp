#include <iostream>
#include <limits>
#include <vector>

/**
 * @brief Вспомогательная функция, проверяет проходит ли кирпич через отверстие в стене
 * 
 * @param brick_w, brick_l размер кирпича
 * @param wall_w, wall_l размер отверстия в стене
 * @return true если проходит, иначе false
 * 
 * @note для solution_1
 */
bool fit(int& brick_w, int& brick_l, int& wall_w, int& wall_l) {
    // Комбинаторика. Если хоть каким-то образом brick пролезет через wall, то return true
    if (brick_w <= wall_w && brick_l <= wall_l || brick_l <= wall_w && brick_w <= wall_l)
        return true;
    else return false;
}

/**
 * @brief Вспомогательная функция, ведет поиск двух минимумов
 * 
 * @param a, b, c размер кирпича
 * @return std::pair<int, int> длина и ширина грани кирпича с наименьшими сторонами
 * 
 * @note для solution_2
 */
std::pair<int, int> doubleMin (int& a, int& b, int& c) {
    // Инициализация
    int min1 = a;
    int min2 = a;
    std::vector<int> arr = {a, b, c};

    for (int num : arr) {
        if (num < min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2 && num != min1) {
            min2 = num;
        }
    }

    return {min1, min2};
}

/**
 * @brief Решение первым способом: перебором всех 6 случаев
 * 
 * @param a, b, c размеры кирпича
 * @param d, e размеры отверстия в стене
 * @return true если проходит, иначе false
 * 
 * @note Проверяются все три грани кирпича, каждая грань может быть расположена относительно отверстия в стене 2-мя способами. Итого 6 случаев
 */
bool solution_1(int& a, int& b, int& c, int& d, int& e) {
    if (fit(a, b, d, e) || fit(b, c, d, e) || fit(a, c, d, e))
        return true;
    else return false;
}

/**
 * @brief Решение вторым способом: сравнение минимумов
 * @param a, b, c размеры кирпича
 * @param d, e размеры отверстия в стене
 * @return true если проходит, иначе false
 * 
 * @note Проверяются две упорядоченные пары, с порядком {a, b} | a <= b: brick представляет собой пару {min1, min2} из двух минимальных сторон кирпича, аналогично wall.
 */
bool solution_2(int& a, int& b, int& c, int& d, int& e) {\
    auto brick = doubleMin(a, b, c);
    std::pair<int, int> wall = (d < e) ? std::pair{d, e} : std::pair{e, d};

    if (brick.first <= wall.first && brick.second <= wall.second)
        return true;
    else return false;
}

int main() {
    // Инициализация
    int a = 0, b =0, c = 0, d = 0, e = 0;
    std::cin >> a >> b >> c >> d >> e;

    // Тело
    if (solution_2(a, b, c, d, e))
        std::cout << "YES";
    else std::cout << "NO";

    return 0;
}