#include <iostream>
#include <vector>
#include <cmath>

/**
 * @brief Виды последовательностей для задачи
 * 
 * @note RANDOM определяет последовательность, не принадлежащей ни к одному из типов
 */
enum func_type {
    ERROR = -2,
    RANDOM = -1,
    CONSTANT = 0,
    ASCENDING,
    WEAKLY_ASCENDING,
    DESCENDING,
    WEAKLY_DESCENDING
};

/**
 * @brief Определение вида последовательности
 * 
 * @param seq последовательность
 * @return func_type - вид последовательности
 */
func_type solution(std::vector<int>& seq) {
    // Флаги
    bool flag_CONSTANT = 0;
    bool flag_ASCENDING = 0;
    bool flag_DESCENDING = 0;

    // Линейный поиск
    if (seq.size() < 2)
        return CONSTANT; // Последовательность из ! элемента - CONSTANT

    for (int i = 1; i < seq.size(); i++)
    {
        if (seq[i-1] == seq[i])
            flag_CONSTANT += 1;

        if (seq[i-1] < seq[i])
            flag_ASCENDING += 1;
        else if (seq[i-1] > seq[i]) 
            flag_DESCENDING += 1;        
    }

    // Обработка флагов
    if (flag_ASCENDING & flag_DESCENDING)
        return RANDOM;
    else if (!flag_ASCENDING & !flag_DESCENDING)
        return CONSTANT;
    else {
        if (flag_ASCENDING)
        {
            if (flag_CONSTANT)
                return WEAKLY_ASCENDING;
            else return ASCENDING;
        }

        if (flag_DESCENDING)
        {
            if (flag_CONSTANT)
                return WEAKLY_DESCENDING;
            else return DESCENDING;
        }   
    }
    
    return ERROR;
}

int main() {
    // Объявление
    std::vector<int> seq;
    int usr_int;
    int seq_termination = static_cast<int>(-2*std::pow(10, 9));

    // Инициализация
    std::cin >> usr_int;
    while (usr_int != seq_termination)
    {
        seq.push_back(usr_int);
        std::cin >> usr_int;
    }

    // Тело
    switch (solution(seq))
    {
    case RANDOM:
        std::cout << "RANDOM";
        break;

    case CONSTANT:
        std::cout << "CONSTANT";
        break;

    case ASCENDING:
        std::cout << "ASCENDING";
        break;

    case WEAKLY_ASCENDING:
        std::cout << "WEAKLY_ASCENDING";
        break;

    case DESCENDING:
        std::cout << "DESCENDING";
        break;
    
    case WEAKLY_DESCENDING:
        std::cout << "WEAKLY_DESCENDING";
        break;

    default:
        std::cout << "unknown";
        break;
    }

    return 0;
}