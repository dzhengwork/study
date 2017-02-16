cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(GTest REQUIRED)
include_directories(
	${GTEST_INCLUDE_DIRS}
    ../
)

add_executable(runtests bsttest.cpp)
target_link_libraries(
    runtests 
    ${GTEST_LIBRARIES} 
    pthread
)
