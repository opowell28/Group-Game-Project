cmake_minimum_required(VERSION 3.12)
project(4__groupProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(4__groupProject main.cpp Weapons/Weapon.cpp Weapons/Weapon.h Movement/MoveHandler.cpp Movement/MoveHandler.h Combat/CombatHandler.cpp Combat/CombatHandler.h Character/Character.cpp Character/Character.h)