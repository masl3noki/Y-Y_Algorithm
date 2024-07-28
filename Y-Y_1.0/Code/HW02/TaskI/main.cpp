#include <iostream>
#include <vector>
#include <climits>

/**
 * @brief Проверяем находятся ли итераторы внутри интервала
 * @param left левый конец
 * @param right правый конец
 * @param el исследуемый элемент
 * 
 * @return true, если находится строго внутри интервала, иначе false
 * @note Строгое сравнение, т.е. if (el == left) return false;
 */
bool inInterval (const int& left, const int& right, const int& el) {
    if (el > left && el < right)
        return true;
    else return false;
}

/**
 * @brief Поиск мин в соседних клетках
 * @param field минное поле (2d вектор int'ов)
 * @param N, M количество строк и столбцов поля
 * @param row, col координаты ячейки на поле
 * 
 * @return количество мин
 * @note не более 8 включительно
 */
int checkNeighbor(const std::vector<std::vector<int>>& field, const int& N, const int& M, const int& row, const int& col) {
    int count = 0;
    int row_min = -1,
        row_max = N,
        col_min = -1,
        col_max = M;
    for (int i = row-1; i < row+2; i++) {
        for (int j = col-1; j < col+2; j++) {
            if (inInterval(row_min, row_max, i) && inInterval(col_min, col_max, j)) // Проверка, что не заходим за пределы
                if (field[i][j] == -1)
                    count++;
        }
    }

    return count;    
}

/**
 * @brief Решение задачи
 * @param field минное поле
 * @param N, M количество строк и столбцов поля
 * 
 * @note Обновляем минное поле
 */
void solution(std::vector<std::vector<int>>& field, const int& N, const int& M) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (field[i][j] != -1) {
                count = checkNeighbor(field, N, M, i, j);
                field[i][j] = count;
            }
        }
        count = 0;
    }    
}

int main() {
    // Инициализация
    int N = -1, M = -1, K = -1;
    std::cin >> N >> M >> K;
    
    std::vector<std::vector<int>> matrix(N, std::vector<int>(M, 0));

    std::pair<int, int> buff;
    for (int i = 0; i < K; i++) {
        std::cin >> buff.first >> buff.second;
        matrix[buff.first-1][buff.second-1] = -1;
    }

    // Тело
    solution(matrix, N, M);

    // Вывод
    for (const auto& row : matrix) {
        for (int val : row) {
            if (val == -1)
                std::cout << "*" << " ";
            else   
                std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}