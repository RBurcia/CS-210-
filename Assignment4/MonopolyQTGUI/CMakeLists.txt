cmake_minimum_required(VERSION 3.16)
project(LinkedListMonopoly LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(Monopoly
    main.cpp
    mainwindow.cpp
    mainwindow.h
    board.h
    game.h 
)

target_link_libraries(Monopoly PRIVATE Qt6::Widgets)