#include <iostream>
#include <string>
#include <vector>

template<class T>
void debug_print_vector(std::vector<T>& arr);

/**
 * @brief Тривильная реализация z-функции за O(n^2)
 * 
 * @param s Строка, по которой будет считаться z-функция
 * @return std::vector<int> вектор значений z-функции
 */
std::vector<int> compute_z_func_trivial(std::string s) {
    int n = s.size();
    std::vector<int> z(n);

    // Просто проходимся по строке...
    for (int i = 1; i < n; i++) {
    // ...и внутри каждой строки повышаем счетчик {длина подстроки}++, пока не найдем несовпадающие символы: 
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
    }
    return z;
}

/**
 * @brief Оптимизированная реализация z-функции за O(n). Аналогичен тривиальному с тем лишь условием, что оптимизация происходит при i < r (при i >= r применяется тривиальный алгоритм)
 * 
 * @param s Строка, по которой будет считаться z-функция
 * @return std::vector<int> вектор значений z-функции
 */
std::vector<int> compute_z_func(std::string s) {
    int n = s.size();
    std::vector<int> z(n);
    z[0] = 0; // В z[0] возникает неопределенность, которая никак не влияет на работу алгоритма. Многие источники разрешают это, полагая z[0] = 0
    int l = 0, r = 0; // Граница т.н. segment match - подстроки, которая совпадает с префиксом строки s. По определению segment_match = s[l, r-1]. 
                      // К тому же, r-1 одновременно указывает на последний известный (алгоритму) элемент

    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = std::min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
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

int main() {
    // input
    std::string target;
    std::cin >> target;

    // Инициализация данных
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = target.size();

    auto res = compute_z_func(target);
    debug_print_vector(res);

    return 0;
}

template<class T>
void debug_print_vector(std::vector<T>& arr) {
    for (auto element : arr)
        std::cout << element << " ";
    std::cout << std::endl;    
}