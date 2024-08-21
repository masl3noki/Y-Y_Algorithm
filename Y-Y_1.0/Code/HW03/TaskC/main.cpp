#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    // Инициализация
    int N = 0, M = 0, buff;
    std::set<int> first, second;

    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {   
        std::cin >> buff;
        first.insert(buff);
    }

    for (int i = 0; i < M; i++) {
        std::cin >> buff;
        second.insert(buff);
    }    
    
    //std::cout << "__________________" << std::endl;

    // Тело
    std::set<int> intersection; 
    std::set_intersection(first.begin(), first.end(), 
                          second.begin(), second.end(), 
                          std::inserter(intersection, intersection.begin()));
    
    // Вывод элементов пересечения
    std::cout << intersection.size() << std::endl;
    for (auto el : intersection) {
        std::cout << el << " ";

        // Убираем элементы из пересечения
        first.erase(el);
        second.erase(el);
    } std::cout << std::endl;

    // Вывод элементов first
    std::cout << first.size() << std::endl;
    for (auto el : first)
        std::cout << el << " ";
    std::cout << std::endl;

    // Вывод элементов second
    std::cout << second.size() << std::endl;
    for (auto el : second)
        std::cout << el << " ";
    std::cout << std::endl;

    return 0;
}