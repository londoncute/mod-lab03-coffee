cmake_minimum_required(VERSION 3.10)
project(mod-lab03-coffee)

set(CMAKE_CXX_STANDARD 17)

add_library(Automata STATIC
    src/Automata.cpp
)

add_executable(coffee_machine
    src/main.cpp
)
target_link_libraries(coffee_machine Automata)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

add_executable(mod-lab03-coffee.test test/tests.cpp)

set_target_properties(mod-lab03-coffee.test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test
)

target_link_libraries(mod-lab03-coffee.test
    Automata
    GTest::gtest_main
)

# 🧪 Регистрируем тест
add_test(NAME mod-lab03-coffee.test
         COMMAND ${CMAKE_BINARY_DIR}/test/mod-lab03-coffee.test)
