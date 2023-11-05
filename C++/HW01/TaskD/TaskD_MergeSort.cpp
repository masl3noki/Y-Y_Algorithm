#include <iostream>
#include <vector>

void debug_print_vector(std::vector<int>&);

/**
 * @brief Реализация слияния двух отсортированных векторов в единый, сохраняя порядок. Неустойчивая реализация.
 * 
 * @param target Вектор, куда записывать результат
 * @param start Итератор начала отрезка
 * @param mid Итератор середины отрезка (partition)
 * @param finish Итератор конца отрезка
 */
void merge(std::vector<int>& target, int start, int mid, int finish) {
	
	std::vector<int> temp;

	int i, j;
	i = start;
	j = mid + 1;

    // Заполнение, пока один из векторов не закончится
	while (i <= mid && j <= finish) {

		if (target[i] <= target[j]) {
			temp.push_back(target[i]);
			++i;
		}
		else {
			temp.push_back(target[j]);
			++j;
		}
	}

    // Заполняем оставшиеся элементы
	while (i <= mid) {
		temp.push_back(target[i]);
		++i;
	}

	while (j <= finish) {
		temp.push_back(target[j]);
		++j;
	}

    // Применение изменений
	for (int i = start; i <= finish; ++i) {
		target[i] = temp[i - start];
    }
}

/**
 * @brief Стандартная сортировка слиянием
 * 
 * @param arr Вектор для сортировки
 * @param start Итератор начала вектора 
 * @param finish Итератор конца вектора
 */
void Mergesort_alg(std::vector<int>& arr, int const start, int const finish) {

    if (start >= finish) {
        return;
    }
    
    // Разбиение
    int mid = start + (finish - start) / 2;

    // Рекурсия вплоть до подмножества из 1-2 элементов
    Mergesort_alg(arr, start, mid);
    Mergesort_alg(arr, mid + 1, finish);

    merge(arr, start, mid, finish);   
}

int main() {
    // input
    int n = 0;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    // Сортировка
    Mergesort_alg(v, 0, v.size()-1);
    debug_print_vector(v);

    return 0;
}

void debug_print_vector(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;    
}