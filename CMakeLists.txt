project(compro)

add_executable(compro main.cpp)
add_executable(tool tool.cpp)

set_property(TARGET compro PROPERTY CXX_STANDARD 17)
set_property(TARGET tool PROPERTY CXX_STANDARD 20)
