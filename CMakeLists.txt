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

# Тестовый исполняемый файл
add_executable(automata_test
    test/tests.cpp
)
target_link_libraries(automata_test 
    Automata 
    GTest::GTest 
    GTest::Main
)

# Указываем правильное имя для тестов
add_test(
    NAME automata_test
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/automata_test
)
