cmake_minimum_required(VERSION 3.13)
project(OOP_PJ)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOP_PJ main.cpp console/ConsoleBoardUtil.cpp console/ConsoleBoardUtil.h Checkerboard.cpp Checkerboard.h Position.cpp Position.h Icon.h Session.cpp Session.h Player.cpp Player.h)