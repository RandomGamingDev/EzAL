#include "SoundSource.h"

#ifdef OPENAL
	SoundSource::SoundSource() {
		Init();
	}

	SoundSource::SoundSource(
		ALsizei buffersSize,
		ALuint* buffers,
		ALfloat pitch,
		ALfloat gain,
		std::array<ALfloat, 3> position,
		std::array<ALfloat, 3> velocity,
		ALboolean loop
	) {
		Init(
			buffersSize,
			buffers,
			pitch,
			gain,
			position,
			velocity,
			loop
		);
	}
	
	SoundSource::~SoundSource() {
		Delete();
	}
	
	void SoundSource::Init() {
		Init(&ID);
	}

	void SoundSource::Init(ALuint* ID) {
		alGenSources(1, ID);
	}

	void SoundSource::Init(
		ALsizei buffersSize,
		ALuint* buffers,
		ALfloat pitch,
		ALfloat gain,
		std::array<ALfloat, 3> position,
		std::array<ALfloat, 3> velocity,
		ALboolean loop
	) {
	}

	void SoundSource::Init(
		ALuint* ID,
		ALsizei buffersSize,
		ALuint* buffers,
		ALfloat pitch,
		ALfloat gain,
		std::array<ALfloat, 3> position,
		std::array<ALfloat, 3> velocity,
		ALboolean loop,
		ALsizei* buffersSizeVar,
		ALuint** buffersVar,
		ALfloat* pitchVar,
		ALfloat* gainVar,
		std::array<ALfloat, 3>* positionVar,
		std::array<ALfloat, 3>* velocityVar,
		ALboolean* loopVar
	) {
		*buffersSizeVar = buffersSize;
		*buffersVar = buffers;
		*pitchVar = pitch;
		*gainVar = gain;
		*positionVar = position;
		*velocityVar = velocity;
		*loopVar = loop;
		alGenSources(1, ID);
		UpdateSource(
			*ID,
			buffersSize,
			buffers,
			pitch,
			gain,
			position,
			velocity,
			loop
		);
	}

	void SoundSource::UpdateSource() {
		UpdateSource(
			ID,
			buffersSize,
			buffers,
			pitch,
			gain,
			position,
			velocity,
			loop
		);
	}

	void SoundSource::UpdateSource(
		ALuint ID,
		ALsizei buffersSize,
		ALuint* buffers,
		ALfloat pitch,
		ALfloat gain,
		std::array<ALfloat, 3> position,
		std::array<ALfloat, 3> velocity,
		ALboolean loop
	) {
		UpdatePitch(ID, pitch);
		UpdateGain(ID, gain);
		UpdatePosition(ID, position);
		UpdateVelocity(ID, velocity);
		UpdateLoop(ID, loop);
		QueueBuffers(ID, buffersSize, buffers);
	}

	void SoundSource::UpdatePitch() {
		UpdatePitch(ID, pitch);
	}

	void SoundSource::UpdatePitch(ALuint ID, ALfloat pitch) {
		alSourcef(ID, AL_PITCH, pitch);
	}

	void SoundSource::UpdateGain() {
		UpdateGain(ID, gain);
	}

	void SoundSource::UpdateGain(ALuint ID, ALfloat gain) {
		alSourcef(ID, AL_GAIN, gain);
	}

	void SoundSource::UpdatePosition() {
		UpdatePosition(ID, position);
	}

	void SoundSource::UpdatePosition(ALuint ID, std::array<ALfloat, 3> velocity) {
		alSource3f(ID, AL_POSITION, velocity[0], velocity[1], velocity[2]);
	}

	void SoundSource::UpdateVelocity() {
		UpdateVelocity(ID, velocity);
	}

	void SoundSource::UpdateVelocity(ALuint ID, std::array<ALfloat, 3> velocity) {
		alSource3f(ID, AL_VELOCITY, velocity[0], velocity[1], velocity[2]);
	}

	void SoundSource::UpdateLoop() {
		UpdateLoop(ID, loop);
	}

	void SoundSource::UpdateLoop(ALuint ID, ALboolean loop) {
		alSourcei(ID, AL_LOOPING, loop);
	}

	void SoundSource::QueueBuffers() {
		QueueBuffers(ID, buffersSize, buffers);
	}

	void SoundSource::QueueBuffers(ALuint ID, ALsizei buffersSize, ALuint* buffers) {
		alSourceQueueBuffers(ID, buffersSize, buffers);
	}

	void SoundSource::UnqueueBuffers(ALsizei buffersSize, ALuint* buffers) {
		UnqueueBuffers(ID, buffersSize, buffers);
	}

	void SoundSource::UnqueueBuffers(ALuint ID, ALsizei buffersSize, ALuint* buffers) {
		alSourceUnqueueBuffers(ID, buffersSize, buffers);
	}

	ALint SoundSource::GetState(ALenum toGet) {
		return GetState(ID, toGet);
	}

	ALint SoundSource::GetState(ALuint ID, ALenum toGet) {
		ALint state = 0;
		alGetSourcei(ID, toGet, &state);
		return state;
	}

	void SoundSource::Play() {
		Play(ID);
	}

	void SoundSource::Play(ALuint ID) {
		alSourcePlay(ID);
	}

	void SoundSource::Stop() {
		Stop(ID);
	}

	void SoundSource::Stop(ALuint ID) {
		alSourceStop(ID);
	}

	void SoundSource::Pause() {
		Pause(ID);
	}

	void SoundSource::Pause(ALuint ID) {
		alSourcePause(ID);
	}

	void SoundSource::Rewind() {
		Rewind(ID);
	}

	void SoundSource::Rewind(ALuint ID) {
		alSourceRewind(ID);
	}

	void SoundSource::Delete() {
		Delete(&ID);
	}

	void SoundSource::Delete(ALuint* ID) {
		alDeleteSources(1, ID);
	}
#endif