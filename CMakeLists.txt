cmake_minimum_required(VERSION 3.16)
project(my_utils)

set(CMAKE_CXX_STANDARD 17)

enable_testing()
add_subdirectory(unit_tests)

add_library(my_utils include/StringUtils.h include/OSUtils.h include/ArgumentUtils.h src/StringUtils.cpp src/OSUtils.cpp include/Time.h)

#   INSTALL
if (UNIX AND NOT APPLE)
    include(GNUInstallDirs)
    install(TARGETS ${PROJECT_NAME})
    install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})
endif ()