#include <iostream>
#include <vector>

void debug_print_vector(std::vector<int>&);

/**
 * @brief Разбиение вектора относительно предиката и опорного номера элемента
 * 
 * @param v Вектор для разбиения
 * @param start Левый итератор
 * @param end Правый итератор
 * @param predicate Условие, по которому разделять массив. По умолчанию стоит '<', т.е. массив делится согласно условию "<x"
 * @return int Номер опорного элемента
 */
int Partition(std::vector<int> &v, int start, int end, char predicate = '<') {
	
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
 * @brief Реализация алгоритма быстрой сортировки, когда опорный элемент в конце любого компакта внутри вектора
 * 
 * @param v Вектор на сортировку
 * @param start Левый итератор
 * @param end Правый итератор
 * @param predicate Условие, по которому разделять массив. По умолчанию стоит '<', т.е. массив делится согласно условию "<x"
 */
void Quicksort(std::vector<int> &v, int start, int end, char predicate = '<' ) {
    // Рекурсия, которая заканчивается, когда v.size() < 2;
	if(start < end){
		int p = Partition(v, start, end, predicate);
		Quicksort(v, start, p - 1, predicate);
		Quicksort(v, p + 1, end, predicate);
	}
	
}

int main() {
	
    int n = 0;
    std::vector<int> v;

    // input
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int number = 0;
        std::cin >> number;

        v.push_back(number);
    }
	
	std::cout<<"Вектор до сортировки: "<<std::endl;
	debug_print_vector(v);
	
	Quicksort(v,0,v.size()-1);
	
	std::cout<<"Вектор после сортировки через {<x}: "<<std::endl;
	debug_print_vector(v);

    std::vector<int> v2 = { 1, 5, 2, 4, 3 };
    Quicksort(v,0,v.size()-1, '>');

    std::cout<<"Вектор после сортировки через {>x}: "<<std::endl;
	debug_print_vector(v);

}

void debug_print_vector(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;    
}