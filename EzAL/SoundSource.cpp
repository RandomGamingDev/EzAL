#include "SoundSource.h"

#ifdef OPENAL
	SoundSource::SoundSource() {
		alGenSources(1, &source);
		UpdateSource();
	}

	SoundSource::~SoundSource() {
		alDeleteSources(1, &source);
	}

	void SoundSource::UpdateSource() {
		UpdatePitch();
		UpdateGain();
		UpdatePosition();
		UpdateVelocity();
		UpdateLooping();
		UpdateBuffer();
	}

	void SoundSource::UpdatePitch() {
		alSourcef(source, AL_PITCH, pitch);
	}

	void SoundSource::UpdateGain() {
		alSourcef(source, AL_GAIN, gain);
	}

	void SoundSource::UpdatePosition() {
		alSource3f(source, AL_POSITION, position[0], position[1], position[2]);
	}

	void SoundSource::UpdateVelocity() {
		alSource3f(source, AL_VELOCITY, velocity[0], velocity[1], velocity[2]);
	}

	void SoundSource::UpdateLooping() {
		alSourcei(source, AL_LOOPING, loop);
	}

	void SoundSource::UpdateBuffer() {
		alSourcei(source, AL_BUFFER, buffer);
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