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
		if (!alcMakeContextCurrent(nullptr)) {
			std::cout << "Failed to set the current context to nullptr";
			return;
		}

		alcDestroyContext(context);
		if (context) {
			std::cout << "Failed to destroy the context";
			return;
		}

		if (!alcCloseDevice(device)) {
			std::cout << "Failed to close the sound device";
			return;
		}
	}
#endif
