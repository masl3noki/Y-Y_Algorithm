#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <iterator>

struct pair_hash {
    std::size_t operator()(const std::pair<int, int>& p) const {
        // Используем стандартную хеш-функцию для int и комбинируем хеши
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};

std::unordered_set<std::pair<int, int>, pair_hash> create_neighbours(const int& d, 
                                                                     const std::pair<int, int>& target_point) {
    // создать вектор соседей с расстоянием <= d. Можно отсортировать по увеличению d, будет прирост производительности
    // еще подумал: возможно начинать поиск (вне этой функции) нужно с минимального радиуса - поэтому точно надо задать порядок по возрастанию d
    std::unordered_set<std::pair<int, int>, pair_hash> neighbours;
    
    int i = target_point.first,
        j = target_point.second,
        i_ = 0,
        j_ = -d;

    while (abs(i_) + abs(j_) <= d){
        neighbours.insert({i+i_, j+j_});
        j_++;
    }

    std::unordered_set<std::pair<int, int>, pair_hash> to_add;
    for (const auto& point : neighbours){
        j_ = target_point.second - point.second;

        i_ = target_point.first - point.first + 1; // техническое смещение на уровень вверх (относительно расположения точек)
        while (abs(i_) + abs(j_) <= d){
            to_add.insert({i+i_, j+j_});
            i_++;
        }

        i_ = target_point.first - point.first - 1; // техническое смещение на уровень вниз
        while (abs(i_) + abs(j_) <= d){
            to_add.insert({i+i_, j+j_});
            i_--;
        }
    }

    for (const auto& point : to_add){
        neighbours.insert(point);
    }

    std::cout << neighbours.size() << '\n';
    return neighbours;
    
}

std::unordered_set<std::pair<int, int>, pair_hash> create_neighbours_second_layer(int d, 
                                                                     const std::pair<int, int>& target_point) {
    std::unordered_set<std::pair<int, int>, pair_hash> neighbours;
    auto target_set = create_neighbours(d, target_point);
    d = 2*d;
    int i = target_point.first,
        j = target_point.second,
        i_ = 0,
        j_ = -d;
    

    while (abs(i_) + abs(j_) <= d){
        neighbours.insert({i+i_, j+j_});
        j_++;
    }

    std::unordered_set<std::pair<int, int>, pair_hash> to_add;
    for (const auto& point : neighbours){
        j_ = target_point.second - point.second;

        i_ = target_point.first - point.first + 1; // техническое смещение на уровень вверх (относительно расположения точек)
        while (abs(i_) + abs(j_) <= d){
            to_add.insert({i+i_, j+j_});
            i_++;
        }

        i_ = target_point.first - point.first - 1; // техническое смещение на уровень вниз
        while (abs(i_) + abs(j_) <= d){
            to_add.insert({i+i_, j+j_});
            i_--;
        }
    }

    for (const auto& point : to_add){
        neighbours.insert(point);
    }

    std::cout << neighbours.size() << '\n';
    
    // Уничтожаем первый круг соседей
    
    for (const auto& elem : target_set){
        neighbours.erase(elem);
    }

    std::cout << neighbours.size() << '\n';
    return neighbours;    
}

std::unordered_set<std::pair<int, int>, pair_hash> neighbour_connection(const int& d, 
                                                                        const std::pair<int, int>& host,
                                                                        const std::pair<int, int>& target) {
    // Случай, если общих точек нет. Надо разработать случай, когда существуют общие точки.
    auto host_set = create_neighbours_second_layer(d, host);
    auto target_set = create_neighbours(d, target);
    std::unordered_set<std::pair<int, int>, pair_hash> to_connect;
    for (const auto& point : host_set){
        if 
    }
}

void solution(const int& t,
              const int& d,
              const int& n,  
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
    //std::cin >> t >> d >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> buff.first >> buff.second;
        navigator.push_back(buff);
    }

    // Тело
    //solution(t, d, n, navigator);
    auto a = create_neighbours_second_layer(2, {0, 0});

    return 0;
}