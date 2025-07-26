cmake_minimum_required(VERSION 3.15...4.0)
project(CrossingGuard VERSION 0.1.0
		      DESCRIPTION "Autonomous Traffic Simulation"
		      LANGUAGES CXX)

add_library(sim-engine STATIC sim_engine/src/sim.cpp)
target_include_directories(sim-engine PUBLIC sim_engine/include)

add_executable(crossing-guard main.cpp)
target_link_libraries(crossing-guard PUBLIC sim-engine)
 
