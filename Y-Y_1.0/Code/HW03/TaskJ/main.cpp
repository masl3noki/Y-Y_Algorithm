#include <iostream>
#include <vector>
#include <utility>

std::vector<std::pair<int, int>> create_neighbours(const int& d, const std::pair<int, int>& target_point) {
    // создать вектор соседей с расстоянием <= d. Можно отсортировать по увеличению d, будет прирост производительности
    // еще подумал: возможно начинать поиск (вне этой функции) нужно с минимального радиуса - поэтому точно надо задать порядок по возрастанию d
}

void solution(const int& t, 
              const int& n, 
              const int& d, 
              const std::vector<std::pair<int, int>>& navigator) {
    // Строим соседей последней точки
    // Создаем вектор пар точек (среди соседей), от которых возможно дойти до предпоследней точки навигатора
    // Возвращаем этот построенный вектор
}


int main() {
    // Инициализация
    int t=0, d=0, n=0;
    std::vector<std::pair<int, int>> navigator;
    std::pair<int, int> buff;
    for (int i = 0; i < n; i++) {
        std::cin >> buff.first >> buff.second;
        navigator.push_back(buff);
    }

    // Тело
    solution(t, d, n, navigator);

    return 0;
}