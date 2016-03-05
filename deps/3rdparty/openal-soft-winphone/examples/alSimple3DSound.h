#ifndef AL_SIMPLE_3D_SOUND_H
#define AL_SIMPLE_3D_SOUND_H

#include <functional>

namespace alSimple3DSound {
	static const unsigned int DEFAULT_PLAYBACK_DEVICE = 0xffffffff;
	///
	///note that the 3D coordinates system is right-handed
	///

	///
	///return false if already initialized
	///
	bool initSound(const char* soundFile, unsigned int playbackDevice = DEFAULT_PLAYBACK_DEVICE);
	bool initSoundAsync(const char* soundFile, const std::function<void(bool succeeded)> &callback, unsigned int playbackDevice = DEFAULT_PLAYBACK_DEVICE);
	void release();
	void start(float volume);
	void setListenerOrientations(float up[3], float direction[3]);
	void setListenerPosition(float pos[3]);
	void setSoundPosition(float pos[3]);
};

#endif