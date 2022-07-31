cmake_minimum_required (VERSION 3.8)

find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_path(STB_INCLUDE_DIRS stb.h)
find_package(glm CONFIG REQUIRED)

find_package(OpenAL CONFIG REQUIRED)
find_package(SndFile CONFIG REQUIRED)

add_library(EzAL EzALlibs.h EzAL.h ALlibs.h SoundBuffer.cpp SoundBuffer.h SoundDevice.cpp SoundDevice.h SoundSource.cpp SoundSource.h EzALlibs.h)

target_compile_definitions(EzAL PUBLIC OPENAL)

target_link_libraries(EzAL PUBLIC glad::glad)
target_link_libraries(EzAL PUBLIC glfw)
target_include_directories(EzAL PUBLIC ${STB_INCLUDE_DIRS})
target_link_libraries(EzAL PUBLIC glm::glm)

target_link_libraries(EzAL PUBLIC OpenAL::OpenAL)
target_link_libraries(EzAL PUBLIC SndFile::sndfile)