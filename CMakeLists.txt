cmake_minimum_required(VERSION 3.12)
project(4_groupProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(4_groupProject main.cpp Handlers/Movement/MoveHandler.cpp Handlers/Movement/MoveHandler.h Handlers/Combat/CombatHandler.cpp Handlers/Combat/CombatHandler.h Classes.cpp Classes.h)