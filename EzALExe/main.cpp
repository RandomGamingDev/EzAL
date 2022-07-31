#include <iostream>
#include <thread>

#include "EzAL.h"

#include <glad/glad.h>

int main() {
	while (true) {
		SoundDevice mysounddevice(NULL);

		SoundBuffer sound(SoundBuffer::GetOggData("./test.ogg"));

		SoundSource speaker;

		ALuint buffers[] = { sound.ID };
		speaker.buffersSize = 1;
		speaker.buffers = buffers;
		speaker.QueueBuffers();
		speaker.Play();
		while (speaker.GetState(AL_SOURCE_STATE) == AL_PLAYING);

		std::cout << "got here\n";
	}
}