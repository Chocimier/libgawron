add_executable(demo main.cpp)
set_property(TARGET demo PROPERTY CXX_STANDARD 11)

target_include_directories(demo PUBLIC gawron)
target_link_libraries(demo LINK_PUBLIC gawron)
