#ifndef _OSD_H_
#define _OSD_H_

#include "../engine/teges.h"
//#include "block.h"

//#include <SDL_mixer.h>
#include <SDL_ttf.h>

//#include <vector>
//#include <string>

class Tegris;

class TegrisOsd : public Writing {
	protected:
		TTF_Font *osdFont;
		Tegris* game;

	public:
		TegrisOsd(Tegris* _game);
		~TegrisOsd();
		void renderForefront();
		bool enabled;
};

#endif
