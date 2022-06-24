cmake_minimum_required (VERSION 3.8)

add_executable(EzALExe main.cpp)

target_include_directories(EzALExe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../EzAL)
target_link_libraries(EzALExe PRIVATE EzAL)