cmake_minimum_required(VERSION 3.23)
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

add_executable(Ages1 src/main.cpp src/needed.cpp headers/needed.h src/button.cpp headers/button.h src/label.cpp headers/label.h src/textbox.cpp headers/textbox.h src/tablet.cpp headers/tablet.h src/clickable.cpp headers/clickable.h src/buildings.cpp headers/buildings.h src/game.cpp src/load.cpp src/create.cpp src/obstacle.cpp headers/obstacle.h headers/constants.h src/town_hall.cpp src/upgradetablet.cpp headers/upgradetablet.h src/farm.cpp src/lumber.cpp src/stone.cpp src/buildings_windows/handlebuildings.cpp headers/handlebuildings.h src/buildings_windows/handlestonepit.cpp headers/handlestonepit.h src/buildings_windows/handlefarm.cpp headers/handlefarm.h src/buildings_windows/handlelumbermill.cpp headers/handlelumbermill.h headers/handlewindow.h src/handlemenu.cpp headers/handlemenu.h src/exitwindow.cpp headers/exitwindow.h src/buildings_windows/handletownhall.cpp headers/handletownhall.h src/buildings_windows/handlewarehouse.cpp headers/handlewarehouse.h src/warehouse.cpp src/handlewosaving.cpp headers/handlewosaving.h src/savesystem.cpp headers/savesystem.h src/buildings_windows/handleacademy.cpp headers/handleacademy.h src/academy.cpp src/buildings_windows/handlebarracks.cpp headers/handlebarracks.h src/barracks.cpp src/handlegame.cpp headers/handlegame.h src/buildings_windows/handlechurch.cpp headers/handlechurch.h src/church.cpp headers/soldier.h src/swordsman.cpp headers/swordsman.h headers/battle.h src/soldier.cpp src/spearman.cpp headers/spearman.h src/archer.cpp headers/archer.h src/heavycavalery.cpp headers/heavycavalery.h src/lightcavalry.cpp headers/lightcavalry.h src/knight.cpp headers/knight.h)
target_link_libraries (Ages1 sfml-graphics sfml-window sfml-system)

find_package (Threads REQUIRED)

target_link_libraries(Ages1
        ${CMAKE_THREAD_LIBS_INIT}
        sfml-graphics sfml-window sfml-system
        )
