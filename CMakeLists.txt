cmake_minimum_required(VERSION 4.1)
project(twobody_problem)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(twobody_problem
        src/main.cpp
        src/physics.cpp
        include/physics.h
        include/stellar_object.h
        src/verlet.cpp
        include/verlet.h
        src/world.cpp
        include/world.h
)

target_include_directories(twobody_problem PUBLIC include)
target_include_directories(twobody_problem PUBLIC src)