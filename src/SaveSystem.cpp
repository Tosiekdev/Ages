//
// Created by tosiek on 16.02.2022.
//

#include "../headers/SaveSystem.h"

void SaveSystem::load_save(std::string save_path, std::array<int,8> &levels,HandleTownHall &th_window,std::string &name,int &human,int &wood,int &rock,std::array<buildings,8> &b){
    std::fstream s_path;
    s_path.open(save_path,std::ios::in);
    std::string input;
    int line_nr=0;
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
            case 8:{
                levels[7]=stoi(input);//warehouse
                for(int i=0; i<8; i++) b[i].set_level(levels[i]);
            }
                break;
                //resources
            case 9:
                human=stoi(input);
                break;
            case 10:
                wood=stoi(input);
                break;
            case 11:
                rock=stoi(input);
                break;
            case 12:
                th_window.set_ub_left(0, stof(input),levels[6]);
                break;
            case 13:
                th_window.set_ub_left(1,stof(input),levels[6]);
                break;
            case 14:
                th_window.set_ub_left(2,stof(input),levels[6]);
                break;
            case 15:
                th_window.set_ub_left(3,stof(input),levels[6]);
                break;
            case 16:
                th_window.set_ub_left(4,stof(input),levels[6]);
                break;
            case 17:
                th_window.set_ub_left(5,stof(input),levels[6]);
                break;
            case 18:
                th_window.set_ub_left(6,stof(input),levels[6]);
                break;
            case 19:
                th_window.set_ub_left(7,stof(input),levels[6]);
                break;
        }
        line_nr++;
    }
    s_path.close();
}

void
SaveSystem::save_game(std::string save_path, std::array<int, 8> levels, HandleTownHall &th_window, std::string &name, int &human,int &wood, int &rock){
    //opening save
    std::fstream file;
    file.open(save_path, std::ios::out);

    //save all data
    //levels
    file << name << std::endl;
    for(auto &j:levels)
        file << j << std::endl;

    //resources;
    file << human << std::endl;
    file << wood << std::endl;
    file << rock << std::endl;

    //upgrades time left
    for(int i=0; i<8; i++)
        file << th_window.get_ub_left(i) << std::endl;

    file.close();
}
