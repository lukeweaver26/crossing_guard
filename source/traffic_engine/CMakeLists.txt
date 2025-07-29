add_library(traffic-engine 
    STATIC 
    	src/traffic_engine.cpp
		src/hardbody.cpp
)

target_include_directories(traffic-engine 
	PUBLIC include
)

target_link_libraries(traffic-engine 
	PUBLIC common 
	       box2d
)