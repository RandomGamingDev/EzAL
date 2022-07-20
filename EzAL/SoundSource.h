#ifndef SOUND_SOURCE_HEADER
#define SOUND_SOURCE_HEADER

#include <array>

#ifdef OPENAL
#include <AL\al.h>
#endif

class SoundSource {
public:
	SoundSource();
	~SoundSource();
	
	void UpdateSource();
	void UpdatePitch();
	void UpdateGain();
	void UpdatePosition();
	void UpdateVelocity();
	void UpdateLooping();
	void UpdateBuffer();

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
	std::array<float, 3> position = { 0, 0, 0 };
	std::array<float, 3> velocity = { 0, 0, 0 };
	bool loop = false;
};

#endif