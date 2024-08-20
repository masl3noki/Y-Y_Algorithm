#include <iostream>
#include <sstream>
#include <string>

#include <algorithm>
#include <iterator>
#include <set>
#include <vector>

int main(){
    // Инициализация
    std::set<int> first, second;
    std::vector<int> result;
    
    std::string usr_str;
    std::getline(std::cin, usr_str);
    std::istringstream iss(usr_str);
    for (int n; iss >> n; )
        first.insert(n);
    iss.clear();

    std::getline(std::cin, usr_str);
    iss.str(usr_str);
    for (int n; iss >> n; )
        second.insert(n);

    // Тело
    std::set_intersection(first.begin(), first.end(), second.begin(), second.end(), std::back_inserter(result));

    // Вывод
    for (auto el : result)
        std::cout << el << " ";
    
    return 0;
}