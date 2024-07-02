#include <iostream>
#include <vector>
#include <limits>

int main(){
    // initialising
    std::vector<std::pair<long long, long long>> arr;
    int n = 0;

    std::cin >> n;

    // algo

    long long min_x = std::numeric_limits<long long>::max(); 
    long long min_y = std::numeric_limits<long long>::max();
    long long max_x = std::numeric_limits<long long>::min();
    long long max_y = std::numeric_limits<long long>::min();

    for (int i = 0; i < n; i++)
    {
        long long a, b;
        std::cin>> a >> b;
        
        auto buff = std::pair(a, b);

        arr.push_back(std::pair(a, b));

        if (a > max_x) max_x = a;
        if (a < min_x) min_x = a;
        if (b > max_y) max_y = b;
        if (b < min_y) min_y = b;
    }

    std::cout << min_x << " " << min_y << " " << max_x << " " << max_y << "\n";
    
/*
    for (auto elem: arr)
    {
        std::cout << elem.first << "; " << elem.second << "\n";
    }
*/    

    return 0;
}