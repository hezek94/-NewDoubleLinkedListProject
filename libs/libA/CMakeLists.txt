add_library(libA SHARED math_lib.cpp)
target_include_directories(libA PUBLIC include)
target_link_libraries(libA PUBLIC libB)