cmake_minimum_required(VERSION 3.10)
project(mod-lab03-coffee)

set(CMAKE_CXX_STANDARD 17)

# Основной проект
add_executable(coffee_machine
    src/Automata.cpp
    src/main.cpp
)

# Тесты
find_package(GTest REQUIRED)
add_executable(tests
    test/tests.cpp
    src/Automata.cpp
)
target_link_libraries(tests GTest::GTest GTest::Main)
