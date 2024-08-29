#include <iostream>
#include <set>
#include <unordered_set>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

void create_set(const std::string& str, std::set<std::string>& set) {
    char prev_letter = str[0], next_letter;
    std::string pair;
    if (prev_letter != EOF)
        for (int i=1; i < str.size(); i++) {
            next_letter = str[i];
            pair = std::string(1, prev_letter) + std::string(1, next_letter);
            set.insert(pair);
            prev_letter = next_letter;
        }
}

int main() {
    // Инициализация
    std::vector<std::pair<std::string, std::set<std::string>>> input{{"", {}}, {"", {}}};
    std::set<std::string> result;
    
    std::string buff;
    for (auto& el : input) {
        std::cin >> el.first;
        create_set(el.first, el.second);
    }

    std::set_intersection(input[0].second.begin(), input[0].second.end(),
                          input[1].second.begin(), input[1].second.end(),
                          std::inserter(result, result.begin()));
    
    std::cout << result.size();

    return 0;
}
