//
// Created by tosiek on 16.02.2022.
//

#ifndef AGES1_SAVESYSTEM_H
#define AGES1_SAVESYSTEM_H

#include "buildings-windows/handletownhall.h"
#include <array>
#include <string>
#include <fstream>

class SaveSystem{
public:
    void load_save(std::string save_path, std::array<int, 9> &levels, HandleTownHall &th_window, std::string &name,
                   int &human,
                   int &wood, int &rock, int &money, std::array<buildings, 9> &b);
    static void save_game(const std::string& save_path, std::array<int, 9> &levels, HandleTownHall &th_window, std::string &name,
                   int &human,
                   int &wood, int &rock, int &money);

};


#endif //AGES1_SAVESYSTEM_H
