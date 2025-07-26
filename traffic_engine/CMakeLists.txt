add_library(traffic-engine 
    STATIC 
    	src/traffic_engine.cpp
		src/hardbody.cpp
		src/simulation_clock.cpp
)

target_include_directories(
	traffic-engine 
		PUBLIC include
)