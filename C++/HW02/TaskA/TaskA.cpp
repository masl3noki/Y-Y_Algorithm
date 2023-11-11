#include <iostream>
#include <string>

/**
 * @brief Вычисление хеша для подаваемой строки.
 * 
 * @param s Строка для создания хеша
 * @return long long значение хеша для строки s
 */
long long compute_hash(std::string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;

    for (char c : s) {
        hash_value += (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }

    return hash_value;
}

int main() {
    
    std::cout << compute_hash("ab");

    return 0;
}