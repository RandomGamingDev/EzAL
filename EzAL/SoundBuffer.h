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

struct BufferData {
	ALenum format;
	short* data;
	ALsizei size;
	ALsizei freq;

	BufferData(ALenum format = (ALenum)nullptr, short* data = nullptr, ALsizei size = (ALsizei)nullptr, ALsizei freq = (ALsizei)nullptr) {
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

	SoundBuffer(BufferData data);
	~SoundBuffer();

	void Init(BufferData data);
	static void Init(ALuint* ID, BufferData data);
	void StoreBuffer(BufferData data);
	static void StoreBuffer(ALuint* ID, BufferData data);
	static BufferData GetOggData(const char* filename);
	void Delete();
	static void Delete(ALuint* ID);
};

#endif