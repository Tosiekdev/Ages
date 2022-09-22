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

add_executable(Ages1 src/main.cpp src/needed.cpp headers/needed.h src/ui/button.cpp headers/ui/button.h src/ui/label.cpp headers/ui/label.h src/ui/textbox.cpp headers/ui/textbox.h src/ui/tablet.cpp headers/ui/tablet.h src/ui/clickable.cpp headers/ui/clickable.h src/buildings.cpp headers/buildings.h src/game.cpp src/load.cpp src/create.cpp src/ui/obstacle.cpp headers/ui/obstacle.h headers/constants.h src/upgradetablet.cpp headers/upgradetablet.h src/buildings_windows/handlebuildings.cpp headers/buildings-windows/handlebuildings.h src/buildings_windows/handlestonepit.cpp headers/buildings-windows/handlestonepit.h src/buildings_windows/handlefarm.cpp headers/buildings-windows/handlefarm.h src/buildings_windows/handlelumbermill.cpp headers/buildings-windows/handlelumbermill.h headers/handlewindow.h src/handlemenu.cpp headers/handlemenu.h src/exitwindow.cpp headers/exitwindow.h src/buildings_windows/handletownhall.cpp headers/buildings-windows/handletownhall.h src/buildings_windows/handlewarehouse.cpp headers/buildings-windows/handlewarehouse.h src/handlewosaving.cpp headers/handlewosaving.h src/savesystem.cpp headers/savesystem.h src/buildings_windows/handleacademy.cpp headers/buildings-windows/handleacademy.h src/buildings_windows/handlebarracks.cpp headers/buildings-windows/handlebarracks.h src/handlegame.cpp headers/handlegame.h src/buildings_windows/handlechurch.cpp headers/buildings-windows/handlechurch.h headers/units/soldier.h src/units/swordsman.cpp headers/units/swordsman.h headers/battle.h src/units/soldier.cpp src/units/spearman.cpp headers/units/spearman.h src/units/archer.cpp headers/units/archer.h src/units/heavycavalery.cpp headers/units/heavycavalery.h src/units/lightcavalry.cpp headers/units/lightcavalry.h src/units/knight.cpp headers/units/knight.h src/units/crossbowman.cpp headers/units/crossbowman.h src/units/billman.cpp headers/units/billman.h src/units/axeman.cpp headers/units/axeman.h src/trainingwindow.cpp headers/trainingwindow.h src/buildings_windows/handlebank.cpp headers/buildings-windows/handlebank.h src/buildings_windows/handleironmine.cpp headers/buildings-windows/handleironmine.h)

find_package (Threads REQUIRED)

target_link_libraries(Ages1
        ${CMAKE_THREAD_LIBS_INIT}
        sfml-graphics sfml-window sfml-system
        )
