cmake_minimum_required(VERSION 3.15...4.0)
project(CrossingGuard VERSION 0.1.0
		      DESCRIPTION "Autonomous Traffic Simulation"
		      LANGUAGES CXX)


add_subdirectory(traffic_engine)

add_executable(crossing-guard main.cpp)
target_link_libraries(crossing-guard PUBLIC traffic-engine)
 
