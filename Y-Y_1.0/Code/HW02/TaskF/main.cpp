#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

/**
 * @brief Неверное решение, другой подход
 * @param seq Последовательность чисел
 * 
 * @return Недостающая последовательность минимальной длины 
 * @note В процессе решения возникло решение получше. А это говно блядь
 */
std::vector<int> solution_wrong (std::vector<int>& seq) {
    /* 
    два указателя на оба конца вектора. 
        Если указывают на одинаковые значения, то сдвигаем к середине. 
        Если нет, то добавляем в новый вектор значение left* и двигаем left к середине. 
    
    И так пока не дойдем до середины. Возвращаем длину новго вектора и сам вектор
    */
    // Инициализация
    int* left = &(seq.front());
    int* right = &(seq.back());
    bool flag_neq = true;
    std::vector<int> toAdd;

    // Проходимся по всему вектору
    while (left != right) {
        if (*left != *right) {
            toAdd.push_back(*left);
            left++;
            if (*right == *(right-1)) {
                while (*right == *(right-1)) {
                    right--;
                }
                right--;

                if (left == right) {
                    break;
                    flag_neq = true;
                }
            }
        } else {
            flag_neq = false;
            left++;
            right--;

            if (right < left)
                break;
        }
    }

    if (toAdd.size() != 0) {
        if (flag_neq) {
            toAdd.push_back(*left);
        }

        while (toAdd.back() == seq.back())
        toAdd.pop_back();
    }

    std::reverse(std::begin(toAdd), std::end(toAdd));
    return toAdd;
}

/**
 * @brief Проверка вектор на симметричность
 * @param seq Вектор
 * 
 * @return true, если вектор симметричен, иначе false
 */
bool isSymm (std::vector<int> seq) {
    int* left = &(seq.front());
    int* right = &(seq.back());

    while (left != right) {
        if (*left != *right)
            return false;
        left++;
        right--;

        if (left > right)
            break;
    }

    return true;
}

/**
 * @brief Верное решение
 * @param seq Последовательность чисел
 * 
 * @return Недостающая последовательность минимальной длины
 * @note свдигаем обратную последовательность и проверяем пересечение векторов на симметричность. 
 * Если ок, то запоминаем сколько чисел обрубить. И продолжаем пока не найдем бОльшее число или число==size()
 */
std::vector<int> solution(std::vector<int>& seq) {
    /*
    Решение: К концу исходной последовательности будет "вводить" обратную последовательность и смотреть на симметричность пересечения.
    Если оно симметрично, то сохраняем ее длину. Продолжаем, пока пересечение не станет той же длины, что и исходная последовательность.
    Во время цикла длина меняется в процессе поиска лучшего решения.

    Шаг 1) Создаем обратную последовательность;
    Шаг 2) Цикл: строим пересечение и проверяем на симметричность. if true : сохраняем длину в cut_num, else continue;
    Шаг 3) Ответом будет slice вектора вида [begin()+cut_num, end()];
        *) Если пересечение полностью совпало с длиной последовательности, то возвращаем пустой вектор.
    */
    // Инициализация
    int cut_num = -1;
    std::vector<int> result;
    std::vector<int> r_seq = seq; 

    // Шаг 1)
    std::reverse(std::begin(r_seq), std::end(r_seq));

    // Шаг 2) Находим максимальное симметричное пересечение
    for (int i = 1; i <= r_seq.size(); i++) {
        if (isSymm({r_seq.begin(), r_seq.begin()+i})) {
            cut_num = i;
        }        
    }

    // Шаг 3) Создаем вектор для решения. Тут автоматом выполняется условие *)
    result.assign(r_seq.begin()+cut_num, r_seq.end());
    
    return result;
}

int main() {
    // Инициализация
    int N = 0;
    std::vector<int> seq;

    //
    std::cin >> N;
    int buff;
    for (int i = 0; i < N; i++)
    {
        std::cin >> buff;
        seq.push_back(buff);
    }

    //
    auto result = solution(seq);
    std::cout << result.size() << std::endl;
    for (auto el : result)
        std::cout << el << " ";
    
    return 0;
}