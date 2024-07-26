#include <iostream>
#include <vector>
#include <map>
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
 * @brief Решение задачи (более строгое)
 * 
 * @param seq последовательность чисел
 * @return int количество соседей наиболее часто встречающихся чисел
 * 
 * @note Это неверное решение. Сначала я думал нужно найти количество уникальных чисел, которые всегда больше соседей. 
 * Отличие от требуемого алгоритма в том, что если число, которое уже имеется в словаре, не проходит условие, то оно удаляется (как ключ)
 */
int solution_strict(std::vector<int>& seq) {
    /* может использовать мапу или словарь? По крайней мере точно нужно считать количество уникальных чисел
    Вариант 1) пройтись по вектору, посчитать k - количество уникальных чисел; пройтись снова по вектору k раз и если всегда это число больше двух соседей, то вывести.
            Сложность O(k*N)
    Вариант 2) пройтись по вектору, рассматривая сразу 3 элемента на каждой итерации. На каждой итерации оценить имеет ли смысл рассматривать центральное число.
    Если нет, то continue, если да, то сохраняем число в словарь. Продолжаем итерации, на каждом шаге проверяем центральное число на условие. Если не выполняется, но имеется в словаре, то удаляем из рассмотрения.
    По идее это O(N), а сложность по памяти не меняется. 
    
    По формулировке задачи, мы не рассматриваем крайние элементы? Не знаю пока
    */
    std::map<int, int> candidates;

    int left, mid, right;
    for (int i = 1; i < seq.size()-1; i++) {
        left = seq[i-1];
        mid = seq[i];
        right = seq[i+1];

        if (mid > left && mid > right) {
            if (candidates.find(mid) != candidates.end())
                candidates[mid] += 1;
            else candidates[mid] = 1;
        } else if (candidates.find(mid) != candidates.end())
            candidates.erase(mid);
    }

    int result = 0;
    for (auto el : candidates) 
        result += el.second;

    return result;
}

/**
 * @brief Решение задачи
 * 
 * @param seq последовательность чисел
 * @return int количество соседей наиболее часто встречающихся ччисел
 */
int solution(std::vector<int>& seq) {
    std::map<int, int> candidates;

    int left, mid, right;
    for (int i = 1; i < seq.size()-1; i++) {
        left = seq[i-1];
        mid = seq[i];
        right = seq[i+1];

        if (mid > left && mid > right) {
            if (candidates.find(mid) != candidates.end())
                candidates[mid] += 1;
            else candidates[mid] = 1;
        } /*else if (candidates.find(mid) != candidates.end())
            candidates.erase(mid);*/
    }

    int result = 0;
    for (auto el : candidates) 
        result += el.second;

    return result;
}

int main() {
    // Инициализация
    std::string usr_str;
    std::vector<int> seq;

    std::getline(std::cin, usr_str); 
    parseString(usr_str, seq);

    std::cout << solution(seq);

    return 0;
}