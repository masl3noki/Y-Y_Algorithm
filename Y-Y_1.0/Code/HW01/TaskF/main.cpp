#include <iostream>
#include <climits>
#include <vector>
#include <algorithm> 

/**
 * @brief Самое наглядное и неэффективное решение
 * 
 * @param x1, y1, x2, y2 - размеры ноутбуков
 * @return std::pair<int, int> длина и ширина стола
 * 
 * @warning каждый размер ноутбука <= 1000
 */
std::pair<int, int> solver1 (int& x1, int& y1, int& x2, int& y2) {
    // Некрасивое решение
    struct Solution {
        int width = 0, length = 0;
        int area = 0;
    };
    std::vector<Solution> vecSolutions;

    int w = 0, l = 0;
    
    /* Take 1: 
    *  __
    * [  ]  _
    * [  ] [ ]
    * [__] [_]
    * */
    w = std::max(x1, x2);
    l = y1 + y2;
    vecSolutions.push_back({w, l, w*l});

    /* Take 2: 
    *  __
    * [  ]
    * [  ]  ___
    * [__] [___]
    * */
    w = std::max(x1, y2);
    l = y1 + x2;
    vecSolutions.push_back({w, l, w*l});

    /* Take 3: 
    *  __
    * [  ]
    * [  ]  
    * [__]
    * 
    *  _
    * [ ]
    * [_]
    * */
    w = x1 + x2;
    l = std::max(y1, y2);
    vecSolutions.push_back({w, l, w*l});

    /* Take 4: 
    *  __
    * [  ]
    * [  ]  
    * [__]
    * 
    *  ___
    * [___]
    * */
    w = x1 + y2;
    l = std::max(y1, x2);
    vecSolutions.push_back({w, l, w*l});

    /* Take 5: 
    *  ______   _
    * [      ] [ ]
    * [______] [_]
    * */
    w = std::max(y1, x2);
    l = x1 + y2;
    vecSolutions.push_back({w, l, w*l});

    /* Take 6: 
    *  ______
    * [      ]  ___
    * [______] [___]
    * */
    w = std::max(y1, y2);
    l = x1 + x2;
    vecSolutions.push_back({w, l, w*l});

    /* Take 7: 
    *  ______
    * [      ]
    * [______]
    * 
    *  _
    * [ ]
    * [_]
    * */
    w = y1 + x2;
    l = std::max(x1, y2);
    vecSolutions.push_back({w, l, w*l});

    /* Take 8: 
    *  ______
    * [      ]  
    * [______]
    * 
    *  ___
    * [___]
    * */
    w = y1 + y2;
    l = std::max(x1, x2);
    vecSolutions.push_back({w, l, w*l});

    // Поиск минимальной площади
    int S = INT_MAX;
    int iter = -1;
    for (int i = 0; i < 7; i++)
    {
        if (vecSolutions[i].area < S)
        {
            S = vecSolutions[i].area;
            iter = i;
        }
    }
    
    return {vecSolutions[iter].width, vecSolutions[iter].length};
}

/**
 * @brief Более компактное решение
 * 
 * @param l1, w1, l2, w2 - размеры ноутбуков
 * @return std::pair<int, int> длина и ширина стола
 * 
 * @warning каждый размер ноутбука <= 1000
 */
std::pair<int, int> solver2(int l1, int w1, int l2, int w2) {
    /*
    Тут такой же перебор всех 8 комбинаций. И хотя может показаться, что достаточно проверить лишь 4 (оба горизонт., оба верт., 2 противоположных положения), можно привести контрпример, когда это не так
    Один из них {6, 2, 8, 3} с ответом {8, 5} или {5, 8}.
    */
    std::vector<std::pair<int, int>> combinations = {
        {std::max(l1, l2), w1 + w2},
        {std::max(l1, w2), w1 + l2},
        {std::max(w1, l2), l1 + w2},
        {std::max(w1, w2), l1 + l2},
        {l1 + l2, std::max(w1, w2)},
        {l1 + w2, std::max(w1, l2)},
        {w1 + l2, std::max(l1, w2)},
        {w1 + w2, std::max(l1, l2)}
    };
    
    int S = INT_MAX;
    std::pair<int, int> bestSize;
    
    for (const auto& [length, width] : combinations) {
        int area = length * width;
        if (area < S) {
            S = area;
            bestSize = {length, width};
        }
    }
    
    return bestSize;
}

int main() {
    // Иницилизация
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    std::cin >> x1 >> y1 >> x2 >> y2;

    // Тело
    auto result1 = solver1(x1, y1, x2, y2);
    auto result2 = solver2(x1, y1, x2, y2);

    //std::cout << result1.first << " " << result1.second;
    std::cout << result2.first << " " << result2.second;
    

    return 0;
}