#include <iostream>
#include <vector>

int Partition_r(std::vector<int> &v, int start, int end)
{
    // Генерируем рандомное число на компакте [start; end]
    //srand(time(NULL));
    int random = start + rand() % (end - start);
 
    // Меняем сгенерированный опорный элемент с последним в векторе, т. о. идея сортировки остается той же, но теперь мы реже натыкаемся на худшие исходы
    std::swap(v[random], v[end]);
    
    // Инициализация переменных для scope всей функции
    int pivot = end;
	int j = start;

    for(int i = start; i < end; i++) {
		
            if(v[i] < v[pivot]) {
			    std::swap(v[i], v[j]);
			    j++;
		    }
	    }
	
        std::swap(v[j], v[pivot]);
    
	return j;
}

void Quicksort(std::vector<int> &v, int start, int end) {
    // Рекурсия, которая заканчивается, когда v.size() < 2;
	if(start < end){
		int p = Partition_r(v, start, end);
		Quicksort(v, start, p - 1);
		Quicksort(v, p + 1, end);
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

    Quicksort(v, 0, v.size() - 1);
    
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

}