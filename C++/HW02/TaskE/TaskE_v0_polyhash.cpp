#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>

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

template <class T>
void debug_print_vector(std::vector<T>& arr);

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

/**
 * @brief Вычисление хеш-векторов и вектора степеней полинома
 * 
 * @param String Строка под хеширование
 * @param x_pow Вектор степеней полиномов
 * @param Fs Хеш-вектор прямого хеширования
 * @param Bs Хеш-вектор обратного хеширования
 */
void compute_hashes_vector (const std::string& String, std::vector<unsigned long long>& x_pow, std::vector<unsigned long long>& Fs, std::vector<unsigned long long>& Bs) {
    // Инициализация данных
    const int x = 31; 
    const int p = 1e9 + 9;
    int L = String.size();
    
    // Вычисляем вектор степеней полинома
    for (int i = 1; i < L; i++) 
        x_pow[i] = std::pow(x, i);//(x_pow[i-1] * x);
    
    // Вычисляем хеш-векторы
    for (int i = 0; i < L; i++)
    {
        long long x_p = std::pow(x, i);
        Fs[i+1] = (Fs[i] + (String[i] - 'a' + 1) * x_pow[i]) % p;
        Bs[i+1] = (x * Bs[i] + (String[i] - 'a' + 1)) % p;
    }
    
}

/**/
void compute_hash_scalar (const std::string& String, std::vector<unsigned long long>& x_pow, unsigned long long& Fs_lr, unsigned long long& Bs_lr, int& l, int& r) {
    const int p = 1e9 + 9;
    int L = String.size();

    for (int i = l; i < r; i++)
    {
        Fs_lr += (String[i-1] * x_pow[i - l]) % p;
    }

    for (int i = (L - r); i < (L - l); i++)
    {
        Bs_lr += (String[i-1] * x_pow[i - L + l]) % p;
    }    
}

/**/
std::string modify_string (const std::string& s) {
   if (!s.size()) {
     return "";
   }

   std::stringstream ss;
   ss << s[0];
   for (int i = 1; i < s.size(); i++) {
     ss << '|' << s[i];
   }
   return ss.str();
}

int main() {
    // input
    std::string target = "abacaba";
    //std::cin >> target;

    // Инициализация данных
    const int x = 31; 
    const int p = 1e9 + 9;

    // Обновление целевой строки:
    //target = modify_string(target);
    int L = target.size();

    std::vector<unsigned long long> Fs(L+1, 0); // Хеш-таблица прямого хеширования
    std::vector<unsigned long long> Bs(L+1, 0); // Хеш-таблица обратного хеширования
    std::vector<unsigned long long> x_pow(L, 1); // Вектор степеней полинома

    std::cout << target << std::endl;

    // Создание хеш-таблицы прямого и обратного хеширования:
    compute_hashes_vector(target, x_pow, Fs, Bs);
    
    // Алгоритм поиска подпалиндромов:
    int count = 0;
    for (int pos = 1; pos <= L; pos++) // Идем по хеш-векторам, минуя Hash[0] = 0
    {
        // Индексы углубления O(logN)
        int l = pos; // индекс левой границы
        int r = pos; // индекс правой границы

        while (l >= 1 && r <= L)
        {
            // Прямые и обратные хеши подстроки:
            unsigned long long Fs_lr = 0;
            unsigned long long Bs_lr = 0;
            compute_hash_scalar(target, x_pow, Fs_lr, Bs_lr, l, r);

            //unsigned long long Fs_lr = (Fs[r] - Fs[l]) % p;
            //unsigned long long Bs_lr = (Bs[r] - Bs[l]) % p;
            //auto Bs_lr = (x_pow[l] * Bs[r] - x_pow[r] * Bs[l] % p);

            if (Fs_lr == Bs_lr)
            {
                if (Fs_lr != 0 && Bs_lr != 0 && target[pos-1] != '|')
                    count++;
            } else break;

            // Углубляемся:
            l -= 1;
            r += 1;
        }
    }
    
    std::cout << count;

    return 0;
}

template<class T>
void debug_print_vector(std::vector<T>& arr) {
    for (auto element : arr)
        std::cout << element << " ";
    std::cout << std::endl;    
}