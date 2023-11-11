#include <iostream>
#include <vector>
#include <string>

/**
 * @brief Вычисление хеша для подаваемой строки.
 * 
 * @param s Строка для создания хеша
 * @return long long значение хеша для строки s
 */
long long compute_hash(std::string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;

    for (char c : s) {
        hash_value += (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }

    return hash_value;
}

/*
std::vector<int> rabin_karp(std::string const& sub_strg, std::string const& strg) {
    // Инициализация данных
    const int p = 31; 
    const int m = 1e9 + 9;
    int s = sub_strg.size(), S = strg.size();

    // Вычисление степеней полинома
    std::vector<long long> p_pow(std::max(s, S)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    // Вычисление хешей всех префиксов главной строки
    std::vector<long long> h(S + 1, 0); 
    for (int i = 0; i < S; i++)
        h[i+1] = (h[i] + (strg[i] - 'a' + 1) * p_pow[i]) % m;

    // Вычисление хеша подстроки
    long long h_s = 0; 
    for (int i = 0; i < s; i++) 
        h_s = (h_s + (sub_strg[i] - 'a' + 1) * p_pow[i]) % m; 

    // Нахождение подстроки в главной строке
    std::vector<int> occurrences;
    for (int i = 0; i + s - 1 < S; i++) {
        long long cur_h = (h[i+s] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}*/

int main() {
    // input
    std::string main_strg;
    std::cin >> main_strg;

    int requests_count = 0;
    std::cin >> requests_count;

    // Инициализация данных
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = main_strg.size();

    // Вычисление степеней полинома
    std::vector<long long> p_pow(S); 
    p_pow[0] = 1; 
    for (int i = 1; i < S; i++) 
        p_pow[i] = (p_pow[i-1] * p);

    // Вычисление хешей всех префиксов главной строки
    // Здесь и далее мы не будем изменять строку. Вместо изменения длины S+1 и h[0] = 0, считаем сразу с первого (№0) элемента
    std::vector<long long> h(S, 0); 
    for (int i = 0; i < S; i++) {
        h[i] = (main_strg[i] - 'a' + 1) * p_pow[i];
        if (i) h[i] += h[i-1];
    }

    // Обработка запросов
    for (int request = 0; request < requests_count; request++)
    {
        // input per request
        int sub_strg_size = 0, iter_tg1 = 0, iter_tg2 = 0;
        std::cin >> sub_strg_size >> iter_tg1 >> iter_tg2;

        // Работа с входными данными
        // Хеши двух подстрок. if(iter) нужен как раз для причины описанной выше: h[0] может не равняться 0
        long long h1 = h[iter_tg1 + sub_strg_size - 1];
        if (iter_tg1)  h1 -= h[iter_tg1 - 1];

        long long h2 = h[iter_tg2 + sub_strg_size - 1];
        if (iter_tg2)  h2 -= h[iter_tg2 - 1];

        // Сравнение подстрок
        if (iter_tg1 < iter_tg2 && ( h1 * p_pow[iter_tg2 - iter_tg1] ) == h2 ||
        	iter_tg1 > iter_tg2 && h1 == ( h2 * p_pow[iter_tg1 - iter_tg2] ) ||
            iter_tg1 == iter_tg2 && h1 == h2)
        	std::cout << "yes\n";
        else
        	std::cout << "no\n";
        
    }

    return 0;
}