cmake_minimum_required(VERSION 3.26)
project(Advanced_programming_Plants_vs_Zombies)

set(CMAKE_CXX_STANDARD 17)

include_directories(./easyx/include)
link_directories(./easyx/lib64)
link_libraries(libeasyx.a)

add_executable(Advanced_programming_Plants_vs_Zombies main.cpp)


target_link_libraries(Advanced_programming_Plants_vs_Zombies
        easyx
        winmm
)

