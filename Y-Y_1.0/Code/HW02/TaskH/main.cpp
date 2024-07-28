#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <sstream>

/* Технические функции и классы */  

class two {
protected:
    int first = INT_MIN;
    int secnd = INT_MIN;

public:
    virtual long long mul() const {
        return {static_cast<long long>(first) * static_cast<long long>(secnd)};
    }

    virtual void update(const int& el) {
        if (el >= first) {
            secnd = first;
            first = el;
        } else if (el >= secnd && el != first) {
            secnd = el;
        }
    }

    virtual std::vector<int> get_vector() {
        return {first, secnd};
    }

    virtual int get_max() {
        return std::max(first, secnd);
    }

    virtual bool isValid() {
        if (first != INT_MIN) 
            if (secnd != INT_MIN)
                return true;
        return false;            
    }
};

class three : public two {
private:
    int third = INT_MIN;

public:
    long long mul() const override {
        return {static_cast<long long>(first) * static_cast<long long>(secnd) * static_cast<long long>(third)};
    }

    void update(const int& el) override {
        if (el >= first) {
            third = secnd;
            secnd = first;
            first = el;
        } else if (el >= secnd && el != first) {
            third = secnd;
            secnd = el;
        } else if (el >= third && el != secnd && el != first) {
            third = el;
        }
    }

    std::vector<int> get_vector() override {
        return {first, secnd, third};
    }
    
    int get_max() override {
        return std::max(std::max(first, secnd), third);
    }

    virtual bool isValid() override {
        if (first != INT_MIN) 
            if (secnd != INT_MIN)
                if (third != INT_MIN)
                    return true;
        return false;            
    }
};

/* Решение задачи */

std::vector<int> solution_wrong(std::vector<int>& seq) {
    // Инициализация
    three max_g0,
          max_l0;
    two min_l0;
    
    if (seq.size() < 4) // Проще будет просто вывести оба числа 
        return {seq[0], seq[1], seq[2]};

    // Шаг 1)
    for (int el : seq) {
        if (el > 0) { // Поиск триплета при >= 0
            max_g0.update(el);
        } else { 
            // Поиск триплета, ближайшего к 0 (включительно)
            max_l0.update(el);

            // Поиск альтернативной пары при < 0
            if (el != 0) { // или все же (el < 0) ?
                min_l0.update(el);
            }
        }
    }

    // Ищем какой-нибудь третий элемент для пары
    
}

int main() {
    // Инициализация
    std::vector<int> seq; {
        int element;
        while(std::cin >> element) {
            seq.push_back(element);
        }
    }

    // Формат вывода
    auto result = solution_wrong(seq);
    std::cout << result[0] << " " << result[1] << " " << result[2];

    return 0;
}