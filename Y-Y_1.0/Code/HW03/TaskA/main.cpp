#include <iostream>
#include <set>
#include <vector>

int main(){
    // Инициализация
    std::set<int> unique;
    std::vector<int> usr_ar;

    int buff;
    while (std::cin >> buff) {
        unique.insert(buff);
    }

    // Тело
    int size = unique.size();
    std::cout << size;

    return 0;
}