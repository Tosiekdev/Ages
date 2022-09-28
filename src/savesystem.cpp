//
// Created by tosiek on 16.02.2022.
//

#include "../headers/savesystem.h"

void
SaveSystem::load_save(std::string save_path, std::array<int, 10> &levels, HandleTownHall &th_window, std::string &name,
                      int &human, int &wood, int &rock, int &money, int &iron, std::array<buildings, 10> &b,
                      HandleBarracks &b_window) {
    std::fstream s_path;
    s_path.open(save_path,std::ios::in);
    std::string input;
    int line_nr=0;
    std::vector<int> unitsLeft; //vector with time left for training units
    std::array<int,9> unitsQuantity{}; //array with quantity of every unit
    auto town_hall=static_cast<float>(levels[6]);//level of town hall for proper progress bar drawing
    while(!s_path.eof()){
        getline(s_path, input);

        //assigning value to the right variable
        switch(line_nr){
            case 0:
                name=input;
                break;
            case 1:
                levels[0]=stoi(input);//academy
                break;
            case 2:
                levels[1]=stoi(input);//barracks
                break;
            case 3:
                levels[2]=stoi(input);//church
                break;
            case 4:
                levels[3]=stoi(input);//farm
                break;
            case 5:
                levels[4]=stoi(input);//lumber mill
                break;
            case 6:
                levels[5]=stoi(input);//stone pit
                break;
            case 7:
                levels[6]=stoi(input);//townhall
                break;
            case 8:
                levels[7]=stoi(input);//warehouse
                break;
            case 9:
                levels[8] = std::stoi(input);//bank
                break;
            case 10:
                levels[9]=std::stoi(input);//iron mine
                for (int i = 0; i < 10; i++) b[i].set_level(levels[i]);
                //resources
            case 11:
                human=stoi(input);
                break;
            case 12:
                wood=stoi(input);
                break;
            case 13:
                rock=stoi(input);
                break;
            case 14:
                money=stoi(input);
                break;
            case 15:
                iron=stoi(input);
                break;
                //time left
            case 16:
                th_window.set_ub_left(0, stof(input),town_hall);
                break;
            case 17:
                th_window.set_ub_left(1,stof(input),town_hall);
                break;
            case 18:
                th_window.set_ub_left(2,stof(input),town_hall);
                break;
            case 19:
                th_window.set_ub_left(3,stof(input),town_hall);
                break;
            case 20:
                th_window.set_ub_left(4,stof(input),town_hall);
                break;
            case 21:
                th_window.set_ub_left(5,stof(input),town_hall);
                break;
            case 22:
                th_window.set_ub_left(6,stof(input),town_hall);
                break;
            case 23:
                th_window.set_ub_left(7,stof(input),town_hall);
                break;
            case 24:
                th_window.set_ub_left(8,std::stof(input),town_hall);
                break;
            case 25:
                th_window.set_ub_left(9,std::stof(input),town_hall);
                break;
            case 26:
                unitsQuantity[0]=std::stoi(input);
                break;
            case 27:
                unitsQuantity[1]=std::stoi(input);
                break;
            case 28:
                unitsQuantity[2]=std::stoi(input);
                break;
            case 29:
                unitsQuantity[3]=std::stoi(input);
                break;
            case 30:
                unitsQuantity[4]=std::stoi(input);
                break;
            case 31:
                unitsQuantity[5]=std::stoi(input);
                break;
            case 32:
                unitsQuantity[6]=std::stoi(input);
                break;
            case 33:
                unitsQuantity[7]=std::stoi(input);
                break;
            case 34:
                unitsQuantity[8]=std::stoi(input);
                break;
            default:
                if(!input.empty()){
                    unitsLeft.push_back(std::stoi(input));
                }
        }
        line_nr++;
    }
    if(!unitsLeft.empty()){
        b_window.set_remaining_time(unitsLeft);
    }
    b_window.set_units_quantity(unitsQuantity);
    s_path.close();
}

void
SaveSystem::save_game(const std::string &save_path, std::array<int, 10> &levels, HandleTownHall &th_window,
                      std::string &name, int &human, int &wood, int &rock, int &money, int &iron,
                      HandleBarracks &b_window) {
    //opening save_
    std::fstream file;
    file.open(save_path, std::ios::out);

    //save_ all data
    //levels_
    file << name << std::endl;
    for(auto &j:levels)
        file << j << std::endl;

    //resources;
    file << human << std::endl;
    file << wood << std::endl;
    file << rock << std::endl;
    file << money << std::endl;
    file << iron << std::endl;

    //upgrades time left
    for(int i=0; i<10; i++)
        file << th_window.get_ub_left(i) << std::endl;

    //quantity of units
    for(auto &i:b_window.get_units_quantity()){
        file << i << std::endl;
    }

    //units training time left
    for(auto &i:b_window.get_remaining_time()){
        file << i << std::endl;
    }

    file.close();
}
