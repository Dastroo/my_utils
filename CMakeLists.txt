cmake_minimum_required(VERSION 3.16)
project(my_utils)

set(CMAKE_CXX_STANDARD 17)

enable_testing()
add_subdirectory(unit_tests)

add_library(${PROJECT_NAME}
        include/StringUtils.h src/StringUtils.cpp
        include/OSUtils.h src/OSUtils.cpp
        include/ArgumentUtils.h
        include/Time.h
        include/Bit.h src/Bit.cpp
        )

#   INSTALL
if (UNIX AND NOT APPLE)
    include(GNUInstallDirs)
    install(TARGETS ${PROJECT_NAME})
    install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})
endif ()