#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
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

void debug_print_unset(std::unordered_set<std::string>&);

/***/
std::unordered_set<std::string> get_unset (std::string& s_for) {
    std::unordered_set<std::string> unset;

    unset.insert(s_for + "0" + std::to_string(s_for.size())); // Вносим ключ всей строки
    for (int k = 1; k < s_for.size(); k++) {
        for (int i = 0; i < s_for.size() - k + 1; i++)
            unset.insert(s_for.substr(i, k)+std::to_string(i)+std::to_string(k)); 
    }

    return unset;
}

int main() {
    // input
    std::string target;// = "abdsaw";
    std::cin >> target;

    // создаем хеш-таблицу средствами c++
    auto unset = get_unset(target);
    //debug_print_unmap(unmap);

    /* осуществляем поиск подпалиндромов ТРИВИАЛЬНО */
    int count = 0;// target.size(); // мы полагаем, что подстроки длины 1 - палиндромы
    for (int k = 1; k <= target.size(); k++) {
        for (int pos = 0; pos <= target.size() - k; pos++) {
            
            //std::cout << target.substr(pos, k) << " ";
            std::string s_bac = target.substr(pos, k);
            std::reverse(s_bac.begin(), s_bac.end());

            if (unset.count(s_bac + std::to_string(pos) + std::to_string(k))) {
                    count++;
                }

            /*
            // Индексы для углубления:
            int i = pos;
            //int j = pos;

            // Процесс углубления:
            while (i >= 0 && i + k < target.size())
            {
                // Индекс i и длина подстроки нужны для поиска ключа

                // Переворачиваем строку, будем искать ее в unmap
                std::string s_bac = target.substr(i, k);
                std::reverse(s_bac.begin(), s_bac.end());

                if (unmap.find(s_bac + std::to_string(i) + std::to_string(k)) != unmap.end()) {
                    count++;
                } else break;
            }
            */
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

void debug_print_unset(std::unordered_set<std::string>& unset) {
    for (auto element : unset)
        std::cout << element << "\n";
}