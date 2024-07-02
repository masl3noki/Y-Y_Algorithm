#include <iostream>
#include <vector>

void debug_print_vector(std::vector<int>&);

void merge(std::vector<int>& target, std::vector<int>& v1, std::vector<int>& v2) {
    int v1_iter = 0;
    int v2_iter = 0;

    while (true)
    {
        // Проверяем выход за пределы
        if (v1_iter == v1.size() || v2_iter == v2.size())
        {
            break;
        }

        // Заполнение
        if (v1[v1_iter] <= v2[v2_iter]) {
            target.push_back(v1[v1_iter]);
            v1_iter++;
        } else {
            target.push_back(v2[v2_iter]);
            v2_iter++;
        }
    }

    // Проверка, заполнили ли мы все (в любом случае один из while loop сразу завершится)
    
    while (v1_iter < v1.size()) {
        target.push_back(v1[v1_iter]);
        v1_iter++;
    }

    while (v2_iter < v2.size()) {
        target.push_back(v2[v2_iter]);
        v2_iter++;
    }
}

int main() {
    // input
    int n = 0;
    std::cin >> n;

    std::vector<int> v1(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> v1[i];
    }

    int m = 0;
    std::cin >> m;

    std::vector<int> v2(m);
    for (int i = 0; i < m; i++)
    {
        std::cin >> v2[i];
    }

    // Сортировка
    std::vector<int> result;
    merge(result, v1, v2);
    debug_print_vector(result);

    return 0;
}

void debug_print_vector(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;    
}