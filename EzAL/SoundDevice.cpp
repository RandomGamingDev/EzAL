#include "SoundDevice.h"

#ifdef OPENAL
	SoundDevice::SoundDevice(const ALCchar* deviceName) {
		device = alcOpenDevice(deviceName);
		if (!device) {
			std::cout << "ERROR: Failed to get the device!\n";
			return;
		}
		context = alcCreateContext(device, nullptr);
		if (!context) {
			std::cout << "ERROR: Failed to create the contesxt!\n";
			return;
		}
		if (!alcMakeContextCurrent(context)) {
			std::cout << "ERROR: Failed to make the context current!\n";
			return;
		}
	}

	SoundDevice::~SoundDevice() {
		alcMakeContextCurrent(nullptr);
		alcDestroyContext(context);
		alcCloseDevice(device);
	}
#endif