//
// Created by tosiek on 16.02.2022.
//

#ifndef AGES1_SAVESYSTEM_H
#define AGES1_SAVESYSTEM_H

#include "HandleTownHall.h"
#include <array>
#include <string>
#include <fstream>

class SaveSystem{
public:
    void load_save(string save_path, std::array<int,8> &levels, HandleTownHall &th_window, string &name, int &human, int &wood, int &rock);
    void save_game(string save_path, std::array<int,8> levels, HandleTownHall &th_window, string &name, int &human, int &wood, int &rock);

};


#endif //AGES1_SAVESYSTEM_H
