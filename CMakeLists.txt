cmake_minimum_required(VERSION 3.10)
project(mod-lab03-coffee)

set(CMAKE_CXX_STANDARD 17)

# Основная библиотека
add_library(Automata STATIC
    src/Automata.cpp
)

# Основная программа
add_executable(coffee_machine
    src/main.cpp
)
target_link_libraries(coffee_machine Automata)

add_executable(mod-lab03-coffee.test test/tests.cpp)
target_link_libraries(mod-lab03-coffee.test Automata GTest::GTest GTest::Main)
add_test(NAME mod-lab03-coffee.test COMMAND mod-lab03-coffee.test)
