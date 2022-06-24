#include <iostream>
#include <thread>

#include "EzAL.h"

int main() {
	while (true) {
		SoundDevice mysounddevice = SoundDevice(NULL);

		SoundBuffer sound = SoundBuffer("./test.ogg");

		SoundSource speaker;

		speaker.Play(sound.buffer);
		while (speaker.GetState() == AL_PLAYING);

		std::cout << "got here\n";
	}
}