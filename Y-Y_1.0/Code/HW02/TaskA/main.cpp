#include <iostream>
#include <vector>
#include <string>
#include <sstream>

/**
 * @brief Парсинг string в vector<int>
 * 
 * @param str Строка для парсинга
 * @param result Вектор int'ов куда парсится строка
 * @note Аналог list(map(int, input().split())) в python
 */
void parseString (std::string& str, std::vector<int>& result) {
    std::istringstream iss(str);

    for (int n; iss >> n; )
        result.push_back(n);
}

/**
 * @brief Решение задачи
 * 
 * @param seq вектор чисел
 * @return true, если список монотонно возрастает, иначе false
 */
bool isIncreasing(std::vector<int>& seq) {
    if (seq.size() < 2)
        return true; //Внезапно, но ок
    
    for (int i = 1; i < seq.size(); i++) {
        if (seq[i] > seq[i-1])
            continue;
        else return false;
    }

    return true;
}

int main() {
    // Инициализация
    std::string usr_str;
    std::vector<int> seq;
    
    // list(map(int, input().split())) как в python
    std::getline(std::cin, usr_str); 
    parseString(usr_str, seq);

    if (isIncreasing(seq))
        std::cout << "YES";
    else std::cout << "NO";

    return 0;
}