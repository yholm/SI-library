cmake_minimum_required(VERSION 3.31.5)
project(si_units VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(si_units INTERFACE)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

target_include_directories(si_units INTERFACE "${CMAKE_SOURCE_DIR}/include")

add_executable(arithmetic_tests tests/si_arithmetics.cpp)
target_link_libraries(arithmetic_tests PRIVATE si_units)

add_executable(literal_tests tests/si_literals.cpp)
target_link_libraries(literal_tests PRIVATE si_units)

add_executable(string_tests tests/si_string.cpp)
target_link_libraries(string_tests PRIVATE si_units)

add_test(NAME AritmeticTests COMMAND arithmetic_tests)
add_test(NAME LiteralTests COMMAND literal_tests)
add_test(NAME StringTests COMMAND string_tests)

install(TARGETS si_units EXPORT SIUnitsConfig)
install(EXPORT SIUnitsConfig DESTINATION lib/cmake/si_units)
install(DIRECTORY include/ DESTINATION include)

install(DIRECTORY include/ DESTINATION include)
install(EXPORT SIUnitsConfig DESTINATION lib/cmake/si_units)

include(CPack)
