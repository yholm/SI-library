cmake_minimum_required(VERSION 3.5.0)
project(si_units VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(si_units src/si_units.cpp)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

target_include_directories(si_units PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(tests tests/si_tests.cpp)
target_link_libraries(tests PRIVATE si_units)

add_test(NAME SIUnitTests COMMAND tests)

include(CPack)
