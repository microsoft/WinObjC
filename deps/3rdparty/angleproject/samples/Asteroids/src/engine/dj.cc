#include "dj.h"

#include <stdio.h>
#include <string.h>

SoundChunk::~SoundChunk() {
	logger(3, "Freeing sound %s", resourceLocation->getString());
	Mix_FreeChunk(handle);
}

DJ::DJ(const char* _resourceLocation, bool _soundEnabled)
	: resourceDir(_resourceLocation), SndManager(_soundEnabled)
{
	music = NULL;
	if(_soundEnabled) {
		int audio_rate = 44100;
		Uint16 audio_format = AUDIO_S16SYS;
		int audio_channels = 2;
		int audio_buffers = 4096;

		if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
			logger(-1, "Unable to initialize audio: %s", Mix_GetError());
			exit(1);
		}

		Mix_VolumeMusic(64);
	}
}

DJ::~DJ() {
	if(managerEnabled) {
		Mix_HaltMusic();
		Mix_FreeMusic(music);
		Mix_CloseAudio();
	}
}

SoundChunk* DJ::createResource() {
	return new SoundChunk;
}

Mix_Chunk* DJ::loadResource(SimpleTrl* resourceLocation) {
	char* fileName = new char[strlen(resourceDir) + strlen(resourceLocation->resourceString) + 2];
	sprintf(fileName, "%s/%s", resourceDir, resourceLocation->resourceString);
	logger(2, "Loading %s", fileName);
	Mix_Chunk* ret = Mix_LoadWAV(fileName);
	if(ret == NULL) logger(-1, "Can't load file %s", fileName);
	return ret;
}

int DJ::setMusic(const char* resourceString, int times) {
	if(!managerEnabled) return 0;
	char* fileName = new char[strlen(resourceDir) + strlen(resourceString) + 2];
	sprintf(fileName, "%s/%s", resourceDir, resourceString);
	logger(2, "Loading %s", fileName);
	Mix_HaltMusic();
	Mix_FreeMusic(music);
	music = Mix_LoadMUS(fileName);
	if(music == NULL) {
		logger(-1, "Unable to load Ogg file: %s", Mix_GetError());
		return 1;
	}
	if(Mix_PlayMusic(music, times) == -1) {
		logger(-1, "Unable to play file %s: %s", resourceString, Mix_GetError());
		return 1;
	}
}

void DJ::mute(bool m) {
	// TODO
}

