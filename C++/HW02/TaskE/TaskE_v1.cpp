#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <utility>

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
void debug_print_vector(std::vector<T>&);

void debug_print_unmap(std::unordered_map<std::string, int>&);

/***/
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

/***/
std::unordered_map<std::string, int> get_unmap (std::string& s_for) {
    std::unordered_map< std::string, int > unmap;

    unmap[s_for] = -1; // Вносим ключ всей строки
    for (int k = 1; k < s_for.size(); k++) {
        for (int i = 0; i < s_for.size() - k + 1; i++)
            unmap[s_for.substr(i, k)+std::to_string(i)+std::to_string(k)] = i; 
    }

    return unmap;
}

int main() {
    // input
    std::string target;// = "abdsaw";
    std::cin >> target;

    // создаем хеш-таблицу средствами c++
    auto unmap = get_unmap(target);
    //debug_print_unmap(unmap);

    /* осуществляем поиск подпалиндромов */
    int count = 0;
    for (int k = 0; k < target.size(); k++) {
        count++; // мы полагаем, что подстроки длины 1 - палиндромы
        // Индексы для углубления:
        int i = k;
        int j = k;

        // Процесс углубления:
        while (i >= 0 && j < target.size())
        {
            // Индекс i и длина подстроки нужны для поиска ключа
            int length_substr = j - i;

            // Переворачиваем строку, будем искать ее в unmap
            std::string s_bac = target.substr(i, length_substr);
            std::reverse(s_bac.begin(), s_bac.end());

            if (unmap.find(s_bac + std::to_string(i) + std::to_string(length_substr)) != unmap.end()) {
                count++;
            } else break;
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

void debug_print_unmap(std::unordered_map<std::string, int>& unmap) {
    for (auto element : unmap)
        std::cout << element.first << " " << element.second << "\n";
}