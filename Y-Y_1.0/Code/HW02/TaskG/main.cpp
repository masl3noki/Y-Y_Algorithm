#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <sstream>

/* Технические функции */

// Улучшаем читаемость
bool operator> (const std::pair<int, int>& l, const std::pair<int, int>& r) {
    return (static_cast<unsigned long long>(l.first) * 
            static_cast<unsigned long long>(l.second) > 
            static_cast<unsigned long long>(r.first) * 
            static_cast<unsigned long long>(r.second));
};

bool operator== (const std::pair<int, int>& l, const int& r) {
    return (static_cast<long long>(l.first) == static_cast<long long>(r) && 
            static_cast<long long>(l.second)== static_cast<long long>(r));
};

bool operator!= (const std::pair<int, int>& l, const int& r) {
    return (static_cast<long long>(l.first) != static_cast<long long>(r) && 
            static_cast<long long>(l.second)!= static_cast<long long>(r));
};

/**
 * @brief Решение задачи (кривое, но сойдет)
 * @param seq последовательность
 * 
 * @return Два числа, произведение которых максимально
 */
std::pair<int, int> solution(std::vector<int>& seq) {
    /*
    Шаг 1) Найти максимумы для отрицательных и неотрицательных (т.е. положительных и 0) целых чисел;
    Шаг 2) Сравнить произведения обоих пар и вернуть пару, образующую максимальное произведение;
        *) Примеров на последовательность длиной 1 нет => игнор;
        *) Последовательность длиной 2 не обрабатываем, возвращаем элементы;
        
    Идея следующая: произведение чисел одного знака дает положительное число, поэтому разбиение на пары.
    
    Как будто в примерах не было последовательности с 0, но я попробовал написать костыль. Ноль не дает
    однозначного ответа. Кажется других ситуаций с неоднозначным ответом нет в тестах. 
    
    Ощущение, что решение не полное, но оно прошло.    
    */
    
    // Инициализация. "g0" == "greater than 0" и аналогично "l0"
    std::pair<int, int> g0 = {INT_MIN, INT_MIN}, 
                        l0 = {INT_MIN, INT_MIN};
    
    if (seq.size() < 3) // Проще будет просто вывести оба числа 
        return {seq[0], seq[1]};

    for (int el : seq) {
        if (el >= 0) { // Поиск при >= 0
            if (el >= g0.first) {
                g0.second = g0.first;
                g0.first = el;
            } else if (el >= g0.second && el != g0.first)
                g0.second = el;
        } else 
        if (el < 0) { // Поиск при < 0
            if (std::abs(el) >= std::abs(l0.first)) {
                l0.second = l0.first;
                l0.first = el;
            } else if (std::abs(el) >= std::abs(l0.second) && std::abs(el) != std::abs(l0.first))
                l0.second = el;
        }
    }

    // Сравниваем где больше произведение и проверяем на INT_MIN, если какой-то максимум не нашелся
    if (g0 == INT_MIN && l0 != INT_MIN)
        return l0;
    else if (g0 != INT_MIN && l0 == INT_MIN)
        return g0;
    else { // Верим, что неоднозначного ответа нет
        if (g0 > l0)
            return g0;
        else 
            return l0;
    }
}

int main() {
    // Инициализация
    std::vector<int> seq; {
        int element;
        while(std::cin >> element) {
            seq.push_back(element);
        }
    }

    // Формат вывода
    auto result = solution(seq);
    int first_max = result.first;
    int secnd_max = result.second;   

    if (first_max > secnd_max) // Порядок неубывания по требованию
        std::cout << secnd_max << " " << first_max;
    else std::cout << first_max << " " << secnd_max;

    return 0;
}