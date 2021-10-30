# CMakeList.txt : CMake project for CAcpp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.11)

project ("CAcpp")

# Add source to this project's executable.
set(BOOST_ROOT "D:/local/boost_1_77_0")
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.77.0 COMPONENTS) 

if(Boost_FOUND)
    add_executable (CASimulator "CAcpp.cpp" "CAcpp.h") 
    target_include_directories(CASimulator PUBLIC ${Boost_INCLUDE_DIRS}) 
    target_link_libraries(CASimulator ${Boost_LIBRARIES})
endif()


# TODO: Add tests and install targets if needed.
