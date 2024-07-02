#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <string>

void debug_print_vector(std::vector<std::string>&);

void debug_print_map(std::map<int, std::vector<std::string>>&);

void debug_map_to_vector(std::map<int, std::vector<std::string>>& target_map, std::vector<std::string>& target_arr);

/**
 * @brief Специальный вывод для тестирующей системы Яндекса
 * 
 * @param target Вектор для обработки
 * @param leading_zeros Количество разрядов для вывода (если у числа разрядов меньше, остальные разряды заполняются нулями) (технический параметр)
 */
void fancy_print_vector(std::vector<std::string>& target, int& leading_zeros) {
    for (int i = 0; i < target.size() - 1; i++) {
        std::cout << std::setfill('0') << std::setw(leading_zeros) << target[i] << ", ";
    }
    std::cout << std::setfill('0') << std::setw(leading_zeros) << target[target.size() - 1] << '\n';
}

/**
 * @brief Специальный вывод для тестирующей системы Яндекса
 * 
 * @param target Массив для обработки
 * @param loop Номер разряда, над которым производится обработка (технический параметр)
 * @param leading_zeros Количество разрядов для вывода (если у числа разрядов меньше, остальные разряды заполняются нулями) (технический параметр)
 */
void fancy_print_map(std::map<int, std::vector<std::string>>& target, int& loop, int& leading_zeros) {

    std::cout << "**********" << '\n' 
          << "Phase " << leading_zeros - loop << '\n'; // Скорректирован порядковый номер фазы

    for (auto& elem: target) {
        std::cout << "Bucket " << elem.first << ": ";
        if (elem.second.empty()) std::cout << "empty" << '\n';
        else fancy_print_vector(elem.second, leading_zeros);
    }
}

/**
 * @brief Алгоритм поразрядной сортировки версии LSD (least significant digit)
 * 
 * @param arr Вектор для сортировки
 * @param loop Номер разряда (0 == единицы, 1 == десятки и т.д.)
 * @return std::map<int, std::vector<std::string>> Ассоциативный массив с правилом {цифра: числа, в которых содержится эта цифра на конкретном одинаковом разряде}
 */
std::map<int, std::vector<std::string>> RadixLSD_alg(std::vector<std::string>& arr, int loop) {
    
    std::map<int, std::vector<std::string>> Bucket { 
    {0, {}}, 
    {1, {}}, 
    {2, {}},
    {3, {}},
    {4, {}},
    {5, {}},
    {6, {}},
    {7, {}},
    {8, {}},
    {9, {}}};

    for (const auto arr_element: arr) {
        // Находим int в соотв. разряде элемента из arr
        int num = (arr_element[loop] - '0');
        // Заносим число в соотвествующий элемент внутри мапы
        Bucket[num].push_back(arr_element);
    }

    return Bucket;
}

/**
 * @brief Сортировка Radix LSD
 * 
 * @param v Вектор для сортировки
 * @param max_loops Максимальное количество разрядов в элементах вектора (технический параметр)
 */
void Radixsort(std::vector<std::string>& v, int max_loops = 20) {

    //for (int loop = 0; loop < max_loops; loop++)
    for (int loop = max_loops - 1; loop >= 0; loop--)
    {
        // Итерация по всем разрядам
        std::map<int, std::vector<std::string>> result_map = RadixLSD_alg(v, loop);
        
        debug_map_to_vector(result_map, v);
        fancy_print_map(result_map, loop, max_loops);
    }
}

int main() {
    // input
    int n = 0;
    std::cin >> n;

    int max_loops = -1; // Не оч красиво, но ради скорости мы найдем максимальную длину int из ввода данных для оптимизации RadixLSD
    std::vector<std::string> v(n);
    
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i];
        int num = v[i].size();
        if (max_loops < num) {
            max_loops = num;
        }
    }
    
    // Сортировка и вывод
    std::cout << "Initial array: " << '\n';
    fancy_print_vector(v, max_loops);
    Radixsort(v, max_loops);
    std::cout << "**********" << '\n'
           << "Sorted array:" << '\n';
    fancy_print_vector(v, max_loops);

    return 0;
}

void debug_print_vector(std::vector<std::string>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;    
}

void debug_print_map(std::map<int, std::vector<std::string>>& target) {
    for (auto& elem: target) {
        debug_print_vector(elem.second);
    }
}

void debug_map_to_vector(std::map<int, std::vector<std::string>>& target_map, std::vector<std::string>& target_arr) {
    int j = 0;
    for (auto& elem: target_map) {
        for (int i = 0; i < elem.second.size(); i++)
        {
            target_arr[j] = elem.second[i];
            j++;
        }        
    }
}