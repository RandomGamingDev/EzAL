#ifndef SOUND_BUFFER_HEADER
#define SOUND_BUFFER_HEADER

#ifdef OPENAL
#include <AL/alext.h>
#endif

#include <iostream>

#include <sndfile.h>
#include <inttypes.h>
#include <array>
#include <vector>

class SoundBuffer {
public:
	SoundBuffer(const char* filename);
	~SoundBuffer();

	uint32_t buffer = 0;
};

#endif