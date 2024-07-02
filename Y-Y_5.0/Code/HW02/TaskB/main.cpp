#include <iostream>
#include <vector>
#include <limits>

int main(){
    // initialising
    std::vector<long long> arr;
    int n = 0;
    int k = 0;

    long long price = 0;
    long long max = std::numeric_limits<long long>::min();

    std::cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        long long buff = 0;
        std::cin >> buff;

        arr.push_back(buff);
    }
    

    // algo
    for (int i = 0; i < n-k+1; i++)
    {
        for (int j = i; j <= i+k; j++)
        {
            long long buff = arr[j] - arr[i];

            if (buff > max)
            {
                max = buff;
            }
            
        }
        
    }

    std::cout << max;
    

    return 0;
}