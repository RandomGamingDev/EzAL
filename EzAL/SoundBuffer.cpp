#include "SoundBuffer.h"

#ifdef OPENAL
	SoundBuffer::SoundBuffer(BufferData data) {
		Init(data);
	}

	SoundBuffer::~SoundBuffer() {
		Delete();
	}

	void SoundBuffer::Init(BufferData data) {
		Init(&ID, data);
	}

	void SoundBuffer::Init(ALuint* ID, BufferData data) {
		alGenBuffers(1, ID);
		StoreBuffer(ID, data);
		free(data.data);
	}

	void SoundBuffer::StoreBuffer(BufferData data) {
		StoreBuffer(&ID, data);
	}

	void SoundBuffer::StoreBuffer(ALuint* ID, BufferData data) {
		alBufferData(*ID, data.format, data.data, data.size, data.freq);
		
		ALenum err = alGetError();
		if (err != AL_NO_ERROR) {
			std::cout << "ERROR: OpenAL Error: " << alGetString(err) << '\n';
			if (ID && alIsBuffer(*ID))
				alDeleteBuffers(1, ID);
			return;
		}
	}

	BufferData SoundBuffer::GetOggData(const char* filename) {
		SF_INFO sfinfo;
		SNDFILE* sndfile = sf_open(filename, SFM_READ, &sfinfo);
		if (!sndfile) {
			std::cout << "ERROR: Could not open audio in " << filename << ": " << sf_strerror(sndfile);
			return BufferData();
		}
		if (sfinfo.frames < 1 || sfinfo.frames > static_cast<sf_count_t>((INT_MAX / sizeof(short)) / sfinfo.channels)) {
			std::cout << "ERROR: Bad sample count in " << filename << '(' << sfinfo.frames << ")\n";
			sf_close(sndfile);
			return BufferData();
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
			return BufferData();
		}
		format = formats[sfinfo.channels - 1];

		short* data = static_cast<short*>(malloc(static_cast<size_t>(sfinfo.frames * sfinfo.channels) * sizeof(short)));

		sf_count_t num_frames = sf_readf_short(sndfile, data, sfinfo.frames);
		if (num_frames < 1) {
			std::cout << "ERROR: Failed to read samples in " << filename << '(' << num_frames << ")\n";
			sf_close(sndfile);
			free(data);
			return BufferData();
		}
		ALsizei size = static_cast<ALsizei>(num_frames * sfinfo.channels) * sizeof(short);

		sf_close(sndfile);
		return BufferData(format, data, size, sfinfo.samplerate);
	}

	void SoundBuffer::Delete() {
		Delete(&ID);
	}

	void SoundBuffer::Delete(ALuint* ID) {
		alDeleteBuffers(1, ID);
	}
#endif