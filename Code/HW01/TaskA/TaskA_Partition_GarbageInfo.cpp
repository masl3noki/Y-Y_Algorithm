#include <iostream>
#include <vector>

/**
 * @brief Partition для сортировок через 2 "указателя".
 * 
 * @param arr Вектор для сортировки
 * @param target_elem Опорный элемент
 * @param left Левый итератор
 * @param right Правый итератор
 * @param predicate Условие, по которому разделять массив. По умолчанию стоит '<', т.е. массив делится согласно условию "<x"
 * 
 * @return int - точка разбиения, то есть итератор (индекс) на конец части, которая содержащит элементы, удовлетворяющие заданному предикату. Т.е. по умолчанию возвращает итератор последнего элемента в множестве {elements | <x}.
 */
int partition(std::vector<int>& arr, int target_elem, int left = -1, int right = 0, char predicate = '<') {
    
    int target_iter = -1;

    int count_L = 0;
    int count_R = 0;

    switch (predicate)
    {
    case '>':
        
        //std::cout << "case >" << std::endl;

        break;
    
    default:

        //std::cout << "default case" << std::endl;

        if (arr.size() == 0) {
            //std::cout << count_L << '\n' << count_R << std::endl;
            return 0;
        }

        for (right; right < arr.size() - 1; right++)
        {
            if (arr[right] <= target_elem) {
                // Двигаем левый указатель
                left++;
                count_L++;
                
                // Меняем местами элементы
                int temp = arr[right];
                arr[right] = arr[left];
                arr[left] = temp;
            } else count_R++;
        }

        // Теперь меняем элемент [left + 1] с [right + 1]
        target_iter = left + 1;

        int temp = arr[right];
        arr[right] = arr[target_iter];
        arr[target_iter] = temp;

        break;
    }
    count_R++;

    return target_iter;

}

int main() {
    // входные данные
    int n = 0;
    int x = 0;
    std::cin >> n;

    std::vector<int> arr;
    
    for (int i = 0; i < n; i++) {
        int number = 0;
        std::cin >> number;

        arr.push_back(number);
    }

    std::cin >> x;

    // работа с массивом

    partition(arr, x);

    // вывод и отладка
    
    /*
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i];
    }
    std::cout << std::endl;
    */

    int count_L = 0;
    int count_R = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < x)
        {
            count_L++;
        }
        
    }
    count_R = arr.size() - count_L;

    std::cout << count_L << '\n' << count_R;    
    
    
    return 0;
}