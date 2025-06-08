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

# Тесты
enable_testing()
find_package(GTest REQUIRED)
add_executable(automata_tests
    test/tests.cpp
)
target_link_libraries(automata_tests Automata GTest::GTest GTest::Main)
add_test(NAME automata_tests COMMAND automata_tests)
