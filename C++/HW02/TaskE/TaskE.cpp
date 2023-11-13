#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
void debug_print_vector(std::vector<T>& arr);

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    for(int i = 1; i <= n; i++) {
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

int main() {
    string s;
    cin >> s;

    auto res = manacher_odd(s);
    
    debug_print_vector(res);

    return 0;
}

template<class T>
void debug_print_vector(std::vector<T>& arr) {
    for (auto element : arr)
        std::cout << element << " ";
    std::cout << std::endl;    
}