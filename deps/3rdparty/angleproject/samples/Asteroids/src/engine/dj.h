#ifndef _DJ_H_
#define _DJ_H_ 

#include "manager.h"

#include "SDL_mixer.h"

class DJ;

/**
 * Interface for object that can play sound
 */
class Sounding {
	protected:
		DJ* dj;
	public:
		Sounding(DJ* _dj) : dj(_dj) { }
		void play(Mix_Chunk* chunk) {
			Mix_PlayChannel(-1, chunk, 0);
		}
};

/**
 * Sound resource for manager
 */
class SoundChunk : public TheResource<Mix_Chunk, Sounding, SimpleTrl> {
	public:
		virtual ~SoundChunk();
};


template class Manager<Mix_Chunk, Sounding, SimpleTrl>;
typedef Manager<Mix_Chunk, Sounding, SimpleTrl> SndManager;

/**
 * Implements manager and allows to play music
 */
class DJ : public SndManager {
	public:
		typedef SndManager::ResourceList SoundChunkList;
		typedef SoundChunkList::iterator SoundChunkIterator;
	protected:
		const char* resourceDir;
		SoundChunk* createResource();
		Mix_Chunk* loadResource(SimpleTrl* resourceLocation);
		bool soundEnabled;
		Mix_Music* music;
	public:
		DJ(const char* _resourceLocation, bool _soundEnabled = true);
		~DJ();
		int setMusic(const char* resourceString, int times = -1);
		void mute(bool m = true);
};

#endif // _DJ_H_
