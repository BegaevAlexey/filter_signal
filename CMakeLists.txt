cmake_minimum_required(VERSION 3.16)
project(filter_signal)

set(CMAKE_CXX_STANDARD 17)


set(SOURCE
        )

set(HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/utils.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/utils.h
        )

set(LIBS
        config++
        )

set(INCLUDE_DIR
        ${CMAKE_CURRENT_SOURCE_DIR}/src/
        )

add_executable(${PROJECT_NAME} main.cpp  ${SOURCE} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${LIBS} ${OpenMP_CXX_FLAGS})