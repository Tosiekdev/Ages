//
// Created by tosiek on 16.02.2022.
//

#ifndef AGES1_SAVESYSTEM_H
#define AGES1_SAVESYSTEM_H

#include "handletownhall.h"
#include <array>
#include <string>
#include <fstream>

class SaveSystem{
public:
    void load_save(std::string save_path, std::array<int,8> &levels, HandleTownHall &th_window, std::string &name, int &human, int &wood, int &rock, std::array<buildings,8> &b);
    void save_game(std::string save_path, std::array<int,8> levels, HandleTownHall &th_window, std::string &name, int &human, int &wood, int &rock);

};


#endif //AGES1_SAVESYSTEM_H
