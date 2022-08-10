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

struct SoundData {
	ALenum format;
	short* data;
	ALsizei size;
	ALsizei freq;

	SoundData(ALenum format = (ALenum)nullptr, short* data = nullptr, ALsizei size = (ALsizei)nullptr, ALsizei freq = (ALsizei)nullptr) {
		this->format = format;
		this->data = data;
		this->size = size;
		this->freq = freq;
	}
};

class SoundBuffer {
public:
	#ifdef OPENAL
	ALuint ID;
	#endif

	SoundBuffer(SoundData data);
	~SoundBuffer();

	void Init(SoundData data);
	static void Init(ALuint* ID, SoundData data);
	void StoreBuffer(SoundData data);
	static void StoreBuffer(ALuint* ID, SoundData data);
	static SoundData GetOggData(const char* filename);
	void Delete();
	static void Delete(ALuint* ID);
};

#endif