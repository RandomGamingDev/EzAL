#ifndef SOUND_SOURCE_HEADER
#define SOUND_SOURCE_HEADER

#ifdef OPENAL
#include <AL\al.h>
#endif

class SoundSource {
public:
	SoundSource();
	~SoundSource();
	
	#ifdef OPENAL
	ALint GetState();
	void Play(const ALuint buffer_to_play);
	#endif

	#ifdef OPENAL
	ALuint source;
	ALuint buffer = 0;
	#endif
	float pitch = 1.0f;
	float gain = 1.0f;
	float position[3] = { 0, 0, 0 };
	float velocity[3] = { 0, 0, 0 };
	bool loop = false;
};

#endif