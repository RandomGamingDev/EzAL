#include "SoundDevice.h"

#ifdef OPENAL
	SoundDevice::SoundDevice(const ALCchar* deviceName) {
		Init(deviceName);
	}

	SoundDevice::~SoundDevice() {
		Delete();
	}

	void SoundDevice::Init(const ALCchar* deviceName) {
		Init(deviceName, &device, &context);
	}

	void SoundDevice::Init(const ALCchar* deviceName, ALCdevice** device, ALCcontext** context) {
		*device = alcOpenDevice(deviceName);
		if (!*device) {
			std::cout << "ERROR: Failed to get the device!\n";
			return;
		}
		*context = alcCreateContext(*device, nullptr);
		if (!alcMakeContextCurrent(*context)) {
			std::cout << "ERROR: Failed to make the context current!\n";
			return;
		}
	}

	void SoundDevice::Delete() {
		Delete(device, context);
	}

	void SoundDevice::Delete(ALCdevice* device, ALCcontext* context) {
		alcMakeContextCurrent(nullptr);
		alcDestroyContext(context);
		alcCloseDevice(device);
	}
#endif
