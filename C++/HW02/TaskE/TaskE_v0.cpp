#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
# Тривиальный алгоритм: O(n!)
Реализация тривиального алгоритма:

Мы n! раз переберем все длины возможных подстрок. И каждый раз линейно пройдем по строке.
- очень долго;
+ каждый подпалиндром уникальный.

# Хеш-алгоритм: O(n*logn)
Реализация хеш-алгоритма:

Мы линейно проходим по строке и на каждой букве "спускаемся" в поиск палиндромов, пока либо не выйдем за пределы, либо не встретим NOT палиндром.
- мы проскакиваем палиндромы четной длины! Очень плохо. Алгоритм по факту выдает неверный ответ;
+ довольно быстро, если не брать во внимание алгосы через суффиксные деревья или алгоритм Манакера;
+ каждый палиндром уникальный.

# Хеш-алгоритм v2: O(n*(n-1)*logn)
Реализация хеш-алгоритма v2:

Скажем, что в нашей строке буквы стоят на т.н. "настоящих" индексах, а между ними существуют т.н. "фиктивные" индексы:
s="aba" => s[0..4]:
s[0] = 'a';
s[1] = ' ';
s[2] = 'b';
s[3] = ' ';
s[4] = 'a';
Далее, мы ходим по "настоящим" индексам. Но если на i стоит та же буква, что и на i+2 (а настоящие индексы у нас четны), то мы прыгнем на
фиктивный индекс i-1 и применим алгоритм также как на настоящем.
- долго: строка "а"*10000 будет очень долго обрабатываться - за O(n^2*logn) (худший случай);
+ однако мы теперь учитываем палиндромы четной длины. И даже если их нет, сложность будет O(n*logn);
+ каждый палиндром уникальный.
? O(n*logn) < O(n*n*logn) < O(n!)

*/

/*

*/

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

/**/
int count_subpalins_trivial(std::string s) {
    int count = 0;
    int n = s.size();
    
    for (int len_lst = 1; len_lst <= n; len_lst++)
    {
        for (int i = 0; i < n; i++)
        {
            std::string target = s.substr(i, len_lst);

            /* Проверить, что target - палиндром */

            if (i+len_lst >= n)
            {
                break;
            }
            
        }
    }

    return count;
}

int getSubpolyCount(std::string s_for) {
    auto s_bac = s_for;
    std::reverse(s_bac.begin(), s_bac.end());

    //auto h_for = compute_hash_vector(s_for, );
    //auto h_bac = compute_hash_vector(s_rev, );
    
    
    return 0;
}


class Subpoly {
    private:
        // Инициализация констант
        const int p = 31; 
        const int m = 1e9 + 9;
        
        // Инициализация данных
        std::string s_for;
        std::string s_bac = s_for;
        std::vector <long long> h_for;
        std::vector <long long> h_bac;

        /**
         * @brief Вычисление степеней полинома
         * 
         * @param s_size Длина строки
         * @return std::vector<long long> вектор степеней полинома
         */
        std::vector<long long> p_pow(int s_size) {
            std::vector<long long> p_pow(s_size); 
            p_pow[0] = 1; 
            for (int i = 1; i < s_size; i++) 
                p_pow[i] = (p_pow[i-1] * p);
            
            return p_pow;
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

    public:
        Subpoly(std::string s) {
            s_for = s;
            std::reverse(s_bac.begin(), s_bac.end());
            h_for = compute_hash_vector(s_for, p_pow(s.size()));
        }

        //get

};


int main() {
    // input
    std::string target = "abdsaw";
    //std::cin >> target;

    // Инициализация данных
    const int p = 31; 
    const int m = 1e9 + 9;
    //int S = target.size();

    auto b = target;
    std::reverse(b.begin(), b.end());
    std::cout << target << " " << b;

    //Subpoly foo;

    return 0;
}

template<class T>
void debug_print_vector(std::vector<T>& arr) {
    for (auto element : arr)
        std::cout << element << " ";
    std::cout << std::endl;    
}