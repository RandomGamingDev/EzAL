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
	ALCdevice* device;
	ALCcontext* context;
	#endif

	#ifdef OPENAL
	SoundDevice(const ALCchar* deviceName);
	#endif
	~SoundDevice();

	#ifdef OPENAL
	void Init(const ALCchar* deviceName);
	static void Init(const ALCchar* deviceName, ALCdevice** device, ALCcontext** context);
	#endif
	void Delete();
	#ifdef OPENAL
	static void Delete(ALCdevice* device, ALCcontext* context);
	#endif
};

#endif