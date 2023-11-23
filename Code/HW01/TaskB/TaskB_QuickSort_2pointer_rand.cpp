#include <iostream>
#include <vector>

void debug_print_vector(std::vector<long long>&);

/**
 * @brief Функция, которая за O(n) проверяет массив на факт сортировки
 * 
 * @param arr вектор для проверки
 * @param size размер вектора (рудиментарный аргумент)
 * @return true если вектор отсортирован, иначе 
 * @return false 
 */
bool isSortedVector (std::vector<long long>& arr, int size) {
    
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
 * @return int Номер опорного элемента
 */
int Partition(std::vector<long long> &v, int start, int end, char predicate = '<') {
	
    // Инициализация переменных для scope всей функции
    int pivot = end;
	int j = start;

    switch (predicate)
    {
    case '>':
        
        // Алгоритм для предиката >x
        for(int i = start; i < end; i++) {
		
            if(v[i] > v[pivot]) {
			    std::swap(v[i], v[j]);
			    j++;
		    }
	    }
	
        std::swap(v[j], v[pivot]);

        break;
    
    default:

        // Алгоритм для предиката <x
        for(int i = start; i < end; i++) {
		
            if(v[i] < v[pivot]) {
			    std::swap(v[i], v[j]);
			    j++;
		    }
	    }
	
        std::swap(v[j], v[pivot]);

        break;
    }
	
	return j;
}

/**
 * @brief Функция-прослойка между partition и интерфейсом quick sort для внедрения вариантов разбиения
 * 
 * @param v Вектор на сортировку
 * @param start Левый итератор
 * @param end Правый итератор
 * @param predicate Условие, по которому разделять массив. По умолчанию стоит '<', т.е. массив делится согласно условию "<x"
 * @return int Номер опорного элемента
 */
int Partition_r(std::vector<long long> &v, int start, int end, char predicate = '<')
{
    // Генерируем рандомное число на компакте [start; end]
    int random = start + rand() % (end - start);
 
    // Меняем сгенерированный опорный элемент с последним в векторе, т. о. идея сортировки остается той же, но теперь мы реже натыкаемся на худшие исходы
    std::swap(v[random], v[end]);
 
    return Partition(v, start, end, predicate);
}

/**
 * @brief Реализация алгоритма быстрой сортировки, когда опорный элемент в конце любого компакта внутри вектора
 * 
 * @param v Вектор на сортировку
 * @param start Левый итератор
 * @param end Правый итератор
 * @param predicate Условие, по которому разделять массив. По умолчанию стоит '<', т.е. массив делится согласно условию "<x"
 */
void Quicksort_alg(std::vector<long long> &v, int start, int end, char predicate = '<' ) {
    // Рекурсия, которая заканчивается, когда v.size() < 2;
	if(start < end){
		int p = Partition_r(v, start, end, predicate);
		Quicksort_alg(v, start, p - 1, predicate);
		Quicksort_alg(v, p + 1, end, predicate);
	}
}

/**
 * @brief Оболочка реализации алгоритма быстрой сортировки
 * 
 * @param v Вектор на сортировку
 * @param predicate Условие, по которому разделять массив. По умолчанию стоит '<', т.е. массив делится согласно условию "<x"
 */
void Quicksort(std::vector<long long> &v, char predicate = '<' ) {
    if (!isSortedVector(v, v.size())) {
        Quicksort_alg(v, 0, v.size() - 1, predicate);
    }
}

int main() {
	
    int n = 0;
    std::vector<long long> v, v2;

    // input
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int number = 0;
        std::cin >> number;

        v.push_back(number);
    }
    v2 = v;
	
	std::cout<<"Вектор до сортировки: "<<std::endl;
	debug_print_vector(v);
	
	Quicksort(v);
	
	std::cout<<"Вектор после сортировки через {<x}: "<<std::endl;
	debug_print_vector(v);

    Quicksort(v2, '>');

    std::cout<<"Вектор после сортировки через {>x}: "<<std::endl;
	debug_print_vector(v2);
}

void debug_print_vector(std::vector<long long>& arr) {
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;    
}