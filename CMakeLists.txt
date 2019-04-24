cmake_minimum_required(VERSION 3.12)
project(4_groupProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(4_groupProject main.cpp Weapons/Weapon.cpp Weapons/Weapon.h Handlers/Movement/MoveHandler.cpp Handlers/Movement/MoveHandler.h Handlers/Combat/CombatHandler.cpp Handlers/Combat/CombatHandler.h Character/Character.cpp Character/Character.h Player/Player.cpp Player/Player.h Character/Enemy.cpp Character/Enemy.h Classes.cpp Classes.h)