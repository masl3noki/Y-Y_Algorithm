#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

/**
 * @brief "Конструктор" мапы, которая считает количество вхождений пар оснований генома
 * 
 * @param str геном жителя в виде строки
 * @param map мапа для парсинга генома
*/
void create_set(const std::string& str, std::map<std::string, int>& map) {
    char prev_letter = str[0], next_letter;
    std::string pair;
    if (prev_letter != EOF)
        for (int i=1; i < str.size(); i++) {
            next_letter = str[i];
            pair = std::string(1, prev_letter) + std::string(1, next_letter);
            map[pair]++;
            prev_letter = next_letter;
        }
}

/**
 * @brief Собственная реализация операции пересечения между мапами
 * 
 * @param left, right мапы, над которыми проводится операция
 * @return мапа, которая представляет пересечение множеств
 */
std::map<std::string, int> map_intersection(std::map<std::string, int> left, 
                      std::map<std::string, int> right) {
    std::map<std::string, int>::const_iterator il = left.begin();
    std::map<std::string, int>::const_iterator ir = right.begin();
    std::map<std::string, int> result;

     while (il != left.end() && ir != right.end()) {
        if (il->first < ir->first)
            ++il;
        else if (ir->first < il->first)
            ++ir;
        else {
            result[il->first] = (il->second);
            //result.insert(std::make_pair(il->first, std::make_pair(il->second, ir->second)));
            ++il;
            ++ir;
        }
    }

    return result;
}

int main() {
    // Инициализация
    std::vector<std::pair<std::string, std::map<std::string, int>>> input{{"", {}}, {"", {}}};
    std::map<std::string, int> result;
    
    std::string buff;
    for (auto& el : input) {
        std::cin >> el.first;
        create_set(el.first, el.second);
    }

    // Тело
    result = map_intersection(input[0].second, input[1].second);
    
    int count = 0;
    for (const auto& el : result)
        count += el.second;

    std::cout << count;

    return 0;
}
