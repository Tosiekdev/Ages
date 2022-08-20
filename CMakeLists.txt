cmake_minimum_required(VERSION 3.21)
project(Ages1)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "/home/tosiek/Documents/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "/home/tosiek/Documents/SFML-2.5.1/lib")
set(SFML_DIR "/home/tosiek/Documents/SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(Ages1 src/main.cpp src/needed.cpp headers/needed.h src/button.cpp headers/button.h src/label.cpp headers/label.h src/textbox.cpp headers/textbox.h src/tablet.cpp headers/tablet.h src/Clickable.cpp headers/Clickable.h src/buildings.cpp headers/buildings.h src/game.cpp src/load.cpp src/create.cpp src/obstacle.cpp headers/obstacle.h headers/constants.h src/town_hall.cpp src/Upgrade_tablet.cpp headers/Upgrade_tablet.h src/farm.cpp src/lumber.cpp src/stone.cpp src/buildings_windows/HandleBuildings.cpp headers/HandleBuildings.h src/buildings_windows/HandleStonePit.cpp headers/HandleStonePit.h src/buildings_windows/HandleFarm.cpp headers/HandleFarm.h src/buildings_windows/HandleLumberMill.cpp headers/HandleLumberMill.h headers/HandleWindow.h src/HandleManu.cpp headers/HandleManu.h src/ExitWindow.cpp headers/ExitWindow.h src/buildings_windows/HandleTownHall.cpp headers/HandleTownHall.h src/buildings_windows/HandleWarehouse.cpp headers/HandleWarehouse.h src/warehouse.cpp src/HandleWoSaving.cpp headers/HandleWoSaving.h src/SaveSystem.cpp headers/SaveSystem.h src/buildings_windows/HandleAcademy.cpp headers/HandleAcademy.h src/academy.cpp src/buildings_windows/HandleBarracks.cpp headers/HandleBarracks.h src/barracks.cpp src/HandleGame.cpp headers/HandleGame.h src/buildings_windows/HandleChurch.cpp headers/HandleChurch.h src/church.cpp headers/Soldier.h src/SwordsMen.cpp headers/SwordsMen.h headers/Battle.h src/Soldier.cpp src/spearman.cpp headers/spearman.h)
target_link_libraries (Ages1 sfml-graphics sfml-window sfml-system)

find_package (Threads REQUIRED)

target_link_libraries(Ages1
        ${CMAKE_THREAD_LIBS_INIT}
        sfml-graphics sfml-window sfml-system
        )
