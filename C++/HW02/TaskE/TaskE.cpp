#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template <class T>
void debug_print_vector(std::vector<T>& arr);

/**
 * @brief Оптимизированная реализация префикс-функции за O(n)
 * 
 * @param s Строка по которой вычисляется префикс-функция
 * @return std::vector<int> префикс-функция
 */
std::vector<int> compute_prefix_func(std::string const& s) {
    int n = s.length();
    std::vector<int> pi(n);
    pi[0] = 0;

    for (int i = 1; i < n; i++) {
        // Первое предположение, что самая большая длина j < pi[i] и при условии, что s[0..j-1] = s[i-j+1..i]
        int j = pi[i-1];
        // Если суффикс длины j+1 также и префикс, то pi[i] = j+1. При j=0 полагаем, что pi[i] = 0
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }

    return pi;
}

/**
 * @brief Вычисление хешей префиксов строки за O(длина строки)
 * 
 * @param strg Вектор на хеширование
 * @param p_pow Вектор степеней полинома
 * @return std::vector <long long> возвращает вектор хешей
 */
std::vector <long long> compute_hash_vector(std::string const& strg, std::vector<long long> const& p_pow) {
    int n = strg.size();
    
    std::vector<long long> h(n, 0); 
    for (int i = 0; i < n; i++) {
        h[i] = (strg[i] - 'a' + 1) * p_pow[i];
        if (i) h[i] += h[i-1];
    }

    return h;
}

/* Проблемы в начале и конце. К тому же кажется, что алгос упускает в расчете некоторые подстроки */

int count_subpalins_trivial(std::string s) {
    int count = 0;
    int n = s.size();
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            std::string target = s.substr(i, j);
            std::string target_reversed = s.substr(i, j);
            std::reverse(target_reversed.begin(), target_reversed.end());
            if (target == target_reversed)
            {
                count++;
            }
        }
    }
    
    return count;
}


int main() {
    // input
    std::string target = "abdsaw";
    //std::cin >> target;

    // Инициализация данных
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = target.size();

    std::cout << count_subpalins_trivial(target);

    return 0;
}

template<class T>
void debug_print_vector(std::vector<T>& arr) {
    for (auto element : arr)
        std::cout << element << " ";
    std::cout << std::endl;    
}