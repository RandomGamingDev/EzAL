#include <iostream>
#include <thread>

#include "EzAL.h"

int main() {
	while (true) {
		SoundDevice mysounddevice(NULL);

		SoundBuffer sound(SoundBuffer::GetOggData("./test.ogg"));

		SoundSource speaker;

		speaker.Play(sound.buffer);
		while (speaker.GetState() == AL_PLAYING);

		std::cout << "got here\n";
	}
}