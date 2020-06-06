cmake_minimum_required(VERSION 3.15)
project(Renju)

set(CMAKE_CXX_STANDARD 14)

add_executable(Renju main.cpp ChessBoard.cpp ChessBoard.h ChessMan.cpp ChessMan.h Rules.cpp Rules.h Player.cpp Player.h Game.cpp Game.h Manipulation.cpp Manipulation.h Core.cpp Core.h)