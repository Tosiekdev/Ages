cmake_minimum_required(VERSION 3.13)
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

add_executable(Ages1 main.cpp needed.cpp needed.h button.cpp button.h label.cpp label.h textbox.cpp textbox.h tablet.cpp tablet.h clickable.cpp clickable.h buildings.cpp buildings.h game.cpp load.cpp create.cpp obstacle.cpp obstacle.h constants.h town_hall.cpp Upgrade_tablet.cpp Upgrade_tablet.h farm.cpp)
target_link_libraries (Ages1 sfml-graphics sfml-window sfml-system)

find_package (Threads REQUIRED)

target_link_libraries(Ages1
        ${CMAKE_THREAD_LIBS_INIT}
        sfml-graphics sfml-window sfml-system
        )