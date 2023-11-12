#include <iostream>
#include <string>
#include <vector>

template<class T>
void debug_print_vector(std::vector<T>& arr);

/**
 * @brief Наивная реализация префикс-функции за O(n^3)
 * 
 * @param s Строка по которой вычисляется префикс-функция
 * @return std::vector<int> префикс-функция
 */
std::vector<int> compute_prefix_func_trivial(std::string const& s) {
    int n = s.length();
    std::vector<int> pi(n);

    for (int i = 0; i < n; i++) // Проходимся по вектору префикс функции
        for (int k = 0; k <= i; k++) // Поиск "правильного" префикса в подстроке
            if (s.substr(0, k) == s.substr(i-k+1, k))
                pi[i] = k;
    
    return pi;
}

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

/**
 * @brief Функция, которая находит длину основания строки (т.е. такой префикс min длины s, что строка S = s * {количество повторов} )
 * 
 * @param s Строка для поиска
 * @return int длина основания строки
 */
int get_string_compression(std::string const& s) {
    int n = s.size();

    auto pi = compute_prefix_func(s);
    int k = n - pi[n - 1];
    if (k % n != 0) 
        return k;
    else
        return n;
}

int main() {
    // input
    std::string target;
    std::cin >> target;

    // Инициализация данных
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = target.size();

    int res = get_string_compression(target);
    std::cout << res;    

    return 0;
}

template<class T>
void debug_print_vector(std::vector<T>& arr) {
    for (auto element : arr)
        std::cout << element << " ";
    std::cout << std::endl;    
}