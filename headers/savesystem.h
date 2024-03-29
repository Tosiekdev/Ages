//
// Created by tosiek on 16.02.2022.
//

#ifndef AGES1_SAVESYSTEM_H
#define AGES1_SAVESYSTEM_H

#include "buildings-windows/handletownhall.h"
#include "buildings-windows/handlebarracks.h"
#include <array>
#include <string>
#include <fstream>

class SaveSystem{
public:
    void load_save(std::string save_path, std::array<int, 10> &levels, HandleTownHall &th_window, std::string &name,
                   int &human, int &wood, int &rock, int &money, int &iron, std::array<buildings, 10> &b,
                   HandleBarracks &b_window);
    static void save_game(const std::string &save_path, std::array<int, 10> &levels, HandleTownHall &th_window,
                          std::string &name, int &human, int &wood, int &rock, int &money, int &iron,
                          HandleBarracks &b_window);

};


#endif //AGES1_SAVESYSTEM_H
