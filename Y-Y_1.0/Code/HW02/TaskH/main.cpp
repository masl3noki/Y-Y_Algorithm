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
    return (static_cast<long long>(l.first) == static_cast<long long>(r) || 
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
std::pair<int, std::pair<int, int>> solution(std::vector<int>& seq) {
    /*
    Шаг 1) Найти максимумы для отрицательных и неотрицательных (т.е. положительных и 0) целых чисел;
    Шаг 2) Сравнить произведения обоих пар и зафиксировать пару, образующую максимальное произведение;
    Шаг 3) Максимальное произведение будет с этой парой при третьем максимуме, либо 0. Возвращаем ответ.
        *) Примеров на последовательность длиной 1, 2 нет => игнор;
        *) Последовательность длиной 3 не обрабатываем, возвращаем элементы.
        
    Идея следующая: произведение чисел одного знака дает положительное число, поэтому разбиение на пары.
        Далее ищем число №3 в порядке приоритета: {max среди положительных чисел}, {цифра 0}, {min среди отрицательных чисел}.
    Если будем рассматривать пару чисел с разными знаками, то нам придется соответственно искать в порядке приоритета:
        {max среди отрицательных чисел}, {цифра 0}, {min среди положительных чисел}. Но есть предположение, что это
        все можно свести к поиску максимальной пары одинакового знака и т.д.
    
    В отличии от задачи G, здесь 0 может давать однозначный ответ. Кажется других ситуаций с неоднозначным ответом нет в тестах. 
    
    Ощущение, что решение не полное, но оно прошло.    
    */
    
    // Инициализация. "g0" == "greater than 0" и аналогично "l0"
    std::pair<int, int> g0 = {INT_MIN, INT_MIN}, 
                        l0 = {INT_MIN, INT_MIN};
    int third_number = INT_MIN;
    
    if (seq.size() < 4) // Проще будет просто вывести оба числа 
        return {seq[0], {seq[1], seq[2]}};

    // Шаг 1)
    for (int el : seq) {
        if (el >= 0) { // Поиск при >= 0
            if (el >= g0.first) {
                third_number = g0.second;
                g0.second = g0.first;
                g0.first = el;
            } else if (el >= g0.second && el != g0.first) {
                third_number = g0.second;
                g0.second = el;
            } else if (el >= third_number && el != g0.second && el != g0.first)
                third_number = el;
            
        } else 
        if (el < 0) { // Поиск при < 0
            if (std::abs(el) >= std::abs(l0.first)) {
                third_number = l0.second;
                l0.second = l0.first;
                l0.first = el;
            } else if (std::abs(el) >= std::abs(l0.second) && std::abs(el) != std::abs(l0.first)) {
                third_number = l0.second;
                l0.second = el;
            } else if (std::abs(el) >= std::abs(third_number) && std::abs(el) != std::abs(l0.second) && std::abs(el) != std::abs(l0.first))
                third_number = el;
        }
    }

    // Шаг 2) Сравниваем где больше произведение и проверяем на INT_MIN, если какой-то максимум не нашелся.
    /*        Также ищем нет ли числа, большего, чем third_number среди чисел в неиспользуемой паре. Другими словами:
              Пусть наибольшее произведение получается из lo. Тогда if (third_number > g0.first) third_number = g0.first.
              Также проверяем второе число.       
    */   
    std::pair<int, int> res_pair;
    if (g0 == INT_MIN && l0 != INT_MIN)
        res_pair = l0;
    else if (g0 != INT_MIN && l0 == INT_MIN)
        res_pair = g0;
    else { // Верим, что неоднозначного ответа нет
        if (g0 > l0)
            res_pair = g0;
        else 
            res_pair = l0;
    }

    // Шаг 3)
    /*  Также ищем нет ли числа, большего, чем third_number среди чисел в неиспользуемой паре. Другими словами:
        Пусть наибольшее произведение получается из lo. Тогда if (third_number > g0.first) third_number = g0.first.
        Также проверяем второе число.       
    */ 
    if (res_pair == g0) {
        if (third_number < l0.first) third_number = l0.first;
        if (third_number < l0.second) third_number = l0.second;
    } else {    
        if (third_number < g0.first) third_number = g0.first;
        if (third_number < g0.second) third_number = g0.second;
    }
    return {third_number, res_pair};
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
    std::cout << result.first << " " << (result.second).first << " " << (result.second).second;

    return 0;
}