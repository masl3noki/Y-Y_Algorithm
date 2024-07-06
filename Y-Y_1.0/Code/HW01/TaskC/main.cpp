#include <iostream>
#include <string>
#include <algorithm>

class phoneNumber {
    private:
        std::string uneditedNum = "";
        long code = 495;
        long num = -1;

    public:
        // Конструктор
        phoneNumber(std::string str) {
            uneditedNum = str;
        }

        // Перегрузка оператора ==
        bool operator==(const phoneNumber& other) const{
            if (code == other.code && num == other.num)
                return true;
            else return false;            
        }

        // Парсинг
        void parse() {
            /* Удалим все лишние символы в строке
            * std::remove_if() переместит не-цифры в конец массива string;
            * lambda-функция вовзращает true, если с - цифра;
            * метод erase удалит элементы, начиная с позиции, возвращенной std::remove_if до конца строки.
            */
            uneditedNum.erase(std::remove_if(uneditedNum.begin(), uneditedNum.end(), [](unsigned char c) { return !std::isdigit(c); }), uneditedNum.end());

            // Парсим
            switch (uneditedNum.length())
            {
            case 7:
                code = 495;
                num = std::stol(uneditedNum);
                break;

            case 11:
                uneditedNum.erase(uneditedNum.begin());
                code = std::stol(uneditedNum.substr(0, 3));
                num = std::stol(uneditedNum.substr(3, 9));
                break;                
            }
        }
};

int main() {
    // Инициализация
    std::string str;
    std::cin >> str;
    phoneNumber mainNumber (str);
    mainNumber.parse();

    // Тело
    for (int i = 0; i < 3; i++)
    {
        std::cin >> str;
        phoneNumber newNumber (str);
        newNumber.parse();

        std::cout << ((mainNumber == newNumber) ? "YES\n" : "NO\n");
    }

    return 0;
}