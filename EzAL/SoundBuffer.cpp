#include "SoundBuffer.h"

#ifdef OPENAL
	SoundBuffer::SoundBuffer(const char* filename) {
		SF_INFO sfinfo;
		SNDFILE* sndfile = sf_open(filename, SFM_READ, &sfinfo);
		if (!sndfile) {
			std::cout << "ERROR: Could not open audio in " << filename << ": " << sf_strerror(sndfile);
			return;
		}
		if (sfinfo.frames < 1 || sfinfo.frames > static_cast<sf_count_t>((INT_MAX / sizeof(short)) / sfinfo.channels)) {
			std::cout << "ERROR: Bad sample count in " << filename << '(' << sfinfo.frames << ")\n";
			sf_close(sndfile);
			return;
		}

		ALenum format = AL_NONE;
		const std::array<ALenum, 4> formats = { AL_FORMAT_MONO16, AL_FORMAT_STEREO16, AL_FORMAT_BFORMAT2D_16, AL_FORMAT_BFORMAT3D_16 };
		if (
			(
				(sfinfo.channels == 3 || sfinfo.channels == 4) &&
				!sf_command(sndfile, SFC_WAVEX_GET_AMBISONIC, NULL, 0) == SF_AMBISONIC_B_FORMAT
				) ||
			sfinfo.channels < 1 || sfinfo.channels > 4) {
			std::cout << "ERROR: Unsupported channel count: " << sfinfo.channels << '\n';
			sf_close(sndfile);
			return;
		}
		format = formats[sfinfo.channels - 1];

		short* membuf = static_cast<short*>(malloc(static_cast<size_t>(sfinfo.frames * sfinfo.channels) * sizeof(short)));

		sf_count_t num_frames = sf_readf_short(sndfile, membuf, sfinfo.frames);
		if (num_frames < 1) {
			std::cout << "ERROR: Failed to read samples in " << filename << '(' << num_frames << ")\n";
			sf_close(sndfile);
			free(membuf);
			return;
		}
		ALsizei num_bytes = static_cast<ALsizei>(num_frames * sfinfo.channels) * sizeof(short);

		alGenBuffers(1, &buffer);
		alBufferData(buffer, format, membuf, num_bytes, sfinfo.samplerate);

		free(membuf);
		sf_close(sndfile);
		ALenum err = alGetError();
		if (err != AL_NO_ERROR) {
			std::cout << "ERROR: OpenAL Error: " << alGetString(err) << '\n';
			if (buffer && alIsBuffer(buffer))
				alDeleteBuffers(1, &buffer);
			return;
		}
	}

	SoundBuffer::~SoundBuffer() {
		alDeleteBuffers(1, &buffer);
	}
#endif