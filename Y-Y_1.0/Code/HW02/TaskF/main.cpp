#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

/**
 * 
 * 
 * @note Говно блядь
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
 * 
 * 
 * @note свдигаем обратную последовательность и проверяем пересечение векторов на симметричность. Если ок, то запоминаем сколько чисел обрубить. И продолжаем пока не найдем бОльшее число или число==size()
 */
std::vector<int> solution(std::vector<int>& seq) {

}

int main() {
    // Инициализация
    int N = 0;
    std::vector<int> seq;

    std::cin >> N;
    int buff;
    for (int i = 0; i < N; i++)
    {
        std::cin >> buff;
        seq.push_back(buff);
    }

    auto result = solution(seq);
    std::cout << result.size() << std::endl;
    for (auto el : result)
        std::cout << el << " ";
    
    return 0;
}