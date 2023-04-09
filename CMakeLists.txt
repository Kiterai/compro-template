project(compro)

add_executable(compro main.cpp)
add_executable(test test.cpp)
add_executable(tool tool.cpp)

target_include_directories(compro PRIVATE ./libs)
target_include_directories(test PRIVATE ./libs)

set_property(TARGET compro PROPERTY CXX_STANDARD 17)
set_property(TARGET test PROPERTY CXX_STANDARD 17)
set_property(TARGET tool PROPERTY CXX_STANDARD 20)
