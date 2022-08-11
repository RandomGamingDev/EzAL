cmake_minimum_required (VERSION 3.8)

find_package(OpenAL CONFIG REQUIRED)
find_package(SndFile CONFIG REQUIRED)

add_library(EzAL EzALlibs.h EzAL.h ALlibs.h SoundBuffer.cpp SoundBuffer.h SoundDevice.cpp SoundDevice.h SoundSource.cpp SoundSource.h EzALlibs.h)

target_compile_definitions(EzAL PUBLIC OPENAL)

target_link_libraries(EzAL PUBLIC OpenAL::OpenAL)
target_link_libraries(EzAL PUBLIC SndFile::sndfile)