// Includes
#include <iostream>
#include <thread>

#include "EzAL.h"

#include <glad/glad.h>

int main() {
	while (true) {
		SoundDevice mysounddevice(NULL);
                
                // Set audio file
		SoundData data = SoundBuffer::GetOggData("./test.ogg");
		SoundBuffer sound(data);
		free(data.data);
    
		SoundSource speaker;

                // Configure buffer and play
		ALuint* buffers = new ALuint[1] {sound.ID};
		speaker.buffersSize = 1;
		speaker.buffers = buffers;
		speaker.QueueBuffers();
		speaker.Play();
		while (speaker.GetState(AL_SOURCE_STATE) == AL_PLAYING);

		std::cout << "got here\n";
	}
}
