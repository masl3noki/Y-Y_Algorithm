#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    // Инициализация
    int x=0, y=0, z=0;
    unsigned int N = 0;
    std::unordered_set<int> buttons;
    std::cin >> x >> y >> z >> N;
    
    int buff = N%10;
    while (N != 0) {
        if (!(buff == x || buff == y || buff == z))
            buttons.insert(buff);
    
        N /= 10;
        buff = N%10;
    }

    std::cout << buttons.size();

    return 0;
}