#include <iostream>
#include <cmath>
#include <vector>

std::pair<int, int> solution(int& a, int& b, int& n, int& m) {
    /* Пока допустим, что Таня всегда права 
    */

    // Инициализация
    int a_min = 1 + (a + 1) * (n - 1);
    int a_max = (a + 1) * n - 1;
    int b_min = 1 + (b + 1) * (m - 1);
    int b_max = (b + 1) * m - 1;

    int minm = std::max(a_min, b_min);
    int maxm = std::max(a_max, b_max);

    std::pair<int, int> result = {minm, maxm};

    /* Гипотеза: если возникает противоречие, значит Т сбилась со счета. Когда может возникать противоречие?
    Когда разница между элементами std::max() может вместить больше поездов, чем n или m.
    
    Нам достаточно считать сколько поездов может приехать в "разницу", т.к. поиск лишних поездов (когда Т насчитала больше)
    можно свести к обратной ситуации (когда Т насчитала меньше), только для другого пути.
    Это можно свести к следующему условию: 
        1) пересчитать a_min, ... , b_max с a+1 и b+1;
        2) новые значение a_min, ... , b_max попадают в прошлый интервал [minm; maxm]
    */

    a_min = 1 + (a + 2) * (n - 1);
    a_max = (a + 2) * n - 1;
    b_min = 1 + (b + 2) * (m - 1);
    b_max = (b + 2) * m - 1;

   if ()
   {
        return {-1, -1}; // Уникальное значение, которое не может быть достигнуто ни при каких a,b,n,m.
   }
   
    return result;
}

int main() {
    // Инициализация
    int a=0, b=0, n=0, m=0;
    std::cin >> a >> b >> n >> m;

    // Тело
    auto result = solution(a, b, n, m);

    if (result.first == -1)
    {
        std::cout << -1;
    } else std::cout << result.first << " " << result.second;

    return 0;
}