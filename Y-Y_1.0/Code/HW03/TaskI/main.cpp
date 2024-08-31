#include <iostream>
#include <set>
//#include <unordered_set> Не использую, т.к. для этого надо доп. хеш-функцию писать
#include <string>
#include <algorithm>

/**
 * @brief Поиск пересечения элементов множества
 * 
 * @param students множество школьников
 * 
 * @note Здесь я использовал buff_intersection и проверку на пустое множество, т.к. иначе результрующее множество не изменялось бы, при математически пустом пересечении.
 */
void step_1(std::set<std::set<std::string>> students) {
    std::set<std::set<std::string>>::iterator st_it;
    std::set<std::string> intersection = *(students.begin());

    for (st_it = students.begin(); st_it != students.end(); st_it++) {
        std::set<std::string> buff_intersection;
        std::set_intersection((*st_it).begin(), (*st_it).end(),
                              intersection.begin(), intersection.end(),
                              std::inserter(buff_intersection, buff_intersection.begin()));

        if (buff_intersection.size() == 0) {
            intersection = buff_intersection;
            break;                          
        }  
    }
    
    // Вывод
    std::cout << intersection.size() << '\n';
    for (const auto& language : intersection)
        std::cout << language << " \n";
}

/**
 * @brief Поиск объединения элементов множества, т.е. A U B
 * 
 * @param students множество школьников
 */
void step_2(std::set<std::set<std::string>> students) {
    std::set<std::set<std::string>>::iterator st_it;
    std::set<std::string> union_set = *(students.begin());

    for (st_it = students.begin(); st_it != students.end(); st_it++) {
        std::set_union((*st_it).begin(), (*st_it).end(),
                              union_set.begin(), union_set.end(),
                              std::inserter(union_set, union_set.begin()));
    }
    
    // Вывод
    std::cout << union_set.size() << '\n';
    for (const auto& language : union_set)
        std::cout << language << " \n";
}

int main() {
    // Инициализация
    int N=-1;
    /* 
    Храним множество всех школьников. Каждый элемент этого множества это множество языков
    Если будут повторения, то нам не страшно, т.к. на ответ это не повлияет
    */
    std::set<std::set<std::string>> students;
    std::cin >> N;

    int buffN=-1;
    std::string buff;
    for (int i = 0; i < N; i++) {
        std::cin >> buffN;
        std::set<std::string> buffSet;
        for (int j = 0; j < buffN; j++) {
            std::cin >> buff;
            buffSet.insert(buff);
        }

        students.insert(buffSet);
    }

    // Тело
    // Шаг 1) Вычисляем общий язык школьников:
    step_1(students);

    // Шаг 2) Вычисляем "количество языков, которые знает хотя бы один школьник":
    step_2(students);

    return 0;
}