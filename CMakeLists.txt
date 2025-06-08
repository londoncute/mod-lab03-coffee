cmake_minimum_required(VERSION 3.10)
project(mod-lab03-coffee)

set(CMAKE_CXX_STANDARD 17)

# Главная библиотека
add_library(Automata STATIC
    src/Automata.cpp
)

# Основной исполняемый файл
add_executable(coffee_machine
    src/main.cpp
)
target_link_libraries(coffee_machine Automata)

# Тесты
find_package(GTest REQUIRED)
add_executable(tests
    test/tests.cpp
)
target_link_libraries(tests Automata GTest::GTest GTest::Main)
