#ifndef SOUND_SOURCE_HEADER
#define SOUND_SOURCE_HEADER

#include <array>

#ifdef OPENAL
#include <AL\al.h>
#endif

class SoundSource {
public:
	#ifdef OPENAL
	ALuint ID;
	ALsizei buffersSize;
	ALuint* buffers;
	ALfloat pitch = 1.0f;
	ALfloat gain = 1.0f;
	std::array<ALfloat, 3> position = { 0, 0, 0 };
	std::array<ALfloat, 3> velocity = { 0, 0, 0 };
	ALboolean loop = false;
	#endif

	SoundSource();
	SoundSource(
		ALsizei buffersSize,
		ALuint* buffers,
		ALfloat pitch,
		ALfloat gain,
		std::array<ALfloat, 3> position,
		std::array<ALfloat, 3> velocity,
		ALboolean loop
	);
	SoundSource(
		ALfloat pitch,
		ALfloat gain,
		std::array<ALfloat, 3> position,
		std::array<ALfloat, 3> velocity,
		ALboolean loop
	);
	~SoundSource();
	
	void Init();
	static void Init(ALuint* ID);
	void Init(
		ALsizei buffersSize,
		ALuint* buffers,
		ALfloat pitch,
		ALfloat gain,
		std::array<ALfloat, 3> position,
		std::array<ALfloat, 3> velocity,
		ALboolean loop
	);
	static void Init(
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
	);
	void UpdateSource();
	static void UpdateSource(
		ALuint ID,
		ALsizei buffersSize,
		ALuint* buffers,
		ALfloat pitch,
		ALfloat gain,
		std::array<ALfloat, 3> position,
		std::array<ALfloat, 3> velocity,
		ALboolean loop
	);
	void UpdatePitch();
	static void UpdatePitch(ALuint ID, ALfloat pitch);
	void UpdateGain();
	static void UpdateGain(ALuint ID, ALfloat gain);
	void UpdatePosition();
	static void UpdatePosition(ALuint ID, std::array<ALfloat, 3> velocity);
	void UpdateVelocity();
	static void UpdateVelocity(ALuint ID, std::array<ALfloat, 3> velocity);
	void UpdateLoop();
	static void UpdateLoop(ALuint ID, ALboolean loop);
	void QueueBuffers();
	static void QueueBuffers(ALuint ID, ALsizei buffersSize, ALuint* buffers);
	#ifdef OPENAL
	void UnqueueBuffers(ALsizei buffersSize, ALuint* buffers);
	static void UnqueueBuffers(ALuint ID, ALsizei buffersSize, ALuint* buffers);
	ALint GetState(ALenum toGet);
	static ALint GetState(ALuint ID, ALenum toGet);
	#endif
	void Play();
	void Play(ALuint ID);
	void Stop();
	static void Stop(ALuint ID);
	void Pause();
	static void Pause(ALuint ID);
	void Rewind();
	static void Rewind(ALuint ID);
	void Delete();
	static void Delete(ALuint* ID);
};

#endif