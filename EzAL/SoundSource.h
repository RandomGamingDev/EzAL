#ifndef SOUND_SOURCE_HEADER
#define SOUND_SOURCE_HEADER

#include <array>

#ifdef OPENAL
#include <AL\al.h>
#endif

class SoundSource {
public:
	SoundSource();
	SoundSource(
		ALuint buffer,
		ALfloat pitch,
		ALfloat gain,
		std::array<ALfloat, 3> position,
		std::array<ALfloat, 3> velocity,
		ALboolean loop
	);
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
	
	ALuint source;
	ALuint buffer;
	ALfloat pitch = 1.0f;
	ALfloat gain = 1.0f;
	std::array<ALfloat, 3> position = { 0, 0, 0 };
	std::array<ALfloat, 3> velocity = { 0, 0, 0 };
	ALboolean loop = false;
	#endif
};

#endif