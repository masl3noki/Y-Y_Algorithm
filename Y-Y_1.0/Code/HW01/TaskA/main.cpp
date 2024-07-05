#include <iostream>
#include <string>

int ac (std::string& cmd, int& t_room, int& t_cond) {
    if (cmd == "auto") 
        // из описания следует, что всегда возвращает t_cond
        return t_cond;

    else if (cmd == "heat") 
        // возвращает t_cond только, если t_room <= t_cond
        if (t_room <= t_cond)
            return t_cond;
        else 
            return t_room;

    else if (cmd == "freeze") 
        // возвращает t_cond только, если t_room >= t_cond
        if (t_room >= t_cond)
            return t_cond;
        else 
            return t_room;

    else if (cmd == "fan")
        // всегда возвращает t_room
        return t_room;
    
    return -999999;
}

int main() {
    // Инициализация
    int t_room = 0;
    int t_cond = 0;
    std::string cmd = "";

    // Тело
    std::cin >> t_room >> t_cond;
    std::cin >> cmd;

    std::cout << ac(cmd, t_room, t_cond);
    return 0;
}