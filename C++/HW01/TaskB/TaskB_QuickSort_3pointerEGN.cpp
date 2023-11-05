#include <iostream>
#include <vector>
#include <random>

void debug_print_vector(std::vector<int>&);

/**
 * @brief Функция проверяет отсортирован ли вектор
 * 
 * @param arr Вектор для проверки на отсортированность;
 * @param iter При вызове впервые - длина вектора;
 * 
 * @return true - вектор отсортирован, иначе
 * @return false 
 */
bool isSortedVector (std::vector<int>& arr, int size) {
    
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }

    return true;
    
}

/**
 * @brief Разбиение вектора относительно предиката и опорного номера элемента
 * 
 * @param v Вектор для разбиения
 * @param start Левый итератор
 * @param end Правый итератор
 * @param predicate Условие, по которому разделять массив. По умолчанию стоит '<', т.е. массив делится согласно условию "<x"
 * 
 * @return int Номер опорного элемента
 */
void Partition(std::vector<int> &v, int start, int end, int& i, int& j, char predicate = '<') {
	
    // Инициализация переменных для scope всей функции
	int predicate_itr = start; // итератор >x
    int equal = start; // итератор =x
    int now = start; // итератор как если бы это был for

    switch (predicate)
    {
    case '>':
        
        // Алгоритм для предиката >x

        while (true)
        {
            if (v[now] > v[equal]) {

                int temp = v[now];
                v[now] = v[predicate_itr];
                v[predicate_itr] = v[equal];
                v[equal] = temp;
                
                predicate_itr++;
                equal++;
            } else if (v[now] == v[equal]) {

                int temp = v[now];
                v[now] = v[predicate_itr];
                v[predicate_itr] = temp;

                predicate_itr++;
            }

            if (now == end) break;

            now++;
        }

        break;
    
    default:

        // Алгоритм для предиката <x

        while (true)
        {
            if (v[now] < v[equal]) {

                int temp = v[now];
                v[now] = v[predicate_itr];
                v[predicate_itr] = v[equal];
                v[equal] = temp;
                
                predicate_itr++;
                equal++;
            } else if (v[now] == v[equal]) {

                int temp = v[now];
                v[now] = v[predicate_itr];
                v[predicate_itr] = temp;

                predicate_itr++;
            }

            if (now == end) break;

            now++;
        }

        break;
    }
	
    i = equal;
    j = predicate_itr;	
}

/**
 * @brief Реализация алгоритма быстрой сортировки, когда опорный элемент в конце любого компакта внутри вектора
 * 
 * @param v Вектор на сортировку
 * @param start Левый итератор
 * @param end Правый итератор
 * @param predicate Условие, по которому разделять массив. По умолчанию стоит '<', т.е. массив делится согласно условию "<x"
 */
void Quicksort_alg(std::vector<int> &v, int start, int end, char predicate = '<' ) {
    // Рекурсия, которая заканчивается, когда v.size() < 2;
	if(start < end){

        // Разбиение
        int i, j;
		Partition(v, start, end, i, j, predicate);

        // Рекурсия
		Quicksort_alg(v, start, i - 1, predicate);
		Quicksort_alg(v, j, end, predicate);
	}
	
}

/**
 * @brief Реализация алгоритма быстрой сортировки, когда опорный элемент в конце любого компакта внутри вектора
 * 
 * @param v Вектор на сортировку
 * @param predicate Условие, по которому разделять массив. По умолчанию стоит '<', т.е. массив делится согласно условию "<x"
 */
void Quicksort(std::vector<int> &v, char predicate = '<' ) {
    int start = 0;
    int end = v.size() - 1;

    if (!isSortedVector(v, v.size())) {
        Quicksort_alg(v, start, end, predicate);
    }

}

int main() {
	
    int n = 0;
    std::cin >> n;

    // input    
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
   
    Quicksort(v);
    debug_print_vector(v);

}

void debug_print_vector(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;    
}
