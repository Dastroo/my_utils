add_executable(UnitTests main.cpp unit_tests.cpp doctest.h)
target_link_libraries(UnitTests my_utils)