#include "SoundSource.h"

#ifdef OPENAL
	SoundSource::SoundSource() {
		alGenSources(1, &source);
		alSourcef(source, AL_PITCH, pitch);
		alSourcef(source, AL_GAIN, gain);
		alSource3f(source, AL_POSITION, position[0], position[1], position[2]);
		alSource3f(source, AL_VELOCITY, velocity[0], velocity[1], velocity[2]);
		alSourcei(source, AL_LOOPING, loop);
		alSourcei(source, AL_BUFFER, buffer);
	}

	SoundSource::~SoundSource() {
		alDeleteSources(1, &source);
	}

	ALint SoundSource::GetState() {
		ALint state = 0;
		alGetSourcei(source, AL_SOURCE_STATE, &state);
		return state;
	}

	void SoundSource::Play(const ALuint buffer_to_play) {
		buffer = buffer_to_play;
		alSourcei(source, AL_BUFFER, static_cast<ALint>(buffer));
		alSourcePlay(source);
	}
#endif