#ifndef SOUND_DEVICE_HEADER
#define SOUND_DEVICE_HEADER

#ifdef OPENAL
#include <AL\al.h>
#include <AL\alc.h>
#endif

#include <iostream>

class SoundDevice {
public:
	#ifdef OPENAL
	SoundDevice(const ALCchar* deviceName);
	#endif
	~SoundDevice();

	#ifdef OPENAL
	ALCdevice* device;
	ALCcontext* context;
	#endif
};

#endif